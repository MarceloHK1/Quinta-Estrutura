//Algoritmo para manter a árvore balanceada
//Uma árvore rubro-negra continua sendo uma árvore de busca

//Todo nó é ou vermelho ou preto
//A raiz é preta
//As folhas(nós da extremidade) são NULL e tem cor preta
//Se um nó é vermelho, seus dois filhos são pretos
//		E ele é o filho esquerdo do seu pai(esquerdista)
//Em cada nó, todo caminho dele para uma de suas folhas descendentes tem a mesma quantidade de nós pretos
//		Não se conta o próprio nó
//		Denomina-se a altura-negra do nó

//Operações
//--Rotação à esquerda
//	A(alfa a esquerda) e x(Beta a esquerda e teta a direita) a direita do A
//	Vira X(teta a direita) e A(alfa a esquerda e beta a direita) a esquerda do X
//	As cores são trocadas

//--Rotação à direita
//	A(teta a direita) e X(alfa a esquerda e beta a direita) a esquerda de A
//	Vira X(alfa a esquerda) e A(beta a esquerda e teta a direita) a direita de X
//	As cores são trocadas

//--Subida do vermelho
//	Apenas troca as cores dos nós

//--Inserção do elemento
//	Igual a árvore de busca(novo nó sempre vermelho)
//	Correções precisam ser feitas
//		-Não pode filho direito vermelho e filho esquerdo preto(Rotacionar a esquerda)
//		-Não pode neto esquerdo vermelho de filho vermelho(Rotacionar a direita)	
//		-Não pode ambos filhos vermelhor(Subir vermelho)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
	int cor;		//0:preto e 1:vermelho
};

struct no *rotacionaEsquerda(struct no *raiz) {
	struct no *temp = raiz -> direita;		//aponta para o elemento da direita da raiz
	raiz -> direita = temp -> esquerda;		//raiz direita aponta para o elemento da esquerda de temp
	temp -> esquerda = raiz;				//o que apontava para o elemento da esquerda de temp, aponta para a raiz
	
	//correcao da cor
	temp -> cor = raiz -> cor;
	raiz -> cor = 1;
	
	return temp;
}

struct no *rotacionaDireita(struct no *raiz) {		//igual o da esquerda, mas trocando as direções
	struct no *temp = raiz -> esquerda;
	raiz -> esquerda = temp -> direita;
	temp -> direita = raiz;
	
	temp -> cor = raiz -> cor;
	raiz -> cor = 1;
	
	return temp;
}

void subirVermelho (struct no *raiz) {
	raiz -> cor = 1;
	raiz -> esquerda -> cor = 0;
	raiz -> direita -> cor = 0;
}

int vermelho(struct no *raiz) {
	return ((raiz==NULL) ? 0 : raiz -> cor);	
}

struct no *inserir(struct no *raiz, int number) {
	if (raiz == NULL) {
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = number;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		raiz -> cor = 1;
	} else {
		if (raiz -> numero > number) {
			raiz -> esquerda = inserir(raiz -> esquerda, number);
		} else {
			raiz -> direita = inserir(raiz -> direita, number);
		}
	}
	
	if ((! vermelho(raiz -> esquerda)) && (vermelho(raiz -> direita))) {
		raiz = rotacionaEsquerda(raiz);
	} 
	if ((vermelho(raiz -> esquerda)) && (vermelho(raiz -> esquerda -> esquerda))) {
		raiz = rotacionaDireita(raiz);
	}
	if ((vermelho(raiz -> direita)) && (vermelho(raiz -> esquerda))) {
		subirVermelho(raiz);
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
	int i=0;
	
	for (i=0; i<1000; i++) {
		raiz = inserir(raiz, i);
	}	
	imprimir(raiz, "");
}
