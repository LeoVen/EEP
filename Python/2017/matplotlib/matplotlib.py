import numpy
import scipy
import matplotlib

def f(t):
    return numpy.exp(-t) * numpy.cos(2*np.pi*t)

t1 = numpy.arange(0.0, 5.0, 0.1)
t2 = numpy.arange(0.0, 5.0, 0.02)

matplotlib.pyplot.figure(1)
matplotlib.pyplot.subplot(211)
matplotlib.pyplot.plot(t1, f(t1), 'bo', t2, f(t2), 'k')

matplotlib.pyplot.subplot(212)
matplotlib.pyplot.plot(t2, numpy.cos(2*np.pi*t2), 'r--')
matplotlib.pyplot.show()
