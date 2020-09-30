import cv2
import numpy as np


if __name__ == '__main__':
    img1 = cv2.imread('image.jpg')
    img2 = cv2.imread('french_flag.jpg')

    print(img1.shape)
    print(img2.shape)

    result = cv2.addWeighted(img1, 0.7, img2, 0.3, 0)

    cv2.imshow('Result', result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
