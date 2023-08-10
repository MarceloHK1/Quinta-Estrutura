#include <stdio.h>
#include <stdlib.h>

struct no {																//Declara��o 
	int numero;
	struct no *proximo;													//Proximo n�mero do n� (ponteiro proximo)
};

struct no *cabeca = NULL;												//N�mero cabe�a do n� (ponteiro apontando para nada)

void inserir(int parametroNumero) {										//Fun��o void(retornar nada) que insere n�meros no n�
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));		//malloc = abre o espa�o de mem�ria para o ponteiro do tamanho do n�
	novoNo -> numero = parametroNumero;									//adiciona o valor ao n�mero do ponteiro
	novoNo -> proximo = NULL;											//adiciona o valor ao pr�ximo n�mero do n�
	
	if (cabeca == NULL) {												//se a lista estiver vazia
		cabeca = novoNo;												//adiciona o ponteiro cabeca na lista (simples)
	} else {															//se a lista j� tem algum n� (o cabeca n�o muda)
		struct no *ponteiro;
		
		ponteiro = cabeca;												//variavel ponteiro apontando para o mesmo lugar que o ponteiro cabeca aponta
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;								//aponta para o pr�ximo n�mero da lista, caso o elemento pr�ximo n�o for nulo
		}
		ponteiro -> proximo = novoNo;									//adiciona o novoNo para o ponteiro proximo (finalmente)
	}
}

void imprimir() {														//funcao para imprimir
	struct no *ponteiro;
	
	ponteiro = cabeca;
	while (ponteiro != NULL) {											//enquanto ainda existir um pr�ximo n� ele imprime o atual
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

void remover(int parametroNumero) {										//fun��o para remover um n� da lista
	struct no *ponteiroExcluir;
	struct no *ponteiroAnterior;
	
	if (cabeca -> numero == parametroNumero) {							//caso f�cil de remover o primeiro n� da lista
		ponteiroExcluir = cabeca;										//aponta para o primeiro
		cabeca = cabeca -> proximo;										//aponta para o proximo
		free(ponteiroExcluir);											//remove o primeiro
	} else {															//caso dif�cil de remover no meio da lista
		ponteiroAnterior = cabeca;											//aponta para o primeiro
		while ((ponteiroAnterior -> proximo != NULL) && 
			(ponteiroAnterior -> proximo -> numero != parametroNumero)){	//proximo n�mero for diferente do elemento remover
			
			ponteiroAnterior = ponteiroAnterior -> proximo; 				//cabeca vira o proximo
		}
		if (ponteiroAnterior -> proximo != NULL) {							//se o �ltimo elemento for n�o nulo
			ponteiroExcluir = ponteiroAnterior -> proximo;					//ponteiroexcluir vira o proximo 
			ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;		//o proximo vira o proximo do ponteiroexcluir
			free(ponteiroExcluir);
		}				
	}
}



int main() {															//fun�ao principal
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
