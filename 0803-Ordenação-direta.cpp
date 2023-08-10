//Ordenação direta//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int j = 0;
time_t t ;																		//variável para o time.h


int main() {
	srand((unsigned) time(&t));													//gera números aleatórios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializaçao da memória para adicionar números no vetor
		vetor[i] = (rand() % 100000);											//gera números aleatórios para adicionar no vetor
	}																			//pega um número aleatório infinito e pega o resto desse n pela divisão por 100000
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);												//printar os números aleatórios
	}

	for (i=0; i<99999; i++) {													// i = número que é comparado com os números seguintes do vetor, por isso o último i deve ser o penúltimo do vetor
		for (j=(i+1); j<100000; j++){											// j = do próximo ao último
			if (vetor[i] > vetor[j]) {											
				int temp = vetor[i];											//variável auxiliar
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);
	}
}


