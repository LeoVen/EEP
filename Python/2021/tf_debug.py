import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '0'
os.environ['TF_CPP_MIN_VLOG_LEVEL'] = '3'
import tensorflow as tf

physdev = tf.config.list_physical_devices('GPU')
print(physdev)
