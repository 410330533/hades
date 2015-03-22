use strict;
use warnings;

# scalar
my $string = 'world';
print "hello " . $string . "\n";

# array
my @array = (
    'print',
    'these',
    'strings',
    'out',
    'for',
    'me',
);
print $array[0] . "\n"; # "print"
print $array[1] . "\n"; # "these"
print $array[2] . "\n"; # "strings"
print $array[3] . "\n"; # "out"
print $array[4] . "\n"; # "for"
print $array[5] . "\n"; # "me"

print "This array has ".(scalar @array)." elements\n"; # "这个数组有6个元素"
print "The last populated index is ".$#array."\n";   # "最后一个索引的号码是 5"
print "Hello $string \n"; # "Hello world"
print "@array \n";        # "print these strings out for me"

print "Hello \$string\n"; # "Hello $string"
print 'Hello $string' . "\n";  # "Hello $string"
print "\@array\n";        # "@array"
print '@array' . "\n";         # "@array"

# hash
my %scientists = (
    "Newton"   => "Isaac",
    "Einstein" => "Albert",
    "Darwin"   => "Charles",
);
print $scientists{"Newton"} . "\n";   # "Isaac"
print $scientists{"Einstein"} . "\n"; # "Albert"
print $scientists{"Darwin"} . "\n";   # "Charles"