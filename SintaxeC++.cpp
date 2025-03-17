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

int main() {
    Menu menu;
    setlocale(LC_ALL, "pt-BR");

    do {
		std::cout<<"\nSINTAXE DO C++";
		std::cout<<"\n1: Fazer Contas \n2: Ver-Sintaxe Da Linguagem C++ \n3: ";
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
						std::cout<<"\nDigite Dois Valores: ";
						std::cin>>a>>b;					
						resultado=FazendoContas::adicao(a,b);
						
						if(a!=int() || b!=int()){
							std::cout<<"\nValores não são inteiros!";
							menu.tela=false;
							break;
							}
						else{
						printf("\n%d + %d = %d\n",a,b,resultado);
					}
					break;
					
					case '-':
						std::cout<<"\nDigite Dois Valores: ";
						std::cin>>a>>b;
						resultado=FazendoContas::subtracao(a,b);
							
						if(a!=int() || b!=int()){
							std::cout<<"\nValores não são inteiros!";
							menu.tela=false;
							break;
							}
						else{
						printf("\n%d + %d = %d\n",a,b,resultado);
					}								
					break;
					
					case '*':
						std::cout<<"\nDigite Dois Valores: ";
						std::cin>>a>>b;
						resultado=FazendoContas::multiplicacao(a,b);
						
						if(a!=int() || b!=int()){
							std::cout<<"\nValores não são inteiros!";
							menu.tela=false;
							break;
							}
						else{
						printf("\n%d + %d = %d\n",a,b,resultado);
					}		

					
					case '/':
						std::cout<<"\nDigite Dois Valores: ";
						std::cin>>a>>b;
						resultado=FazendoContas::divisao(a,b);
						
						if(a!=int() || b!=int()){
							std::cout<<"\nValores não são inteiros!";
							menu.tela=false;
							break;
							}
						else{
						printf("\n%d + %d = %d\n",a,b,resultado);
					}
					
					case 'r':
						std::cout<<"\nDigite Um Valor: ";
						std::cin>>a;					
						raiz_quadrada = FazendoContas::raiz(a);
						std::cout<<"\nRaiz Quadrada de "<<a<<": "<<raiz_quadrada;

						if(a!=int() || b!=int()){
							std::cout<<"\nValores não são inteiros!";
							menu.tela=false;
							break;
							}
						else{
						printf("\n%d + %d = %d\n",a,b,resultado);
					}
					
					default:
						std::cout<<"\nOperação Inválida!";
					break;
				}
				 std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            
            case 2:
				std::cout<<"\n1: Operadores Aritméticos \n2: Tipos Primitivos\n3: Estruturas-Condicionais\n4: Estrutura-De-Repetições\n5: Tipos-Lógicos \n6: Collections\n6: Iterator\n";
				std::cout<<"\nO QUE DESEJA VER: ";
				std::cin>>sintaxe;
				
				switch(sintaxe){
					case 1:
					break;
					
					case 2:
					break;
					
					case 3:
					break;
					
					case 4:
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
					}
				
                menu.aperteContinue();
                break;

            case 3:
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
