/* Exercicio EX05a - Pilha com alocação dinamica (Listas encadeadas) */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char *data;
	struct Node *next;
}Node;

Node *create(){
	Node *newNode = (Node*)malloc(sizeof(Node*));
    if(!newNode){
        printf("Alocacao de memoria mal sucedida.");
        exit(1);
	}
	newNode -> next = NULL;
    return	newNode;
}

char *topo(Node *top){
	if(isEmpty(top)){
		printf("Underflow");
		abort();
	}
	return top->data;
}

int isEmpty(Node *top){
	return top == NULL;
}

void push(Node **top, char *s){
	Node *temp = create();
	temp->data = s;
	temp->next = *top;
	*top = temp;	
}

char *pop(Node **top){
	if(isEmpty(*top)){
		printf("Underflow");
		exit(1);
	}
	Node *temp = *top;
	*top = (*top)->next;
	char *s = temp->data;
	free(temp);
	return s;
}

void destroy(Node **top){
	Node *temp;
	while(*top != NULL){
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

void printPilha(Node *top){
	if (!isEmpty(top)) {
		while(top!=NULL){
			printf("%s -> ", top->data);
			top = top->next;
		}
		printf("NULL\n\n");
	} 
	else{
		printf("\tPilha esvaziada com sucesso!\n\n");
	}
}

int main(void){

	Node *top = NULL;
	push(&top, "Primeiro");
	push(&top, "Segundo");
	push(&top, "Terceiro");
	push(&top, "Quarto");
	push(&top, "Quinto");
	printf("\n\tImpressao da Lista encadeada: ");
	printPilha(top);
	printf("\tTopo da Pilha: %s\n\n", topo(top));
	printf("\tPop: %s\n", pop(&top));
	printf("\tPop: %s\n", pop(&top));
	printf("\tPop: %s\n", pop(&top));
	printf("\n\tImpressao da Lista encadeada apos pop: ");
	printPilha(top);
	printf("\tTopo da Pilha: %s\n", topo(top));
	printf("\n\tEsvaziando a Lista...\n\n");
	destroy(&top);
	printPilha(top);

	return 0;
}
