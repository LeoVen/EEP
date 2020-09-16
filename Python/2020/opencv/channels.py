import cv2
import numpy as np

white = (255, 255, 255)

if __name__ == '__main__':
    image = cv2.imread('image.jpg')

    cv2.imshow('Original', image)

    w, h, d = image.shape

    for i in range(w):
        for j in range(h):
            B, G, R = image[i, j]
            if R >= G and R >= B:
                image[i, j] = (0, 0, 255)
            elif G >= R and G >= B:
                image[i, j] = (0, 255, 0)
            elif B >= G and B >= R:
                image[i, j] = (255, 0, 0)
            else:
                image[i, j] = (255, 255, 255)

    cv2.imshow('Predominant Channels', image)
    cv2.waitKey()
    cv2.destroyAllWindows()
