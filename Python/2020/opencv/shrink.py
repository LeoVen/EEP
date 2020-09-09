import cv2
import numpy as np


# Shrink ratio (integer)
ratio = 3


def pred_color(image, offsetx, offsety, width, height):
    t = R = G = B = 0
    w, h, d = image.shape
    uptox = offsetx + width if offsetx + width < w else w
    uptoy = offsety + height if offsety + height < h else h
    for i in range(offsetx, uptox):
        for j in range(offsety, uptoy):
            b, g, r = image[i, j]
            R += r
            G += g
            B += b
            t += 1
    return (B // t, G // t, R // t)


if __name__ == '__main__':
    image = cv2.imread('image.jpg')

    cv2.imshow('Original', image)

    w, h, d = image.shape
    result = np.zeros((w // ratio, h // ratio, 3), dtype=np.uint8)

    width = w // result.shape[0]
    height = h // result.shape[1]

    print("File shape: ", image.shape)
    print("Tile shape: ", width, " x ", height)

    x = y = 0
    for i in range(0, w, width):
        for j in range(0, h, height):
            color = pred_color(image, i, j, width, height)
            if x < result.shape[0] and y < result.shape[1]:
                result[x, y] = color
            y += 1
        x += 1
        y = 0

    cv2.imshow('Shrinked', result)
    cv2.waitKey()
    cv2.destroyAllWindows()
