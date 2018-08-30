# #
# strings.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 29/08/2018
#
# #

print "\n%d" % ["Hello      World".strip.length]

puts

puts "My string has Hello inside! %s" % [(string.include? "Hello") ? "true" : "false"]

str = " Lorem Ipsum"

puts "\nString is: #{str}"

puts str.upcase
puts str.downcase
puts str.strip
puts "Index of \'rem\': %d (note the first space)" % [str.index("rem")]

