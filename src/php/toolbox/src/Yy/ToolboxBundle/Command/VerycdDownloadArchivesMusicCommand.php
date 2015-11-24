<?php

namespace Yy\ToolboxBundle\Command;

use Symfony\Bundle\FrameworkBundle\Command\ContainerAwareCommand;
use Symfony\Component\Console\Input\InputArgument;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Question\Question;
use GuzzleHttp\Client;
use GuzzleHttp\Promise;
use Yy\ToolboxBundle\Entity\VerycdArchivesMusic;

class VerycdDownloadArchivesMusicCommand extends ContainerAwareCommand
{
    private $container;
    private $entityManager;
    private $verycdArchivesMusicRepo;

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
        $this->verycdArchivesMusicRepo = $this->entityManager->getRepository('YyToolboxBundle:VerycdArchivesMusic');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $basrUrl = 'http://www.verycd.com';
        $client = new Client([
            'base_uri' => $basrUrl,
        ]);
        $resp = $client->request('GET', 'archives/music/');
        $body = $resp->getBody()->getContents();
        preg_match_all('|<dd><a href="(/archives/music/\d+\.html)" title=".+?">(.+?)</a></dd>|', $body, $matches);
        $count = count($matches[0]);
        $output->writeln(sprintf('match done, count = %d', $count));

        for ($i=0; $i<$count; $i++) {
            $url = $basrUrl . $matches[1][$i];
            $verycdArchivesMusic = $this->verycdArchivesMusicRepo->findOneBy([
                'url' => $url,
            ]);
            if ($verycdArchivesMusic != null)
                continue ;

            $verycdArchivesMusic = new VerycdArchivesMusic();
            $verycdArchivesMusic
                ->setTitle($matches[2][$i])
                ->setUrl($url)
            ;
            $this->entityManager->persist($verycdArchivesMusic);
        }
        $this->entityManager->flush();

        $output->writeln('command end...');
    }
}
