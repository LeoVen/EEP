# 03 - The Dot Product

import numpy as np

# input
inputs = [1, 2, 3, 2.5]

# weights
weights = [
    [0.2, 0.8, -0.5, 1.0],
    [0.5, -0.91, 0.26, -0.5],
    [-0.26, -0.27, 0.17, 0.87]
]

# bias
biases = [2, 3, 0.5]

# output
o = np.dot(weights, inputs) + biases

print(o)
