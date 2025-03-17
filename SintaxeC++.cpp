#include <iostream>
#include <string>
#include <locale.h>
#include <limits>
#include <cmath>
#include <vector>
#include <list>
#include <GL/gl.h>
#include <GL/glut.h>
#include <map>
#include <queue>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>

GLfloat escala = 1;
GLfloat rotacao = 0;
GLfloat moverx,movery = 0.0f;


struct Desenhos{
	public:
			static void Quadrado(){
			glClearColor(1.0f,0.0f,0.0f,0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(-5,5,-5,5);
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glScalef(escala,escala,0);
			glRotatef(rotacao,0,0,1);
			glTranslatef(movery,moverx,0);
			
			glBegin(GL_POLYGON);
			glColor3f(1.0f,0.0f,0.1f);
			glVertex2f(-0.5,-0.5);
			glColor3f(0.0f,0.1f,1.0f);
			glVertex2f(0.5f,-0.5f);
			glColor3f(0.1f,1.0f,0.0f);
			glVertex2f(0.5f,0.5f);
			glColor3f(1.0f,1.1f,0.1f);
			glVertex2f(-0.5f,0.5f);
			glEnd();
			
			glFlush();
			//glSwapBuffers();
			}
			
		static void Triângulo(){
			glClearColor(0.0f,0.0f,0.0f,0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(-5,5,-5,5);
			
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glScalef(escala,escala,0);
			glRotatef(rotacao,0,0,1);
			glTranslatef(movery,moverx,0);
			
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f,0.0f,0.1f);
			glVertex2f(-0.5,-0.5);
			glColor3f(0.0f,0.1f,1.0f);
			glVertex2f(0.5f,-0.5f);
			glColor3f(0.1f,1.0f,0.0f);
			glVertex2f(0.0f,0.5f);
			glColor3f(1.0f,1.1f,0.1f);
			glEnd();
			
			glFlush();		
		}
		
		 static void zoom(unsigned char tecla, GLint x, GLint y){
			
			
			switch(tecla){
				
				case '=':
					escala+=0.1f;
				break;
				
				case '-':
					escala-=0.1f;
				break;
				
				case 'q':
					rotacao+=3;
				break;
				
				case 'w':
					rotacao-=3;
				break;
				
				}
				glutPostRedisplay();
			}
		
		static void movimentar( int tecla, int x, int y ){
			
			
			switch(tecla){
				
				case GLUT_KEY_UP:
					moverx+=0.1f;
				break;		
				
				case GLUT_KEY_DOWN:
					moverx-=0.1f;
				break;
				
				case GLUT_KEY_RIGHT:
					movery+=0.1f;
				break;
				
				case GLUT_KEY_LEFT:
					movery-=0.1f;
				break;
				
				}
				glutPostRedisplay();
			}
	};

class Menu {
	
public:
    std::string mensagem = "\nDigite Uma Opção: ";
    bool tela = true;
    int opt;

    void aperteContinue() {
        std::cout << "\nPressione Qualquer Tecla Para Continuar: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    void limparEntrada() {
		std::cout << "\nPressione Qualquer Tecla Para Continuar: ";
        std::cin.clear(); // Limpa o erro do cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove qualquer lixo do buffer
        std::cin.get();

    }
    
};

    namespace FazendoContas{
				
				int adicao(int a, int b){
					
					return a+b;
					}
				int subtracao(int a, int b){
					
					return a-b;
					}
				int multiplicacao(int a, int b){
					
					return a*b;
					}
				int divisao(int a, int b){
					
					return a/b;
					}
				int raiz(int a){
					
					return sqrt(a);
					}
		}

int main(int argc, char** argv) {
    Menu menu;
    setlocale(LC_ALL, "pt-BR");

    do {
		std::cout<<"\nSINTAXE DO C++";
		std::cout<<"\n1: Fazer Contas \n2: Ver-Sintaxe Da Linguagem C++ \n3: Ver-Desenhos\n4: Sair\n";
        std::cout << menu.mensagem;
        std::cin >> menu.opt;

        // Se o usuário digitar algo inválido (ex: letra), limpa o erro e pede de novo
        if (std::cin.fail()) {
            std::cout << "\nEntrada inválida! Por favor, digite um número.\n";
            menu.limparEntrada();
            continue; // Volta para o início do loop sem executar o switch
        }

        switch (menu.opt) {
            case 1:
			int a,b;
			int resultado;
			int raiz_quadrada;
			int sintaxe;
			
			char operacao;
			std::cout<<"\n\t+ adição\n\t- subtração\n\t* multiplicação\n\t/ divisão\n\tr raiz-quadrada";
			std::cout<<"\n\nDigite Uma Operação[ + - * / r]: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin>>operacao;			
			  
            switch(operacao){
					
					case '+':
						std::cout << "\nDigite Dois Valores: ";
						if (!(std::cin >> a >> b)) {  // Verifica se a entrada é válida
							std::cout << "\nEntrada inválida!";
							menu.limparEntrada();
							break;
						}
						resultado = FazendoContas::adicao(a, b);
						std::cout << "\n" << a << " + " << b << " = " << resultado << "\n";
						menu.limparEntrada();
						break;
					
					case '-':
						std::cout << "\nDigite Dois Valores: ";
						if (!(std::cin >> a >> b)) {  // Verifica se a entrada é válida
							std::cout << "\nEntrada inválida!";
							menu.limparEntrada();
							break;
						}
						resultado = FazendoContas::subtracao(a, b);
						std::cout << "\n" << a << " - " << b << " = " << resultado << "\n";
						menu.limparEntrada();
						break;
					
					
					case '*':
						std::cout << "\nDigite Dois Valores: ";
						if (!(std::cin >> a >> b)) {  // Verifica se a entrada é válida
							std::cout << "\nEntrada inválida!";
							menu.limparEntrada();
							break;
						}
						resultado = FazendoContas::multiplicacao(a, b);
						std::cout << "\n" << a << " * " << b << " = " << resultado << "\n";
						menu.limparEntrada();
						break;
					

					
					case '/':
						std::cout << "\nDigite Dois Valores: ";
						if (!(std::cin >> a >> b)) {  // Verifica se a entrada é válida
							std::cout << "\nEntrada inválida!";
							menu.limparEntrada();
							break;
						}
						resultado = FazendoContas::divisao(a, b);
						std::cout << "\n" << a << " / " << b << " = " << resultado << "\n";
						menu.limparEntrada();
						break;
					
					case 'r':
						std::cout << "\nDigite Um Valor: ";
						if (!(std::cin >> a)) {  // Verifica se a entrada é válida
							std::cout << "\nEntrada inválida!";
							menu.limparEntrada();
							break;
						}
						resultado = FazendoContas::raiz(a);
						std::cout <<"\nRaiz De: "<<a<<": "<<resultado << "\n";
						menu.limparEntrada();
						break;
					
					default:
						std::cout<<"\nOperação Inválida!";
					break;
				}
				 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            
            case 2:
				std::cout<<"\n1: Operadores Aritméticos \n2: Tipos Primitivos\n3: Estruturas-Condicionais\n4: Estrutura-De-Repetições\n5: Tipos-Lógicos \n6: Collections\n7: Iterator\n";
				std::cout<<"\nO QUE DESEJA VER: ";
				std::cin>>sintaxe;
				switch(sintaxe){
					case 1:
					std::cout<<"\n*********************************************";
					std::cout<<"\nOPERADORES ARITMÉTICOS: ";
					std::cout<<"\n\t+ -* /";
					std::cout<<"\n\t++ -- ";
					std::cout<<"\n\t+= -= *= /=\n";
					std::cout<<"*********************************************";
					break;
					
					case 2:
					std::cout<<"\n*********************************************";
					std::cout<<"\nTIPOS PRIMITIVOS: ";
				
					if(typeid(std::string)==typeid(std::string)){
						std::cout<<"\nstd::string: \nTamanho bytes: "<<sizeof(std::string);
						std::cout<<"\n\nint: \nTamanho bytes: "<<sizeof(int);
						std::cout<<"\n\nfloat: \nTamanho bytes: "<<sizeof(float);
						std::cout<<"\n\ndouble: \nTamanho bytes: "<<sizeof(double);
						std::cout<<"\n\nchar: \nTamanho bytes:  "<<sizeof(char);
						std::cout<<"\n\nByte: \nTamanho bytes: "<<sizeof(std::byte);
						std::cout<<"\n*********************************************";

						}
						else{
							return 0;
							}
					break;
					
					case 3:
					std::cout<<"\n*********************************************";
					std::cout<<"\nEstruturas-Condicionais: ";
					std::cout<<"\n\n\tif(condição){\ninstrução}\n";
					std::cout<<"\n\n\telse if(condição){\ninstrução}\n";
					std::cout<<"\n\n\telse{\ninstrução}\n";
					std::cout<<"*********************************************";
					break;
					
					case 4:
					std::cout<<"\n*********************************************";
					std::cout<<"\nEstruturas De Repetições: ";

					std::cout<<"\n*********************************************";
			
					break;
					
					case 5:
					break;
					
					case 6:
					break;
					
					case 7:
					break;
					
					case 8:
					break;
					
					case 9:
					break;
					
					default:
					std::cout<<"\nOpção Inválida!";
					break;
					}
				
                menu.aperteContinue();
                break;
			
			case 3:
			
			int selecionar;
			std::cout<<"\n1: Quadrado\n2: Retângulo \n3: Círculo \n4: Triângulo\n";
			std::cin>>selecionar;
			
			switch(selecionar){
				
				case 1:
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
				glutInitWindowSize(800,600);
				glutInitWindowPosition(350,120);
				glutCreateWindow("Quadrado");
				glutDisplayFunc(Desenhos::Quadrado);
				glutKeyboardFunc(Desenhos::zoom);
				glutSpecialFunc(Desenhos::movimentar);
				glutMainLoop();				
				break;
				
				case 2:
				
				break;
				
				case 3:
				
				break;
				
				case 4:
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
				glutInitWindowSize(800,600);
				glutInitWindowPosition(350,120);
				glutCreateWindow("Triângulo");
				glutDisplayFunc(Desenhos::Triângulo);
				glutKeyboardFunc(Desenhos::zoom);
				glutSpecialFunc(Desenhos::movimentar);
				glutMainLoop();
				break;
				
				default:
				
				break;
				
				}
			
			break;
			
            case 4:
                std::cout << "\nObrigado Por Utilizar O Programa!\n";
                menu.tela = false;
             break;

            default:
                std::cout << "\nOpção Inválida!\n";
                menu.aperteContinue();
                break;
        }
    } while (menu.tela);

    return 0;
}
