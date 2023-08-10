//Ordenação BubbleSort//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int troquei = 0;
time_t t ;																		//variável para o time.h


int main() {
	srand((unsigned) time(&t));													//gera números aleatórios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializaçao da memória para adicionar números no vetor
		vetor[i] = (rand() % 100000);											//gera números aleatórios para adicionar no vetor
	}																			//pega um número aleatório infinito e pega o resto desse n pela divisão por 100000
	
	for (i=0; i<100000; i++) {								
		printf("%d\n", vetor[i]);												//printar os números aleatórios
	}
	
	troquei = 1;
	while (troquei) {															//se nada negar o troquei=0, o while fará apenas 1 vez
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
