#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int x) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = x;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		cabeca = novoNo;
	} else {
		struct no *ponteiro = cabeca;
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
	}
}

int remover() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		} else {
			retorno = cabeca -> numero;	
			free(cabeca);
			cabeca = cabeca -> proximo;
		}
	}
	return retorno;
}

int main() {
	printf("%d\n", remover());
	printf("===========================\n");
	
	inserir(1);
	printf("%d\n", remover());
	printf("==========================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	
	printf("==========================\n");
}
