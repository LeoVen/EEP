import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '0'
os.environ['TF_CPP_MIN_VLOG_LEVEL'] = '3'
import tensorflow as tf

physdev = tf.config.list_physical_devices('GPU')

if len(physdev) > 0:
    print(physdev)
    tf.config.experimental.set_memory_growth(physdev[0], True)
else:
    print('¯\_(ツ)_/¯')
