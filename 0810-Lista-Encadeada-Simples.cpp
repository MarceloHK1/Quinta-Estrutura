#include <stdio.h>
#include <stdlib.h>

struct no {											//Declaração 
	int numero;
	struct no *proximo;									//Proximo número do nó (ponteiro proximo)
};

struct no *cabeca = NULL;									//Número cabeça do nó (ponteiro apontando para nada)

void inserir(int parametroNumero) {								//Função void(retornar nada) que insere números no nó
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));				//malloc = abre o espaço de memória para o ponteiro do tamanho do nó
	novoNo -> numero = parametroNumero;							//adiciona o valor ao número do ponteiro
	novoNo -> proximo = NULL;								//adiciona o valor ao próximo número do nó
	
	if (cabeca == NULL) {									//se a lista estiver vazia
		cabeca = novoNo;								//adiciona o ponteiro cabeca na lista (simples)
	} else {										//se a lista já tem algum nó (o cabeca não muda)
		struct no *ponteiro;
		
		ponteiro = cabeca;								//variavel ponteiro apontando para o mesmo lugar que o ponteiro cabeca aponta
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;						//aponta para o próximo número da lista, caso o elemento próximo não for nulo
		}
		ponteiro -> proximo = novoNo;							//adiciona o novoNo para o ponteiro proximo (finalmente)
	}
}

void imprimir() {										//funcao para imprimir
	struct no *ponteiro;
	
	ponteiro = cabeca;
	while (ponteiro != NULL) {								//enquanto ainda existir um próximo nó ele imprime o atual
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

void remover(int parametroNumero) {								//função para remover um nó da lista
	struct no *ponteiroExcluir;
	struct no *ponteiroAnterior;
	
	if (cabeca -> numero == parametroNumero) {						//caso fácil de remover o primeiro nó da lista
		ponteiroExcluir = cabeca;							//aponta para o primeiro
		cabeca = cabeca -> proximo;							//aponta para o proximo
		free(ponteiroExcluir);								//remove o primeiro
	} else {										//caso difícil de remover no meio da lista
		ponteiroAnterior = cabeca;							//aponta para o primeiro
		while ((ponteiroAnterior -> proximo != NULL) && 
			(ponteiroAnterior -> proximo -> numero != parametroNumero)){		//proximo número for diferente do elemento remover
			
			ponteiroAnterior = ponteiroAnterior -> proximo; 			//cabeca vira o proximo
		}
		if (ponteiroAnterior -> proximo != NULL) {					//se o último elemento for não nulo
			ponteiroExcluir = ponteiroAnterior -> proximo;				//ponteiroexcluir vira o proximo 
			ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;		//o proximo vira o proximo do ponteiroexcluir
			free(ponteiroExcluir);
		}				
	}
}



int main() {											//funçao principal
	int i;
	
	for (i=0; i<10; i++){
		inserir(i);
	}	
	imprimir();
	printf("===========================\n");
	
	remover(2);
	remover(3);
	remover(9);
	remover(8);
	imprimir();
}
