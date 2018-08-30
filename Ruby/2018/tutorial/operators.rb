# #
# operators.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 29/08/2018
#
# #

# Constant numbers
A = 12.0
B = 5.0

C = 43
D = 13

puts "\nOperators\n---------\n"
# Operators
puts A + B         # Addition
puts A - B         # Subtraction
puts A * B         # Multiplication
puts A / B         # Division
puts A % B         # Modulus
puts A ** B        # Exponent
puts A ** (1 / B)  # Root

puts "\nAssignment\n----------\n"
# Assignment
c  =  A
c  += A
c  -= A
c  *= A
c  /= A
c  %= A
c **= A

# Parallel Assignment
x, y, z = 10, 20, 30

puts "\nComparison\n----------\n"
# Comparison operators
puts A == B
puts A != B
puts A > B
puts A < B
puts A >= B
puts A <= B
puts A <=> B # Returns 0 if equal, 1 if greater and -1 if less

puts "\nBitwise\n-------\n"
puts "[%d & %d] ->  %b & %b = %10b [%3d]" % [C, D, C, D, C & D, C & D]
puts "[%d | %d] ->  %b | %b = %10b [%3d]" % [C, D, C, D, C | D, C | D]
puts "[%d ^ %d] ->  %b ^ %b = %10b [%3d]" % [C, D, C, D, C ^ D, C ^ D]
puts "[%d << %d] ->   %b << %b = %10b [%3d]" % [C, 2, C, 2, C << 2, C << 2]
puts "[%d >> %d] ->   %b >> %b = %10b [%3d]" % [C, 2, C, 2, C >> 2, C >> 2]
puts "[  ~%d  ] ->       ~%b  = %10b [%3d]" % [C, C, ~C, ~C]

puts "\nLogical\n-------\n"

A and B # If both the operands are true, then the condition becomes true
A or B  # If any of the two operands are non zero, then the condition becomes true
A && B  # If both the operands are non zero, then the condition becomes true
A || B  # If any of the two operands are non zero, then the condition becomes true
! A     # Reverses the logical state of its operand
not A   # Use to reverses the logical state of its operand

# Ternary operator
# (boolean expression) ? true : false
puts "%d and %d are %s" % [A, B, (A == B) ? "equal" : "not equal"]

# Range operators

# .. has range inclusive [x, y]
for i in 0..5
	print "%d " % [i]
end
puts
# ... has range exclusive [x, y)
for i in 0...5
	print "%d " % [i]
end
