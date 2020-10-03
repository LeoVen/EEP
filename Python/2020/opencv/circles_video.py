import cv2
import numpy as np


def detect_circles(image):
    img = image.copy()

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (21, 21), cv2.BORDER_DEFAULT)

    circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1, 60, param1=50, param2=30, minRadius=0, maxRadius=0)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        for counter, i in enumerate(circles[0, :]):
            cv2.circle(img, (i[0], i[1]), i[2], (50, 200, 200), 5)
            cv2.circle(img, (i[0], i[1]), 2, (255, 0, 0), 3)

    return img, gray


if __name__ == '__main__':
    cap = cv2.VideoCapture(0)

    while (True):
        ret, frame = cap.read()

        img, gray = detect_circles(frame)

        cv2.imshow('Detected', img)
        cv2.imshow('Gray', gray)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
