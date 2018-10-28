/* Exercicio EX05b - Deque com alocação dinamica (Listas encadeadas) */

#include<stdio.h>
#include<stdlib.h>

//-------------------Definição das estruturas Deque e Nó-------------------------//

typedef struct Node {
	char *data;
    struct Node *prev;
	struct Node *next;
}*Node;

typedef struct Deque{
	Node left, right;
}Deque;

//---------------------------------Funções -----------------------------------//

void create(Deque d){	
	d->left = d->right = NULL;		
}

int isEmpty(Deque *d) {
    return !d->left;
}

void store(Deque d, char *s, char lado){	
	if(isEmpty(d)){
		d->left = malloc(sizeof(struct Node));
		d->left->data = s;
		d->right = d->left;
	}
	else if(lado == 'e'){
		d->left->prev = malloc(sizeof(struct Node));
		d->left->prev->data = s;
		d->left->prev->prev = NULL;
		d->left->prev->next = d->left;
		d->left = d->left->prev;
	}	
	else{
		d->right->next = malloc(sizeof(struct Node));
		d->right->next->data = s;
		d->right->next->next = NULL;
		d->right->next->prev = d->right;
		d->right = d->right->next;
	}	
}

char *retrieve(Deque d, char lado){	
	char *c;
	Node ptr = malloc(sizeof(Node));
    if (isEmpty(d)) {
        printf("\n\n\tUnderflow\n\n");
        abort();
    }
	else if(lado == 'e'){
		c = d->left->data;		
		ptr = d->left;
		d->left = ptr->next;	
	}
	else{
		c = d->right->data;
		ptr = d->right;
		d->right = ptr->prev;
	}
	free(ptr);	
	if (d->right == NULL)
		d->left = NULL;
	return c;	
}

void destroy(Deque *d) {
    while (d->left != NULL) {
        Node temp = d->left;
        d->left = temp->next;
        free(temp);
    }
    d->right = d->left;
}

void exibe(Deque *d){ 
	while (d->left->next) { 
		printf("%s -> ", d->left->data); 
		d->left = d->left->next; 
	} 
}	

//---------------------------------Função Main-----------------------------------//

int main(void){

	Deque d;
	create(d);

	store(d, "1 E", 'e');
	store(d, "2 D", 'd');
	store(d, "3 E", 'e');
	store(d, "4 D", 'd');
	store(d, "5 E", 'e');
	store(d, "6 D", 'd');
	store(d, "7 E", 'e');
	store(d, "8 D", 'd');
	store(d, "9 E", 'e');
	store(d, "10 D", 'd');
	store(d, "11 E", 'e');
	store(d, "12 D", 'd');
	
	exibe(d);

	printf("\n\n\tExibindo:\n\n");
	
	printf("\n\n\tPrimeiro da Deque retirado: %s\n", retrieve(d,'d'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'e'));	
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'d'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'e'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'d'));	
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'e'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'d'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'e'));	
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'d'));
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'e'));	
	printf("\tProximo da Deque retirado: %s\n", retrieve(d,'d'));
	printf("\tUltimo da Deque retirado: %s\n\n", retrieve(d,'e'));	

	printf("\n\n\tDestruindo:\n\n");

	destroy(d);

	return 0;
}

