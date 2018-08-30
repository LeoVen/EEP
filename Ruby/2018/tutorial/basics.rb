# #
# basics.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 29/08/2018
#
# #

for i in 0..15
	# decimal, binary, hexadecimal, octal
	# puts "%d %b %x %o" % [i, i, i, i]

	# Can also add spacing
	puts "%4d %6b %4x %4o" % [i, i, i, i]
end

my_name = "Alan"

print("\nHello, my name is " + my_name)
print("\nHello, my name is %s" % [my_name])

integer = 12
float = 3.14
string = "Hello World"
bool1 = true
bool2 = false
nothing = nil
