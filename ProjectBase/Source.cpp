#include <cstdlib>
#include <iostream>
#include "Polygons.h"
using namespace std;

bool drawCircle = false; //flag para habilitar o desenho de círculos (apenas um exemplo)
float v1[2], v2[2], v3[2], v4[2]; //conjuntos de vértices que utilizarei para desenho.
float r, g, b; //variáveis utilizadas para cores
float radius; //variável correspondente ao raio dos circulos.
//float minX=-3, minY=-3, maxX=3, maxY=3; //variáveis correspondentes ao tamanho do plano cartesiano
//para desenho da casa, comentar a linha acima e descomentar a linha abaixo
float minX = 0, minY = 0, maxX = 6, maxY = 6;

Polygons polyg;	
//Callback de erro 
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

//Callback de teclado
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		drawCircle = !drawCircle;
	}
}
//callback para redimensionar
void reshape(GLFWwindow*window, int width, int height) {

	if (width > height) {
		glViewport(minX*(height/width),maxX*(height/width),minY,maxY);
	}
	else if (width < height) {
		glViewport(minX,maxX,minY*(width/height),maxY*(width/height));
	}
}

// Programa Principal 
int main(void)
{
	//Inicialização da janela da aplicação
	GLFWwindow* window;

	//Inicializando a lib
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Criando a janela
	window = glfwCreateWindow(1024, 768, "Exercicio 1 OpenGL !", NULL, NULL);
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
	//setando a callback de redesenho
	//glfwSetFramebufferSizeCallback(window, reshape);
	//Setando a callback de erro
	glfwSetErrorCallback(error_callback);

	while (!glfwWindowShouldClose(window)) //loop da aplicação :)
	{

		int width, height;
		float ratio;
		//aqui recupera o tamanho atual da janela, para correção do aspect ratio mais tarde
		glfwGetFramebufferSize(window, &width, &height);
		//setando a viewport da OpenGL, para ocupar toda a janela da aplicação
		glViewport(0, 0, width, height);
		
		// Limpa a janela de visualização com a cor branca
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//Setando a matriz de projeção, para definir o Ortho (câmera ortográfica 2D)
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//Setando a janela do mundo a ser vista (window), a câmera ortográfica 2D
		
		gluOrtho2D(minX,maxX,minY,maxY);	

		//Trocando para a matriz de modelo
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		if (drawCircle) {
			//desenho dos circulos aletórios //ajustar pois está "preso" no loop e não para de desenhar.
			r = rand() % 10 / 10.0;
			b = rand() % 10 / 10.0;
			g = rand() % 10 / 10.0;
			radius = rand() % 10 / 10.0;
			float posX = rand() % 4;
			float posY = rand() % 4;

			polyg.DrawCircleP(posX, posY,'L', r, g, b, radius,radius);
			
		}
		else {
			/*vertices utilizados para desenho do quadrado
			v1[0] = 0, v1[1] = 0;
			v2[0] = 0.25f, v2[1] = 0;
			v3[0] = 0.25f, v3[1] = 0.5f;
			v4[0] = 0, v4[1] = 0.5f;
			*/
			
			//vertices utilizados para desenho do triangulo

			//	v1[0] = 0, v1[1] = 0.5f;
			//v2[0] = 0.125f, v2[1] = 1;
			//v3[0] = 0.25f, v3[1] = 0.5f;
			//inserir comandos para desenhos aqui!
			//polyg.DrawCaracolP();
			//polyg.DrawCircleP(1, 1, 'p', 0, 0, 0, 1,0.5);
			//polyg.DrawHeptagonP(); 
			//polyg.DrawHegaxonP();
			//polyg.DrawPacMan();
			//polyg.DrawPizzaP();
			//polyg.DrawRetangleP();
			//polyg.DrawQuadP(v1,v2,v3,v4,0,0,0);
			//polyg.DrawTriangleP(v1,v2,v3,0.4,0.4,1); 
			//glViewport(-400,-300,width,height);
			//polyg.desenho();

			//viewport1 - duas casas no mesmo "terreno" :)
			/*glViewport(0, 0, width, height);
				polyg.desenho();
				glViewport(width/2, 0, width, height);
			polyg.desenho();*/
			
			//viewport2 - apenas o sol
			/*glViewport(-150, -150, width, height);
			polyg.desenho();*/

			//viewport3 - apenas sol grama
			/*glViewport(-70, -3, width, height);
				polyg.desenho();*/
			
			
			//viewport4 - apenas a casa com grama
			/*glViewport(690, 200, width, height);
				polyg.desenho();*/

			polyg.teste();
		}
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
