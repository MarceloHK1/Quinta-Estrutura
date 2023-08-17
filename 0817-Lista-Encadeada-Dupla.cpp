#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *anterior;																								//no anterior
	struct no *proximo;																									//no posterior
};

struct no *cabeca = NULL;

void inserir (int numero) {
	struct no *novoNo;
	novoNo = (struct no*) malloc(sizeof(struct no));
	(*novoNo).numero = numero;
	(*novoNo).anterior = NULL;																							//Essa linha e a de baixo executam a mesma coisa
	(*novoNo).proximo = NULL;																							//Essa linha e a de cima executam a mesma coisa
	
	if (cabeca == NULL) {
		cabeca = novoNo;
	} else {
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
		novoNo -> anterior = ponteiro;
	}
}

void imprimir () {
	printf("========================\n");
	
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

void remover (int numero) {
	struct no *ponteiroExcluir = cabeca;
	
	if (cabeca -> numero == numero) {																								//Elemento pra excluir é o primeiro da lista
		cabeca = cabeca -> proximo;
		cabeca -> anterior = NULL;
		free(ponteiroExcluir);
	} else {
		while (ponteiroExcluir != NULL) {
			if (ponteiroExcluir -> numero == numero) {																	//Elemento pra excluir no meio da lista
				if (ponteiroExcluir -> proximo == NULL) {																//Último elemento da lista
					ponteiroExcluir -> anterior -> proximo = NULL;
					free(ponteiroExcluir);
				} else {
					ponteiroExcluir -> anterior -> proximo = ponteiroExcluir -> proximo; 								//a seta que aponta pro proximo do anterior aponta para o proximo do atual (pula 1 no)
					ponteiroExcluir -> proximo -> anterior = ponteiroExcluir -> anterior;								//a seta que aponta pro anterior do proximo aponta para o anterior do atual (pula 1 no)
					free(ponteiroExcluir);
				}
			}
			ponteiroExcluir = ponteiroExcluir -> proximo;	
		}
	}
}


int main () {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	
	imprimir();

	remover(1);
	remover(3);
	remover(5);
	
	imprimir();
}





