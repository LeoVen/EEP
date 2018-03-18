def stirling2(n, k):
	if n == 0 and k == 0:
		return 1
	elif n == 0 or k == 0:
		return 0
	else:
		return stirling2(n-1, k-1) + k * stirling2(n-1, k)

def bell(n):
	if n == 0:
		return 1
	part = 0
	for k in range(1, n+1):
		part += stirling2(n, k)
	return part

def main():
	for i in range(21):
		print("B({}) = {}".format(i, bell(i)))



if __name__ == '__main__':
	main()