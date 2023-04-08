#include <GL/glut.h>
#include <math.h>

void Stadium(void)
{
    glClearColor(0, 0, 0.5, 0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 0, 0, 0);

    glLineWidth(2);
    // It create 5 lines (Lines)
    glBegin(GL_POLYGON);
    glColor3f(0, 0.54, 0);
    glVertex2f(0.9, -0.9);
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glEnd();

    glColor3f(1, 1, 1);
    glPointSize(5);
    // 3 Points penality and center 
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glVertex2f(-0.65, 0);
    glVertex2f(0.65, 0);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    // 2 Touch Lines
    glVertex2f(0.9, -0.9);
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    // 2 Goal Lines
    glVertex2f(-0.9, -0.9);
    glVertex2f(-0.9, 0.9);
    glVertex2f(0.9, 0.9);
    glVertex2f(0.9, -0.9);
    // 1 Halfway Line
    glVertex2f(0, 0.9);
    glVertex2f(0, -0.9);

    // penality Area Line
    glBegin(GL_LINES);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.6, 0.5);
    glVertex2f(0.6, -0.5);
    glVertex2f(0.6, -0.5);
    glVertex2f(0.9, -0.5);

    // Goal Area Line
    glBegin(GL_LINES);
    glVertex2f(0.9, 0.28);
    glVertex2f(0.7, 0.28);
    glVertex2f(0.7, 0.28);
    glVertex2f(0.7, -0.28);
    glVertex2f(0.7, -0.28);
    glVertex2f(0.9, -0.28);

    // Right Goal Net
    glBegin(GL_LINES);
    glVertex2f(0.9, 0.28);
    glVertex2f(0.98, 0.28);
    glVertex2f(0.98, 0.28);
    glVertex2f(0.98, -0.28);
    glVertex2f(0.98, -0.28);
    glVertex2f(0.9, -0.28);
    glBegin(GL_LINES);
    glVertex2f(0.91, 0.28);
    glVertex2f(0.91, -0.28);
    glVertex2f(0.92, 0.28);
    glVertex2f(0.92, -0.28);
    glVertex2f(0.93, 0.28);
    glVertex2f(0.93, -0.28);
    glVertex2f(0.94, 0.28);
    glVertex2f(0.94, -0.28);
    glVertex2f(0.95, 0.28);
    glVertex2f(0.95, -0.28);
    glVertex2f(0.96, 0.28);
    glVertex2f(0.96, -0.28);
    glVertex2f(0.97, 0.28);
    glVertex2f(0.97, -0.28);
    glVertex2f(0.9, 0.26);
    glVertex2f(0.98, 0.26);
    glVertex2f(0.9, 0.24);
    glVertex2f(0.98, 0.24);
    glVertex2f(0.9, 0.22);
    glVertex2f(0.98, 0.22);
    glVertex2f(0.9, 0.20);
    glVertex2f(0.98, 0.20);
    glVertex2f(0.9, 0.18);
    glVertex2f(0.98, 0.18);
    glVertex2f(0.9, 0.16);
    glVertex2f(0.98, 0.16);
    glVertex2f(0.9, 0.14);
    glVertex2f(0.98, 0.14);
    glVertex2f(0.9, 0.12);
    glVertex2f(0.98, 0.12);
    glVertex2f(0.9, 0.10);
    glVertex2f(0.98, 0.10);
    glVertex2f(0.9, 0.08);
    glVertex2f(0.98, 0.08);
    glVertex2f(0.9, 0.06);
    glVertex2f(0.98, 0.06);
    glVertex2f(0.9, 0.04);
    glVertex2f(0.98, 0.04);
    glVertex2f(0.9, 0.02);
    glVertex2f(0.98, 0.02);
    //     
    glVertex2f(0.9, 0);
    glVertex2f(0.98, 0);
    glVertex2f(0.9, -0.26);
    glVertex2f(0.98, -0.26);
    glVertex2f(0.9, -0.24);
    glVertex2f(0.98, -0.24);
    glVertex2f(0.9, -0.22);
    glVertex2f(0.98, -0.22);
    glVertex2f(0.9, -0.20);
    glVertex2f(0.98, -0.20);
    glVertex2f(0.9, -0.18);
    glVertex2f(0.98, -0.18);
    glVertex2f(0.9, -0.16);
    glVertex2f(0.98, -0.16);
    glVertex2f(0.9, -0.14);
    glVertex2f(0.98, -0.14);
    glVertex2f(0.9, -0.12);
    glVertex2f(0.98, -0.12);
    glVertex2f(0.9, -0.10);
    glVertex2f(0.98, -0.10);
    glVertex2f(0.9, -0.08);
    glVertex2f(0.98, -0.08);
    glVertex2f(0.9, -0.06);
    glVertex2f(0.98, -0.06);
    glVertex2f(0.9, -0.04);
    glVertex2f(0.98, -0.04);
    glVertex2f(0.9, -0.02);
    glVertex2f(0.98, -0.02);
    
    // Left Goal Net
    glBegin(GL_LINES);
    glVertex2f(-0.9, 0.28);
    glVertex2f(-0.98, 0.28);
    glVertex2f(-0.98, 0.28);
    glVertex2f(-0.98, -0.28);
    glVertex2f(-0.98, -0.28);
    glVertex2f(-0.9, -0.28);
    glBegin(GL_LINES);
    glVertex2f(-0.91, 0.28);
    glVertex2f(-0.91, -0.28);
    glVertex2f(-0.92, 0.28);
    glVertex2f(-0.92, -0.28);
    glVertex2f(-0.93, 0.28);
    glVertex2f(-0.93, -0.28);
    glVertex2f(-0.94, 0.28);
    glVertex2f(-0.94, -0.28);
    glVertex2f(-0.95, 0.28);
    glVertex2f(-0.95, -0.28);
    glVertex2f(-0.96, 0.28);
    glVertex2f(-0.96, -0.28);
    glVertex2f(-0.97, 0.28);
    glVertex2f(-0.97, -0.28);
    glVertex2f(-0.9, 0.26);
    glVertex2f(-0.98, 0.26);
    glVertex2f(-0.9, 0.24);
    glVertex2f(-0.98, 0.24);
    glVertex2f(-0.9, 0.22);
    glVertex2f(-0.98, 0.22);
    glVertex2f(-0.9, 0.20);
    glVertex2f(-0.98, 0.20);
    glVertex2f(-0.9, 0.18);
    glVertex2f(-0.98, 0.18);
    glVertex2f(-0.9, 0.16);
    glVertex2f(-0.98, 0.16);
    glVertex2f(-0.9, 0.14);
    glVertex2f(-0.98, 0.14);
    glVertex2f(-0.9, 0.12);
    glVertex2f(-0.98, 0.12);
    glVertex2f(-0.9, 0.10);
    glVertex2f(-0.98, 0.10);
    glVertex2f(-0.9, 0.08);
    glVertex2f(-0.98, 0.08);
    glVertex2f(-0.9, 0.06);
    glVertex2f(-0.98, 0.06);
    glVertex2f(-0.9, 0.04);
    glVertex2f(-0.98, 0.04);
    glVertex2f(-0.9, 0.02);
    glVertex2f(-0.98, 0.02);
    // 
    glVertex2f(-0.9, 0);
    glVertex2f(-0.98, 0);
    glVertex2f(-0.9, -0.26);
    glVertex2f(-0.98, -0.26);
    glVertex2f(-0.9, -0.24);
    glVertex2f(-0.98, -0.24);
    glVertex2f(-0.9, -0.22);
    glVertex2f(-0.98, -0.22);
    glVertex2f(-0.9, -0.20);
    glVertex2f(-0.98, -0.20);
    glVertex2f(-0.9, -0.18);
    glVertex2f(-0.98, -0.18);
    glVertex2f(-0.9, -0.16);
    glVertex2f(-0.98, -0.16);
    glVertex2f(-0.9, -0.14);
    glVertex2f(-0.98, -0.14);
    glVertex2f(-0.9, -0.12);
    glVertex2f(-0.98, -0.12);
    glVertex2f(-0.9, -0.10);
    glVertex2f(-0.98, -0.10);
    glVertex2f(-0.9, -0.08);
    glVertex2f(-0.98, -0.08);
    glVertex2f(-0.9, -0.06);
    glVertex2f(-0.98, -0.06);
    glVertex2f(-0.9, -0.04);
    glVertex2f(-0.98, -0.04);
    glVertex2f(-0.9, -0.02);
    glVertex2f(-0.98, -0.02);

    // penality Area Line
    glBegin(GL_LINES);
    glVertex2f(-0.9, 0.5);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.6, -0.5);
    glVertex2f(-0.6, -0.5);
    glVertex2f(-0.9, -0.5);

    // Goal Area Line
    glBegin(GL_LINES);
    glVertex2f(-0.9, 0.28);
    glVertex2f(-0.7, 0.28);
    glVertex2f(-0.7, 0.28);
    glVertex2f(-0.7, -0.28);
    glVertex2f(-0.7, -0.28);
    glVertex2f(-0.9, -0.28);

    // Corner
    glBegin(GL_LINE_LOOP);
    for (int i = -270; i >= -315; i--)
    {
        double th = i * M_PI / -90;
        glVertex2f(0.9 + 0.04 *  cos(th), 0.9 + 0.06 * sin(th));
    }
    for (int j = -315; j >= -360; j--)
    {
        double th = j * M_PI / -90;
        glVertex2f(-0.9 + 0.04 *  cos(th), 0.9 + 0.06 * sin(th));
    }
    for (int k = 0; k >= -45; k--)
    {
        double th = k * M_PI / -90;
        glVertex2f(-0.9 + 0.04 *  cos(th), -0.9 + 0.06 * sin(th));
    }
    for (int l = -45; l >= -90; l--)
    {
        double th = l * M_PI / -90;
        glVertex2f(0.9 + 0.04 *  cos(th), -0.9 + 0.06 * sin(th));
    }

    // Center Circle
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(0.2 * cos(th), 0.35 * sin(th));
    }

     glBegin(GL_LINE_LOOP);
    for (int i = 90; i < 270; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(0.6 + 0.1 * cos(th), 0 + 0.3 * sin(th));
    }
    glBegin(GL_LINE_LOOP);
    for (int i = 270; i < 450; i++)
    {
        double th = i * 3.14 / 180;
        glVertex2f(-0.6 + 0.1 * cos(th), 0 + 0.3 * sin(th));
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argV)
{
    glutInit(&argc, argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Stadium Project");
    glutDisplayFunc(Stadium);
    glutMainLoop();
    return 0;
}
