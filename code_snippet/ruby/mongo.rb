require 'mongo'

include Mongo

mongo_client = MongoClient.new('localhost', 27017)
#  puts mongo_client.database_names
db = mongo_client.db('test')
coll = db.collection('testData')
doc = {"name" => "MongoDB", "type" => "database", "count" => 1, "info" => {"x" => 203, "y" => '102'}}
# id = coll.insert(doc)
# puts id
# puts coll.find_one

coll.find.each do |row|
  puts row.inspect
end

exit
doc["name"] = "MongoDB Ruby"
coll.update({"_id" => id}, doc)

coll.update({"_id" => "5295b24102c0ff86ce394488"}, {"xx" => "oo"})
puts 'updated...'
puts coll.find("_id" => "5295b24102c0ff86ce394488").to_a
