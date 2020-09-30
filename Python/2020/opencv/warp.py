import cv2
import numpy as np

width, height = 250, 350
resize = 0.3


if __name__ == '__main__':
    img = cv2.imread("poker.jpg")
    w, h, d = img.shape

    pking = np.float32([[1545, 1175], [2085, 1515], [875, 1705], [1425, 2125]])
    pqueen = np.float32([[2075, 650], [2665, 705], [1935, 1200], [2585, 1270]])
    pres = np.float32([[0, 0], [width, 0], [0, height], [width, height]])

    mat_king = cv2.getPerspectiveTransform(pking, pres)
    king = cv2.warpPerspective(img, mat_king, (width, height))

    mat_queen = cv2.getPerspectiveTransform(pqueen, pres)
    queen = cv2.warpPerspective(img, mat_queen, (width, height))

    poly_king = np.int32([pking[0], pking[1], pking[3], pking[2]])
    poly_queen = np.int32([pqueen[0], pqueen[1], pqueen[3], pqueen[2]])

    cv2.polylines(img, [poly_king], True, (0, 255, 0), thickness=10)
    cv2.polylines(img, [poly_queen], True, (0, 0, 255), thickness=10)

    cv2.imshow('King', king)
    cv2.imshow('Queen', queen)
    cv2.imshow('Original', cv2.resize(img, (int(h * resize), int(w * resize))))
    cv2.waitKey()
    cv2.destroyAllWindows()
