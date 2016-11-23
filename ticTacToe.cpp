#include <iostream>
#include <GL/glut.h>

#include "ticTacToe.h"
#include "board.h"

Board board (3, 3);

void display(void)
{
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 0, 100, 100);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tic Tac Toe");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
