#include <stdio.h>
#include <stdlib.h>

//Declara��o de constantes
const int MODULO = 16;

//Declara��o de estruturas
struct no {
	int numero;
	struct no *proximoNo;
};

struct diretor {
	int resto;
	struct diretor *proximoDiretor;
	struct no *proximoNo;	
};

//Declara��o de v�riaveis
struct diretor *cabeca = NULL;

//Fun��o que procura um diretor
struct diretor *procurarDiretor(int resto) {						//retorna um ponteiro para diretor
	struct diretor *ponteiro = cabeca;
	while ((ponteiro != NULL) && (ponteiro -> resto != resto)) {
		ponteiro = ponteiro -> proximoDiretor;
	}
	if (ponteiro == NULL) {											//n�o foi encontrado o diretor com valor igual ao procurado(lista vazia)
		ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
		ponteiro -> resto = resto;									//resto do ponteiro vira o valor
		ponteiro -> proximoNo = NULL;								//ponteiro aponta para nada
		ponteiro -> proximoDiretor = cabeca;						//proximoDiretor � cabeca(nada)
		cabeca = ponteiro;											//cabeca vira o ponteiro
	}
	return ponteiro;
}

//Fun��o que insere um n� na matriz esparsa
void inserir(int numero) {
	struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;				//o novo n� aponta para o proximo do diretor
	ponteiroDiretor -> proximoNo = novoNo;							//o diretor aponta para o novo n�s
}

//Fun��o que imprime a matriz esparsa
void imprimir() {
	struct diretor *ponteiroDiretor = cabeca;						//sendo a cabe�a
	printf("============ Matriz Esparsa ================\n");
	
	while (ponteiroDiretor != NULL) {								//se cabeca n�o for nula
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;		//o n�  vira o pr�ximo n� desse mesmo diretor
		printf("%d:\t", ponteiroDiretor -> resto);					//printa o resto/diretor
		
		while (ponteiroNo != NULL) {								//enquanto o no n�o for nulo
			printf("%d\t", ponteiroNo -> numero);					//printa o n�mero do n�
			ponteiroNo = ponteiroNo -> proximoNo;					//passa para o pr�ximo n�
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;			//passa para o pr�ximo diretor
	}
}

//Fun��o que remove
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





