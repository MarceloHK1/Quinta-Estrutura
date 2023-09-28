//Complexidade para inserção, remoção e busca(nivel do esforço)
//-Listas encadeadas
//		inserir e remover em Ordem(1) -> independem do tamanho da lista
//		buscar em Ordem(n)
//-Vetores não-ordenados
//		inserir e remover em Ordem(1)
//			-inserir no final
//			-remover e trocar com o último e remover o último
//		Buscar em Ordem(N)
//-Vetores ordenados
//		Buscar em ordem(log n)
//		Inserir e remover em Ordem(N)
//-Árvores binárias de busca
//		As 3 operações levam Ordem(log N)

//Árvore binária em que cada nó contém um elemento de um conjunto ordenável
//Cada nó r, com subarvores esquerda Te e direita Td satisfaz:
//	-e < r para todo elemento e pertencente a Te
//	-e > d para todo elemento e pertencente a Td

//Busca de elemento
//--Algoritmo recursivo para encontro do valor
//		se estiver na raiz, devolve
//		se for menor que a raiz, esquerda
//		se for maior que a raiz, direita
//--Inserção de elemento
//		algoritmo de busca

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

struct no *inserir(struct no *raiz, int number) {
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = number;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		
	} else {
		if (number < raiz -> numero) {
			raiz -> esquerda = inserir(raiz -> esquerda, number);
		} else {
			raiz -> direita = inserir(raiz -> direita, number);
		}
	}
	return raiz;
}

void buscar(struct no *raiz, int number) {
	if (raiz == NULL) {
		printf("NÃO ACHEI!");
	} else if (raiz -> numero == number) {
		printf("Achei!!\n");
	} else if (raiz -> numero > number) {
		buscar(raiz -> esquerda, number);
	} else {
		buscar(raiz -> direita, number);
	}
}

void navegarEmOrdem(struct no *raiz) {
	if (raiz != NULL) {
		navegarEmOrdem(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
	}
}

int menu() {
	int opcao;
	
	printf("\n==========================================\n");
	printf("|               MENU DE OPCOES           |\n");
	printf("==========================================\n");
	printf("|              1 - Inserir               |\n");
	printf("|              2 - Buscar                |\n");
	printf("|              3 - Navegar               |\n");
	printf("| 4 - Inicializar a arvore aleatoriamente|\n");
	printf("|              5 - Sair                  |\n");
	printf("==========================================\n");
	printf("Digite sua opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

int main() {
	struct no *raiz = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	time_t t;
	srand((unsigned) time(&t));
	
	while (opcao != 5) {
		opcao = menu();
		
		if (opcao == 1) {
			printf("Digite o numero: ");
			scanf("%d", &numero);
			raiz = inserir(raiz, numero);
		} else if (opcao == 2) {
			printf("Digite o número: ");
			scanf("%d", &numero);
			buscar(raiz, numero);
		} else if (opcao == 3) {
			navegarEmOrdem(raiz);
		} else if (opcao == 4) {
			for (i=0; i<10000; i++) {
				raiz = inserir(raiz, rand());
			}
		}
	}
}

