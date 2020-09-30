import cv2
import numpy as np

# Tile size
S = 5


def pred_color(image, offsetx, offsety):
    t = R = G = B = 0
    w, h, d = image.shape
    uptox = offsetx + S if offsetx + S < w else w
    uptoy = offsety + S if offsety + S < h else h
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
    result = np.zeros((w, h, 3), dtype=np.uint8)

    print("File shape: ", image.shape)
    print("Tile shape: ", S, " x ", S)

    w, h, d = result.shape

    for i in range(0, w, S):
        for j in range(0, h, S):
            color = pred_color(image, i, j)
            uptox = i + S if i + S < w else w
            uptoy = j + S if j + S < h else h
            for x in range(i, uptox):
                for y in range(j, uptoy):
                    result[x, y] = color

    cv2.imshow('Tiled', result)
    cv2.waitKey()
    cv2.destroyAllWindows()
