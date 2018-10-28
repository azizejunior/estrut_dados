#include<stdio.h>
#define MAX 20

typedef struct pilha {
	char vet[MAX];
	int topo1;
	int topo2;
} TPilhad;

void create(TPilhad *p) {
	p->topo1 = -1;
	p->topo2 = MAX;
}

void push(TPilhad *p, char x, int l){
	if(isfull(p,l)){
		printf("overflow\n");
		abort();
	}
	if(l==1){
		p->topo1++;
		p->vet[p->topo1] = x;
	}
	else{
		p->topo2--;
		p->vet[p->topo2] = x;
	}
}

char pop(TPilhad *p, int l){
	char aux;
	if (isempty(p,l)){
		printf("underflow\n");
		abort();
	}
	else{ 
		if(l==1){
			aux = p->vet[p->topo1];
			p->topo1--;
			return aux;
		}
		else{
			aux = p->vet[p->topo2];
			p->topo2++;
			return aux;
		}
	}
}	

char top(TPilhad *p, int l) {
	if (isempty(p,l)) {
		printf("underflow\n");
		abort();
	}
	else{
		if(l == 1)
			return p->vet[p->topo1];
		else
			return p->vet[p->topo2];
	}
}

int isfull(TPilhad *p, int l) {
	if(l==1)
		return(p->topo1 == MAX-1 || p->topo1 + 1 == p->topo2);
	else
		return(p->topo2 == 0 || p->topo2 - 1 == p->topo1);
}

int isempty(TPilhad *p, int l) {
	if(l==1)
		return (p->topo1 == -1 || p->topo2 == 0);
	else
		return (p->topo2 == MAX || p->topo1 == MAX - 1);
}

void destroy(TPilhad *p) {
	p->topo1 = -1;
	p->topo2 = MAX;
}

int main(void){

	// Exercicio a) Cria pilha dupla, empilha, desempilha e destroi a pilha  //

	TPilhad p;
	create(&p);

	char v1[MAX+1] = "direito";
	char v2[MAX+1] = "esquerda";
	char v3[MAX+1] = " ";
	
	int i;

	for(i=0; v1[i]; i++)
		push(&p, v1[i], 1);

	for(i=0; v2[i]; i++)
		push(&p, v2[i], 2);

	printf("\n");

	printf("topo1 = %c\n", top(&p,1));
	printf("topo2 = %c\n", top(&p,2));

	while(!isempty(&p,1)){
		printf("%c", pop(&p,1));	
	}
	printf("\n");
	while(!isempty(&p,2)){
		printf("%c", pop(&p,2));	
	}
	destroy(&p);
	printf("\n");

	return 0;
}


	
