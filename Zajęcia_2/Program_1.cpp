﻿//Bartosz Kwiczala
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "math.h"

#define GL_PI 3.1415f

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void RenderScene(void)
{
	GLfloat x, y, z, angle; // Zmienne przechowujące współrzędne i kąty
	GLfloat sizes[2]; // Do zapisania dopuszczalnego zakresu wielkości
	GLfloat step; // Zapamiętuje obsługiwany przyrost rozmiaru
	GLfloat curSize; // Zapamęituje aktualny rozmiar
					 
	glClear(GL_COLOR_BUFFER_BIT);
	// Zapisanie stanu macierzy i wykonanie obrotu
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	// Pobranie dopuszczalnych rozmiarów punktów
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	// Ustalenie początkowego rozmiaru punktu
	curSize = sizes[0];
	// Ustalenie pocztkowej współrzędnej
	z = -50.0f;
	
	for (angle = 0.0f; angle <= (2.0f*3.1415f)*4.0f; angle += 0.1f)
	{
		
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		
		glPointSize(curSize);
		
		glBegin(GL_POINTS);
		glVertex3f(x, y, z);
		glEnd();
		
		z += 0.5f;
		curSize += step;
	}
	
	glPopMatrix();
	
	glutSwapBuffers();
}

void SetupRC()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
}
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;
	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;
	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;
	if (key > 356.0f)
		xRot = 0.0f;
	if (key < -1.0f)
		xRot = 355.0f;
	if (key > 356.0f)
		yRot = 0.0f;
	if (key < -1.0f)
		yRot = 355.0f;
	
	glutPostRedisplay();
}
void ChangeSize(int w, int h)
{

	GLfloat nRange = 100.0f;
	

	if (h == 0)
		h = 1;



	glViewport(0, 0, w, h);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	

	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Korkociag");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	return 0;
}