#include<stdio.h>
#include<stdlib.h>

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

int maiorNO(ptr raiz){
	//if(!isempty(raiz)){
		
		int maior, aux, esq, dir;
		aux = raiz->data;
		maior = aux;	
		
		if(raiz->linkE != NULL){
			esq = maiorNO(raiz->linkE);
			if(esq > maior)
				maior = esq;
		}
		else if(raiz->linkD != NULL){
			dir = maiorNO(raiz->linkD);
			if(dir > maior)
				maior = dir;
		}
		return maior;		
	//}
	//else
		//printf("\nArvore Vazia\n");	
}

int main(void){
	ptr raiz;
	create(&raiz);
	inclui(&raiz, 17);
	inclui(&raiz, 10);
	inclui(&raiz, 20);
	inclui(&raiz, 5);
	//inclui(&raiz, 1);
	//inclui(&raiz, 9);
	//inclui(&raiz, 55);
	//inclui(&raiz, 15);
	//inclui(&raiz, 25);
	//inclui(&raiz, 6);
	//inclui(&raiz, 18);
	//inclui(&raiz, 9);
	//inclui(&raiz, 100);
	//inclui(&raiz, 21);
	//inclui(&raiz, 27);
	printf("\n\nMaior elemento de uma arvore nao ordenada: %d", maiorNO(raiz));	
	destroy(&raiz);
	printf("\n\n");
	
	return 0;
}
