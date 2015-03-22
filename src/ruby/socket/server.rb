require 'socket'

server = TCPServer.new 2000
puts 'server start...'

loop do
    client = server.accept
    puts 'new client accept...'

    client.puts "Hello !"
    client.puts "Time is #{Time.now}"

    client.close
    puts 'client close...'
end
