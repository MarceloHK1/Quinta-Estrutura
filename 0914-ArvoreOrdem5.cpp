//Estrutura de dados n�o linear
//Aumenta as performances de busca, por meio de algoritmos recursivos
//Organizada de forma hier�rquica
//Elemento raiz, ligadas a outros elementos chamados filhos
//Os filhos podem ter outrso filhos, caso n�o tenham s�o chamadas folhas
//Os n�s sem ser a raiz formam conjuntos disjuntos chamados de sub�rvore

//Ordem = quantidade de filhos dos n�s da �rvore
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

struct no *inserir (struct no *raiz, int number) {															//Fun��o para inserir um n� na �rvore
	if (raiz == NULL) {																						//Se a �rvore estiver vazia
		raiz = (struct no *) malloc(sizeof(struct no));
		
		raiz -> numero = number;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	} else {																								//Se a �rvore n�o estiver vazia
		int sorteio = (rand() % 5);																			//Resto de um n�mero aleat�rio / qntd de filhos
		
		if (sorteio == 0) {																					//fun��o recursiva at� achar um n� vazio
			raiz -> filho1 = inserir(raiz -> filho1, number);												//insere no filho1 o n�mero
		} else if (sorteio == 1) {
			raiz -> filho2 = inserir(raiz -> filho2, number);											
		} else if (sorteio == 2) {
			raiz -> filho3 = inserir(raiz -> filho3, number);
		} else if (sorteio == 3) {
			raiz -> filho4 = inserir(raiz -> filho4, number);
		} else if (sorteio == 4) {
			raiz -> filho5 = inserir(raiz -> filho5, number);
		}
	}
	return raiz;
}

void imprimir(struct no *raiz, char *endentacao) {															//Fun��o que imprime a �rvore
	if (raiz != NULL) {
		printf("%s%d\n", endentacao, raiz -> numero);	
		
		char *temp = (char *) malloc(1024 * sizeof(char));
		strcpy(temp, endentacao);																			//copia o valor da endentacao para temp
		strcat(temp, "---");																				//soma no temp, "---"
		
		imprimir(raiz -> filho1, temp);
		imprimir(raiz -> filho2, temp);
		imprimir(raiz -> filho3, temp);
		imprimir(raiz -> filho4, temp);
		imprimir(raiz -> filho5, temp);
	}
}

int main () {
	struct no *raiz = NULL;																					//Declara��o de vari�veis
	time_t t;
	char *endentacao = (char *) malloc(1024 * sizeof(char));
	
	srand((unsigned) time(&t));																				//Inicializa��o da aleatoriedade
	
	strcpy(endentacao, "");
	imprimir(raiz, endentacao);
	
	int i = 0;
	for (i = 0; i<10000; i++) {
		raiz = inserir(raiz, i);
	}
	
	imprimir(raiz, endentacao);
}

