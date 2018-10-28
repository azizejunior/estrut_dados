#include<stdio.h>
#include<stdlib.h>

/****************************************************************************
	EX06-5 (Altere a sub-rotina anterior para que receba como parâmetro 
	uma lista encadeada circular e retorne sua quantidade de elementos).
*****************************************************************************/

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

int quantCirc(ptr *lista){
	ptr aux; 
	aux = *lista;
	int cont = 0;
	while (aux->link != *lista){
		cont++;
		aux = aux->link;
	}
	return cont + 1;
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
	listaCirc(&lista);
	printf("\n\nQuantidade de itens da lista: %d\n\n", quantCirc(&lista));
	
	return 0;
}
