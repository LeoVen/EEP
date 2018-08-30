# #
# numbers.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 29/08/2018
#
# #

# Constant number
PI = 355.0/113.0

# Functions
puts PI
puts (-PI).abs    # Absolute value
puts PI.ceil      # Smallest integer greater than or equal to n
puts PI.floor     # Largest integer less than or equal to n
puts PI.integer?  # Returns true if PI is integer
puts PI.round     # Rounds to the nearest integer
puts PI.truncate  # Returns as integer with decimals removed
puts PI.to_i      # Converts to integer
puts PI.to_f      # Converts to float


# --------------------------------------------------
print "\n\n\n"
puts 1/3
puts 1.0/3.0
puts 1 / 3.0

d = 1.0/3.0

for i in 0..99
	d **=d
end

puts d
