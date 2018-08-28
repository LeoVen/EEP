# #
# num_syst.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 27/08/2018
#
# #

max = 4096

for i in 0..max
	puts "%6d %14b %6x %8o" % [i, i, i, i]
end