def stirling1():
	# TODO
	return

def stirling2(n, k):
	if n == 0 and k == 0:
		return 1
	elif n == 0 or k == 0:
		return 0
	else:
		return stirling2(n-1, k-1) + k * stirling2(n-1, k)


def main():
	print(stirling2(10, 7))


if __name__ == '__main__':
	main()