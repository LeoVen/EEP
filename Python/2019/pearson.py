import numpy as np
import matplotlib.pyplot as plt

def f(x):
  return x**2

x = np.array([80, 85, 50, 70, 55, 77, 85, 93, 65, 60])
y = np.array([1.8, 1.83, 1.65, 1.9, 1.6, 1.8, 1.78, 1.86, 1.7, 1.65])

coef = np.polyfit(x, y, 1)

# Pearson Correlation Coeficient
# y' = a + bx
n = len(x)
b = (n * sum(x*y) - sum(x) * sum(y)) / (n * sum(x**2) - sum(x) ** 2)
a = (sum(y) - b * sum(x)) / n

x_space = np.linspace(50, 100)

# Values
plt.scatter(x, y)

# Using np.polyfit
plt.plot(x, np.polyval(coef, x), c='r')

# Using Pearson
plt.plot(x_space, np.polyval([b, a], x_space), c='g')

plt.show()
