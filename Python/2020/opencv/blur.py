import cv2
import numpy as np


if __name__ == '__main__':
    image = cv2.imread('Lenna.png')

    mean = cv2.boxFilter(image, -1, (5, 5))
    median = cv2.medianBlur(image, 5)
    gauss = cv2.GaussianBlur(image, (5, 5), 1)

    cv2.imshow('Box Filter', mean)
    cv2.imshow('Median Blur', median)
    cv2.imshow('Gaussian Blur', median)
    cv2.waitKey()
    cv2.destroyAllWindows()
