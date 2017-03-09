#include "Polygons.h"
#include <iostream>
#include <string>

void Polygons::DrawCircleP(float posX, float posY, char form, float r, float g, float b, float radius){
	glPointSize(15);
	glLineWidth(1);
	glColor3f(r, g, b);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = radius, raioY = radius;
	if (form =='P' || form =='p'){
		glBegin(GL_POLYGON);
	}else if (form == 'L' || form =='l'){
		glBegin(GL_LINE_LOOP);
	}
	for (int i = 0; i < circle_points; i++) {
		angle = 2 * Pi*i / circle_points;
		glVertex2d(posX + (cos(angle)*raioX), +(posY + (sin(angle)*raioY)));
		//glVertex2d(cos(angle)*raioX,+(sin(angle)*raioY));
	}
	glEnd();

}

void Polygons::DrawCaracolP() {
	glPointSize(1);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = 0, raioY = 0;

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circle_points; i++) {
		angle = 10 * Pi*i / circle_points;
		glVertex2d(cos(angle)*(raioX += 0.01), sin(angle)*(raioY += 0.01f));
	}
	glEnd();

}

void Polygons::DrawEllipsesP() {
	glPointSize(15);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	for (float x = 0.0; x <= 1 * Pi; x += 0.03){
		glBegin(GL_POLYGON);
			glVertex2f(sin(x), 1 / 2 * cos(x));
			glVertex2f(sin(x + 0.03), 1 / 2 * cos(x + 0.03));
		glEnd();
	}
}

void Polygons::DrawHeptagonP() {

	glPointSize(15);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 6; ++i) {
		glVertex2d(sin(i / 6.0 * 2 * Pi), cos(i / 6.0 * 2 * Pi));
	}
	glEnd();

}
void Polygons::DrawHegaxonP(){
	glPointSize(15);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);
	float y = 0.5*sqrt(3);
		
		glVertex2d(-0.5, y*(-1));
		glVertex2d(-1, 0);
		glVertex2d(-0.5, y);
		glVertex2d(0.5, y);
		glVertex2d(1, 0);
		glVertex2d(0.5, y*(-1));
	glEnd();
		
}
void Polygons::DrawPacMan() {
	DrawCircleP(0, 0, 'p', 1, 1, 0, 1);
	DrawCircleP(0, 0.5, 'p',0,0,0,0.08);

	glColor3f(1, 1, 1);
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat radius = 1;
	GLfloat x = 0;
	GLfloat y = 0;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = Pi / 4;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();

}



void Polygons::DrawRetangleP() {

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON); //desenho de um retangulo
	glVertex2d(0, 0);
	glVertex2d(0.25, 0);
	glVertex2d(0.25, 0.5);
	glVertex2d(0, 0.5);
	glEnd();
}

void Polygons::DrawTriangleP(float v1[2], float v2[2], float v3[2]) {

	glPointSize(15);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	glBegin(GL_POLYGON); //desenho de um triângulo
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.0, 1.5f);
	glVertex2f(-0.5f, 0.5f);

	glEnd();

}

void Polygons::DrawPizzaP() {

	glColor3f(0, 0, 0);
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat radius = 1;
	GLfloat x = 0;
	GLfloat y = 0;
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = Pi / 4;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();

}






void Polygons::teste() {

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
		glVertex2d(0.25, 0.05);
		glVertex2d(3, 0.05);
		glVertex2d(3, 0);
	glEnd();



	DrawCircleP(1,1,'p', 1, 1, 0, 0.2);

	/*
	glPointSize(15);
	glLineWidth(1);
	glColor3f(1, 1, 1);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = 1, raioY = 1;
	glBegin(GL_POLYGON);
	
for (int i = 0; i < circle_points; i++) {
		angle = 2 * Pi*i / circle_points;
		glVertex2d(2 + (cos(angle)*raioX), (2 + (sin(angle)*raioY)));
	}
	glEnd();
	*/

		

}




