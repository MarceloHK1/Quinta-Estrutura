//Uma �rvore bin�ria � AVL quando a diferen�a de altura entre as sub�rvores esquerda(sae) e direita(sad) de um n� qualquer n�o � superior a 1.
//Os algoritmos de balanceamento de �rvore s�o chamados algoritmos AVL.

//Quando um novo n� � inserido em uma �rvore balanceada, podem ocorrer 3 situa��es:
//		1) Se h(sae) == h(sad), as alturas ser�o diferentes, mas a �rvore continua balanceada;
//		2) Se h(sae) > h(sad), e o n� for inserido na sad, as alturas ficam iguais;
//		3) Se h(sae) < h(sad), e o n� for inserido na sae, o balanceamento fica violado;

//Rota��es para rebalancear:
//		1)Rota���o a esquerda; == a �rvore rubro negro
//		2)Rota��o a direita; == a �rvore rubro negro
//		3)Dupla rota��o a esquerda(esquerda + direita);
//		4)Dupla rota��o a direita(direita + esquerda);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
	int altura;
};

int getAlturaDoNo(struct no *raiz) {			//Retorna a altura do n�
	return (raiz == NULL) ? 0 : raiz -> altura;
}

int getMaximoEntreDoisNumeros(int a, int b) {		//Retorna o maior entre dois n�meros
	return (a > b) ? a : b;
}

int getBalancoDaArvore(struct no *raiz) {		//Retorna o balanceamento da �rvore
	int retorno = 0;
	
	if (raiz != NULL) {
		retorno = (getAlturaDoNo(raiz -> esquerda) - getAlturaDoNo(raiz -> direita));
	}
	
	return retorno;
}

struct no *rotacaoEsquerda(struct no *raiz) {
	struct no *novaRaiz = raiz -> direita;
	struct no *temp = novaRaiz -> esquerda;
	novaRaiz -> esquerda = raiz;
	raiz -> direita = temp;
	
	//Correcao da altura
	raiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> esquerda), getAlturaDoNo(raiz -> direita)) + 1);
	novaRaiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz -> esquerda), getAlturaDoNo(novaRaiz -> direita)) + 1);

	return novaRaiz;
}

struct no *rotacaoDireita(struct no *raiz) {
	struct no *novaRaiz = raiz -> esquerda;
	struct no *temp = novaRaiz -> direita;
	novaRaiz -> direita = raiz;
	raiz -> esquerda = temp;
	
	//Correcao da altura
	raiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> esquerda), getAlturaDoNo(raiz -> direita)) + 1);
	novaRaiz -> altura = (getMaximoEntreDoisNumeros(getAlturaDoNo(novaRaiz -> esquerda), getAlturaDoNo(novaRaiz -> direita)) + 1);

	return novaRaiz;
}

struct no *inserir(struct no *raiz, int number) {
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = number;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		raiz -> altura = 1;
	} else {
		if (raiz -> numero > number) {
			raiz -> esquerda = inserir(raiz -> esquerda, number);
		} else {
			raiz -> direita = inserir(raiz -> direita, number);
		}
	}
	
	//Atualiza��o da altura
	raiz -> altura = (1 + getMaximoEntreDoisNumeros(getAlturaDoNo(raiz -> esquerda), getAlturaDoNo(raiz -> direita)));
	
	//Recupera��o do balan�o da �rvore
	int balanco = getBalancoDaArvore(raiz);
	
	//Rota��es para balancear a �rvore
	if ((balanco > 1) && (number < raiz -> esquerda -> numero)) {		//Esquerda - Esquerda
		raiz = rotacaoDireita(raiz);
	}
	if ((balanco < -1) && (number > raiz -> direita -> numero)) {			//Direita - Direita
		raiz = rotacaoEsquerda(raiz);
	}
	if ((balanco > 1) && (number > raiz -> esquerda -> numero)) {			//Esquerda - Direita
		raiz -> esquerda = rotacaoEsquerda(raiz -> esquerda);
		raiz = rotacaoDireita(raiz);
	}
	if ((balanco < -1) && (number < raiz -> direita -> numero)) {			//Direita - Esquerda
		raiz -> direita = rotacaoDireita(raiz -> direita);
		raiz = rotacaoEsquerda(raiz);
	}
	
	return raiz;
}

void imprimir(struct no *raiz, char *endentacao) {
	if (raiz != NULL) {
		printf("%s%d\n", endentacao, raiz -> numero);	
		
		char *temp = (char *) malloc(1024 * sizeof(char));
		strcpy(temp, endentacao);								
		strcat(temp, "---");									
		
		imprimir(raiz -> esquerda, temp);
		imprimir(raiz -> direita, temp);
	}
}

int main() {
	struct no *raiz = NULL;
	int i = 0;

	for (i=0; i<10; i++) {
		raiz = inserir(raiz, i);
	}

	imprimir(raiz, "");
}

