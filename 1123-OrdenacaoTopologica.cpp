//Lembra uma pós ordem da árvore binária

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int QTDVERTICES = 8;

void criar (int grafo[QTDVERTICES][QTDVERTICES], int aleatorio) {
	int i = 0;
	int j = 0;
	int aresta = 0;
	
	for (i=0; i<QTDVERTICES; i++) {
		for (j=0; j<QTDVERTICES; j++) {
			if (aleatorio) {
				aresta = (rand() % 2);
			} else {
				printf("Digite <1> se %d estiver conectado a %d: ", i, j);
				scanf("%d", &aresta);
			}
			grafo[i][j] = aresta;
		}
	}
}

void ordenarTopologicoRecursivo(int grafo[QTDVERTICES][QTDVERTICES], int visitado[QTDVERTICES], int vertice) {
	int i;
	visitado[vertice] = 1;

	for (i = 0 ; i < QTDVERTICES ; i++) {
		if (grafo[vertice][i]) {
			if (! visitado[i]) {
				ordenarTopologicoRecursivo(grafo, visitado, i);
			}
		}
	}
	printf("%d\t", vertice);
}

void ordenarTopologico(int grafo[QTDVERTICES][QTDVERTICES]) {
	int vertice;
	int visitado[QTDVERTICES];

	for (vertice = 0 ; vertice < QTDVERTICES ; vertice++) {
		visitado[vertice] = 0;
	}

	for (vertice = 0 ; vertice < QTDVERTICES ; vertice++) {
		if (! visitado[vertice]) {
			ordenarTopologicoRecursivo(grafo, visitado, vertice);
		}
	}
	printf("\n");
}

int main() {
	int grafo[QTDVERTICES][QTDVERTICES];
	
	time_t t;
	srand((unsigned) time(&t));
	
	criar(grafo, 0);
	ordenarTopologico(grafo);
}

