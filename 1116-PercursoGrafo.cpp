#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int QTDVERTICES = 16;

void criar(int grafo[QTDVERTICES][QTDVERTICES], int aleatorio) {
	int i = 0;
	int j = 0;
	int aresta = 0;
	
	for (i=0; i<(QTDVERTICES - 1); i++) {
		for (j=(i+1); j<QTDVERTICES; j++) {
			if (aleatorio) {
				aresta = (rand() % 2);
			} else {
				printf("Digite <1> se %d estiver conectado a %d: ", i, j);
				scanf("%d", &aresta);
			}
			
			grafo[i][j] = aresta;
			grafo[j][i] = aresta;
		}
	}
}

int procurarPercursoRecursivo(int grafo[QTDVERTICES][QTDVERTICES], int visitado[QTDVERTICES], int inicio, int fim) {
	int vizinho = 0;
	int retorno = 0;
	
	if (inicio == fim) {
		retorno = 1;	
	} else {
		visitado[inicio] = 1;
		for (vizinho = 0 ; vizinho < QTDVERTICES ; vizinho++) {
			if ((grafo[inicio][vizinho]) && (! visitado[vizinho])) {
				if (procurarPercursoRecursivo(grafo, visitado, vizinho, fim)) {
					retorno = 1;
					printf("%d <- ", vizinho);
					break;
				}
			}
		}
	}
	return retorno;
}

int procurarPercurso(int grafo[QTDVERTICES][QTDVERTICES], int inicio, int fim) {
	int i = 0;
	int visitado[QTDVERTICES];
	int encontrei = 0;

	for (i = 0 ; i < QTDVERTICES ; i++) {
		visitado[i] = 0;
	}

	encontrei = procurarPercursoRecursivo(grafo, visitado, inicio, fim);
	printf("%d\n", inicio);

	return encontrei;
}

int main() {
	int grafo[QTDVERTICES][QTDVERTICES];
	int inicio = 0;
	int fim = 0;
	
	time_t t;
	srand((unsigned) time(&t));
	
	criar(grafo, 0);
	while (inicio != -1) {
		printf("Digite um vertice inicial: ");
		scanf("%d", &inicio);
		
		printf("Digite o vertice final: ");
		scanf("%d", &fim);
		
		if (procurarPercurso(grafo, inicio, fim)) {
			printf("Encontrei um caminho! \n\n");
		} else {
			printf("Nao encontrei um caminho! \n\n");
		}
	}
}
