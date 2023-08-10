//Ordena��o BubbleSort//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int troquei = 0;
time_t t ;																		//vari�vel para o time.h


int main() {
	srand((unsigned) time(&t));													//gera n�meros aleat�rios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializa�ao da mem�ria para adicionar n�meros no vetor
		vetor[i] = (rand() % 100000);											//gera n�meros aleat�rios para adicionar no vetor
	}																			//pega um n�mero aleat�rio infinito e pega o resto desse n pela divis�o por 100000
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);												//printar os n�meros aleat�rios
	}
	
	troquei = 1;
	while (troquei) {															//se nada negar o troquei=0, o while far� apenas 1 vez
		troquei = 0;
		
		for (i=0; i<99999; i++) {
			if (vetor[i] > vetor[i+1]) {
				int temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				
				troquei = 1;													//se ocorrer a troca, o while acontece novamente
			}
		}
	}
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);
	}
}
