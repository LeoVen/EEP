# https://www.thepythoncode.com/article/canny-edge-detection-opencv-python
import cv2
import numpy as np


if __name__ == '__main__':
    cap = cv2.VideoCapture(0)

    while True:
        _, frame = cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        edges = cv2.Canny(gray, 100, 200)
        cv2.imshow("edges", edges)
        cv2.imshow("gray", gray)
        if cv2.waitKey(1) == ord("q"):
            break

    cap.release()
    cv2.destroyAllWindows()
