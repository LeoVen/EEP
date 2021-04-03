# 05 - Hidden Layer Activation Functions

# Step Functions
# Sigmoid Function
# Rectfied Linear Unit Function (ReLU)

import numpy as np
import nnfs
from nnfs.datasets import spiral_data

# Sets a default seed and a default data type for np.dot
nnfs.init()

class DenseLayer:
    def __init__(self, n_inputs, n_neurons):
        self.weights = np.random.randn(n_inputs, n_neurons) * 0.1
        self.biases = np.zeros((1, n_neurons))
    def forward(self, inputs):
        self.output = np.dot(inputs, self.weights) + self.biases
    def layer_info(self):
        print(f"W.shape: {self.weights.shape}; B.shape: {self.biases.shape}")


class ActivationRelu:
    def forward(self, inputs):
        self.output = np.maximum(0, inputs)


class ActivationSoftmax:
    def forward(self, inputs):
        exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
        probabilities = exp_values / np.sum(exp_values, axis=1, keepdims=True)
        self.output = probabilities

x, y = spiral_data(samples=100, classes=3)

print(f'x.shape: {x.shape}')
# print(x[:5])

print(f'y.shape: {y.shape}')
# print(y[:5])

def plot_data(x, y):
    import matplotlib.pyplot as plt
    plt.scatter(x[:,0], x[:,1], c=y)
    plt.show()

# plot_data(x, y)

dense1 = DenseLayer(2, 10)
activation1 = ActivationRelu()
dense2 = DenseLayer(10, 10)
activation2 = ActivationSoftmax()

# Compute
dense1.forward(x)
activation1.forward(dense1.output)
dense2.forward(activation1.output)
activation2.forward(dense2.output)

print(activation2.output[:5])
