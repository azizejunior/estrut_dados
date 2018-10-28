#include<stdio.h>
#include<stdlib.h>

/**********************************************************************
	EX06-2 (Construa uma sub-rotina que transforme uma 
	lista encadeada simples em uma lista encadeada circular. 
	A lista será passada como parâmetro.)
***********************************************************************/

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

void listaCirc(ptr *lista){
	ptr aux; 
	aux = *lista;
	if(!aux->link)
		aux->link = *lista;
	else{
		while (aux->link != NULL){
			if(!aux->link->link){
				aux->link->link = *lista;
				return;
			}
			else
				aux = aux->link;
		}
	}
}

void exibe(ptr lista) { 
	while (lista != NULL) { 
		printf("%s", lista->data); 
		lista = lista->link; 
	} 
}	

void exibeListaCirc(ptr lista) { 
	int i = 0;
	while (i < 15) { 
		printf("%s", lista->data); 
		lista = lista->link;
		i++; 
	} 
}	

int main(void){
	ptr lista = NULL;
	insere(&lista,"5)  ");
	insere(&lista,"4 -> ");
	insere(&lista,"3 -> ");	
	insere(&lista,"2 -> ");	
	insere(&lista,"(1 -> ");	
	exibe(lista);
	printf("\n\n");
	listaCirc(&lista);
	exibeListaCirc(lista);
	printf("\n\n");
	return 0;
}
