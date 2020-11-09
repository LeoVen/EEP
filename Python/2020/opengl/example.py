import cv2
import numpy as np
import pygame
from OpenGL.GL import *
from OpenGL.GLU import *

cap = cv2.VideoCapture(0)


def create_blank(width, height, rgb_color=(0, 0, 0)):
    """Create new image(numpy array) filled with certain color in RGB"""
    # Cria uma imagem vazia
    image = np.zeros((height, width, 3), np.uint8)
    # Define a cor
    color = tuple(rgb_color)
    # Preenche imagem com uma cor
    image[:] = color

    return image


def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display,pygame.DOUBLEBUF|pygame.OPENGL)
    gluPerspective(90, (display[0]/display[1]),0.1, 50.0 )
    glTranslatef(0.0, 0.0, -5)


    while(True):
        ret, frame = cap.read()
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        avg_color_per_row = np.average(frame, axis=0)
        avg_color = np.average(avg_color_per_row, axis=0)
        avg_color_final = avg_color/255
        color_final = tuple(reversed(avg_color_final))

        #print(avg_color)
        #print(avg_color_final)

        width, height = 300, 300
        cor = (avg_color)
        image = create_blank(width, height, rgb_color=cor)
        cv2.imshow('CorMedia',image)

        verticies = (
            (1, -1, -1),
            (1, 1, -1),
            (-1, 1, -1),
            (-1, -1, -1),
            (1, -1, 1),
            (1, 1, 1),
            (-1, -1, 1),
            (-1, 1, 1)
            )

        edges = (
            (0, 1),
            (0, 3),
            (0, 4),
            (2, 1),
            (2, 3),
            (2, 7),
            (6, 3),
            (6, 4),
            (6, 7),
            (5, 1),
            (5, 4),
            (5, 7)
            )

        colors = (
            (color_final),
            (color_final),
            (color_final),
            (color_final),
            (color_final),
            (color_final),
            )

        surfaces = (
            (0,1,2,3),
            (3,2,7,6),
            (6,7,5,4),
            (4,5,1,0),
            (1,5,7,2),
            (4,0,3,6)
            )


        def Cube():
            glBegin(GL_QUADS)
            for surface in surfaces:
                x = 0
                for vertex in surface:
                    x+=1
                    glColor3fv(colors[x])
                    glVertex3fv(verticies[vertex])
            glEnd()

            glBegin(GL_LINES)
            for edge in edges:
                for vertex in edge:
                    glVertex3fv(verticies[vertex])
            glEnd()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    glTranslatef(-0.5,0,0)
                if event.key == pygame.K_RIGHT:
                    glTranslatef(0.5,0,0)

                if event.key == pygame.K_UP:
                    glTranslatef(0,1,0)
                if event.key == pygame.K_DOWN:
                    glTranslatef(0,-1,0)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        glRotatef(1, 1, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Cube()
        pygame.display.flip()
        pygame.time.wait(10)

main()

cv2.waitKey()
cap.release()
cv2.destroyAllWindows()
