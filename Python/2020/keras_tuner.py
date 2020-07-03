from tensorflow.keras.datasets import fashion_mnist
from tensorflow.keras.callbacks import TensorBoard

from tensorflow import keras
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Dense, Flatten, Activation
from tensorflow.keras import layers
from kerastuner.tuners import RandomSearch
from kerastuner.engine.hyperparameters import HyperParameters
import os
import time
import pickle

t = int(time.time())

LOG_DIR = os.path.normpath(f"C:/Dev/TF/kt{t}")
# LOG_DIR = os.path.normpath("~/Dev/TF/kt{t}")
PICKLE = os.path.normpath(f"{LOG_DIR}/model_{t}.pkl")

print('LOG_DIR <-', LOG_DIR)
print('PICKLE  <-', PICKLE)

tensorboard = TensorBoard(log_dir=LOG_DIR)

'''
Label   Description
0   T-shirt/top
1   Trouser
2   Pullover
3   Dress
4   Coat
5   Sandal
6   Shirt
7   Sneaker
8   Bag
9   Ankle boot
'''

(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
x_train = x_train.reshape(-1, 28, 28, 1)  # reshaping for convnet
x_test = x_test.reshape(-1, 28, 28, 1)  # reshaping for convnet


def build_model(hp):  # random search passes this hyperparameter() object
    model = keras.models.Sequential()

    model.add(Conv2D(hp.Int('input_units',
                                min_value=32,
                                max_value=256,
                                step=32), (3, 3), input_shape=x_train.shape[1:]))

    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))

    for i in range(hp.Int('n_layers', 1, 4)):  # adding variation of layers.
        model.add(Conv2D(hp.Int(f'conv_{i}_units',
                                min_value=32,
                                max_value=256,
                                step=32), (3, 3)))
        model.add(Activation('relu'))

    model.add(Flatten())
    model.add(Dense(10))
    model.add(Activation("softmax"))

    model.compile(optimizer="adam",
                  loss="sparse_categorical_crossentropy",
                  metrics=["accuracy"])

    return model


tuner = RandomSearch(
    build_model,
    objective='val_accuracy',
    max_trials=2,  # how many variations on model?
    executions_per_trial=1,  # how many trials per variation? (same model could perform differently)
    directory=LOG_DIR)

tuner.search_space_summary()

tuner.search(x=x_train,
             y=y_train,
             epochs=2,
             batch_size=64,
             callbacks=[tensorboard],
             validation_data=(x_test, y_test))

tuner.results_summary()


with open(PICKLE, "wb") as f:
    pickle.dump(tuner, f)
