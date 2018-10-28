#include<stdio.h>
#include<stdlib.h>

/*********************************************************************************
	EX06-4 (Construa uma sub-rotina que retorne a quantidade de
	elementos de uma lista encadeada simples que será passada como parâmetro).
**********************************************************************************/

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

int quantidade(ptr *lista){
	ptr aux; 
	aux = *lista;
	int cont = 0;
	while (aux != NULL){
		cont++;
		aux = aux->link;
	}
	return cont;
}

void exibe(ptr lista) { 
	while (lista != NULL) { 
		printf("%s", lista->data); 
		lista = lista->link; 
	} 
}	

int main(void){
	ptr lista = NULL;
	
	insere(&lista,"10)  ");
	insere(&lista,"9 -> ");
	insere(&lista,"8 -> ");
	//insere(&lista,"7 -> ");
	//insere(&lista,"6 -> ");
	//insere(&lista,"5 -> ");
	//insere(&lista,"4 -> ");
	//insere(&lista,"3 -> ");	
	//insere(&lista,"2 -> ");	
	//insere(&lista,"(1 -> ");	
	
	printf("Conteudo da Lista: \n\n");
	exibe(lista);
	printf("\n\nQuantidade de itens da lista: %d\n\n", quantidade(&lista));
	
	return 0;
}
