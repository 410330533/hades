<?php

namespace Unbroken\ToolboxBundle\Command;

use Symfony\Bundle\FrameworkBundle\Command\ContainerAwareCommand;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class ReadEmailCommand extends ContainerAwareCommand
{
    protected function configure()
    {
        $this
            ->setName('read_email')
            ->setDescription('read email')
            ->addArgument('host', InputArgument::REQUIRED, 'host')
            ->addArgument('username', InputArgument::REQUIRED, 'username')
            ->addArgument('password', InputArgument::REQUIRED, 'password')
        ;
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        // {localhost:995/pop3/ssl/novalidate-cert}INBOX
        $host = $input->getArgument('host');
        $username = $input->getArgument('username');
        $password = $input->getArgument('password');

        $conn = imap_open($host, $username, $password);
        $count = imap_num_msg($conn);
        $output->writeln(sprintf('count = %d', $count));

        $readCount = 0;
        for ($i=$count; $i>1; $i--) {
            $output->writeln(sprintf('index = %d', $i));

            $header = imap_headerinfo($conn, $i);
            $from = $header->from;
            $mailbox = $from[0]->mailbox;
            $output->writeln(sprintf('header = %s', var_export($header, true)));

            $fetchBody = imap_fetchbody($conn, $i, 1);
            $output->writeln(sprintf('fetchBodyRaw = %s', $fetchBody));
            $fetchBody = str_replace("\r\n", '', $fetchBody);
            $fetchBody = base64_decode($fetchBody);
            $fetchBody = mb_convert_encoding($fetchBody, 'UTF8', 'GBK');
            $output->writeln(sprintf('fetchBody = %s', $fetchBody));

            if (++$readCount > 5) {
                break ;
            }
        }

        imap_close($conn);
    }
}
