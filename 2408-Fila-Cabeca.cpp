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
	
	novoNo -> proximo = cabeca;												//proximo de x vira cabeca
	cabeca = novoNo;														//cabeca vira x
}

int remover() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {									//so tem um no na fila
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		} else {															//mais de um nó na fila
			struct no *ponteiro = cabeca;
			
			while (ponteiro -> proximo -> proximo != NULL) {
				ponteiro = ponteiro -> proximo;
			}
			retorno = ponteiro -> proximo -> numero;
			free(ponteiro -> proximo);
			ponteiro -> proximo = NULL;
		}
	}	
	return retorno;
}

int main () {
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
	
	
	
	
	
	
	
	
	
	
	

