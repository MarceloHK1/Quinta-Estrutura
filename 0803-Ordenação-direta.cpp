//Ordena��o direta//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int j = 0;
time_t t ;																		//vari�vel para o time.h


int main() {
	srand((unsigned) time(&t));													//gera n�meros aleat�rios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializa�ao da mem�ria para adicionar n�meros no vetor
		vetor[i] = (rand() % 100000);											//gera n�meros aleat�rios para adicionar no vetor
	}																			//pega um n�mero aleat�rio infinito e pega o resto desse n pela divis�o por 100000
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);												//printar os n�meros aleat�rios
	}

	for (i=0; i<99999; i++) {													// i = n�mero que � comparado com os n�meros seguintes do vetor, por isso o �ltimo i deve ser o pen�ltimo do vetor
		for (j=(i+1); j<100000; j++){											// j = do pr�ximo ao �ltimo
			if (vetor[i] > vetor[j]) {											
				int temp = vetor[i];											//vari�vel auxiliar
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);
	}
}


