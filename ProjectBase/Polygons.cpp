#include "Polygons.h"
#include <iostream>
#include <string>


void Polygons::DrawCircle(float posX, float posY, float radius, float nPoints)
{
	float rd = radius;

	float angle = 0.0;
	float slice = 2 * Pi / nPoints;
	float x, y;

	float xi = posX;
	float yi = posY;

	//Habilitar a cor do círculo
	glColor3f(0, 0, 0);

	//Tamanho do ponto
	glPointSize(1);

	//Espessura da linha
	glLineWidth(1);

	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glBegin(GL_TRIANGLE_FAN);
	while (angle <= 2 * Pi)
	{
		/*Sorteia uma cor para o vertice
		float r = rand() % 10 / 10.0;
		float b = rand() % 10 / 10.0;
		float g = rand() % 10 / 10.0;*/

		glColor3f(0, 0, 0);

		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	/*/Para desenhar o contorno
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(0, 0, 0);
	angle = 0.0;
	glBegin(GL_TRIANGLE_FAN);
	while (angle <= 2 * Pi)
	{
	//Calcular posicao do ponto em x, y
	x = xi + rd * cos(angle);
	y = yi + rd * sin(angle);
	glVertex2f(x, y);
	//Atualizar o angulo
	angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	//Para desenhar os pontos
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(1, 1, 1);
	angle = 0.0;
	glBegin(GL_POINTS);
	while (angle <= 2 * Pi)
	{
	//Calcular posicao do ponto em x, y
	x = xi + rd * cos(angle);
	y = yi + rd * sin(angle);
	glVertex2f(x, y);
	//Atualizar o angulo
	angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();*/

}

void Polygons::DrawTriangle()
{
	glPointSize(15);
	glLineWidth(3);

	// Desenha um triângulo no centro da janela
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(-0.5, -0.5);
	glColor3f(0, 1, 0);
	glVertex3f(0.0, 0.5, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

	glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}


void Polygons::DrawCircleP(char form, float r, float g, float b, float radius){
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
		glVertex2d(cos(angle)*raioX, sin(angle)*raioY);
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

void Polygons::DrawTriangleP() {

	glPointSize(15);
	glLineWidth(3);
	glColor3f(0, 0, 0);

	glBegin(GL_TRIANGLES); //desenho de um triângulo
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();

}

void Polygons::DrawPizzaP() {

	glPointSize(15);
	glLineWidth(1);
	glColor3f(0, 0, 0);

	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = 1.0f, raioY = 1.0f;

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < circle_points; i++) {
		angle = (Pi / 4)*i / circle_points;
		glVertex2d(cos(angle)*raioX, sin(angle)*raioY);
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
	for (float x = 0.0; x <= 1 * Pi; x += 0.03)
	{
		glBegin(GL_LINES);
		glVertex2f(sin(x), 1 / 2 * cos(x));
		glVertex2f(sin(x + 0.03), 1 / 2 * cos(x + 0.03));
		glEnd();
	}
}


void Polygons::DrawPacMan() {
	//DrawCircleP('p');
	//DrawCircle(0, 0.5, 0.08, 300);


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


void Polygons::teste() {

}


