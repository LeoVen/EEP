# 01 - Intro and Neuron Code

# input
i = [1.2, 5.1, 2.1]

# weights
w = [3.1, 2.1, 8.7]

# bias
b = 3

# output
o = sum([i[x] * w[x] for x in range(len(i))]) + b

print(o)
