#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char *data;
    struct nodo *link;
}* Nodo;

typedef struct Deque {
    Nodo esq, dir;
} Deque;

void create(Deque *d) {
    d->esq = d->dir = NULL;
	printf("\n\n'd' dentro da funcao create\n");
	printf("Endereco de &d: %X\n", &d);		
	printf("Conteudo de d: %X\n", d);		
	printf("Endereco de &d->esq: %X\n", &d->esq);		
	printf("Endereco de &d->dir: %X\n", &d->dir);	
	printf("Conteudo de d->dir: %X\n", d->dir);	
	printf("Conteudo de d->esq: %X\n\n", d->esq);		
}

int isEmpty(Deque *d) {
    return d->esq == NULL;
}

void insere(Deque *d, char *x, char lado) {
	printf("\n'd' dentro da funcao insere\n\n");
    Nodo n = malloc(sizeof(struct nodo));
    n->data = x;
	printf("Endereco de &n: %X\n", &n);	
	printf("Conteudo de n: %X\n\n", n);			
    if (isEmpty(d)) {
        d->esq = d->dir = n;
        n->link = NULL;
    }
    else if (lado == 'e') {
        n->link = d->esq;
        d->esq = n;
    }
    else {
        d->dir = d->dir->link =  n;
        n->link = NULL;
    }	
	printf("Conteudo de d->dir: %X\n", d->dir);	
	printf("Conteudo de d->dir->link: %X\n", d->dir->link);
	printf("Conteudo de d->dir->data: %s\n\n", d->dir->data);		
	printf("Conteudo de d->esq: %X\n", d->esq);	
	printf("Conteudo de d->esq->link: %X\n", d->esq->link);	
	printf("Conteudo de d->esq->data: %s\n\n", d->esq->data);	
}	


char *retira(Deque *d, char lado) {
    if (isEmpty(d)) {
        printf("underflow");
        abort();
    }
    char *x;
    if (lado == 'e') {
        x = d->esq->data;
        Nodo a = d->esq;
        d->esq = a->link;
        free(a);
    }
    else {
        x = d->dir->data;
        Nodo a = d->esq;
        while (a->link && a->link->link) 
			a = a->link;
        free(d->dir);
        if (a == d->dir) 
			d->esq = d->dir = NULL;
        else {
            d->dir = a;
            d->dir->link = NULL;
        }
    }
    return x;
}

void destroy(Deque *d) {
    while (d->esq != NULL) {
        Nodo a = d->esq;
        d->esq = a->link;
        free(a);
    }
    d->dir = d->esq;
}

int main(void){

	Deque dq;
	create(&dq);
	printf("Tamanho de Deque: %d\n", sizeof(Deque));
	printf("Endereco de &dq: %X\n", &dq);	
	printf("Endereco de &dq.esq: %X\n", &dq.esq);
	printf("Endereco de &dq.dir: %X\n", &dq.dir);
	printf("Conteudo de dq.dir: %X\n", dq.dir);
	printf("Conteudo de dq.esq: %X\n", dq.esq);	
	
	insere(&dq, "1 E", 'e');
	insere(&dq, "2 D", 'd');
	insere(&dq, "3 E", 'e');
	insere(&dq, "4 D", 'd');
	insere(&dq, "5 E", 'e');
	insere(&dq, "6 D", 'd');
	insere(&dq, "7 E", 'e');
	insere(&dq, "8 D", 'd');
	insere(&dq, "9 E", 'e');
	insere(&dq, "10 D", 'd');
	insere(&dq, "11 E", 'e');
	insere(&dq, "12 D", 'd');

	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'e'));
	printf("Conteudo de retira: %s\n", retira(&dq, 'd'));

	destroy(&dq);	
		
	printf("\n");

	return 0;
}
