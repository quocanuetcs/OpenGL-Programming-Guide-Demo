#include <GL/glut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>
#include "Icosa.h"
#include "CleaningTheWindow.h"
#include "DrawRectangle.h"
#include "DrawPolygon.h"
#include "Dotted.h"
#include "Dash.h"
#include "DrawLine.h"

using namespace std;
const int width = 500;
const int height = 500;
const int lineSpace = 25;
int curContent = 0;

const int nContent = 10;
string content[nContent] = {"OpenGL Programming Guide",
                            "Cleaning the window (Magenta)",
                            "Cleaning the window (Red)",
                            "Draw Line",
                            "Draw Rectangle",
                            "Draw Rectangle With Auto Function",
                            "Draw Dash",
                            "Draw Dotted",
                            "Draw Polygon",
                            "Draw Icosahedron"};

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
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) text[i]);
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
            CleaningTheWindow::cleaningMagenta();
            drawText(content[1].data(), content[1].size(), 0, height - lineSpace);
            break;
        case 2:
            CleaningTheWindow::cleaningRed();
            drawText(content[2].data(), content[2].size(), 0, height - lineSpace);
            break;
        case 3:
            drawText(content[3].data(), content[3].size(), 0, height - lineSpace);
            DrawLine::draw();
            break;
        case 4:
            drawText(content[4].data(), content[4].size(), 0, height - lineSpace);
            DrawRectangle::drawDefault();
            break;
        case 5:
            drawText(content[5].data(), content[5].size(), 0, height - lineSpace);
            DrawRectangle::drawAuto();
            break;
        case 6:
            drawText(content[6].data(), content[6].size(), 0, height - lineSpace);
            Dash::draw();
            break;
        case 7:
            drawText(content[7].data(), content[6].size(), 0, height - lineSpace);
            Dotted::draw();
            break;
        case 8:
            drawText(content[8].data(), content[8].size(), 0, height - lineSpace);
            DrawPolygon::draw();
            break;
        case 9:
            drawText(content[9].data(), content[9].size(), 0, height - lineSpace);
            Icosa::display();
            break;

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
