# https://github.com/mongodb/mongo-ruby-driver

require 'mongo'

include Mongo

@client = MongoClient.new('localhost', 27017)
@db     = @client['test']
@coll   = @db['testData']

@coll.remove

3.times do |i|
  @id = @coll.insert({'a' => i+1})
  puts "id = #{@id}"
end

puts "There are #{@coll.count} records. Here they are:"
@coll.find.each { |doc| puts doc.inspect }
