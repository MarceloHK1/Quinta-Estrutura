//Estrutura de dados não linear
//Aumenta as performances de busca, por meio de algoritmos recursivos
//Organizada de forma hierárquica
//Elemento raiz, ligadas a outros elementos chamados filhos
//Os filhos podem ter outrso filhos, caso não tenham são chamadas folhas
//Os nós sem ser a raiz formam conjuntos disjuntos chamados de subárvore

//Ordem = quantidade de filhos dos nós da árvore
//Nível = distância entre um nó e a raiz
//Altura = maior nível entre todas as folhas da árvore + 1

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

struct no *inserir (struct no *raiz, int number) {															//Função para inserir um nó na árvore
	if (raiz == NULL) {																						//Se a árvore estiver vazia
		raiz = (struct no *) malloc(sizeof(struct no));
		
		raiz -> numero = number;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	} else {																								//Se a árvore não estiver vazia
		int sorteio = (rand() % 5);																			//Resto de um número aleatório / qntd de filhos
		
		if (sorteio == 0) {																					//função recursiva até achar um nó vazio
			raiz -> filho1 = inserir(raiz -> filho1, number);												//insere no filho1 o número
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

void imprimir(struct no *raiz, char *endentacao) {															//Função que imprime a árvore
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
	struct no *raiz = NULL;																					//Declaração de variáveis
	time_t t;
	char *endentacao = (char *) malloc(1024 * sizeof(char));
	
	srand((unsigned) time(&t));																				//Inicialização da aleatoriedade
	
	strcpy(endentacao, "");

	
	int opcao = 0;
	while (opcao != 3) {
		printf("==================================\n");
		printf("|                Menu            |\n");
		printf("==================================\n");
		printf("|         1 - Inserir            !\n");
		printf("|         2 - Imprimir           !\n");
		printf("|         3 - Sair               !\n");
		printf("==================================\n");
		
		printf("Digite a opção: ");
		scanf("%d", &opcao);
		
		if (opcao == 1) {
			int number = 0;
			printf("Digite o numero: ");
			scanf("%d", &number);
			raiz = inserir(raiz, number);
		} else if (opcao == 2) {
			imprimir(raiz, endentacao);
		}
	}
}

