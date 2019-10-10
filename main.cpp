/** PARA CONSTRUIR AS FORMAS GEOMETRICAS, FOI INFERIDO QUE FOSSE MELHOR QUE AO 
 * 	APERTAR TECLAS DO TECLADO, A FORMA FOSSE DEFINIDA, E OS PONTOS PUDESSEM SER
 *  SELECIONADOS PELO USUARIO.
 *  DESSA FORMA, AS TECLAS DO TECLADO CORRESPONDEM AS FORMAS DA SEGUINTE MANEIRA:
 * I/i - LINHAS
 * H/i - QUADRILATEROS
 * V/v - TRIANGULOS
 * D/d - POLIGONOS QUAISQUER
 * O/o - CIRCUNFERÊNCIAS
 */

// Bibliotecas utilizadas pelo OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;


double x_1, y_1, x_2, y_2;
double dx, dy, d, incE, incNE;

int width = 512, height = 512; //Largura e altura da janela



/***********************************************************************************/
//UMA ESTRUTURA PARA MELHOR LIDAR COM OS PONTOS
struct Ponto
{
	int X, Y;
	Ponto(int x = 0, int y = 0)
	{
		X = x;
		Y = y;
	}
};
/***********************************************************************************/
//VARIAVEIS UTILIZADAS NAS FUNÇÕES CRIADAS PELO ALUNO
vector<Ponto> pontos, aux_pontos;
int which_one;
/***********************************************************************************/




// Declaracoes forward das funcoes utilizadas
void init(void);
void reshape(int w, int h);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

// Funcao que implementa o Algoritmo Imediato para rasterizacao de retas
void retaImediata(double x1, double y1, double x2, double y2);



/*************************************************************************************/
// FUNÇÕES IMPLEMENTADAS PELO ALUNO
void brasenhamLine(vector <Ponto> p);
void brasenhamLine2(double x1, double y1, double x2, double y2); //constroe a linha utilizando o Algoritmo de Brasenham
void drawnQuad(vector <Ponto> p); // constroe um quadrado/retangulo com base no algoritmo de Brasenham
void drawnTriangule(vector <Ponto> p);// constroe um triangulo com base no algoritmo de Brasenham
void drawnPolign(vector <Ponto> p) ;// constroe um poligno com base no algoritmo de Brasenham
void drawnCircle(Ponto centro, int raio); // constroe uma circunferencia com base no algoritmo de Brasenham
bool Done(); //verifica que forma o usuario deseja desenhar
/************************************************************************************/




// Funcao que percorre a lista de pontos desenhando-os na tela
void drawPontos();

// Funcao Principal do C
int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Passagens de parametro C para o glut
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
	glutInitWindowSize (width, height);  // Tamanho da janela do OpenGL
	glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
	glutCreateWindow ("Rasterizacao"); // Da nome para uma janela OpenGL
	init(); // Chama funcao init();
	glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
	glutKeyboardFunc(keyboard); //funcao callback do teclado
	glutMouseFunc(mouse); //funcao callback do mouse
	glutDisplayFunc(display); //funcao callback de desenho
	glutMainLoop(); // executa o loop do OpenGL
	return 0; // retorna 0 para o tipo inteiro da funcao main();
}

// Funcao com alguns comandos para a inicializacao do OpenGL;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
}

void reshape(int w, int h)
{
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

	width = w;
	height = h;
	glOrtho (0, w, 0, h, -1 , 1);

	// muda para o modo GL_MODELVIEW (não pretendemos alterar a projecção
	// quando estivermos a desenhar na tela)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Funcao usada na funcao callback para utilizacao das teclas normais do teclado
void keyboard(unsigned char key, int x, int y)
{
	switch (key)   // key - variavel que possui valor ASCII da tecla precionada
	{
	case 27: // codigo ASCII da tecla ESC
		exit(0); // comando pra finalizacao do programa
		break;
	case 'i':
	case 'I':
		which_one = 0;
		aux_pontos.clear();
		break;
	case 'h':
	case 'H':
		which_one = 1;
		aux_pontos.clear();
		break;
	case 'v':
	case 'V':
		which_one = 2;
		aux_pontos.clear();
		break;
	case 'd':
	case 'D':
		which_one = 3;
		aux_pontos.clear();
		break;
	case 'o':
	case 'O':
		which_one = 4;
		aux_pontos.clear();
		break;
	}
}

//Funcao usada na funcao callback para a utilizacao do mouse
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			aux_pontos.push_back(Ponto(x, height - y));
			if(Done())
				glutPostRedisplay();
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state == GLUT_DOWN)
		{
			aux_pontos.clear();
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

bool Done()
{
	if(which_one == 0 && aux_pontos.size() > 1)
	{
		brasenhamLine(aux_pontos);
		aux_pontos.clear();
		return true;
	}
	else if(which_one == 1 && aux_pontos.size() > 1)
	{
		drawnQuad(aux_pontos);
		aux_pontos.clear();
		return true;
	}
	else if(which_one == 2 && aux_pontos.size() > 2)
	{
		drawnTriangule(aux_pontos);
		aux_pontos.clear();
		return true;
	}
	else if(which_one == 3)
	{
		drawnPolign(aux_pontos);
		return true;
	}
	else if(which_one == 4)
	{
		for(int i = 0; i < (int)aux_pontos.size(); i++)
			drawnCircle(aux_pontos[i], 80);

		aux_pontos.clear();
		return true;
	}

	return false;
}

// Funcao usada na funcao callback para desenhar na tela
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //Limpa o Buffer de Cores
	glColor3f (0.0, 0.0, 0.0); // Seleciona a cor default como preto
	drawPontos();
	glutSwapBuffers(); // manda o OpenGl renderizar as primitivas

}

//Funcao que desenha os pontos contidos em uma lista de pontos
void drawPontos()
{

	glBegin(GL_POINTS);
	for(int i = 0; i < (int)pontos.size(); i++)
		glVertex2i(pontos[i].X, pontos[i].Y);
	glEnd();
}

void swap(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
}

void drawnCircle(Ponto centro, int raio)
{
	int d = 1 - raio;
	int dE = 3;
	int dSE = (-2 * raio) + 5;

	int x = 0, y = raio;

	pontos.push_back(Ponto(centro.X + x, centro.Y + y));
	pontos.push_back(Ponto(centro.X + x, centro.Y - y));
	pontos.push_back(Ponto(centro.X - x, centro.Y + y));
	pontos.push_back(Ponto(centro.X - x, centro.Y - y));

	while (y > x)
	{
		if (d < 0)
		{
			d += dE;
			dE += 2;
			dSE += 2;
		}
		else
		{
			d += dSE;
			dE += 2;
			dSE += 4;
			y--;
		}
		x++;
		pontos.push_back(Ponto(centro.X + x, centro.Y + y));
		pontos.push_back(Ponto(centro.X + x, centro.Y - y));
		pontos.push_back(Ponto(centro.X - x, centro.Y + y));
		pontos.push_back(Ponto(centro.X - x, centro.Y - y));

		pontos.push_back(Ponto(centro.X + y, centro.Y + x));
		pontos.push_back(Ponto(centro.X + y, centro.Y - x));
		pontos.push_back(Ponto(centro.X - y, centro.Y + x));
		pontos.push_back(Ponto(centro.X - y, centro.Y - x));
	}

}

void drawnPolign(vector <Ponto> p)
{
	int size = p.size();

	if(!size)
		return;

	for(int i = 1; i < size ; i++)
		brasenhamLine2(p[i - 1].X, p[i - 1].Y, p[i].X, p[i].Y);

	//brasenhamLine(p[0].X, p[0].Y, p[size - 1].X, p[size - 1].Y);
}

void drawnTriangule(vector <Ponto> p)
{
	if(p.size() < 3) return;

	for(int i = 2; i < (int)p.size(); i += 3)
	{
		brasenhamLine2(p[i - 2].X, p[i - 2].Y, p[i - 1].X, p[i - 1].Y);
		brasenhamLine2(p[i].X, p[i].Y, p[i - 1].X, p[i - 1].Y);
		brasenhamLine2(p[i - 2].X, p[i - 2].Y, p[i].X, p[i].Y);
	}

	brasenhamLine2(p[0].X, p[0].Y, p[1].X, p[1].Y);
	brasenhamLine2(p[1].X, p[1].Y, p[2].X, p[2].Y);
	brasenhamLine2(p[0].X, p[0].Y, p[2].X, p[2].Y);
}

void drawnQuad(vector <Ponto> p)
{
	for(int i = 1; i < (int)p.size(); i += 2)
	{
		brasenhamLine2(p[i - 1].X, p[i - 1].Y, p[i].X, p[i - 1].Y);
		brasenhamLine2(p[i - 1].X, p[i - 1].Y, p[i - 1].X, p[i].Y);
		brasenhamLine2(p[i - 1].X, p[i].Y, p[i].X, p[i].Y);
		brasenhamLine2(p[i].X, p[i].Y, p[i].X, p[i - 1].Y);
	}
}
void brasenhamLine(vector <Ponto> p)
{
	for(int i = 1; i < (int)p.size(); i += 2)
	{
		brasenhamLine2(p[i - 1].X, p[i - 1].Y, p[i].X, p[i].Y);
	}
}



void brasenhamLine2(double x1, double y1, double x2, double y2)
{
	bool declive = false, simetrico = false;
	double dx, dy, d, incE, incNE, x, y, aux;
	dx = x2 - x1;
	dy = y2 - y1;

	if(dx * dy < 0)
	{
		y1 = -y1;
		y2 = -y2;
		dy = -dy;
		simetrico = true;
	}

	if(abs(dx) < abs(dy))
	{
		aux = x1;
		x1 = y1;
		y1 = aux;

		aux = x2;
		x2 = y2;
		y2 = aux;

		aux = dx;
		dx = dy;
		dy = aux;
		declive = true;
	}

	if(x1 > x2)
	{
		aux = x1;
		x1 = x2;
		x2 = aux;

		aux = y1;
		y1 = y2;
		y2 = aux;

		dx = -dx;
		dy = -dy;
	}

	d = 2 * dy - dx;
	incE = 2 * dy;
	incNE = 2 * (dy - dx);

	x = x1;
	y = y1;

	double yf, xf;
	if(declive)
	{
		xf = y;
		yf = x;
	}

	if(simetrico)
	{
		yf = -yf;
	}

	pontos.push_back(Ponto((int)xf, (int)yf));

	while (x < x2)
	{
		if(d <= 0)
		{
			d += incE;
		}
		else
		{
			d += incNE;
			y++;
		}
		x++;

		xf = x;
		yf = y;

		if(declive)
		{
			xf = y;
			yf = x;
		}

		if(simetrico)
		{
			yf = -yf;
		}

		pontos.push_back(Ponto((int)xf, yf));
	}

}

void retaImediata(double x1, double y1, double x2, double y2)
{
	double m, b, yd, xd;
	double xmin, xmax, ymin, ymax;

	//Armazenando os extremos para desenho
	pontos.push_back(Ponto((int)x1, (int)y1));
	pontos.push_back(Ponto((int)x2, (int)y2));

	if(x2 - x1 != 0) //Evita a divisão por zero
	{
		m = (y2 - y1) / (x2 - x1);
		b = y1 - (m * x1);

		if(m >= -1 && m <= 1) // Verifica se o declive da reta tem tg de -1 a 1, se verdadeira calcula incrementando x
		{
			xmin = (x1 < x2) ? x1 : x2;
			xmax = (x1 > x2) ? x1 : x2;

			for(int x = (int)xmin + 1; x < xmax; x++)
			{
				yd = (m * x) + b;
				yd = floor(0.5 + yd);
				pontos.push_back(Ponto(x, (int)yd));
			}
		}
		else   // Se menor que -1 ou maior que 1, calcula incrementado os valores de y
		{
			ymin = (y1 < y2) ? y1 : y2;
			ymax = (y1 > y2) ? y1 : y2;

			for(int y = (int)ymin + 1; y < ymax; y++)
			{
				xd = (y - b) / m;
				xd = floor(0.5 + xd);
				pontos.push_back(Ponto((int)xd, y));
			}
		}

	}
	else   // se x2-x1 == 0, reta perpendicular ao eixo x
	{
		ymin = (y1 < y2) ? y1 : y2;
		ymax = (y1 > y2) ? y1 : y2;
		for(int y = (int)ymin + 1; y < ymax; y++)
			pontos.push_back(Ponto((int)x1, y));
	}
}

