#include <GL/glut.h>
void CgExample(void)
{
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 0, 0, 0);

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(9, 0);
    glVertex2f(-9, 0);
    glVertex2f(0, 9);
    glVertex2f(0, -9); 

    glEnd();
    glFlush();
}
void mykeyboard(unsigned char key, int x, int y)
{
  GLint z;
  glColor3f(1, 0, 1);
  glLineWidth(2);
  if (key == 'a' || key == 'A')
  {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 0.6);
    glVertex2f(-0.7, 0.3);
    glVertex2f(-0.3, 0.3);
    glEnd();

    glRasterPos2f(-0.6, 0.1);
    for (z = 0; z < 9; z++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "Triangle"[z]);
    glEnd();
    glFlush();
  }
  else if (key == 'b' || key == 'B')
  {
    glBegin(GL_QUADS);
    glVertex2f(0.3, 0.7);
    glVertex2f(0.8, 0.7);
    glVertex2f(0.8, 0.3);
    glVertex2f(0.3, 0.3);
    glEnd();
    glFlush();
  }

  else if (key == 'c' || key == 'C')
  {
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.2);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.6, -0.6);
    glVertex2f(-0.3, -0.6);
    glEnd();
    glFlush();
  }
  else if (key == 'n' || key == 'N')
  {
    glRasterPos2f(-0.9, -0.9);
    for (z = 0; z < 15; z++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "Birhane Gebrial"[z]);
    glEnd();
    glFlush();
  }
}
int main(int argc, char **argV)
{
  glutInit(&argc, argV);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("this is my first program");
  glutDisplayFunc(CgExample);
  glutKeyboardFunc(mykeyboard);
  glutMainLoop();
  return 0;
}
