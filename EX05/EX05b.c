/* Exercicio EX05b - Fila com alocação dinamica (Listas encadeadas) */

#include<stdio.h>
#include<stdlib.h>

//-------------------Definição das estruturas Fila e Nó-------------------------//

typedef struct Node {
	char *data;
    struct Node *next;
}Node;

typedef struct Fila{
	Node *front;
	Node *rear;
}Fila;

//---------------------------------Funções -----------------------------------//

Fila *create(void){
	Fila *f;
	f = (Fila*)malloc(sizeof (Fila*));
	if (!f) 
		exit(1);
	f->front = NULL;
	return f;
}

void store(Fila *f, char *c){
	Node *temp = (Node*)malloc(sizeof (Node*));
	if (!temp)
		exit(1);
	temp->data = c;
	temp->next = NULL;
	if(f->front == NULL)
		f->front = temp;
	else 
		f->rear->next= temp;
	f->rear = temp;
}

char *retrieve(Fila *f){
	char *aux;
	Node *temp;
	temp = f->front;
	if (!temp){
		printf( "Fila vazia");
		exit(1);
	}
	aux = temp->data;
	f->front = temp->next;
	free(temp);
	return aux;
}

int IsEmpty(Fila *f) {
   return f->front == NULL;
}

void destroy(Fila *f){
	Node *temp, *next;
	temp = f->front;
	while (temp != NULL){
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(f);
}

//---------------------------------Função Main-----------------------------------//

int main(void){

	Fila *f = create();
	store(f, "Primeiro");
	store(f, "Segundo");
	store(f, "Terceiro");
	store(f, "Quarto");
	printf("\tProximo da Fila retirado: %s\n\n", retrieve(f));
	printf("\tProximo da Fila retirado: %s\n\n", retrieve(f));
	printf("\tProximo da Fila retirado: %s\n\n", retrieve(f));	
	destroy(f);

	return 0;
}

