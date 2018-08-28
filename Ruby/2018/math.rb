# #
# math.rb
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 28/08/2018
#
# #

def factorial(num)
	if num <= 1
		return 1
	else
		return factorial(num - 1) * num
	end
end

def is_prime(n)

	if n <= 1
		return false
	end

	if n <= 3
		return true
	end

	if (n % 2 == 0 || n % 3 == 0)
		return false
	end

	i = 5

	while i * i <= n

		if n % i == 0 || n % (i + 2) == 0
			return false
		end

		i += 6
	end

	return true
	
end

def nth_prime(n)

	if n == 0
		return 0
	end

	nth = 0
	i = 0

	loop do
		i += 1

		if is_prime(i)
			nth += 1
		end

		break if nth == n
	end

	return i

end