#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL;

void push(int x) {															//função para inserir um nó
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = x;
	novoNo -> proximo = NULL;
	
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

int top() {																	//para verificar o primeiro no da pilha
	int retorno = -1;
	
	if (cabeca != NULL) {
		retorno = cabeca -> numero;
	}
	return retorno;
}

int pop() {																	//funcao para retirar o elemento da pilha
	int retorno = -1;
	if (cabeca != NULL) {
		struct no *excluir = cabeca;
		retorno = cabeca -> numero;
		cabeca = cabeca -> proximo;
		free(excluir);
	}
	return retorno;
}

int main () {
	printf("%d\n", pop());
	printf("===========================\n");
	
	push(1);
	printf("%d\n", pop());
	printf("==========================\n");
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	
	printf("==========================\n");
}

