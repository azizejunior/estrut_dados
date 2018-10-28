#include<stdio.h>
#define MAX 40

typedef struct pilha {
	char vet[MAX];
	int topo;
} TPilha;

void create(TPilha *p) {
	p->topo = -1;
}

void push(TPilha *p, char x){
	if(isfull(p)){
		printf("overflow\n");
		abort();
	} 
	p->topo++;
	p->vet[p->topo] = x;
}

char pop(TPilha *p){
	char aux;
	if (isempty(p)){
		printf("underflow\n");
		abort();
	}
	aux = p->vet[p->topo];
	p->topo--;
	return aux;
}

char top(TPilha *p) {
	if (isempty(p)) {
		printf("underflow\n");
		abort();
	}
	return p->vet[p->topo];
}

int isfull(TPilha *p) {
	return p->topo == MAX-1;
}

int isempty(TPilha *p) {
	return p->topo == -1;
}

void destroy(TPilha *p) {
	p->topo = -1;
}

char *inverte(char c[]){
	TPilha p;
	create(&p);
	int i, j = 0;
	static char aux[MAX];
	for(i = 0; c[i]; i++){
		push(&p, c[i]);
		if(c[i+1] == 32 || c[i+1] == '\0')
			while(!isempty(&p)){
				aux[j] = pop(&p);				
				j++;
			}			
	}
	destroy(&p);	
	return aux;
}

int main(void){

	// Exercicio 1c) Função que recebe uma string e inverte as palavras da frase //

	char s[MAX] = "Os ratos roeram a roupa do rei de roma";
	printf("%s", inverte(s));	
	return 0;
}


	
