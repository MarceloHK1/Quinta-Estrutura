//Ordena��o direta//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>																//importa o pacote pra aleatoriedade

int vetor[100000];
int i = 0;
int busca = 0;																	//n�mero procurado
int achei = 0;																	//se achou
time_t t ;																		//vari�vel para o time.h


int main() {
	srand((unsigned) time(&t));													//gera n�meros aleat�rios cada vez que rodar o programa
	
	for (i = 0; i<100000; i++) {												//inicializa�ao da mem�ria para adicionar n�meros no vetor
		vetor[i] = (rand() % 100000);											//gera n�meros aleat�rios para adicionar no vetor
	}																			//pega um n�mero aleat�rio infinito e pega o resto desse n pela divis�o por 100000
	
	printf("Digite um valor para ser procurado: ");								//pede um valor a ser procurado
	scanf("%d", &busca);														//coloca esse valor na variavel busca
	
	achei = -1;	
	for (i=0; i<100000; i++) {													
		if (vetor[i] == busca) {												//se o vetor[i] for igual ao busca
			achei = i;															//achei vai ser a posi��o do n�mero no vetor que se iguala a busca
		}
	}
	if (achei == -1) {
		printf("Se fudeu!!");
	} else {
		printf("Achei! Na posicao %d", achei);
	}
}
