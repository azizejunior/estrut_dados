#include<stdio.h>
#include<stdlib.h>

/**********************************************************************
	EX06-3 (Construa uma sub-rotina que concatene duas listas
	encadeadas simples que serão passadas como parâmetros;.)
***********************************************************************/

typedef struct nodo { 
	char *data; 
	struct nodo *link; 
}*ptr;

void insere(ptr *lista, char *elem) { 
	ptr aux = malloc(sizeof(struct nodo)); 
	aux->data = elem; 
	aux->link = *lista; 
	*lista = aux; 
}

void concatena(ptr *lista1, ptr *lista2){
	ptr aux; 
	aux = *lista1;
	while(aux != NULL){
		if(!aux->link){
			aux->link = *lista2;
			break;
		}
		aux = aux->link;
	}
}

void exibe(ptr lista) { 
	while (lista != NULL) { 
		printf("%s", lista->data); 
		lista = lista->link; 
	} 
}	

int main(void){
	ptr lista1 = NULL;
	ptr lista2 = NULL;	
	insere(&lista2,"10)  ");
	insere(&lista2,"9 -> ");
	insere(&lista2,"8 -> ");
	insere(&lista2,"7 -> ");
	insere(&lista2,"6 -> ");
	insere(&lista1,"5 -> ");
	insere(&lista1,"4 -> ");
	insere(&lista1,"3 -> ");	
	insere(&lista1,"2 -> ");	
	insere(&lista1,"(1 -> ");	
	
	printf("Conteudo da Lista 1: \n");
	exibe(lista1);
	printf("\n\n");
	printf("Conteudo da Lista 2: \n");
	exibe(lista2);
	printf("\n\n");
	concatena(&lista1, &lista2);
	printf("Conteudo da Lista Concatenada: \n");
	exibe(lista1);
	printf("\n\n");

	return 0;
}
