# #
# arrays.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 03/09/2018
#
# #

# Creating a new array

array0 = Array.new
array1 = Array.new(20)      # starts array with size 20
array2 = Array.new(20, "a") # starts array with size 20 where each is a string of "a"

print "#{array0}\n"
print "#{array1}\n"
print "#{array2}\n"

puts array0.size == array0.length

# You can also use a block to initialize each element
array3 = Array.new(20) { |v| v = v * v}

print "#{array3}\n"

# These also work

array4 = Array.[](1, 2, 3, 4, 5)
array5 = Array[1, 2, 3, 4, 5]

print "#{array4}\n"
print "#{array5}\n"

# Using intervals
array6 = Array(0..9)

print "#{array6}\n"
