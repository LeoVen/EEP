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


class ActivationRelu:
    def forward(self, inputs):
        self.output = np.maximum(0, inputs)


class ActivationSoftmax:
    def forward(self, inputs):
        exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
        probabilities = exp_values / np.sum(exp_values, axis=1, keepdims=True)
        self.output = probabilities

x, y = spiral_data(samples=100, classes=3)

dense1 = DenseLayer(2, 3)
activation1 = ActivationRelu()
dense2 = DenseLayer(3, 3)
activation2 = ActivationSoftmax()

# Compute
dense1.forward(x)
activation1.forward(dense1.output)
dense2.forward(activation1.output)
activation2.forward(dense2.output)

print(activation2.output[:5])