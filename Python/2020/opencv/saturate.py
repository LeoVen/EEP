import cv2
import numpy as np


def t_saturate(pixel):
    H, S, V = pixel
    S /= 255
    return (H, ((1 - S) * S + S) * 255, V)


if __name__ == '__main__':
    image = cv2.imread('image.jpg')
    cv2.imshow('Original', image)

    hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    w, h, d = image.shape

    for i in range(w):
        for j in range(h):
            hsv_image[i, j] = t_saturate(hsv_image[i, j])

    final_image = cv2.cvtColor(hsv_image, cv2.COLOR_HSV2BGR)

    cv2.imshow('Saturated', final_image)
    cv2.waitKey()
    cv2.destroyAllWindows()
