# Multiplicative Persistence
# https://www.youtube.com/watch?v=Wim9WJeDTHQ

def per(n):

	print(n)

	if n < 10:
		return 0

	digits = [int(i) for i in str(n)]

	r = 1
	for d in digits:
		r *= d

	return per(r) + 1

def main():
	print(f"Steps: {per(327)}\n")
	print(f"Steps: {per(277777788888899)}\n")
	print(f"Steps: {per(777777888888992)}\n")
	print(f"Steps: {per(3339933399)}\n")

if __name__ == '__main__':
	main()
