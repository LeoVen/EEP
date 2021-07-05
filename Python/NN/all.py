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
        # Initialize weights and biases
        self.weights = np.random.randn(n_inputs, n_neurons) * 0.1
        self.biases = np.zeros((1, n_neurons))
    def forward(self, inputs):
        # Calculate output values from inputs, weights and biases
        self.output = np.dot(inputs, self.weights) + self.biases
    def layer_info(self):
        print(f"W.shape: {self.weights.shape}; B.shape: {self.biases.shape}")


class ActivationRelu:
    def forward(self, inputs):
        self.output = np.maximum(0, inputs)


class ActivationSoftmax:
    def forward(self, inputs):
        # Get unormalized probabilities
        exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
        # Normalize for each sample
        probabilities = exp_values / np.sum(exp_values, axis=1, keepdims=True)
        self.output = probabilities


class Loss:

    # Calculates the data and regularization losses
    # given model output and ground truth values
    def calculate(self, output, y):
        sample_losses = self.forward(output, y)
        data_loss = np.mean(sample_losses)
        return data_loss


class LossCategoricalCrossentropy(Loss):

    def forward(self, y_pred, y_true):

        # Number of samples in a batch
        samples = len(y_pred)

        # Prevent division by 0
        y_pred_clipped = np.clip(y_pred, 1e-7, 1 - 1e-7)

        # Categorical labels
        if len(y_true.shape) == 1:
            correct_confidences = y_pred_clipped[range(samples), y_true]
        # One-hot encoded
        elif len(y_true.shape) == 2:
            correct_confidences = np.sum(y_pred_clipped * y_true, axis=1)

        negative_log_likelihood = -np.log(correct_confidences)
        return negative_log_likelihood


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

dense1 = DenseLayer(2, 3)
activation1 = ActivationRelu()
dense2 = DenseLayer(3, 3)
activation2 = ActivationSoftmax()
loss_function = LossCategoricalCrossentropy()

# Compute
dense1.forward(x)
activation1.forward(dense1.output)
dense2.forward(activation1.output)
activation2.forward(dense2.output)

loss = loss_function.calculate(activation2.output, y)

print(activation2.output[:5])
print(loss)
