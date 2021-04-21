import tensorflow as tf
import matplotlib.pyplot as plt

from tensorflow.keras import layers

physical_devices = tf.config.list_physical_devices('GPU')
print(physical_devices)

if len(physical_devices) > 0:
    tf.config.experimental.set_memory_growth(physical_devices[0], True)
    print('Memory Growth = True')

mnist = tf.keras.datasets.mnist

(x_train, y_train), (x_test, y_test) = mnist.load_data()

idx = 0

data = x_train[idx].reshape(1, 28, 28, 1).astype('float32') / 255.0

max_pooling = tf.keras.Sequential([
    layers.Input(shape=[28, 28, 1]),
    layers.MaxPooling2D(pool_size=(2, 2)),
])
avg_pooling = tf.keras.Sequential([
    layers.Input(shape=(28, 28, 1)),
    layers.AveragePooling2D(pool_size=(2, 2)),
])

max_pooling.compile()
avg_pooling.compile()

maxp_res = max_pooling.predict(data)
avgp_res = avg_pooling.predict(data)

fig, (ax1, ax2, ax3) = plt.subplots(1, 3)

ax1.imshow(data[0], cmap='gray')
ax1.set_title('Original')

ax2.imshow(maxp_res[0], cmap='gray')
ax2.set_title('MaxPooling (2, 2)')

ax3.imshow(avgp_res[0], cmap='gray')
ax3.set_title('AvgPooling (2, 2)')

plt.show()
