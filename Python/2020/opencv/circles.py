import cv2
import numpy as np


def detect_circles(image):
    img = image.copy()

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (25, 25), cv2.BORDER_DEFAULT)

    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 20, param1=50, param2=30, minRadius=100, maxRadius=120)

    print(circles)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        for counter, i in enumerate(circles[0, :]):
            cv2.circle(img, (i[0], i[1]), i[2], (50, 200, 200), 5)
            cv2.circle(img, (i[0], i[1]), 2, (255, 0, 0), 3)
        cv2.putText(img, 'Coins: ' + str(len(circles[0, :])), (30, 30), cv2.FONT_HERSHEY_SIMPLEX, 1.1, (115, 50, 230), 2)

    return img, gray


if __name__ == '__main__':

    image = cv2.imread('coins.jpg')
    img, gray = detect_circles(image)

    cv2.imshow('Detected', img)
    cv2.imshow('Gray', gray)

    cv2.waitKey()
    cv2.destroyAllWindows()
