import cv2
import numpy as np


def t_grayscale(pixel):
    B, G, R = pixel
    # ITU-R BT.2100
    Y = 0.2627 * R + 0.6780 * G + 0.0593 * B
    return (Y, Y, Y)


if __name__ == '__main__':
    image = cv2.imread('image.jpg')

    w, h, d = image.shape

    for i in range(w):
        for j in range(h):
            image[i, j] = t_grayscale(image[i, j])

    cv2.imshow('Grayscale', image)
    cv2.waitKey()
    cv2.destroyAllWindows()
