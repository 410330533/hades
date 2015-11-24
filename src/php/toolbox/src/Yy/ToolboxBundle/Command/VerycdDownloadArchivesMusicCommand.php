<?php

namespace Yy\ToolboxBundle\Command;

use Symfony\Bundle\FrameworkBundle\Command\ContainerAwareCommand;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Question\Question;

class VerycdDownloadArchivesMusicCommand extends ContainerAwareCommand
{
    private $container;
    private $entityManager;

    protected function configure()
    {
        $this
            ->setName('verycd:downloadArchivesMusic')
        ;
    }

    protected function initialize(InputInterface $input, OutputInterface $output)
    {
        $this->container = $this->getContainer();
        $this->entityManager = $this->container->get('doctrine')->getManager();
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $output->writeln('hello world from here ' . $this->getName());
    }
}
