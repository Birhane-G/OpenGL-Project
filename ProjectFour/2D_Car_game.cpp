#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

#pragma GCC diagnostic ignored "-Wwrite-strings"

int FPS = 50;
int gv = 0;

int start = 0;
int level = 0;
int score = 0;

int roadDivTopMost = 0;
int roadTop = 0;
int roadMdl = 0;
int roadBtm = 0;

int roadLTop = 0;
int roadLMdl = 0;
int roadLBtm = 0;

int car;
int lrIndex;

int car1;
int lrIndex1;
int car2;
int lrIndex2;
int car3;
int lrIndex3;
int car4;
int lrIndex4;
int car5;
int lrIndex5;

char s[60];
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void opponentCar()
{
    // glColor3f(0.0, 0.0, 1.0);
    // glBegin(GL_POLYGON);
    // glVertex2f(lrIndex1 + 26, car1 + 100);
    // glVertex2f(lrIndex1 + 26, car1 + 86);
    // glVertex2f(lrIndex1 + 34, car1 + 86);
    // glVertex2f(lrIndex1 + 34, car1 + 100);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.6, 0.0);
    glVertex2f(lrIndex1 + 25, car1 + 98);
    glVertex2f(lrIndex1 + 24, car1 + 96);
    glVertex2f(lrIndex1 + 24, car1 + 94);
    glVertex2f(lrIndex1 + 24.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 24.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 24.5, car1 + 86);
    glVertex2f(lrIndex1 + 23.7, car1 + 83);
    glColor3f(1.0, 0.6, 0.4);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 4.8 * cos(th), car1 + 83 + 6 * sin(th));
    }
    glVertex2f(lrIndex1 + 33.3, car1 + 83);
    glVertex2f(lrIndex1 + 32.5, car1 + 86);
    glVertex2f(lrIndex1 + 32.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 33, car1 + 94);
    glColor3f(1.0, 0.6, 0.0);
    glVertex2f(lrIndex1 + 33, car1 + 96);
    glVertex2f(lrIndex1 + 32, car1 + 98);
    glVertex2f(lrIndex1 + 25, car1 + 98);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 25, car1 + 98);
    glVertex2f(lrIndex1 + 24, car1 + 96);
    glVertex2f(lrIndex1 + 24, car1 + 94);
    glVertex2f(lrIndex1 + 24.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 24.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 24.5, car1 + 86);
    glVertex2f(lrIndex1 + 23.7, car1 + 83);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 4.8 * cos(th), car1 + 83 + 6 * sin(th));
    }
    glVertex2f(lrIndex1 + 33.3, car1 + 83);
    glVertex2f(lrIndex1 + 32.5, car1 + 86);
    glVertex2f(lrIndex1 + 32.5, car1 + 93.5);
    glVertex2f(lrIndex1 + 33, car1 + 94);
    glVertex2f(lrIndex1 + 33, car1 + 96);
    glVertex2f(lrIndex1 + 32, car1 + 98);
    glVertex2f(lrIndex1 + 25, car1 + 98);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(2);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 24.5, car1 + 97);
    glVertex2f(lrIndex1 + 32.5, car1 + 97);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 25, car1 + 97);
    glVertex2f(lrIndex1 + 25, car1 + 96);
    glVertex2f(lrIndex1 + 26, car1 + 95);
    glVertex2f(lrIndex1 + 31, car1 + 95);
    glVertex2f(lrIndex1 + 32, car1 + 96);
    glVertex2f(lrIndex1 + 32, car1 + 97);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 26.5, car1 + 95);
    glVertex2f(lrIndex1 + 26.5, car1 + 91);
    glVertex2f(lrIndex1 + 30.5, car1 + 91);
    glVertex2f(lrIndex1 + 30.5, car1 + 95);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 27, car1 + 91);
    glVertex2f(lrIndex1 + 27, car1 + 88);
    glVertex2f(lrIndex1 + 30, car1 + 88);
    glVertex2f(lrIndex1 + 30, car1 + 91);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 27, car1 + 88);
    glVertex2f(lrIndex1 + 25.5, car1 + 86);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 3 * cos(th), car1 + 86 + 2 * sin(th));
    }
    glVertex2f(lrIndex1 + 31.5, car1 + 86);
    glVertex2f(lrIndex1 + 30, car1 + 88);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 3 * cos(th), car1 + 86 + 6 * sin(th));
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 26, car1 + 80);
    glVertex2f(lrIndex1 + 26, car1 + 79);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 2.5 * cos(th), car1 + 79 + 1 * sin(th));
    }
    glVertex2f(lrIndex1 + 31, car1 + 79);
    glVertex2f(lrIndex1 + 31, car1 + 80);

    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 28.5 + 2.5 * cos(th), car1 + 80 + 1 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 26, car1 + 88.5);
    glVertex2f(lrIndex1 + 25, car1 + 87);
    glVertex2f(lrIndex1 + 25, car1 + 93.5);
    glVertex2f(lrIndex1 + 26, car1 + 93.5);
    glVertex2f(lrIndex1 + 26, car1 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 31, car1 + 88.5);
    glVertex2f(lrIndex1 + 32, car1 + 87);
    glVertex2f(lrIndex1 + 32, car1 + 93.5);
    glVertex2f(lrIndex1 + 31, car1 + 93.5);
    glVertex2f(lrIndex1 + 31, car1 + 88.5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    for (int i = 0; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 31.7 + 0.6 * cos(th), car1 + 81 + 0.7 * sin(th));
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.1, 0.3);
    for (int i = 0; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex1 + 25.4 + 0.6 * cos(th), car1 + 81 + 0.7 * sin(th));
    }
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(6);
    glColor3f(0.0, 0.1, 0.3);
    glVertex2f(lrIndex1 + 25.5, car1 + 97.5);
    glVertex2f(lrIndex1 + 27, car1 + 97.5);
    glVertex2f(lrIndex1 + 29.5, car1 + 97.5);
    glVertex2f(lrIndex1 + 31.5, car1 + 97.5);
    glVertex2f(lrIndex1 + 26, car1 + 96.5);
    glVertex2f(lrIndex1 + 31, car1 + 96.5);
    glEnd();
    // car1--;
    if (car1 < -120)
    {

        if (lrIndex1 == 0)
        {

            lrIndex1 = 40;
        }
        else if (lrIndex1 == 40)
        {

            lrIndex1 = 10;
        }
        else if (lrIndex1 == 10)
        {

            lrIndex1 = 20;
        }
        else if (lrIndex1 == 20)
        {

            lrIndex1 = 30;
        }
        else
        {

            lrIndex1 = 0;
        }
        car1 = 0;
        score++;
    }
    if ((abs(lrIndex - lrIndex1) < 8) && (car1 + 100 < car + 45) && (car1 + 100 > car + 3))
    {
        start = 0;
        gv = 1;
    }
    glEnd();

    // glColor3f(1.0, 1.0, 0.0);
    // glBegin(GL_POLYGON);
    // glVertex2f(lrIndex2 + 26, car2 + 100);
    // glVertex2f(lrIndex2 + 26, car2 + 84);
    // glVertex2f(lrIndex2 + 34, car2 + 84);
    // glVertex2f(lrIndex2 + 34, car2 + 100);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(lrIndex2 + 24.5, car2 + 98.5);
    glVertex2f(lrIndex2 + 24, car2 + 98);
    glVertex2f(lrIndex2 + 24, car2 + 84);
    glColor3f(0.0, 0.0, 0.4);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex2 + 28.5 + 4.5 * cos(th), car2 + 84 + 4 * sin(th));
    }
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(lrIndex2 + 33, car2 + 84);
    glVertex2f(lrIndex2 + 33, car2 + 98);
    glVertex2f(lrIndex2 + 32.5, car2 + 98.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.5);
    glVertex2f(lrIndex2 + 24.5, car2 + 98.5);
    glVertex2f(lrIndex2 + 24, car2 + 98);
    glVertex2f(lrIndex2 + 24, car2 + 84);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex2 + 28.5 + 4.5 * cos(th), car2 + 84 + 4 * sin(th));
    }
    glVertex2f(lrIndex2 + 33, car2 + 84);
    glVertex2f(lrIndex2 + 33, car2 + 98);
    glVertex2f(lrIndex2 + 32.5, car2 + 98.5);
    glVertex2f(lrIndex2 + 24.5, car2 + 98.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.5);
    glVertex2f(lrIndex2 + 25, car2 + 97);
    glVertex2f(lrIndex2 + 25, car2 + 87);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex2 + 28.5 + 3.5 * cos(th), car2 + 87 + 4 * sin(th));
    }
    glVertex2f(lrIndex2 + 32, car2 + 87);
    glVertex2f(lrIndex2 + 32, car2 + 97);
    glVertex2f(lrIndex2 + 25, car2 + 97);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.5);
    glVertex2f(lrIndex2 + 26.5, car2 + 95.5);
    glVertex2f(lrIndex2 + 26.5, car2 + 90);
    glVertex2f(lrIndex2 + 30.5, car2 + 90);
    glVertex2f(lrIndex2 + 30.5, car2 + 95.5);
    glVertex2f(lrIndex2 + 26.5, car2 + 95.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 25.2, car2 + 96.8);
    glVertex2f(lrIndex2 + 25.2, car2 + 94);
    glVertex2f(lrIndex2 + 26.3, car2 + 94);
    glVertex2f(lrIndex2 + 26.3, car2 + 95.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 31.8, car2 + 96.8);
    glVertex2f(lrIndex2 + 31.8, car2 + 94);
    glVertex2f(lrIndex2 + 30.7, car2 + 94);
    glVertex2f(lrIndex2 + 30.7, car2 + 95.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 25.2, car2 + 93.8);
    glVertex2f(lrIndex2 + 25.2, car2 + 91);
    glVertex2f(lrIndex2 + 26.3, car2 + 91);
    glVertex2f(lrIndex2 + 26.3, car2 + 93.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 30.7, car2 + 93.8);
    glVertex2f(lrIndex2 + 30.7, car2 + 91);
    glVertex2f(lrIndex2 + 31.8, car2 + 91);
    glVertex2f(lrIndex2 + 31.8, car2 + 93.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 25.2, car2 + 90.8);
    glVertex2f(lrIndex2 + 25.2, car2 + 88.7);
    glVertex2f(lrIndex2 + 26.3, car2 + 90);
    glVertex2f(lrIndex2 + 26.3, car2 + 90.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 31.8, car2 + 90.8);
    glVertex2f(lrIndex2 + 31.8, car2 + 88.7);
    glVertex2f(lrIndex2 + 30.7, car2 + 90);
    glVertex2f(lrIndex2 + 30.7, car2 + 90.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 25.4, car2 + 96.8);
    glVertex2f(lrIndex2 + 31.6, car2 + 96.8);
    glVertex2f(lrIndex2 + 30.7, car2 + 95.7);
    glVertex2f(lrIndex2 + 26.3, car2 + 95.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex2 + 31.8, car2 + 88.4);
    glVertex2f(lrIndex2 + 30.5, car2 + 89.8);
    glVertex2f(lrIndex2 + 26.4, car2 + 89.8);
    glVertex2f(lrIndex2 + 25.2, car2 + 88.4);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex2 + 28.5 + 3.3 * cos(th), car2 + 88.4 + 1 * sin(th));
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(lrIndex2 + 25.5, car2 + 97.8);
    glVertex2f(lrIndex2 + 27, car2 + 97.8);
    glVertex2f(lrIndex2 + 29.5, car2 + 97.8);
    glVertex2f(lrIndex2 + 31.5, car2 + 97.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(lrIndex2 + 26.5, car2 + 82.3);
    glVertex2f(lrIndex2 + 25.7, car2 + 81.8);
    glVertex2f(lrIndex2 + 24.7, car2 + 83.3);
    glVertex2f(lrIndex2 + 25.4, car2 + 83.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(lrIndex2 + 30.5, car2 + 82.3);
    glVertex2f(lrIndex2 + 31.3, car2 + 81.8);
    glVertex2f(lrIndex2 + 32.3, car2 + 83.3);
    glVertex2f(lrIndex2 + 31.6, car2 + 83.8);
    glEnd();
    // car2--;
    if (car2 < -120)
    {

        if (lrIndex2 == 0)
        {

            lrIndex2 = 10;
        }
        else if (lrIndex2 == 40)
        {
            lrIndex2 = 30;
        }
        else if (lrIndex2 == 10)
        {
            lrIndex2 = 0;
        }
        else if (lrIndex2 == 20)
        {
            lrIndex2 = 40;
        }
        else
        {
            lrIndex2 = 20;
        }
        car2 = 0;
        score++;
    }
    if ((abs(lrIndex - lrIndex2) < 8) && (car2 + 100 < car + 42) && (car2 + 100 > car + 2))
    {
        start = 0;
        gv = 1;
    }
    glEnd();
    // glColor3f(1.0, 0.0, 0.0);
    // glBegin(GL_POLYGON);
    // glVertex2f(lrIndex3 + 26, car3 + 100);
    // glVertex2f(lrIndex3 + 26, car3 + 84);
    // glVertex2f(lrIndex3 + 34, car3 + 84);
    // glVertex2f(lrIndex3 + 34, car3 + 100);

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.0, 0.1);
    glVertex2f(lrIndex3 + 24, car3 + 98);
    glVertex2f(lrIndex3 + 24, car3 + 90);
    glColor3f(0.7, 0.0, 0.1);
    glVertex2f(lrIndex3 + 32, car3 + 90);
    glVertex2f(lrIndex3 + 32, car3 + 98);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 24, car3 + 98);
    glVertex2f(lrIndex3 + 24, car3 + 90);
    glVertex2f(lrIndex3 + 32, car3 + 90);
    glVertex2f(lrIndex3 + 32, car3 + 98);
    glVertex2f(lrIndex3 + 24, car3 + 98);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.0, 0.1);
    glVertex2f(lrIndex3 + 27.5, car3 + 90);
    glVertex2f(lrIndex3 + 27.5, car3 + 89);
    glVertex2f(lrIndex3 + 28.5, car3 + 89);
    glVertex2f(lrIndex3 + 28.5, car3 + 90);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.0, 0.1);
    glVertex2f(lrIndex3 + 24, car3 + 89);
    glVertex2f(lrIndex3 + 24, car3 + 82);
    glColor3f(0.7, 0.0, 0.1);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex3 + 28 + 4 * cos(th), car3 + 82 + 5 * sin(th));
    }
    glVertex2f(lrIndex3 + 32, car3 + 82);
    glVertex2f(lrIndex3 + 32, car3 + 89);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 24, car3 + 89);
    glVertex2f(lrIndex3 + 24, car3 + 82);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex3 + 28 + 4 * cos(th), car3 + 82 + 5 * sin(th));
    }
    glVertex2f(lrIndex3 + 32, car3 + 82);
    glVertex2f(lrIndex3 + 32, car3 + 89);
    glVertex2f(lrIndex3 + 24, car3 + 89);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 25.5, car3 + 88.5);
    glVertex2f(lrIndex3 + 25.5, car3 + 84);
    glVertex2f(lrIndex3 + 30.5, car3 + 84);
    glVertex2f(lrIndex3 + 30.5, car3 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 30.7, car3 + 88.5);
    glVertex2f(lrIndex3 + 30.7, car3 + 86);
    glVertex2f(lrIndex3 + 31.8, car3 + 86);
    glVertex2f(lrIndex3 + 31.8, car3 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 25.3, car3 + 88.5);
    glVertex2f(lrIndex3 + 25.3, car3 + 86);
    glVertex2f(lrIndex3 + 24.2, car3 + 86);
    glVertex2f(lrIndex3 + 24.2, car3 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 25.3, car3 + 85.8);
    glVertex2f(lrIndex3 + 25.3, car3 + 84);
    glVertex2f(lrIndex3 + 24.2, car3 + 82.5);
    glVertex2f(lrIndex3 + 24.2, car3 + 85.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 30.7, car3 + 85.8);
    glVertex2f(lrIndex3 + 30.7, car3 + 84);
    glVertex2f(lrIndex3 + 31.8, car3 + 82.5);
    glVertex2f(lrIndex3 + 31.8, car3 + 85.8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 31.8, car3 + 82.3);
    glVertex2f(lrIndex3 + 30.5, car3 + 83.8);
    glVertex2f(lrIndex3 + 25.5, car3 + 83.8);
    glVertex2f(lrIndex3 + 24.2, car3 + 82.3);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex3 + 28 + 3.8 * cos(th), car3 + 82.5 + 1.5 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(lrIndex3 + 25.2, car3 + 81);
    glVertex2f(lrIndex3 + 25.2, car3 + 80);
    glVertex2f(lrIndex3 + 26, car3 + 79);
    glVertex2f(lrIndex3 + 26, car3 + 80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(lrIndex3 + 30.8, car3 + 81);
    glVertex2f(lrIndex3 + 30.8, car3 + 80);
    glVertex2f(lrIndex3 + 30, car3 + 79);
    glVertex2f(lrIndex3 + 30, car3 + 80);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex3 + 28 + 2 * cos(th), car3 + 79 + 0.8 * sin(th));
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 25, car3 + 97);
    glVertex2f(lrIndex3 + 25, car3 + 91);
    glVertex2f(lrIndex3 + 31, car3 + 91);
    glVertex2f(lrIndex3 + 31, car3 + 97);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex3 + 24, car3 + 98);
    glVertex2f(lrIndex3 + 25, car3 + 97);
    glVertex2f(lrIndex3 + 32, car3 + 98);
    glVertex2f(lrIndex3 + 31, car3 + 97);
    glVertex2f(lrIndex3 + 32, car3 + 90);
    glVertex2f(lrIndex3 + 31, car3 + 91);
    glVertex2f(lrIndex3 + 24, car3 + 90);
    glVertex2f(lrIndex3 + 25, car3 + 91);
    glEnd();
    // car3--;
    if (car3 < -120)
    {
        if (lrIndex3 == 0)
        {
            lrIndex3 = 30;
        }
        else if (lrIndex3 == 40)
        {
            lrIndex3 = 0;
        }
        else if (lrIndex3 == 10)
        {
            lrIndex3 = 10;
        }
        else if (lrIndex3 == 20)
        {
            lrIndex3 = 20;
        }
        else
        {
            lrIndex3 = 40;
        }
        car3 = 0;
        score++;
    }
    if ((abs(lrIndex - lrIndex3) < 8) && (car3 + 100 < car + 44) && (car3 + 100 > car + 3))
    {
        start = 0;
        gv = 1;
    }
    glEnd();
    // glColor3f(1.0, 0.0, 1.0);
    // glBegin(GL_POLYGON);
    // glVertex2f(lrIndex4 + 26, car4 + 100);
    // glVertex2f(lrIndex4 + 26, car4 + 86);
    // glVertex2f(lrIndex4 + 34, car4 + 86);
    // glVertex2f(lrIndex4 + 34, car4 + 100);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(lrIndex4 + 24.3, car4 + 92);
    glVertex2f(lrIndex4 + 24.3, car4 + 87);
    glVertex2f(lrIndex4 + 24, car4 + 86);
    glVertex2f(lrIndex4 + 24, car4 + 80);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 4 * cos(th), car4 + 80 + 2 * sin(th));
    }
    glVertex2f(lrIndex4 + 32, car4 + 86);
    glVertex2f(lrIndex4 + 31.7, car4 + 87);
    glVertex2f(lrIndex4 + 31.7, car4 + 92);
    glVertex2f(lrIndex4 + 32, car4 + 93);
    glVertex2f(lrIndex4 + 32, car4 + 98);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 4 * cos(th), car4 + 98 + 2 * sin(th));
    }
    glVertex2f(lrIndex4 + 24, car4 + 98);
    glVertex2f(lrIndex4 + 24, car4 + 93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(lrIndex4 + 24.3, car4 + 92);
    glVertex2f(lrIndex4 + 24.3, car4 + 87);
    glVertex2f(lrIndex4 + 24, car4 + 86);
    glVertex2f(lrIndex4 + 24, car4 + 80);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 4 * cos(th), car4 + 80 + 2 * sin(th));
    }
    glVertex2f(lrIndex4 + 32, car4 + 86);
    glVertex2f(lrIndex4 + 31.7, car4 + 87);
    glVertex2f(lrIndex4 + 31.7, car4 + 92);
    glVertex2f(lrIndex4 + 32, car4 + 93);
    glVertex2f(lrIndex4 + 32, car4 + 98);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 4 * cos(th), car4 + 98 + 2 * sin(th));
    }
    glVertex2f(lrIndex4 + 24, car4 + 98);
    glVertex2f(lrIndex4 + 24, car4 + 93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(lrIndex4 + 25, car4 + 97);
    glVertex2f(lrIndex4 + 25, car4 + 80);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 3 * cos(th), car4 + 80 + 2 * sin(th));
    }
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(lrIndex4 + 31, car4 + 97);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 3 * cos(th), car4 + 97 + 2 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 26.5, car4 + 88);
    glVertex2f(lrIndex4 + 25, car4 + 86);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 3 * cos(th), car4 + 86 + 1.5 * sin(th));
    }
    glVertex2f(lrIndex4 + 29.5, car4 + 88);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 1.5 * cos(th), car4 + 88 - 0.3 * sin(th));
    }
    glVertex2f(lrIndex4 + 26.5, car4 + 88);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 25, car4 + 87);
    glVertex2f(lrIndex4 + 25, car4 + 91);
    glVertex2f(lrIndex4 + 26.5, car4 + 91);
    glVertex2f(lrIndex4 + 26.5, car4 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 25, car4 + 91.5);
    glVertex2f(lrIndex4 + 25, car4 + 95);
    glVertex2f(lrIndex4 + 26.5, car4 + 93);
    glVertex2f(lrIndex4 + 26.5, car4 + 91.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 31, car4 + 87);
    glVertex2f(lrIndex4 + 31, car4 + 91);
    glVertex2f(lrIndex4 + 29.5, car4 + 91);
    glVertex2f(lrIndex4 + 29.5, car4 + 88.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 31, car4 + 91.5);
    glVertex2f(lrIndex4 + 31, car4 + 95);
    glVertex2f(lrIndex4 + 29.5, car4 + 93);
    glVertex2f(lrIndex4 + 29.5, car4 + 91.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 26.8, car4 + 93.5);
    glVertex2f(lrIndex4 + 25.5, car4 + 95);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 1.2 * cos(th), car4 + 93.5 - 0.3 * sin(th));
    }
    glVertex2f(lrIndex4 + 30.5, car4 + 95);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 28 + 2.5 * cos(th), car4 + 95 + 1 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 24, car4 + 80);
    for (int i = 180; i <= 250; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 26 + 2 * cos(th), car4 + 80 + 1.4 * sin(th));
    }
    glVertex2f(lrIndex4 + 25.4, car4 + 79.5);
    glVertex2f(lrIndex4 + 24, car4 + 80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 32, car4 + 80);
    glVertex2f(lrIndex4 + 30.6, car4 + 79.5);
    for (int i = 270; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 30 + 2 * cos(th), car4 + 80 + 1.4 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 24, car4 + 98);
    glVertex2f(lrIndex4 + 24, car4 + 97);
    glVertex2f(lrIndex4 + 24.5, car4 + 97);
    glVertex2f(lrIndex4 + 24.5, car4 + 98);
    glVertex2f(lrIndex4 + 25, car4 + 98);
    glVertex2f(lrIndex4 + 25, car4 + 99);
    for (int i = 90; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 25 + 1 * cos(th), car4 + 98.2 + 1 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i <= 90; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex4 + 31 + 1 * cos(th), car4 + 98.2 + 1 * sin(th));
    }
    glVertex2f(lrIndex4 + 32, car4 + 98);
    glVertex2f(lrIndex4 + 32, car4 + 97);
    glVertex2f(lrIndex4 + 31.5, car4 + 97);
    glVertex2f(lrIndex4 + 31.5, car4 + 98);
    glVertex2f(lrIndex4 + 31, car4 + 98);
    glVertex2f(lrIndex4 + 31, car4 + 99.2);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 24, car4 + 86);
    glVertex2f(lrIndex4 + 24.3, car4 + 87);
    glVertex2f(lrIndex4 + 23.5, car4 + 87.5);
    glVertex2f(lrIndex4 + 23, car4 + 87);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex4 + 32, car4 + 86);
    glVertex2f(lrIndex4 + 31.7, car4 + 87);
    glVertex2f(lrIndex4 + 32.5, car4 + 87.5);
    glVertex2f(lrIndex4 + 33, car4 + 87);
    glEnd();
    // car4--;
    if (car4 < -120)
    {
        if (lrIndex4 == 0)
        {
            lrIndex4 = 20;
        }
        else if (lrIndex4 == 40)
        {
            lrIndex4 = 40;
        }
        else if (lrIndex4 == 10)
        {
            lrIndex4 = 30;
        }
        else if (lrIndex4 == 20)
        {
            lrIndex4 = 0;
        }
        else
        {
            lrIndex4 = 10;
        }
        car4 = 0;
        score++;
    }
    if ((abs(lrIndex - lrIndex4) < 8) && (car4 + 100 < car + 34) && (car4 + 100 > car + 0))
    {
        start = 0;
        gv = 1;
    }

    glColor3f(0.5, 0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex5 + 26, car5 + 100);
    glVertex2f(lrIndex5 + 26, car5 + 86);
    glVertex2f(lrIndex5 + 34, car5 + 86);
    glVertex2f(lrIndex5 + 34, car5 + 100);
    // car5--;
    if (car5 < -120)
    {
        if (lrIndex5 == 0)
        {
            lrIndex5 = 0;
        }
        else if (lrIndex5 == 40)
        {
            lrIndex5 = 20;
        }
        else if (lrIndex5 == 10)
        {
            lrIndex5 = 40;
        }
        else if (lrIndex5 == 20)
        {
            lrIndex5 = 10;
        }
        else
        {
            lrIndex5 = 30;
        }
        car5 = 0;
        score++;
    }
    if ((abs(lrIndex - lrIndex5) < 8) && (car5 + 100 < car + 34) && (car5 + 100 > car + 0))
    {
        start = 0;
        gv = 1;
    }
    glEnd();
}
void startGame()
{
    // Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_QUADS);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    glColor3f(0.94, 0.94, 0.94);
    glBegin(GL_QUADS);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();
    glColor3f(0.94, 0.94, 0.94);
    glBegin(GL_QUADS);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(60, roadTop + 170);
    glVertex2f(60, roadTop + 100);
    glVertex2f(62, roadTop + 100);
    glVertex2f(62, roadTop + 170);
    glEnd();
    roadTop--;
    if (roadTop < -170)
    {
        roadTop = 10;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(60, roadMdl + 90);
    glVertex2f(60, roadMdl + 50);
    glVertex2f(62, roadMdl + 50);
    glVertex2f(62, roadMdl + 90);
    glEnd();
    roadMdl--;
    if (roadMdl < -90)
    {
        roadMdl = 50;
    }
    // Left
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(38, roadLMdl + 50);
    glVertex2f(38, roadLMdl + 100);
    glVertex2f(40, roadLMdl + 100);
    glVertex2f(40, roadLMdl + 50);
    glEnd();
    roadLMdl--;
    if (roadLMdl < -100)
    {
        roadLMdl = 100;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(38, roadLBtm + 10);
    glVertex2f(38, roadLBtm + 40);
    glVertex2f(40, roadLBtm + 40);
    glVertex2f(40, roadLBtm + 10);
    glEnd();
    roadLBtm--;
    if (roadLBtm < -40)
    {
        roadLBtm = 100;
    }
    // Score Board
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(80, 80);
    glVertex2f(100, 80);
    glVertex2f(100, 98);
    glVertex2f(80, 98);
    glEnd();
    char buffer[50];
    sprintf(buffer, "SCORE: %d", score);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95, (void *)GLUT_BITMAP_HELVETICA_18, buffer);
    // Speed Print
    char buffer1[50];
    sprintf(buffer1, "SPEED: %dKm/h", FPS - 40);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95 - 2.5, (void *)GLUT_BITMAP_HELVETICA_18, buffer1);
    // level Print
    if (score % 2 == 0)
    {
        int last = score / 20;
        if (last != level)
        {
            level = score / 20;
            FPS = FPS + 5;
        }
    }
    char level_buffer[50];
    sprintf(level_buffer, "LEVEL: %d", level);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95 - 5, (void *)GLUT_BITMAP_HELVETICA_18, level_buffer);
    glEnd();

    // MAIN car
    // glBegin(GL_QUADS);
    // glVertex2f(lrIndex + 26, car + 3);
    // glVertex2f(lrIndex + 26, car + 17);
    // glVertex2f(lrIndex + 34, car + 17);
    // glVertex2f(lrIndex + 34, car + 3);
    // glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.0, 0.2);
    glVertex2f(lrIndex + 24.5, car + 13.5);
    glVertex2f(lrIndex + 24.5, car + 8);
    glVertex2f(lrIndex + 24, car + 7.5);
    glVertex2f(lrIndex + 24, car + 5);
    glVertex2f(lrIndex + 26, car + 2);
    glVertex2f(lrIndex + 30, car + 2);
    glVertex2f(lrIndex + 32, car + 5);
    glVertex2f(lrIndex + 32, car + 7.5);
    glVertex2f(lrIndex + 31.5, car + 8);
    glColor3f(0.7, 0.0, 0.0);
    glVertex2f(lrIndex + 31.5, car + 13.5);
    glVertex2f(lrIndex + 32, car + 14);
    glVertex2f(lrIndex + 32, car + 17);

    for (int i = 90; i <= 270; i++)
    {
        double th = i * 3.14 / 360;
        glVertex2f(lrIndex + 28 + 4 * cos(th), car + 16.5 + 4.5 * sin(th));
    }
    glVertex2f(lrIndex + 24, car + 17);
    glVertex2f(lrIndex + 24, car + 14);
    glVertex2f(lrIndex + 24.5, car + 13.5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 0.5);
    glVertex2f(lrIndex + 24.5, car + 13.5);
    glVertex2f(lrIndex + 24.5, car + 8);
    glVertex2f(lrIndex + 24, car + 7.5);
    glVertex2f(lrIndex + 24, car + 5);
    glVertex2f(lrIndex + 26, car + 2);
    glVertex2f(lrIndex + 30, car + 2);
    glVertex2f(lrIndex + 32, car + 5);
    glVertex2f(lrIndex + 32, car + 7.5);
    glVertex2f(lrIndex + 31.5, car + 8);
    glVertex2f(lrIndex + 31.5, car + 13.5);
    glVertex2f(lrIndex + 32, car + 14);
    glVertex2f(lrIndex + 32, car + 17);
    for (int i = 90; i <= 270; i++)
    {
        double th = i * 3.14 / 360;
        glVertex2f(lrIndex + 28 + 4 * cos(th), car + 16.5 + 4.5 * sin(th));
    }
    glVertex2f(lrIndex + 24, car + 17);
    glVertex2f(lrIndex + 24, car + 14);
    glVertex2f(lrIndex + 24.5, car + 13.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    for (int i = 90; i <= 270; i++)
    {
        double th = i * 3.14 / 360;
        glVertex2f(lrIndex + 28 + 4.5 * cos(th), car + 15.5 + 4 * sin(th));
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(lrIndex + 31.2, car + 7);
    glVertex2f(lrIndex + 31.2, car + 5.7);
    glVertex2f(lrIndex + 24.8, car + 5.7);
    glVertex2f(lrIndex + 24.8, car + 7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 3.2 * cos(th), car + 5.7 + 3 * sin(th));
    }
    glEnd();

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.4);
    glVertex2f(lrIndex + 25.6, car + 7.5);
    glVertex2f(lrIndex + 25.6, car + 5);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 2.4 * cos(th), car + 5 + 1.5 * sin(th));
    }
    glVertex2f(lrIndex + 30.4, car + 7.5);
    glVertex2f(lrIndex + 30.4, car + 5);
    for (int i = 180; i <= 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 2.4 * cos(th), car + 7.5 + 0.5 * sin(th));
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(lrIndex + 25.6, car + 7.5);
    glVertex2f(lrIndex + 25.4, car + 12);
    glVertex2f(lrIndex + 30.4, car + 7.5);
    glVertex2f(lrIndex + 30.6, car + 12);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 2.4 * cos(th), car + 12 + 1 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.4);
    glVertex2f(lrIndex + 25.4, car + 12);
    glVertex2f(lrIndex + 25, car + 15);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 2.4 * cos(th), car + 12 + 1 * sin(th));
    }
    glVertex2f(lrIndex + 30.6, car + 12);
    glVertex2f(lrIndex + 31, car + 15);
    for (int i = 0; i <= 180; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(lrIndex + 28 + 3 * cos(th), car + 15 + 3 * sin(th));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex + 24, car + 14);
    glVertex2f(lrIndex + 24.5, car + 13.5);
    glVertex2f(lrIndex + 23.9, car + 12.7);
    glVertex2f(lrIndex + 23.3, car + 12.7);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(lrIndex + 32, car + 14);
    glVertex2f(lrIndex + 31.5, car + 13.5);
    glVertex2f(lrIndex + 32.1, car + 12.7);
    glVertex2f(lrIndex + 32.7, car + 12.7);
    glEnd();
    opponentCar();
}
void fristDesign()
{
    if (gv == 0)
    {
        glColor3f(1.0, 1.0, 0.0);
        renderBitmapString(20, 73, (void *)GLUT_BITMAP_HELVETICA_18, "************************************************************");
        glColor3f(1.0, 1.0, 0.0);
        renderBitmapString(35, 70, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Bright Project");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(20, 67, (void *)GLUT_BITMAP_HELVETICA_18, "_________________________________________");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(30, 62, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "COMPUTER GRAPHICS");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(35, 57, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT");
        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(32, 52, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "2D");
        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(37, 52, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Car Game");
        glColor3f(0.200, 1.000, 0.900);
        renderBitmapString(30, 47, (void *)GLUT_BITMAP_HELVETICA_18, "SPACE BUTTON TO START");
        renderBitmapString(30, 42, (void *)GLUT_BITMAP_HELVETICA_18, "ESC BUTTON TO EXIT");
    }
    else if (gv == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(25, 75, (void *)GLUT_BITMAP_HELVETICA_18, "**********************************************************");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(40, 72, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (start == 1)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        startGame();
    }
    else
    {
        fristDesign();
    }
    glFlush();
    glutSwapBuffers();
}
void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        // FPS = FPS - 20;
        if (car >= 2)
        {
            car = car - (FPS / 20);
        }
        break;
    case GLUT_KEY_UP:
        // FPS = FPS + 20;
        if (car <= 78)
        {
            car = car + (FPS / 20);
        }
        break;
    case GLUT_KEY_LEFT:
        if (lrIndex >= 2)
        {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 2)
            {
                lrIndex = 2;
            }
        }
        break;
    case GLUT_KEY_RIGHT:
        if (lrIndex <= 42)
        {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 42)
            {
                lrIndex = 42;
            }
        }
        break;
    default:
        break;
    }
}
void processKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        if (start == 0)
        {
            start = 1;
            gv = 1;
            car = 0;
            lrIndex = 2;
            car1 = -30;
            lrIndex1 = 2;
            car2 = -30;
            lrIndex2 = 40;
            car3 = -30;
            lrIndex3 = 20;
            car4 = -30;
            lrIndex4 = 30;
            car5 = 30;
            lrIndex5 = 10;
            score = 0;
            level = 0;
            FPS = 50;
        }
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 50, timer, 0);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700, 650);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("2D CAR GAME");
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);
    gluOrtho2D(0, 100, 0, 100);
    glClearColor(0.184, 0.310, 0.310, 1);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}