x = 4
puts 'This appears to be true.' if x == 4

# while
x = 1
x = x + 1 while x < 10
puts "x = #{x}"

# array
animals = ['lions', 'tigers', 'bears']
animals.each {|animal| puts animal}

# hash
user = {'username' => 'betty', 'age' => 10}
puts "username = #{user['username']}, age = #{user['age']}"

# function
def hello_world
    puts 'hello world'
end

# yield
class Fixnum
    def my_times
        i = self
        while i > 0
            i = i - 1
            yield
        end
    end
end
3.my_times {puts 'many moose'}

# 代码块作为函数参数传递
def call_block(&block)
    block.call
end

def pass_block(&block)
    call_block(&block)
end

pass_block {puts 'hello, block'}

# class
class Tree
    attr_accessor :children, :node_name

    def initialize(name, children=[])
        @children = children
        @node_name = name
    end

    def visit_all(&block)
        visit &block
        children.each {|c| c.visit_all &block}
    end

    def visit(&block)
        block.call self
    end
end

ruby_tree = Tree.new("root", [Tree.new('a', [Tree.new('b'), Tree.new('c')]), Tree.new('d', [Tree.new('e'), Tree.new('f')])])
puts 'visiting a node'
ruby_tree.visit {|node| puts node.node_name}
puts 'visiting entire tree'
ruby_tree.visit_all {|node| puts node.node_name}

# module
module ToFile
    def filename
        "object_#{self.object_id}.txt"
    end

    def to_f
        File.open(filename, 'w') {|f| f.write(to_s)}
    end
end

class Person
    include ToFile
    attr_accessor :name

    def initialize(name)
        @name = name
    end

    def to_s
        name
    end
end

Person.new('matz').to_f

# method_missing
class Roman
    def self.method_missing name, *args
        roman = name.to_s
        roman.gsub!("IV", "IIII")
        roman.gsub!("IX", "VIIII")
        roman.gsub!("XL", "XXXX")
        roman.gsub!("XC", "LXXXX")

        (roman.count("I") + 
         roman.count("V") * 5 +
         roman.count("X") * 10 +
         roman.count("L") * 50 +
         roman.count("C") * 100)
    end
end

puts Roman.X
puts Roman.XC
puts Roman.XII
