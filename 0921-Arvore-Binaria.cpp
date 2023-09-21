//�rvore cuja ordem � igual a 2

//Se a altura � h, no m�nimo h n�s e no m�ximo 2^h-1 n�s.
//Se a �rvore tem n>=1 n�s, a altura � no m�nimo log(n+1) e no m�ximo n.

//Travessia: pr�-ordem (raiz, todo mundo da esquerda e depois todo mundo da direita)
//Travessia: em-ordem (todo mundo da esquerda, raiz e todo mundo da direita)
//Travessia: p�s-ordem (todo mundo da esquerda, todo mundo da direita e raiz)

//EXEMPLO
//pre: A,B,D,H,I,E,C,F,J,K,G,L
//em:  H,D,I,B,E,A,J,F,K,C,G,L
//pos: H,I,D,E,B,J,K,F,L,G,C,A

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

struct no *inserir (struct no *raiz, int number){
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		
		raiz -> numero = number;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else {
		int sorteio = (rand() % 2);
		
		if (sorteio == 0) {
			raiz -> esquerda = inserir(raiz -> esquerda, number);
		} else if (sorteio == 1) {
			raiz -> direita = inserir(raiz -> direita, number);
		}
	}
	return raiz;
};

void navegarPreOrdem(struct no *raiz) {
	if (raiz != NULL) {
		printf("%d\t", raiz -> numero);
		navegarPreOrdem(raiz -> esquerda);
		navegarPreOrdem(raiz -> direita);
	}
}

void navegarEmOrdem(struct no *raiz) {
	if (raiz != NULL) {
		navegarEmOrdem(raiz -> esquerda);	
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
	}	
}

void navegarPosOrdem(struct no *raiz) {
	if (raiz != NULL) {
		navegarPosOrdem(raiz -> esquerda);
		navegarPosOrdem(raiz -> direita);
		printf("%d\t", raiz -> numero);
	}
}

int main() {
	struct no *raiz = NULL;
	time_t t;
	srand((unsigned) time(&t));
		
	int i = 0;
	for (i=0; i<10; i++) {
		raiz = inserir(raiz, i);
	}
	
	printf("\n================= PRE-ORDEM =====================\n");
	navegarPreOrdem(raiz);
	printf("\n================== EM-ORDEM =====================\n");
	navegarEmOrdem(raiz);
	printf("\n================= POS-ORDEM =====================\n");
	navegarPosOrdem(raiz);
}
