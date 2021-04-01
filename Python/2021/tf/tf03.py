import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

from tensorflow.keras.datasets import mnist
from tensorflow.keras import layers
from tensorflow import keras

import tensorflow as tf

print(tf.test.gpu_device_name())

physical_devices = tf.config.list_physical_devices('GPU')
tf.config.experimental.set_memory_growth(physical_devices[0], True)

(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train = x_train.reshape(-1, 28 * 28).astype('float32') / 255.0
x_test = x_test.reshape(-1, 28 * 28).astype('float32') / 255.0

# Sequential API (Convenient, but no flexible)
def get_model_sequential():
    return keras.Sequential(
        [
            # Without Input, it isn't possible to do model.summary() before modle.fit()
            keras.Input(shape=(28 * 28)),
            layers.Dense(512, activation='relu', name='first_layer'),
            layers.Dense(256, activation='relu', name='second_layer'),
            layers.Dense(10),
        ]
    )

# Functional API (A bit more flexible)
def get_model_functional():
    inputs = keras.Input(shape=(28 * 28))
    x = layers.Dense(512, activation='relu', name='first_layer')(inputs)
    x = layers.Dense(256, activation='relu', name='second_layer')(x)
    outputs = layers.Dense(10, activation='softmax')(x)
    return keras.Model(inputs=inputs, outputs=outputs)

# Get output of specific layer
def get_output(model, layer_name):
    model = keras.Model(inputs=model.inputs,
                        outputs=[model.get_layer(layer_name).output])
    feature = model.predict(x_train)
    print(feature.shape)

# Gets all the features
def get_outputs(model):
    model = keras.Model(inputs=model.inputs,
                        outputs=[layer.output for layer in model.layers])
    features = model.predict(x_train)
    for feature in features:
        print(feature.shape)

model = get_model_functional()
# get_output(model, 'second_layer')
# get_outputs(model)

print(model.summary())

model.compile(
    loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    # optimizer=keras.optimizers.Adam(lr=0.001),
    # optimizer=keras.optimizers.Adagrad(),
    optimizer=keras.optimizers.RMSprop(),
    metrics=['accuracy'],
)

model.fit(x_train, y_train, batch_size=32, epochs=5, verbose=2)
model.evaluate(x_test, y_test, batch_size=32, verbose=2)
