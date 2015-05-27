BOT_NAME = 'doubanmoive'
SPIDER_MODULES = ['doubanmoive.spiders']
NEWSPIDER_MODULE = 'doubanmoive.spiders'
ITEM_PIPELINES={
  'doubanmoive.mongo_pipelines.MongoDBPipeline':300,
  'doubanmoive.pipelines.DoubanmoivePipeline':400,
}
LOG_LEVEL='DEBUG'

DOWNLOAD_DELAY = 2
RANDOMIZE_DOWNLOAD_DELAY = True
USER_AGENT = 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_3) AppleWebKit/536.5 (KHTML, like Gecko) Chrome/19.0.1084.54 Safari/536.5'
COOKIES_ENABLED = True

MONGODB_SERVER = 'localhost'
MONGODB_PORT = 27017
MONGODB_DB = 'python'
MONGODB_COLLECTION = 'test'
