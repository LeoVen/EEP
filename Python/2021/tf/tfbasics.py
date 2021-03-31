import os
import tensorflow as tf

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
physdev = tf.config.list_physical_devices('GPU')

# shape (x, y) := x rows, y columns

# Tensor Initialization
x = tf.constant(4.0, shape=(1, 1), dtype=tf.float64)
x = tf.constant([[1, 2, 3], [4, 5, 6]])  # Matrix

x = tf.ones((3, 3))
x = tf.zeros((2, 2))
x = tf.eye(3)  # I for the identity matrix

x = tf.random.normal((3, 3), mean=0, stddev=1)
x = tf.random.uniform((1, 3), minval=0, maxval=1)
x = tf.range(start=1, limit=10, delta=2)

x = tf.cast(x, dtype=tf.float64)

# tf.float32(16, 32, 64)
# tf.int(8, 16, 32, 64)
# tf.bool

# Mathematical Operations
x = tf.constant([1, 2, 3])
y = tf.constant([9, 8, 7])

z = tf.add(x, y)
z = x + y

z = tf.subtract(x, y)
z = x - y

z = tf.divide(x, y)
z = x / y

z = tf.multiply(x, y)  # Element-wise
z = x * y

z = tf.tensordot(x, y, axes=1)
z = tf.reduce_sum(x * y, axis=0)

z = x ** 5

a = tf.random.normal((3, 4))
b = tf.random.normal((4, 3))
z = tf.matmul(a, b)
z = a @ b

# Indexing
c = tf.constant([0, 1, 1, 2, 3, 1, 2, 3])
idx = tf.constant([0, 3])
z = tf.gather(c, idx)

# Reshaping
x = tf.range(9)
x = tf.reshape(x, (3, 3))
x = tf.transpose(x, perm=[1, 0])
