# https://www.youtube.com/watch?v=qli-JCrSwuk


# O(2^n)
def helper(data, k):

	if k == 0:
		return 1

	s = len(data) - k

	if data[s] == '0':
		return 0

	result = helper(data, k-1)

	if k >= 2 and int(data[s:s+2]) <= 26:
		result += helper(data, k-2)

	return result

def num_ways(data):

	return helper(data, len(data))


# O(n)
def helper_m(data, k, memo):
	
	if k == 0:
		return 1
	
	s = len(data) - k
	
	if data[s] == '0':
		return 0

	if memo[k] != None:
		return memo[k]

	result = helper_m(data, k-1, memo)
	
	if k >= 2 and int(data[s:s+2]) <= 26:
		result += helper_m(data, k-2, memo)

	memo[k] = result
	
	return result

def num_ways_m(data):
	
	memo = [None for i in range(len(data))]	

	return helper(data, len(data))