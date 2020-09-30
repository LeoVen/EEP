import cv2
import numpy as np

resize = 0.3


if __name__ == '__main__':
    img = cv2.imread("poker.jpg")

    w, h, d = img.shape

    cv2.imshow('Original', img)
    cv2.imshow('Resized', cv2.resize(img, (int(h * resize), int(w * resize))))
    cv2.waitKey()
    cv2.destroyAllWindows()
