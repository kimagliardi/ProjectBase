#include "Draw.h"


void Draw::Casa() {

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON); //casa
	glVertex2d(0, 0);
	glVertex2d(0.25, 0);
	glVertex2d(0.25, 0.5);
	glVertex2d(0, 0.5);
	glEnd();

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POLYGON);//telhado
	glVertex2d(0, 0.5f);
	glVertex2d(0.125, 1);
	glVertex2d(0.25, 0.5);
	glEnd();

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);//contorno telhado
	glVertex2d(0, 0.5f);
	glVertex2d(0.125, 1);
	glVertex2d(0.25, 0.5);
	glEnd();

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0.8, 0);


	glBegin(GL_QUADS);//gramado
		glVertex2d(0.25, 0);
		glVertex2d(0.25, 0.10);
		glVertex2d(1, 0.10);
		glVertex2d(1, 0);
	glEnd();

}


/*	glPointSize(15);
	glLineWidth(3);
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_POLYGON);//janela casa
	glVertex2d(0, 0.5f);
	glVertex2d(0.125, 1);
	glVertex2d(0.25, 0.5);
	glEnd();
*/