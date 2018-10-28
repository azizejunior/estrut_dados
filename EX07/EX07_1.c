#include<stdio.h>
#include<stdlib.h>
/*
Ex1.Construa uma sub-rotina que retorne o maior elemento de uma árvore de busca binária passada como parâmetro;
			(ordenada)	
*/
typedef struct nodo { 
	int data; 
	struct nodo *linkE, *linkD; 
} nodo; 

typedef nodo* ptr;

void create(ptr *raiz) { 
	*raiz = NULL; 
}

int isempty(ptr raiz) { 
	return raiz == NULL; 
}

void inclui(ptr *raiz, int x) { 
	if (isempty(*raiz)) { 
		*raiz = malloc(sizeof(nodo)); 
		(*raiz)->data = x; 
		(*raiz)->linkE = (*raiz)->linkD = NULL; 
	} 
	else if (x > (*raiz)->data) 
		inclui(&(*raiz)->linkD, x); 
	else 
		inclui(&(*raiz)->linkE, x);
}

void destroy(ptr *raiz) { 
	if (!isempty(*raiz)) { 
		destroy(&(*raiz)->linkE); 
		destroy(&(*raiz)->linkD); 
		free(*raiz); *raiz = NULL; 
	} 
}

int maiorOrd(ptr raiz){
	if(!isempty(raiz)){	
		if(raiz->linkD != NULL)
			return maiorOrd(raiz->linkD);
		else
			return raiz->data;
	}		
}

int main(void){
	ptr raiz;
	create(&raiz);
	inclui(&raiz, 8);
	inclui(&raiz, 4);
	inclui(&raiz, 12);
	inclui(&raiz, 2);
	inclui(&raiz, 6);
	inclui(&raiz, 10);
	inclui(&raiz, 14);
	inclui(&raiz, 1);
	inclui(&raiz, 3);
	inclui(&raiz, 5);
	inclui(&raiz, 7);
	inclui(&raiz, 9);
	inclui(&raiz, 11);
	inclui(&raiz, 13);
	inclui(&raiz, 15);
	printf("\n\nMaior elemento: %d", maiorOrd(raiz));	
	destroy(&raiz);
	printf("\n\n");
	
	return 0;
}
