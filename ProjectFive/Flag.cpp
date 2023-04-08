// #include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
// #include <MMSystem.h>
double Ydir = 0;
GLdouble ya = 6, xa = 5, yca = 2, xca = 1, y1ca = 0.02, x1ca = 1, lax = 0.5, lay = 2;
float yF = 1, xF = 1, wave = 1;
float yf = 1, xf = 1;
float yxf = 1;
float x1f = 1, xL = 1;

void Wave()
{
    if (wave == 1)
    {
        //*******************************RECTANGLE FLAG WAVE*****************************************
        if (ya > -6 && yF == 1)
            ya = ya - 0.05;
        if (ya <= -6 && yF == 1)
            yF = 0;
        if (ya < 6 && yF == 0)
            ya = ya + 0.05;
        if (ya >= 6 && yF == 0)
            yF = 1;

        if (xa > -5 && xF == 1)
            xa = xa - 0.05;
        if (xa <= -5 && xF == 1)
            xF = 0;
        if (xa < 5 && xF == 0)
            xa = xa + 0.05;
        if (xa >= 5 && xF == 0)
            xF = 1;
        //*******************************POLYGON FLAG WAVE*****************************************
        if (yca > -2 && yf == 1)
            yca = yca - 0.02;
        if (yca <= -2 && yf == 1)
            yf = 0;
        if (yca < 2 && yf == 0)
            yca = yca + 0.02;
        if (yca >= 2 && yf == 0)
            yf = 1;

        if (xca > -1 && xf == 1)
            xca = xca - 0.01;
        if (xca <= -1 && xf == 1)
            xf = 0;
        if (xca < 1 && xf == 0)
            xca = xca + 0.01;
        if (xca >= 1 && xf == 0)
            xf = 1;
        //*******************************STAR FLAG WAVE*****************************************
        if (y1ca > -0.02 && yxf == 1)
            y1ca = y1ca - 0.009;
        if (y1ca <= -0.02 && yxf == 1)
            yxf = 0;
        if (y1ca < 0.02 && yxf == 0)
            y1ca = y1ca + 0.009;
        if (y1ca >= 0.02 && yxf == 0)
            yxf = 1;

        if (x1ca > -1 && x1f == 1)
            x1ca = x1ca - 0.01;
        if (x1ca <= -1 && x1f == 1)
            x1f = 0;
        if (x1ca < 1 && x1f == 0)
            x1ca = x1ca + 0.01;
        if (x1ca >= 1 && x1f == 0)
            x1f = 1;
        //*********************LASSO WAVE****************************
        if (lax > -0.5 && xL == 1)
            lax = xa - 0.02;
        if (lax <= -0.5 && xL == 1)
            xL = 0;
        if (lax < 0.5 && xL == 0)
            lax = xa + 0.02;
        if (lax >= 0.5 && xL == 0)
            xL = 1;
    }
    Ydir = Ydir + 0.0068;
    if (Ydir > 65)
        Ydir = Ydir - 0.007;
    glutPostRedisplay();
}
void Flag()
{
    GLdouble x[8], y1[8], y2[8], y3[8], y4[8], xc[4], yc[4], xs[3], xs2[3], ys[3],
        xs3[3], ys1[3], xs4[3], ys2[3], xs5[3], xl[3], yl[3], xl1[3], yl1[3], xl2[3],
        yl2[3], xl3[3], yl3[3], xl4[3], yl4[3], xl5[3], yl5[3], xl6[3], yl6[3], xl7[3],
        yl7[3], xl8[3], yl8[3], xl9[3], yl9[3], xla[8], yla[8];

    GLdouble xt[400], y1t[400], y2t[400], y3t[400], y4t[400], xct[200], yct[200],
        xst[100], yst[100], xst2[100], xst3[100], ys1t[100], xst4[100], ys2t[100],
        xst5[100], xlt[100], ylt[100], xl1t[100], yl1t[100], xl2t[100], yl2t[100],
        xl3t[100], yl3t[100], xl4t[100], yl4t[100], xl5t[100], yl5t[100], xl6t[100],
        yl6t[100], xl7t[100], yl7t[100], xl8t[100], yl8t[100], xl9t[100], yl9t[100], xlat[400], ylat[400], t;
    int i, c;
    //*******************************RECTANGLE FLAG VARIABLES *****************************************
    x[0] = 46;
    x[1] = 53.5 + xa;
    x[2] = 53.5 + xa;
    x[3] = 61 + xa;
    x[4] = 61 + xa;
    x[5] = 68.5 + xa;
    x[6] = 68.5 + xa;
    x[7] = 76 - xa;
    y1[0] = 30;
    y1[1] = 30 + ya;
    y1[2] = 30 - ya;
    y1[3] = 30;
    y1[4] = 30;
    y1[5] = 30 + ya;
    y1[6] = 30 - ya;
    y1[7] = 30;
    y2[0] = 25;
    y2[1] = 25 + ya;
    y2[2] = 25 - ya;
    y2[3] = 25;
    y2[4] = 25;
    y2[5] = 25 + ya;
    y2[6] = 25 - ya;
    y2[7] = 25;
    y3[0] = 20;
    y3[1] = 20 + ya;
    y3[2] = 20 - ya;
    y3[3] = 20;
    y3[4] = 20;
    y3[5] = 20 + ya;
    y3[6] = 20 - ya;
    y3[7] = 20;
    y4[0] = 15;
    y4[1] = 15 + ya;
    y4[2] = 15 - ya;
    y4[3] = 15;
    y4[4] = 15;
    y4[5] = 15 + ya;
    y4[6] = 15 - ya;
    y4[7] = 15;
    //*********************************POLYGON VARIABLES ************************************************
    xc[0] = 61 + xca;
    xc[1] = 61 + xca;
    xc[2] = 61 + xca;
    xc[3] = 61 + xca;
    yc[0] = 22.5;
    yc[1] = 22.5 + yca;
    yc[2] = 22.5 - yca;
    yc[3] = 22.5;
    //**********************************STAR VARIABLES ***************************************************
    xs[0] = 58.25 + x1ca;
    xs[1] = 58.25 + x1ca;
    xs2[0] = 63.5 + x1ca;
    xs2[1] = 63.5 + x1ca;
    ys[0] = 23.6 + y1ca;
    ys[1] = 23.6 + y1ca;
    xs3[0] = 59.05 + x1ca;
    xs3[1] = 59.05 + x1ca;
    ys1[0] = 19.7 + y1ca;
    ys1[1] = 19.7 + y1ca;
    xs4[0] = 61.05 + x1ca;
    xs4[1] = 61.05 + x1ca;
    ys2[0] = 25.7 + y1ca;
    ys2[1] = 25.7 + y1ca;
    xs5[0] = 62.75 + x1ca;
    xs5[1] = 62.75 + x1ca;
    //**********************************RIFLECTION VARIABLE ******************************************************
    xl[0] = 62.25 + x1ca;
    xl[1] = 62.25 + x1ca;
    yl[0] = 24.3 + y1ca;
    yl[1] = 24.3 + y1ca;
    xl1[0] = 63.25 + x1ca;
    xl1[1] = 63.25 + x1ca;
    yl1[0] = 25.3 + y1ca;
    yl1[1] = 25.3 + y1ca;
    xl2[0] = 59.75 + x1ca;
    xl2[1] = 59.75 + x1ca;
    // yl2[0]= 24.3;    yl2[1]= 24.3;same as yl
    xl3[0] = 58.75 + x1ca;
    xl3[1] = 58.75 + x1ca;
    // yl3[0]= 25.3;    yl3[1]= 25.3;same as yl1
    xl4[0] = 62.75 + x1ca;
    xl4[1] = 62.75 + x1ca;
    yl4[0] = 22 + y1ca;
    yl4[1] = 22 + y1ca;
    xl5[0] = 63.75 + x1ca;
    xl5[1] = 63.75 + x1ca;
    yl5[0] = 21.4 + y1ca;
    yl5[1] = 21.4 + y1ca;
    xl6[0] = 60.95 + x1ca;
    xl6[1] = 60.95 + x1ca;
    yl6[0] = 20.5 + y1ca;
    yl6[1] = 20.5 + y1ca;
    // xl7[0] =  60.95;  xl7[1] =  60.95; same as xl6
    yl7[0] = 19.2 + y1ca;
    yl7[1] = 19.2 + y1ca;
    xl8[0] = 59.25 + x1ca;
    xl8[1] = 59.25 + x1ca;
    // yl8[0]= 22;    yl8[1]= 22; same as yl4
    xl9[0] = 58.25 + x1ca;
    xl9[1] = 58.25 + x1ca;
    // yl9[0]= 21.4;    yl9[1]= 21.4; same as yl5
    //**********************************LASSO**************************
    xla[0] = 45.4 + lax;
    xla[1] = 45.4 - lax;
    xla[2] = 45.4 + lax;
    xla[3] = 45.4 - lax;
    xla[4] = 45.4 + lax;
    xla[5] = 45.4 - lax;
    xla[6] = 45.4;
    xla[7] = 45.4;
    yla[0] = 8;
    yla[1] = 10;
    yla[2] = 20;
    yla[3] = 30;
    yla[4] = 60;
    yla[5] = 70;
    yla[6] = 85;
    yla[7] = 97;

    for (i = 0, t = 0, c = 0; t < 1; i++, t = t + 0.01)
    {
        //*******************************RECTANGLE FLAG*****************************************
        xt[i] = pow(1 - t, 7) * x[0] + 7 * t * pow(1 - t, 6) * x[1] + 21 * pow(t, 2) * pow(1 - t, 5) * x[2] + 35 * pow(t, 3) * pow(1 - t, 4) * x[3] + 35 * pow(t, 4) * pow(1 - t, 3) * x[4] + 21 * pow(t, 5) * pow(1 - t, 2) * x[5] + 7 * pow(t, 6) * (1 - t) * x[6] + pow(t, 7) * x[7];
        y1t[i] = pow(1 - t, 7) * y1[0] + 7 * t * pow(1 - t, 6) * y1[1] + 21 * pow(t, 2) * pow(1 - t, 5) * y1[2] + 35 * pow(t, 3) * pow(1 - t, 4) * y1[3] + 35 * pow(t, 4) * pow(1 - t, 3) * y1[4] + 21 * pow(t, 5) * pow(1 - t, 2) * y1[5] + 7 * pow(t, 6) * (1 - t) * y1[6] + pow(t, 7) * y1[7];
        y2t[i] = pow(1 - t, 7) * y2[0] + 7 * t * pow(1 - t, 6) * y2[1] + 21 * pow(t, 2) * pow(1 - t, 5) * y2[2] + 35 * pow(t, 3) * pow(1 - t, 4) * y2[3] + 35 * pow(t, 4) * pow(1 - t, 3) * y2[4] + 21 * pow(t, 5) * pow(1 - t, 2) * y2[5] + 7 * pow(t, 6) * (1 - t) * y2[6] + pow(t, 7) * y2[7];
        y3t[i] = pow(1 - t, 7) * y3[0] + 7 * t * pow(1 - t, 6) * y3[1] + 21 * pow(t, 2) * pow(1 - t, 5) * y3[2] + 35 * pow(t, 3) * pow(1 - t, 4) * y3[3] + 35 * pow(t, 4) * pow(1 - t, 3) * y3[4] + 21 * pow(t, 5) * pow(1 - t, 2) * y3[5] + 7 * pow(t, 6) * (1 - t) * y3[6] + pow(t, 7) * y3[7];
        y4t[i] = pow(1 - t, 7) * y4[0] + 7 * t * pow(1 - t, 6) * y4[1] + 21 * pow(t, 2) * pow(1 - t, 5) * y4[2] + 35 * pow(t, 3) * pow(1 - t, 4) * y4[3] + 35 * pow(t, 4) * pow(1 - t, 3) * y4[4] + 21 * pow(t, 5) * pow(1 - t, 2) * y4[5] + 7 * pow(t, 6) * (1 - t) * y4[6] + pow(t, 7) * y4[7];

        //*********************************POLYGON************************************************
        xct[i] = pow(1 - t, 3) * xc[0] + 3 * t * pow(1 - t, 2) * xc[1] + 3 * pow(t, 2) * (1 - t) * xc[2] + pow(t, 3) * xc[3];
        yct[i] = pow(1 - t, 3) * yc[0] + 3 * t * pow(1 - t, 2) * yc[1] + 3 * pow(t, 2) * (1 - t) * yc[2] + pow(t, 3) * yc[3];
        //**********************************STAR***************************************************
        xst[i] = (1 - t) * xs[0] + t * xs[1];
        yst[i] = (1 - t) * ys[0] + t * ys[1];
        xst2[i] = (1 - t) * xs2[0] + t * xs2[1];
        xst3[i] = (1 - t) * xs3[0] + t * xs3[1];
        ys1t[i] = (1 - t) * ys1[0] + t * ys1[1];
        xst4[i] = (1 - t) * xs4[0] + t * xs4[1];
        ys2t[i] = (1 - t) * ys2[0] + t * ys2[1];
        xst5[i] = (1 - t) * xs5[0] + t * xs5[1];
        //**********************************RIFLECTION******************************************************
        xlt[i] = (1 - t) * xl[0] + t * xl[1];
        ylt[i] = (1 - t) * yl[0] + t * yl[1];
        xl1t[i] = (1 - t) * xl1[0] + t * xl1[1];
        yl1t[i] = (1 - t) * yl1[0] + t * yl1[1];
        xl2t[i] = (1 - t) * xl2[0] + t * xl2[1];
        // yl2t[i] = (1-t)*yl2[0]+t*yl2[1]; same as y1t
        xl3t[i] = (1 - t) * xl3[0] + t * xl3[1];
        // yl3t[i] = (1-t)*yl3[0]+t*yl3[1]; same as y11t
        xl4t[i] = (1 - t) * xl4[0] + t * xl4[1];
        yl4t[i] = (1 - t) * yl4[0] + t * yl4[1];
        xl5t[i] = (1 - t) * xl5[0] + t * xl5[1];
        yl5t[i] = (1 - t) * yl5[0] + t * yl5[1];
        xl6t[i] = (1 - t) * xl6[0] + t * xl6[1];
        yl6t[i] = (1 - t) * yl6[0] + t * yl6[1];
        // xl7t[i] = (1-t)*xl7[0]+t*xl7[1]; same as xl6t
        yl7t[i] = (1 - t) * yl7[0] + t * yl7[1];
        xl8t[i] = (1 - t) * xl8[0] + t * xl8[1];
        // yl8t[i] = (1-t)*yl8[0]+t*yl8[1]; same as y14t
        xl9t[i] = (1 - t) * xl9[0] + t * xl9[1];
        // yl9t[i] = (1-t)*yl9[0]+t*yl9[1];  same as xl5t
        //***********************************************************************
        xlat[i] = pow(1 - t, 7) * xla[0] + 7 * t * pow(1 - t, 6) * xla[1] + 21 * pow(t, 2) * pow(1 - t, 5) * xla[2] + 35 * pow(t, 3) * pow(1 - t, 4) * xla[3] + 35 * pow(t, 4) * pow(1 - t, 3) * xla[4] + 21 * pow(t, 5) * pow(1 - t, 2) * xla[5] + 7 * pow(t, 6) * (1 - t) * xla[6] + pow(t, 7) * xla[7];
        ylat[i] = pow(1 - t, 7) * yla[0] + 7 * t * pow(1 - t, 6) * yla[1] + 21 * pow(t, 2) * pow(1 - t, 5) * yla[2] + 35 * pow(t, 3) * pow(1 - t, 4) * yla[3] + 35 * pow(t, 4) * pow(1 - t, 3) * yla[4] + 21 * pow(t, 5) * pow(1 - t, 2) * yla[5] + 7 * pow(t, 6) * (1 - t) * yla[6] + pow(t, 7) * yla[7];
        c++;
    }
    //************************************GREEN****************************************************
    glColor3f(0.08, 0.4, 0.16);
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < c; i++)
    {
        glVertex2d(xt[i], Ydir + y1t[i]);
        glVertex2d(xt[i], Ydir + y2t[i]);
    }
    glEnd();
    //************************************YELLOW***************************************************
    glColor3f(0.95, 0.78, 0.20);
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < c; i++)
    {
        glVertex2d(xt[i], Ydir + y2t[i]);
        glVertex2d(xt[i], Ydir + y3t[i]);
    }
    glEnd();
    //************************************RED***************************************************
    glColor3f(0.89, 0.18, 0.09);
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < c; i++)
    {
        glVertex2d(xt[i], Ydir + y3t[i]);
        glVertex2d(xt[i], Ydir + y4t[i]);
    }
    glEnd();
    //*************************************POLYGON*************************************************
    glColor3f(0.07, 0.10, 0.4);
    glBegin(GL_POLYGON);
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < 360; i++)
        {
            float b;
            b = i * 3.142 / 180;
            glVertex2f(xct[j] + 4 * cos(b), Ydir + yct[j] + 4 * sin(b));
        }
    }
    glEnd();
    //***************************************STAR***************************************************
    glColor3f(0.95, 0.78, 0.20);
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < c; i++)
    {
        glVertex2f(xst[i], Ydir + yst[i]);
        glVertex2f(xst2[i], Ydir + yst[i]);
        glVertex2f(xst3[i], Ydir + ys1t[i]);
        glVertex2f(xst4[i], Ydir + ys2t[i]);
        glVertex2f(xst5[i], Ydir + ys1t[i]);
    }
    glEnd();
    //*************************************LINE*******************************************************
    glColor3f(0.95, 0.78, 0.20);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    for (int i = 0; i < c; i++)
    {
        glVertex2f(xlt[i], Ydir + ylt[i]);
        glVertex2f(xl1t[i], Ydir + yl1t[i]);
        glVertex2f(xl2t[i], Ydir + ylt[i]);
        glVertex2f(xl3t[i], Ydir + yl1t[i]);
        glVertex2f(xl4t[i], Ydir + yl4t[i]);
        glVertex2f(xl5t[i], Ydir + yl5t[i]);
        glVertex2f(xl6t[i], Ydir + yl6t[i]);
        glVertex2f(xl6t[i], Ydir + yl7t[i]);
        glVertex2f(xl8t[i], Ydir + yl4t[i]);
        glVertex2f(xl9t[i], Ydir + yl5t[i]);
    }
    glEnd();
    glColor3f(0.07, 0.10, 0.4);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < c; i++)
    {
        glVertex2f(xlat[i], ylat[i]);
    }
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 28);
    glVertex2f(46, Ydir + 30);
    glVertex2f(45, Ydir + 30);
    glVertex2f(45, Ydir + 28);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 18);
    glVertex2f(46, Ydir + 21);
    glVertex2f(45, Ydir + 21);
    glVertex2f(45, Ydir + 18);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 24);
    glVertex2f(46, Ydir + 26);
    glVertex2f(45, Ydir + 26);
    glVertex2f(45, Ydir + 24);
    glEnd();
    glColor3f(0.07, 0.10, 0.4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(45.5, 7);
    glVertex2f(45.5, 96);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 15);
    glVertex2f(46, Ydir + 18);
    glVertex2f(45, Ydir + 18);
    glVertex2f(45, Ydir + 15);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 21);
    glVertex2f(46, Ydir + 24);
    glVertex2f(45, Ydir + 24);
    glVertex2f(45, Ydir + 21);
    glEnd();
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(46, Ydir + 26);
    glVertex2f(46, Ydir + 28);
    glVertex2f(45, Ydir + 28);
    glVertex2f(45, Ydir + 26);
    glEnd();

    glFlush();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //***************************************STICK********************************************
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(44.0, 5.0);
    glVertex2f(44.5, 5.0);
    glVertex2f(44.5, 97.0);
    glVertex2f(44.0, 97.0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(44.0, 96.3);
    glVertex2f(44.0, 96.0);
    glVertex2f(45.2, 96.0);
    glVertex2f(45.2, 96.3);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 360; i++)
    {
        float b = i * 3.142 / 180;
        glVertex2f(45.5 + 0.5 * cos(b), 96 + 0.5 * sin(b));
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(43.2, 97);
    glVertex2f(44.25, 99);
    glVertex2f(45.2, 97);
    glEnd();
    //************************************BOTTOM*****************************************
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(31.0, 5.0);
    glVertex2f(50.0, 5.0);
    glVertex2f(50.0, 6.5);
    glVertex2f(31.0, 6.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(31.0, 6.5);
    glVertex2f(50.0, 6.5);
    glVertex2f(57.0, 9.0);
    glVertex2f(39.0, 9.0);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(50.0, 6.5);
    glVertex2f(50.0, 5.0);
    glVertex2f(57.0, 7.5);
    glVertex2f(57.0, 9.0);
    glEnd();
    //************************************LINE************************************
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    glVertex2f(50.0, 5.0);
    glVertex2f(50.0, 6.5);
    glVertex2f(50.0, 6.5);
    glVertex2f(57.0, 9.0);
    glVertex2f(50.0, 6.5);
    glVertex2f(31.0, 6.5);
    glEnd();
    Flag();
    glFlush();
}
void Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 150, 0, 100);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0, 0.607, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argC, char *argV[])
{
    glutInit(&argC, argV);
    glutInitWindowSize(1100, 700);
    glutInitWindowPosition(100, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("*FLAG OF ETHIOPIA*");
    // PlaySound(TEXT("Ethiopia.wav"), NULL, SND_ASYNC);
    Init();
    glutIdleFunc(Wave);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}