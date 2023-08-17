#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL;

void inserir (int numero) {
	struct no *novoNo;
	novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		cabeca = novoNo;
		novoNo -> proximo = cabeca;
	} else {
		struct no *ponteiro;
		
		ponteiro = cabeca;
		while (ponteiro -> proximo != cabeca) {
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
		novoNo -> proximo = cabeca;
	}
}

void imprimir () {
	struct no *ponteiro;
	
	ponteiro = cabeca;
	while (1) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		if (ponteiro == cabeca) {
			break;
		}
	}
	printf("========================\n");
}

void remover (int numero) {
	struct no *ponteiroExcluir;
	struct no *ponteiroAnterior;
	
	if (cabeca -> numero == numero) {
		ponteiroAnterior = cabeca;
		while (ponteiroAnterior -> proximo != cabeca) {
			ponteiroAnterior = ponteiroAnterior -> proximo;
		}
		ponteiroExcluir = cabeca;
		cabeca = cabeca -> proximo;
		ponteiroAnterior -> proximo = cabeca;
		free(ponteiroExcluir);
		
	} else {
		ponteiroAnterior = cabeca;
		while (ponteiroAnterior -> proximo -> numero != numero) {
			ponteiroAnterior = ponteiroAnterior -> proximo;
			if (ponteiroAnterior == cabeca) {
				break;
			}
		}
		if (ponteiroAnterior -> proximo -> numero == numero) {
			ponteiroExcluir = ponteiroAnterior -> proximo;
			ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
			free(ponteiroExcluir);
		}
	}
}

int main () {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	
	imprimir();
	
	remover(1);
	remover(3);
	
	imprimir();
}
