<?php

namespace Unbroken\ToolboxBundle\Command;

use Symfony\Bundle\FrameworkBundle\Command\ContainerAwareCommand;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;

class FormatPhotoFilenameCommand extends ContainerAwareCommand
{
    const RAW = 'RAW_';
    const Y = 'Y';
    const N = 'N';
    const JPG = 'JPG';

    protected function configure()
    {
        $this
            ->setName('format_photo_filename')
            ->setDescription('format photo filename')
            ->addArgument('dirName', InputArgument::REQUIRED, 'dir name')

            ->addOption('suffix', null, InputOption::VALUE_OPTIONAL, '(JPG) filename suffix', self::JPG)
            ->addOption('isForceUpdate', null, InputOption::VALUE_OPTIONAL, '(Y/N) is force update when oldFilename equals newFilename', self::N)
            ->addOption('isTest', null, InputOption::VALUE_OPTIONAL, '(Y/N) is test, do nothing to file', self::Y)
        ;
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $dirName = rtrim($input->getArgument('dirName'), '/') . '/';
        if ( ! chdir($dirName))
            throw new \Exception('chdir failed');

        $suffix = $input->getOption('suffix');
        $isForceUpdate = $input->getOption('isForceUpdate');
        $isForceUpdate = strtoupper($isForceUpdate) == self::Y ? true : false;
        $isTest = $input->getOption('isTest');
        $isTest = strtoupper($isTest) == self::Y ? true : false;

        foreach (glob('*.' . $suffix) as $filename) {
            $formatFilename = $this->getFormatFilename($filename);

            if ($isTest) {
                $output->writeln(sprintf('oldFilename = %s, newFilename = %s, only test', $filename, $formatFilename));
                continue ;
            }

            if ($filename == $formatFilename && $isForceUpdate === false) {
                $output->writeln(sprintf('oldFilename = %s, newFilename = %s, skip', $filename, $formatFilename));
                continue ;
            }

            // rename
            $output->writeln(sprintf('oldFilename = %s, newFilename = %s, rename', $filename, $formatFilename));
            rename($filename, $formatFilename);
        }
    }

    private function getFormatFilename($filename)
    {
        $info = exif_read_data($filename, null, true);
        // $make = str_replace(' ', '_', $info['IFD0']['Make']);
        $model = str_replace(' ', '_', $info['IFD0']['Model']);
        $datetime = (new \DateTime($info['EXIF']['DateTimeOriginal']))->format('Ymd_His');

        return sprintf('%s_%s_%s%s', $datetime, $model, self::RAW, $this->getRawFilename($filename));
    }

    private function getRawFilename($filename)
    {
        $filename = str_replace(' ', '', $filename);
        $rawFilename = strrchr($filename, self::RAW);
        if (false === $rawFilename)
            return $filename;

        return substr($rawFilename, strlen(self::RAW));
    }
}
