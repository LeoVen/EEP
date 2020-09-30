import cv2
import numpy as np
from matplotlib import pyplot as plt


if __name__ == '__main__':
    img = cv2.imread('girl.jpg', 0)
    after = cv2.equalizeHist(img)
    # after = cv2.medianBlur(after, 5)

    plt.subplot(211)
    plt.title('Before')
    plt.hist(img.ravel(), 256, [0, 256])
    plt.subplot(212)
    plt.title('After')
    plt.hist(after.ravel(), 256, [0, 256])

    cv2.imshow('Before', img)
    cv2.imshow('After', after)

    plt.show()

    cv2.waitKey()
    cv2.destroyAllWindows()
