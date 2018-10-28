#include<stdio.h>
#include<stdlib.h>

/**********************************************************************
	EX06-1 (Construa uma sub-rotina que remova a duplicidade
	de elementos de uma lista ordenada passada como parâmetro.)
***********************************************************************/

typedef struct nodo { 
	char *data; 
	struct nodo *link; 
} *ptr;

void insere(ptr *list, char *elem) { 
	printf("\nDentro da funcao\n\n"); 
	printf("endereco de &list: %X\n", &list);
	printf("conteudo de list: %X\n", list);
	printf("conteudo de *list: %X\n", *list);
	ptr aux = malloc(sizeof(struct nodo)); 
	printf("endereco de &aux: %X\n", &aux);
	printf("conteudo de aux: %X\n", aux);
	printf("conteudo de &(aux)->data: %X\n", &(aux)->data);
	printf("conteudo de &(aux)->link: %X\n", &(aux)->link);
	printf("conteudo de *aux->data: %X\n", *aux->data);
	printf("conteudo de *aux->link: %X\n", *aux->link);	
	aux->data = elem; 
	aux->link = *list; 
	*list = aux;
	printf("\nApos a atribuicao\n\n"); 
	printf("conteudo de *list: %X\n", *list);
	printf("conteudo de *aux->data: %c\n", *aux->data);
	printf("conteudo de aux->link: %X\n", aux->link);	
}

void remDuplic(ptr *lista){
	ptr aux; 
	aux = *lista;	
	while (aux->link != NULL) { 
		if(aux->data == aux->link->data){
			ptr temp; 
			temp = aux->link;
			aux->link = aux->link->link;
			free(temp);
		}
		else
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
	ptr lista = NULL;
	printf("tamanho de ptr: %d\n\n", sizeof(ptr));
	printf("endereco de lista: %X\n\n", &lista);
	printf("conteudo de lista: %X\n\n", lista);	
	insere(&lista,"G. ");	
	printf("\n\nconteudo de lista apos a rotina: %X\n", lista);	
	insere(&lista,"F -> ");
	printf("\n\nconteudo de lista apos a rotina: %X\n", lista);	
	//printf("conteudo de ptr: %X\n\n", &lista);
	//insere(&lista,"E -> ");
	//printf("conteudo de ptr: %X\n\n", &lista);
	//insere(&lista,"E -> ");
	//printf("conteudo de ptr: %X\n\n", &lista);
	//insere(&lista,"D -> ");
	//printf("conteudo de ptr: %X\n\n", &lista);
	//insere(&lista,"D -> ");
	//insere(&lista,"D -> ");
	//insere(&lista,"D -> ");
	//insere(&lista,"D -> ");
	//insere(&lista,"C -> ");
	//insere(&lista,"C -> ");
	//insere(&lista,"C -> ");
	//insere(&lista,"C -> ");
	//insere(&lista,"B -> ");
	//insere(&lista,"B -> ");
	//insere(&lista,"B -> ");
	//insere(&lista,"A -> ");
	//insere(&lista,"A -> ");	
	//insere(&lista,"A -> ");	
	//insere(&lista,"A -> ");	
	//exibe(lista);
	//printf("\n");
	//printf("\n");
	//remDuplic(&lista);
	//exibe(lista);
	//printf("\n");

	return 0;
}
