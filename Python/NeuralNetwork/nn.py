##
# nn.py
#
# Date 12/04/2019
#
# Leonardo Vencovsky
#
# Simple neural network
##
import numpy as np
# import matplotlib.pyplot as plt

class NeuralNetwork:

    def __init__(self, layer_sizes):
        weight_shapes = [(a,b) for a,b in zip(layer_sizes[1:], layer_sizes[:-1])]
        self.weights = [np.random.standard_normal(s) / s[1] ** .5 for s in weight_shapes]
        self.biases = [np.zeros((s,1)) for s in layer_sizes[1:]]

    def predict(self, a):
        for w,b in zip(self.weights, self.biases):
            a = self.activation(np.matmul(w, a) + b)
        return a

    def print_accuracy(self, images, labels):
        predictions = self.predict(images)
        n_correct = sum([np.argmax(a) == np.argmax(b) for a,b in zip(predictions, labels)])
        print('{0} / {1} accuracy: {2}%'.format(n_correct, len(images), (n_correct / len(images)) * 100))

    @staticmethod
    def activation(x):
        return 1.0 / (1.0 + np.exp(-x))

if __name__ == '__main__':

    with np.load('mnist.npz') as data:
        training_images = data['training_images']
        training_labels = data['training_labels']

    # Show image
    # plt.imshow(training_images[1].reshape(28, 28), cmap='gray')
    # plt.show()

    # (input, inner node, .., output)
    layer_sizes = (784, 5, 10)

    net = NeuralNetwork(layer_sizes)

    net.print_accuracy(training_images, training_labels)

