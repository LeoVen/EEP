import numpy as np
import cv2


if __name__ == '__main__':
    image = cv2.imread("F1Car.jpg")
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    edges = cv2.Canny(gray, threshold1=100, threshold2=200)

    cv2.imshow('Original Gray', image)
    cv2.imshow('Canny', edges)

    cv2.waitKey()
    cv2.destroyAllWindows()
