#include "Polygons.h"
#include <iostream>
#include <string>

void Polygons::DrawCircleP(float posX, float posY, char form, float r, float g, float b, float rX, float rY){
	glPointSize(15);
	glLineWidth(1);
	glColor3f(r, g, b);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = rX, raioY = rY;
	if (form =='P' || form =='p'){
		glBegin(GL_POLYGON);
	}else if (form == 'L' || form =='l'){
		glBegin(GL_LINE_LOOP);
	}
	for (int i = 0; i < circle_points; i++) {
		angle = 2 * Pi*i / circle_points;
		glVertex2d(posX + (cos(angle)*raioX), +(posY + (sin(angle)*raioY)));
	}
	glEnd();

}

void Polygons::DrawCaracolP() {
	glPointSize(1);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = 0.3, raioY = 0.3;

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < circle_points; i++) {
		angle = 10 * Pi*i / circle_points;
		glVertex2d(cos(angle)*(raioX += 0.01), sin(angle)*(raioY += 0.01f));
	}
	glEnd();

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

	glBegin(GL_POLYGON);
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
	DrawCircleP(0, 0, 'p', 1, 1, 0, 1,1);
	DrawCircleP(0, 0.5, 'p',0,0,0,0.08, 0.08);

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

void Polygons::DrawTriangleP(float v1[2], float v2[2], float v3[2],float r, float g, float b) {

	glPointSize(15);
	glLineWidth(1);
	glColor3f(r, g, b);

	glBegin(GL_POLYGON); //desenho de um triângulo
		glVertex2f(v1[0], v1[1]);
		glVertex2f(v2[0], v2[1]);
		glVertex2f(v3[0], v3[1]);
	glEnd();

}

void Polygons::DrawQuadP(float v1[2], float v2[2], float v3[2], float v4[2], float r, float g, float b){
	glPointSize(15);
	glLineWidth(1);
	glColor3f(r, g, b);


	glBegin(GL_POLYGON); //desenho de um retangulo
		glVertex2f(v1[0], v1[1]);
		glVertex2f(v2[0], v2[1]);
		glVertex2f(v3[0], v3[1]);
		glVertex2f(v4[0], v4[1]);
	glEnd();
}

void Polygons::DrawPizzaP() {

	glColor3f(0, 0, 0);
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat radius = 1;
	GLfloat x = 0;
	GLfloat y = 0;
	GLfloat twicePi = Pi / 4;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}


void Polygons::desenho() {

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON); //casa
		glVertex2d(0, 0);
		glVertex2d(0.25, 0);
		glVertex2d(0.25, 0.5);
		glVertex2d(0, 0.5);
	glEnd();

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
		glVertex2d(0.125f, 1);
		glVertex2d(0.25f, 0.5f);
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

	DrawCircleP(2,2,'p', 1, 1, 0, 0.3,0.3);
}

void Polygons::teste() {
	float v1[2], v2[2], v3[2];
	v1[0] = 0, v1[1] = 0;
	v2[0] = 0.5f, v2[1] = 0;
	v3[0] = 0.25f, v3[1] = 0.5f;
	
	DrawCircleP(4,4,'p',1,1,0,0.35,0.35);
	
	//base da montanha
	for (int i = 0; i < 12; i++) {
		DrawTriangleP(v1, v2, v3, 0.545, 0.271, 0.075);
		//*criando 
		v1[0] = v2[0], v1[1] = v2[1];
		v2[0] += 0.5f, v2[1] = 0;
		v3[0] += 0.5f, v3[1] = 0.5f;
		

	}

	/*topo
	v1[0] = 0, v1[1] = 0;
	v2[0] = 0.5f, v2[1] = 0;
	v3[0] = 0.25f, v3[1] = 0.5f;
	for (int i = 0; i < 12; i++) {
		DrawTriangleP(v1, v2, v3, 0.545, 0.271, 0.075);
		//*criando 
		v1[0] = v2[0], v1[1] = v2[1];
		v2[0] += 0.5f, v2[1] = 0;
		v3[0] += 0.5f, v3[1] = 0.5f;
	}*/









}



