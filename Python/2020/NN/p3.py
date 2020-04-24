import numpy as np

# input
i = [1, 2, 3, 2.5]

# weights
w = [
    [0.2, 0.8, -0.5, 1.0],
    [0.5, -0.91, 0.26, -0.5],
    [-0.26, -0.27, 0.17, 0.87]
]

# bias
b = [2, 3, 0.5]

# output
o = np.dot(w, i) + b

print(o)
