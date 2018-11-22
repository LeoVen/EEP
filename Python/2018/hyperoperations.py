# I couldn't get past hexation(2, 3)...

#base[4]num
def tetration(base, num):
	result = 1
	for i in range(num):
		result = base ** result
	return result

#base[5]num
def pentation(base, num):
	result = 1
	for i in range(num):
		result = tetration(base, result)
	return result

#base[6]num
def hexation(base, num):
	result = 1
	for i in range(num):
		result = pentation(base, result)
	return result

#base[7]num
def heptation(base, num):
	result = 1
	for i in range(num):
		result = hexation(base, result)
	return result

#base[8]num
def octation(base, num):
	result = 1
	for i in range(num):
		result = heptation(base, result)
	return result