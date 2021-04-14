import time

import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt

from tensorflow import keras

physical_devices = tf.config.list_physical_devices('GPU')
print(physical_devices)

if len(physical_devices) > 0:
    tf.config.experimental.set_memory_growth(physical_devices[0], True)
    print('Memory Growth = True')

(x_train, y_train), (x_test, y_test) = tf.keras.datasets.cifar10.load_data()

x_train = x_train / 255.0
x_test = x_test / 255.0

print(x_train.shape)
print(y_train.shape)

def get_model(batch_norm, max_pooling, dropout):

    inputs = keras.Input(shape=(32, 32, 3))

    x = keras.layers.Conv2D(32, 3)(inputs)
    if batch_norm:
        x = keras.layers.BatchNormalization()(x)
    x = keras.activations.relu(x)
    if max_pooling:
        x = keras.layers.MaxPooling2D()(x)

    x = keras.layers.Conv2D(64, 3)(x)
    if batch_norm:
        x = keras.layers.BatchNormalization()(x)
    x = keras.activations.relu(x)
    if max_pooling:
        x = keras.layers.MaxPooling2D()(x)

    x = keras.layers.Conv2D(128, 3)(x)
    if batch_norm:
        x = keras.layers.BatchNormalization()(x)
    x = keras.activations.relu(x)

    x = keras.layers.Flatten()(x)

    x = keras.layers.Dense(64, activation='relu')(x)
    if dropout:
        x = keras.layers.Dropout(0.5)(x)

    outputs = keras.layers.Dense(10)(x)

    return keras.Model(inputs=inputs, outputs=outputs)

# batch_norm, max_pooling, dropout
p = [
    # [False, False, False], # Not enough memory
    [False, False, False],
    [True, False, False],
    [False, True, False],
    [False, False, True],
    [True, True, True]
]

models = [get_model(i[0], i[1], i[2]) for i in p]

fit_time = [0 for _ in p]


for model, i in zip(models, range(len(models))):
    model.compile(
        loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        optimizer=keras.optimizers.Adam(lr=3e-4),
        metrics=['accuracy'],
    )

    start = time.time()
    model.fit(x_train, y_train, batch_size=64, epochs=5, verbose=1)
    fit_time[i] = time.time() - start

    print(fit_time[i])


for model, time, param in zip(models, fit_time, p):
    print(model.summary())
    print(f'Fit Time: {time}')
    print(f'BatchNorm: {param[0]}, MaxPooling: {param[1]}, Dropout: {param[2]}')
    model.evaluate(x_test, y_test, batch_size=64, verbose=1)
    print('\n')
