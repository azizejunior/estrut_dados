#include<stdio.h>
#include<stdlib.h>

/**************************************************************************************
	EX06-7 (Construa uma sub-rotina que exiba os elementos de uma lista 
	encadeada simples do último ao primeiro. A lista será passada como parâmetro;.)
***************************************************************************************/

typedef struct nodo { 
	char *data; 
	struct nodo *link; 
} *ptr;

void insere(ptr *lista, char *elem) { 
	ptr aux = malloc(sizeof(struct nodo)); 
	aux->data = elem; 
	aux->link = *lista; 
	*lista = aux; 
}

void exibe(ptr lista) { 
	while (lista != NULL) { 
		printf("%s", lista->data); 
		lista = lista->link; 
	} 
}	

void revPrint(ptr lista){
	if(lista == NULL) return;
	revPrint(lista->link);
	printf("%s", lista->data);	
}	

int main(void){
	ptr lista = NULL;
	insere(&lista,"G -> ");
	insere(&lista,"F -> ");
	insere(&lista,"E -> ");
	insere(&lista,"D -> ");
	insere(&lista,"C -> ");
	insere(&lista,"B -> ");
	insere(&lista,"A. ");	

	printf("Conteudo da Lista antes da funcao: \n\n");
	exibe(lista);
	printf("\n\n");	
	printf("Conteudo da Lista atraves da funcao recursiva : \n\n");	
	revPrint(lista);
	printf("\n\n");

	return 0;
}
