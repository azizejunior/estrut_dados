#include<stdio.h>
#include<stdlib.h>

/*********************************************************************************************************
	EX06-9 (Construa uma sub-rotina que crie e retorne uma nova lista encadeada gerada através da 
	intercalação crescente dos elementos de duas listas encadeadas ordenadas passadas como parâmetros)
**********************************************************************************************************/

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

void exibe(ptr lista){ 
	while (lista != NULL){ 
		printf("%s", lista->data); 
		lista = lista->link; 
	} 
}

void recExibe(ptr lista){
	if(lista == NULL) return;
	recExibe(lista->link);
	printf("%s", lista->data);	
}	

ptr ordenaLista(ptr lista1, ptr lista2){ 
	ptr aux = NULL;
	while(lista1 != NULL && lista2 != NULL){
		if(lista1->data < lista2->data){
			insere(&aux, lista1->data);			
			lista1 = lista1->link;
		}
		else{
			insere(&aux, lista2->data); 
			lista2 = lista2->link;
		}
	}
	while(lista1 != NULL){
		insere(&aux, lista1->data);
		lista1 = lista1->link;
	}
	while(lista2 != NULL){
		insere(&aux, lista2->data);
		lista2 = lista2->link;
	}
	return aux;
}

int main(void){

	ptr lista1 = NULL;
	ptr lista2 = NULL;
	ptr lista3 = NULL;

	insere(&lista2,"10 )");
	insere(&lista1,"9 -> ");
	insere(&lista2,"8 -> ");
	insere(&lista1,"7 -> ");
	insere(&lista2,"6 -> ");
	insere(&lista1,"5 -> ");
	insere(&lista2,"4 -> ");
	insere(&lista1,"3 -> ");	
	insere(&lista2,"2 -> ");	
	insere(&lista1,"( 1 -> ");	

	printf("Conteudo da Lista 1: \n\n");
	exibe(lista1);
	printf("\n\nConteudo da Lista 2: \n\n");
	exibe(lista2);
	lista3 = ordenaLista(lista1, lista2);
	printf("\n\nConteudo da nova lista concatenada: \n\n");
	recExibe(lista3);
	printf("\n\n");
	
	return 0;
}
