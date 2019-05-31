import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial

x = [-2, -1, 0, 2, 4]
y = [7, 4, 1, -1, 0]

coef = Polynomial(lagrange(x, y)).coef

print(coef)

x_space = np.linspace(-4, 6)

plt.scatter(x, y)
plt.plot(x_space, np.polyval(coef, x_space))
plt.show()
