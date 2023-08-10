//Ordenação direta//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int busca = 0;																	//número procurado
int achei = 0;																	//se achou
time_t t ;																		//variável para o time.h


int main() {
	srand((unsigned) time(&t));													//gera números aleatórios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializaçao da memória para adicionar números no vetor
		vetor[i] = (rand() % 100000);											//gera números aleatórios para adicionar no vetor
	}																			//pega um número aleatório infinito e pega o resto desse n pela divisão por 100000
	
	printf("Digite um valor para ser procurado: ");								//pede um valor a ser procurado
	scanf("%d", &busca);														//coloca esse valor na variavel busca
	
	achei = -1;	
	for (i=0; i<100000; i++) {													
		if (vetor[i] == busca) {												//se o vetor[i] for igual ao busca
			achei = i;															//achei vai ser a posição do número no vetor que se iguala a busca
		}
	}
	if (achei == -1) {
		printf("Se fudeu!!");
	} else {
		printf("Achei! Na posicao %d", achei);
	}
}
