# install
```shell
apt-get install python-pip
apt-get install python2.7-dev
apt-get install libxml2-dev
apt-get install libxslt1-dev

pip install scrapy
pip install w3lib
pip install lxml
pip install cssselect
pip install twisted
pip install service_identity
```

# command
```shell
scrapy startproject <project_name>
scrapy genspider [-t template] <name> <domain>
scrapy crawl <spider>
scrapy check [-l] <spider>
scrapy list
scrapy edit <spider>
scrapy fetch <url>
scrapy view <url>
scrapy shell [url]
scrapy parse <url> [options]
scrapy settings [options]
scrapy runspider <spider_file.py>
scrapy version [-v]
scrapy deploy [ <target::project>] | -l <target> | -L ]
scrapy bench
```
