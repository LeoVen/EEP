# 05 - Hidden Layer Activation Functions

# Step Functions
# Sigmoid Function
# Rectfied Linear Unit Function (ReLU)

import numpy as np
import nnfs
from nnfs.datasets import spiral_data

# Sets a default seed and a default data type for np.dot
nnfs.init()

X, y = spiral_data(100, 3)

class DenseLayer:
    def __init__(self, n_inputs, n_neurons):
        self.weights = np.random.randn(n_inputs, n_neurons) * 0.1
        self.biases = np.zeros((1, n_neurons))
    def forward(self, inputs):
        self.output = np.dot(inputs, self.weights) + self.biases


class ActivationRelu:
    def forward(self, inputs):
        self.output = np.maximum(0, inputs)


layer1 = DenseLayer(X.shape[1], 5)
layer1.forward(X)

activation1 = ActivationRelu()
activation1.forward(layer1.output)

# layer2 = DenseLayer(activation1.output.shape[1], 2)
# layer2.forward(activation1.output)

# activation2 = ActivationRelu()
# activation2.forward(layer2.output)

print(activation1.output)

# print(activation2.output)
