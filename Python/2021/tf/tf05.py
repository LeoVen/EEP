import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers, regularizers

# 50000 training images
# 10000 test images
# 32x32 RGB
from tensorflow.keras.datasets import cifar10

physical_devices = tf.config.list_physical_devices('GPU')
print(physical_devices)

if len(physical_devices) > 0:
    tf.config.experimental.set_memory_growth(physical_devices[0], True)

(x_train, y_train), (x_test, y_test) = cifar10.load_data()
x_train = x_train.astype('float32') / 255.0
x_test = x_test.astype('float32') / 255.0

def model_functional():
    inputs = keras.Input(shape=(32, 32, 3))
    x = layers.Conv2D(32, 3,
        padding='same', kernel_regularizer=regularizers.l2(0.01)
    )(inputs)
    x = layers.BatchNormalization()(x)
    x = keras.activations.relu(x)
    x = layers.MaxPooling2D()(x)
    x = layers.Conv2D(64, 3,
        padding='same', kernel_regularizer=regularizers.l2(0.01)
    )(x)
    x = layers.BatchNormalization()(x)
    x = keras.activations.relu(x)
    x = layers.MaxPooling2D()(x)
    x = layers.Conv2D(128, 3,
        padding='same', kernel_regularizer=regularizers.l2(0.01)
    )(x)
    x = layers.BatchNormalization()(x)
    x = keras.activations.relu(x)
    x = layers.Flatten()(x)
    x = layers.Dense(64, activation='relu',
        kernel_regularizer=regularizers.l2(0.01)
    )(x)
    x = layers.Dropout(0.5)(x)
    outputs = layers.Dense(10)(x)
    model = keras.Model(inputs=inputs, outputs=outputs)
    return model

model = model_functional()

print(model.summary())

model.compile(
    loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    optimizer=keras.optimizers.Adam(lr=3e-4),
    metrics=['accuracy'],
)

model.fit(x_train, y_train, batch_size=64, epochs=150, verbose=1)

model.evaluate(x_test, y_test, batch_size=64, verbose=1)

model.save('./tf05_model')
