class Stream < Object
end

module Readable
    def read
        puts "module read"
    end
end

module Writable
    def write
        puts "module write"
    end
end

class ReadStream < Stream
    include Readable
    def read
        puts "class read"
    end
end

class WriteStream < Stream
    include Writable
    def write
        puts "class write"
    end
end

class ReadWriteStream < Stream
    include Readable
    include Writable
end

r = ReadStream.new.read
w = WriteStream.new.write
rw = ReadWriteStream.new
rw.read
rw.write
