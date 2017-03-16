//Program Wyrosowywuje Piêciok¹t foremny



#include <GL/glut.h>

void drawline(float from_x, float from_y, float to_x, float to_y)
{
	
	glVertex2f(from_x, from_y);

	
	glVertex2f(to_x, to_y);
}

void drawShape()
{
	glColor3f(1.0, 1.0, 1.0); 
	glLineWidth(2.0); 

					  
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.476, 0.155);
	glVertex2f(0.294, -0.405);
	glVertex2f(-0.294, -0.405);
	glVertex2f(-0.476, 0.155);



	glEnd();
}

void render(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 3.2, 0.0, 3.1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glPushMatrix();
	glTranslatef(1.5, 1.5, 0.0);
	drawShape();
	glPopMatrix();



	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(640, 580);
	glutCreateWindow("Zaj_1");
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}