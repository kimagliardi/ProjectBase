#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
const float Pi = 3.14159;

class Polygons
{
public:
	Polygons() {}
	~Polygons() {}

	//void DrawCircle(float posX, float posY, float radius, float nPoints);
	void DrawCircleP(float posX, float posY, char form, float r, float g, float b, float rx,float rY);
	void DrawRetangleP();
	void DrawHeptagonP();
	void DrawHegaxonP();
	void DrawTriangleP(float v1[2], float v2[2], float v3[2], float r, float g, float b);
	void DrawQuadP(float v1[2], float v2[2], float v3[2], float v4[2], float r, float g, float b);
	void DrawPizzaP();
	void DrawCaracolP();
	void DrawPacMan();
	void desenho();
	void teste();
};

