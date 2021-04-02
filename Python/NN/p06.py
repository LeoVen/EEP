# 06 - Softmax Activation

import numpy as np

# Assume index 0 is the intended target
layer_outputs = np.array([4.8, 1.21, 2.385])

layer_outputs_batch = [
    [4.8, 1.21, 2.385],
    [8.9, -1.81, 0.2],
    [1.41, 1.051, 0.026]
]

# Determine how wrong the model is

def softmax(inputs):
    # Prevents overflow of high exponential values
    # Keeps the values between 0 and 1
    treated = inputs - np.max(inputs)

    # This way, negative values still have meaning
    exp_values = np.exp(treated)

    # Normalization
    norm_values = exp_values / np.sum(exp_values)

    return norm_values

def softmax_batch(inputs):
    treated = inputs - np.max(inputs, axis=1, keepdims=True)

    exp_values = np.exp(treated)

    norm_values = exp_values / np.sum(exp_values, axis=1, keepdims=True)

    return norm_values


print(softmax(layer_outputs))
print(softmax_batch(layer_outputs_batch))
