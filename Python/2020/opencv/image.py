import cv2
import numpy as np


def t_reds(pixel):
    B, G, R = pixel
    if R > G and R > B:
        return pixel
    return (255, 255, 255)


if __name__ == '__main__':
    image = cv2.imread('image.jpg')

    w, h, d = image.shape

    for i in range(w):
        for j in range(h):
            image[i, j] = t_reds(image[i, j])

    cv2.imshow('Grayscale', image)
    cv2.waitKey()
    cv2.destroyAllWindows()
