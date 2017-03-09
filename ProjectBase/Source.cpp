#include <cstdlib>
#include <iostream>
#include "Polygons.h"
//#include "Draw.h"


using namespace std;

bool drawCircle = false; //flag para habilitar o desenho de c�rculos (apenas um exemplo)

Polygons polyg;	
//Draw desenho;
//Callback de erro 
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

//Callback de teclado
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		drawCircle = !drawCircle;
	}
}

// Programa Principal 
int main(void)
{
	srand(time(0));

	//Inicializa��o da janela da aplica��o
	GLFWwindow* window;

	//Setando a callback de erro
	glfwSetErrorCallback(error_callback);

	//Inicializando a lib
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Criando a janela
	window = glfwCreateWindow(800, 600, "HELLO GLFW!! BYE BYE GLUT!!!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Colocando a janela criada como sendo o contexto atual
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	//Setando a callback de teclado
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) //loop da aplica��o :)
	{
		float ratio;
		int width, height;

		//aqui recupera o tamanho atual da janela, para corre��o do aspect ratio mais tarde
		glfwGetFramebufferSize(window, &width, &height);


		//setando a viewport da OpenGL, para ocupar toda a janela da aplica��o
		glViewport(0, 0, width, height);
		
		// Limpa a janela de visualiza��o com a cor branca
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//Setando a matriz de proje��o, para definir o Ortho (c�mera ortogr�fica 2D)
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//Setando a janela do mundo a ser vista (window), a c�mera ortogr�fica 2D
		gluOrtho2D(-3, 3,-3, 3);

		//Trocando para a matriz de modelo
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		if (drawCircle) {
			float r = rand() % 10 / 10.0;
			float b = rand() % 10 / 10.0;
			float g = rand() % 10 / 10.0;
			float radius = rand() % 10 / 10.0;

			polyg.DrawCircleP(1,1,'p', r, g, b, radius);
			system("PAUSE");
		}
		else {
			//inserir comandos para desenhos aqui!
			//polyg.DrawCaracolP();
			//polyg.DrawCircleP(1, 1, 'p', 0, 0, 0, 1);
			polyg.DrawEllipsesP(); //*****Arrumar este m�todo
			//polyg.DrawHeptagonP(); //*****Arrumar este m�todo
			//polyg.DrawHegaxonP();
			//polyg.DrawPacMan();
			//polyg.DrawPizzaP();
			//polyg.DrawRetangleP();
			//polyg.DrawTriangleP(); 
			
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
