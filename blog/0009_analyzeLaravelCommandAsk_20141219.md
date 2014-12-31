今天我们看下 php Laravel 框架实现的 Command 中的 ask 功能。

直接看代码 `Console/Command.php`
```php
    public function ask($question, $default = null)
    {
        $helper = $this->getHelperSet()->get('question');

        $question = new Question("<question>$question</question>", $default);

        return $helper->ask($this->input, $this->output, $question);
    }
```
看到该类继承了 `\Symfony\Component\Console\Command\Command`
```php
class Command extends \Symfony\Component\Console\Command\Command {
```
所以直接看 symfony command 代码，看 symfony 中，`ask` 函数是怎么写的。我们看下 `Console/Helper/QuestionHelper.php` 的 `ask` 函数
```php
    public function ask(InputInterface $input, OutputInterface $output, Question $question)
    {
        if (!$input->isInteractive()) {
            return $question->getDefault();
        }

        if (!$question->getValidator()) {
            return $this->doAsk($output, $question);
        }

        $that = $this;

        $interviewer = function () use ($output, $question, $that) {
            return $that->doAsk($output, $question);
        };

        return $this->validateAttempts($interviewer, $output, $question);
    }
```
判断下是否 interactive, 是否有 validator. 这些我都不在乎，于是直接往下看。这边是一个 `interviewer` 函数，传到 `validateAttempts` 函数中。我们看 `validateAttempts` 的实现
```php
    private function validateAttempts($interviewer, OutputInterface $output, Question $question)
    {
        $error = null;
        $attempts = $question->getMaxAttempts();
        while (null === $attempts || $attempts--) {
            if (null !== $error) {
                $output->writeln($this->getHelperSet()->get('formatter')->formatBlock($error->getMessage(), 'error'));
            }

            try {
                return call_user_func($question->getValidator(), $interviewer());
            } catch (\Exception $error) {
            }
        }

        throw $error;
    }
```
这里调用了 `$question->getValidator()` 的 `$interviewer()` 函数。看上面的 `interviewer` 函数，是调用 `$that` 的 `doAsk` 函数。`$that` 其实也是 `$this`. 于是直接看 `doAsk` 函数。
```php
    public function doAsk(OutputInterface $output, Question $question)
    {
        $inputStream = $this->inputStream ?: STDIN;

        $message = $question->getQuestion();
        if ($question instanceof ChoiceQuestion) {
            $width = max(array_map('strlen', array_keys($question->getChoices())));

            $messages = (array) $question->getQuestion();
            foreach ($question->getChoices() as $key => $value) {
                $messages[] = sprintf("  [<info>%-${width}s</info>] %s", $key, $value);
            }

            $output->writeln($messages);

            $message = $question->getPrompt();
        }

        $output->write($message);

        $autocomplete = $question->getAutocompleterValues();
        if (null === $autocomplete || !$this->hasSttyAvailable()) {
            $ret = false;
            if ($question->isHidden()) {
                try {
                    $ret = trim($this->getHiddenResponse($output, $inputStream));
                } catch (\RuntimeException $e) {
                    if (!$question->isHiddenFallback()) {
                        throw $e;
                    }
                }
            }

            if (false === $ret) {
                $ret = fgets($inputStream, 4096);
                if (false === $ret) {
                    throw new \RuntimeException('Aborted');
                }
                $ret = trim($ret);
            }
        } else {
            $ret = trim($this->autocomplete($output, $question, $inputStream));
        }

        $ret = strlen($ret) > 0 ? $ret : $question->getDefault();

        if ($normalizer = $question->getNormalizer()) {
            return $normalizer($ret);
        }

        return $ret;
    }
```
函数中的第一行就是关键了，如果没有设置过 `$inputStream` 的话，默认就是 `STDIN`。然后继续往下看。如果是 `isHidden` 的话，就调 `getHiddenResponse` 函数。`getHiddenResponse` 应该是把输出隐藏，然后返回到 `$ret` 变量。然后如果返回 `false` 的话，就 `fgets` 去读 `$inputStream`。再看一下另一个分支的 `autocomplete` 函数。
```php
    private function autocomplete(OutputInterface $output, Question $question, $inputStream)
    {
        $autocomplete = $question->getAutocompleterValues();
        $ret = '';

        $i = 0;
        $ofs = -1;
        $matches = $autocomplete;
        $numMatches = count($matches);

        $sttyMode = shell_exec('stty -g');

        // Disable icanon (so we can fread each keypress) and echo (we'll do echoing here instead)
        shell_exec('stty -icanon -echo');

        // Add highlighted text style
        $output->getFormatter()->setStyle('hl', new OutputFormatterStyle('black', 'white'));

        // Read a keypress
        while (!feof($inputStream)) {
            $c = fread($inputStream, 1);

            // Backspace Character
            if ("\177" === $c) {
                if (0 === $numMatches && 0 !== $i) {
                    $i--;
                    // Move cursor backwards
                    $output->write("\033[1D");
                }

                if ($i === 0) {
                    $ofs = -1;
                    $matches = $autocomplete;
                    $numMatches = count($matches);
                } else {
                    $numMatches = 0;
                }

                // Pop the last character off the end of our string
                $ret = substr($ret, 0, $i);
            } elseif ("\033" === $c) {
                // Did we read an escape sequence?
                $c .= fread($inputStream, 2);

                // A = Up Arrow. B = Down Arrow
                if (isset($c[2]) && ('A' === $c[2] || 'B' === $c[2])) {
                    if ('A' === $c[2] && -1 === $ofs) {
                        $ofs = 0;
                    }

                    if (0 === $numMatches) {
                        continue;
                    }

                    $ofs += ('A' === $c[2]) ? -1 : 1;
                    $ofs = ($numMatches + $ofs) % $numMatches;
                }
            } elseif (ord($c) < 32) {
                if ("\t" === $c || "\n" === $c) {
                    if ($numMatches > 0 && -1 !== $ofs) {
                        $ret = $matches[$ofs];
                        // Echo out remaining chars for current match
                        $output->write(substr($ret, $i));
                        $i = strlen($ret);
                    }

                    if ("\n" === $c) {
                        $output->write($c);
                        break;
                    }

                    $numMatches = 0;
                }

                continue;
            } else {
                $output->write($c);
                $ret .= $c;
                $i++;

                $numMatches = 0;
                $ofs = 0;

                foreach ($autocomplete as $value) {
                    // If typed characters match the beginning chunk of value (e.g. [AcmeDe]moBundle)
                    if (0 === strpos($value, $ret) && $i !== strlen($value)) {
                        $matches[$numMatches++] = $value;
                    }
                }
            }

            // Erase characters from cursor to end of line
            $output->write("\033[K");

            if ($numMatches > 0 && -1 !== $ofs) {
                // Save cursor position
                $output->write("\0337");
                // Write highlighted text
                $output->write('<hl>'.substr($matches[$ofs], $i).'</hl>');
                // Restore cursor position
                $output->write("\0338");
            }
        }

        // Reset stty so it behaves normally again
        shell_exec(sprintf('stty %s', $sttyMode));

        return $ret;
    }
```
也就是一个 `while (!feof($inputStream)) {` 包着，然后里面 `fread`，然后做一些处理，然后 output。

综上，`ask` 函数的本质，就是一个 `$inputStream(默认 STDIN)`，然后 `fgets`, `feof`, `fread` blah blah...标准的流处理函数。
