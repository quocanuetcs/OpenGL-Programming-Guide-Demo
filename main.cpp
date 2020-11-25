#include <GL/glut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>
#include "Icosa.h"
#include "CleaningTheWindow.h"

using namespace std;
const int width = 500;
const int height = 500;
const int lineSpace = 15;
int curContent = 0;

//BUOC 1: TANG N ROI THEM PHAN TU VAO MANG
const int nContent = 4;
string content[nContent] = {"OpenGL Programming Guide",
                            "2.1.1.1 Cleaning the window (yellow)",
                            "2.1.1.1 Cleaning the window (red)",
                            "2.3.2   Icosahedron"};

void drawText(const char *text, int length, int x, int y) {
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);
    for (int i = 0; i < length; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, (int) text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}

int getLine(int x, int y) {
    return y / lineSpace;
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GLUT_SINGLE | GLUT_RGB);
    glLoadIdentity();
}

void clearScreen(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                curContent = getLine(x, y);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                curContent = 0;
            }
            break;
        default:
            break;
    }
}

void display(void) {
    clearScreen();
    switch (curContent) {
        case 0:
            glColor3f(1.0, 1.0, 1.0);
            for (int i = 0; i < nContent; i++) {
                drawText(content[i].data(), content[i].size(), 0, height - lineSpace * (i + 1));
            }
            break;
        case 1:
            CleaningTheWindow::cleaning("yellow");
            drawText(content[1].data(), content[1].size(), 0, height - lineSpace);
            break;
        case 2:
            CleaningTheWindow::cleaning("red");
            drawText(content[2].data(), content[2].size(), 0, height - lineSpace);
            break;
        case 3:
            drawText(content[3].data(), content[3].size(), 0, height - lineSpace);
            Icosa::display();
            break;
            //BUOC 2: Them thu vien va code vao day
    }
    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Programming Guide");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
