#include <stdio.h>
#include <stdlib.h>

//Declaração de constantes
const int MODULO = 16;

//Declaração de estruturas
struct no {
	int numero;
	struct no *proximoNo;
};

struct diretor {
	int resto;
	struct diretor *proximoDiretor;
	struct no *proximoNo;	
};

//Declaração de váriaveis
struct diretor *cabeca = NULL;

//Função que procura um diretor
struct diretor *procurarDiretor(int resto) {						//retorna um ponteiro para diretor
	struct diretor *ponteiro = cabeca;
	while ((ponteiro != NULL) && (ponteiro -> resto != resto)) {
		ponteiro = ponteiro -> proximoDiretor;
	}
	if (ponteiro == NULL) {											//não foi encontrado o diretor com valor igual ao procurado(lista vazia)
		ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
		ponteiro -> resto = resto;									//resto do ponteiro vira o valor
		ponteiro -> proximoNo = NULL;								//ponteiro aponta para nada
		ponteiro -> proximoDiretor = cabeca;						//proximoDiretor é cabeca(nada)
		cabeca = ponteiro;											//cabeca vira o ponteiro
	}
	return ponteiro;
}

//Função que insere um nó na matriz esparsa
void inserir(int numero) {
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;				//o novo nó aponta para o proximo do diretor
	ponteiroDiretor -> proximoNo = novoNo;							//o diretor aponta para o novo nós
}

//Função que imprime a matriz esparsa
void imprimir() {
	struct diretor *ponteiroDiretor = cabeca;						//sendo a cabeça
	printf("============ Matriz Esparsa ================\n");
	
	while (ponteiroDiretor != NULL) {								//se cabeca não for nula
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;		//o nó  vira o próximo nó desse mesmo diretor
		printf("%d:\t", ponteiroDiretor -> resto);					//printa o resto/diretor
		
		while (ponteiroNo != NULL) {								//enquanto o no não for nulo
			printf("%d\t", ponteiroNo -> numero);					//printa o número do nó
			ponteiroNo = ponteiroNo -> proximoNo;					//passa para o próximo nó
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;			//passa para o próximo diretor
	}
}

//Função que remove
void remover(int numero) {
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	
	struct no *ponteiroExcluir;
	struct no *ponteiroAnterior;
	
	if (ponteiroDiretor -> proximoNo -> numero == numero) {
		ponteiroExcluir = ponteiroDiretor -> proximoNo;
		ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
		free(ponteiroExcluir);
	} else {
		ponteiroAnterior = ponteiroDiretor -> proximoNo;
		while ((ponteiroAnterior -> proximoNo != NULL) && (ponteiroAnterior -> proximoNo -> numero != numero)) {
			ponteiroAnterior = ponteiroAnterior -> proximoNo;
		}
		if (ponteiroAnterior -> proximoNo != NULL) {
			ponteiroExcluir = ponteiroAnterior -> proximoNo;
			ponteiroAnterior -> proximoNo = ponteiroExcluir -> proximoNo;
			free(ponteiroExcluir);
		}
	}
}

int main() {
	int i = 0;
	for (i=0; i<100; i++) {
		inserir(i);
	}

	imprimir();
	remover(0);
	imprimir();
}





