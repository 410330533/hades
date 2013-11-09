print (1..33).to_a.shuffle.slice(0..5).sort.map { |v| v.to_s.rjust 2,'0' }.join(' ')
print ' | '
puts (1..16).to_a.shuffle.slice(0).to_s.rjust 2,'0'
