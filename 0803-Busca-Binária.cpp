//Busca Binária//


#include <stdio.h>

int vetor[100000];
int i = 0;
int busca = 0;																	//número procurado
int inicio = 0;
int fim = 0;
int meio = 0;


int main() {
	
	for (i = 0; i<100000; i++) {												//inicializaçao da memória para adicionar números no vetor
		vetor[i] = i;															//gera uma lista com os números iguais às suas posições
	}																			//pega um número aleatório infinito e pega o resto desse n pela divisão por 100000
	
	printf("Digite um valor para ser procurado: ");								//pede um valor a ser procurado
	scanf("%d", &busca);														//coloca esse valor na variavel busca
	
	inicio = 0;
	fim = 99999;
	while (fim >= inicio) {
		meio = (inicio + fim) / 2;												//define o meio
		if (meio == busca) {	
			printf("Achei!! Na posicao %d", meio);
			return 0;
		} else if (vetor[meio] > busca) {										//se o numero procurado for menor que o meio, se percorre até o meio(fim vira meio - 1)
			fim = (meio - 1);
		} else {																//se o numero procurado for maior que o meio, se percorre a partir do meio (inicio vira meio + 1)
			inicio = (meio + 1);
		}
	}
	printf("Se fudeu!!");
}
