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

	void DrawCircle(float posX, float posY, float radius, float nPoints);
	void DrawTriangle();
	void DrawCircleP(char form, float r, float g, float b, float radius);
	void DrawRetangleP();
	void DrawHexagonP();
	void DrawTriangleP();
	void DrawPizzaP();
	void DrawEllipsesP();
	void DrawCaracolP();
	void DrawPacMan();
	void teste();
};

