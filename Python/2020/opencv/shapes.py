import cv2
import numpy as np

# Constants
width = 400
height = 200
background = (220, 220, 220)
red = (52, 63, 226)
orange = (52, 151, 226)
pink = (127, 52, 226)
green = (60, 216, 110)

padw = width * 0.2
padh = 30


def make_image():
    return np.zeros((height, width, 3), np.uint8)


def make_background(img):
    background_poly = np.array([[[0,0], [width, 0], [width, height], [0, height]]], dtype=np.int32)
    return cv2.fillPoly(img, background_poly, background)


def make_crown_base(img):
    poly = np.array([
        [padw, height - padh],
        [width - padw, height - padh],
        [width - padw - 10, height - padh + 15],
        [padw + 10, height - padh + 15]
    ], dtype=np.int32)
    img = cv2.fillPoly(img, [poly], pink)
    return img


def make_crown_star(img):
    poly = np.array([
        [padw, height - padh - 5],
        [padw / 3.5, padh],
        [width / 3, height / 1.8],
        [width / 2, padh],
        [width - width / 3, height / 1.8],
        [width - padw / 3.5, padh],
        [width - padw, height - padh - 5]
    ], dtype=np.int32)
    img = cv2.fillPoly(img, [poly], orange)
    return img


def make_crown_points(img):
    rad = 12
    cv2.circle(img, (int(padw / 3.5), padh), rad, red, thickness=-1)
    cv2.circle(img, (width // 2, padh), rad, red, thickness=-1)
    cv2.circle(img, (int(width - padw / 3.5), padh), rad, red, thickness=-1)
    return img


def make_jewel(img):
    rad = 30
    cv2.circle(img, (width // 2, int(height / 1.75)), rad, green, thickness=-1)
    return img


if __name__ == '__main__':
    img = make_image()
    img = make_background(img)
    img = make_crown_base(img)
    img = make_crown_star(img)
    img = make_crown_points(img)
    img = make_jewel(img)

    cv2.imshow('image', img)
    cv2.waitKey(0)

    cv2.destroyAllWindows()
