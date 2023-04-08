#include<GL/glut.h>

void Program(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,0,0,0);


	glPointSize(20);
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(0,0);
	glEnd();
	glFlush();
}
int main(int argc  ,char**argV){
	glutInit(&argc,argV);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("This is My First OpenGl Program");
	glutDisplayFunc(Program);
	glutMainLoop();
	return 0;
}