#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAMANHO = 5;

void criar(int grafo[TAMANHO][TAMANHO], int aleatorio) {
	int i = 0;
	int j = 0;
	int aresta = 0;
	
	for (i=0; i<TAMANHO; i++) {
		for (j=0; j<TAMANHO; j++) {
			grafo[i][j] = 0;
		}
	}
	
	for (i=0; i<TAMANHO-1; i++) {
		for (j=(i+1); j<TAMANHO; j++) {
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

void imprimir(int grafo[TAMANHO][TAMANHO]) {
	int i = 0;
	int j = 0;
	
	for (i=0; i<TAMANHO; i++) {
		for (j=0; j<TAMANHO; j++) {
			printf("%d\t", grafo[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int procurarVerticeMaiorGrau(int grafo[TAMANHO][TAMANHO]) {
	int retorno = -1;
	
	int i=0;
	int j=0;
	int maior = 0;
	int contador = 0;
	
	
	for (i=0; i<TAMANHO; i++) {
		contador = 0;
		for (j=0; j<TAMANHO; j++) {
			if (grafo[i][j]) {
				contador++;
			}
		}
		if (contador > maior) {
			maior = contador;
			retorno = i;
		}
	}
	
	return retorno;	
}

int main() {
	int grafo[TAMANHO][TAMANHO];
	criar(grafo, 0);
	imprimir(grafo);

	
	printf("O vertice de maior grau: %d\n", procurarVerticeMaiorGrau(grafo));	
}

