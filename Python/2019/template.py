from string import Template

def Main():
	cart = []
	cart.append(dict(item='Coke', price=8, qty=2))
	cart.append(dict(item='Cake', price=12, qty=1))
	cart.append(dict(item='Fish', price=32, qty=4))

	T = Template("$qty x $item = $price")

	total = 0

	print('Cart:')

	for data in cart:
		print(T.substitute(data))
		total += data['price']

	print("Total : " + str(total))

if __name__ == '__main__':
	Main()