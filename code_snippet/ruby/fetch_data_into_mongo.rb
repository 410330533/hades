require 'net/http'
require 'json'
require 'mongo'
require 'inifile'
require 'date'

$isStop = false

def fetch_data
  config_filename = 'config.ini'
  lastUpdated = nil
  if ! File.exist?(config_filename)
    ini = IniFile.new({:filename => config_filename})
  else
    ini = IniFile.load(config_filename)
    lastUpdated = ini['global']['lastUpdated']
  end
  lastUpdated = '2013-01-01 00:00:00' if lastUpdated == nil

  uri = URI('') # need a url
  uri.query = URI.encode_www_form({:lastUpdated => lastUpdated})
  puts "time start = #{DateTime.now}, lastUpdated = #{lastUpdated}"
  response = Net::HTTP.get(uri)
  data = JSON.parse(response)['data']

  client = Mongo::MongoClient.new('localhost', 27017)
  db = client['mall']
  coll = db['order']

  i = 0
  data.each do |row|
    i += 1

    puts "i = #{i}, tid = #{row['tid']}, status = #{row['status']}, buyer_nick = #{row['buyer_nick']}, seller_nick = #{row['seller_nick']}, created = #{row['created']}, jdp_modified = #{row['jdp_modified']}"
    orderData = JSON.parse(row['jdp_response'])['trade_fullinfo_get_response']['trade']
    
    order = coll.find_one({tid: row['tid']})
    if nil == order
      puts "not exists, create"
      coll.insert({tid: row['tid'], data: orderData})
    else
      puts "exists, update"
      coll.update({tid: row['tid']}, {tid: row['tid'], data: orderData})
    end

    lastUpdated = row['jdp_modified'] if DateTime.parse(row['jdp_modified']) > DateTime.parse(lastUpdated)
  end

  puts "length = #{data.length}"
  $isStop = true if data.length < 100
  puts "time end = #{DateTime.now}, lastUpdated = #{lastUpdated}"
  puts

  ini['global'] = { 'lastUpdated' => lastUpdated }
  ini.write
end

while false == $isStop do
  fetch_data
end

