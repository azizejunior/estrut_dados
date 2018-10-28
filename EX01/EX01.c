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

int palindromo(TPilha *p, char *c){
	int i, j, s = 0, cont = 0;
	char aux[MAX];
	for(i = 0, j = 0; c[i]!='\0'; i++, j++){
		if(c[i] == 32)
			i++;
		aux[j] = c[i];
		push(p, c[i]);
		cont++;	
	}	
	for(i = 0; i < cont; i++)
		if(aux[i] == pop(p))
			s++;
	if(s == cont)
		return 1;
	else
		return 0;	
}



char *inverte(char *c){
	TPilha p;
	create(&p);
	int i, j = -1;
	for(i = 0; c[i]!= '\0'; i++){
		if(c[i] == ' '){
			while(!isempty(&p)){
				j++;
				c[j] = pop(&p);				
			}
			j++;
			c[j] = ' ';
		}
		else if(c[i+1] == '\0'){
			push(&p, c[i]);
			while(!isempty(&p)){
				j++;
				c[j] = pop(&p);
			}
		}		
		else
			push(&p, c[i]);			
	}	
	return c;
}




int main(void){

	// Exercicio 1a) Cria pilha, empilha, desempilha e destroi a pilha  //

	TPilha p;
	create(&p);
	char v[MAX] = "Inconstitucionalissimamente";
	int i,j;
	for(i=0; v[i]!='\0'; i++)
		push(&p, v[i]);
	printf("\n");
	for(j = 0; j < i; j++)
		printf("%c", pop(&p));
	destroy(&p);
	printf("\n\n");	

	// Exercicio 1b) Função que recebe uma string e verifica se é palindromo //

	char va[MAX] = "a mala nada na lama";
	char vb[MAX] = "O rato roeu a roupa do rei de roma";
	char vc[MAX] = "megabobagem";
	char vd[MAX] = "palindromo";
	
	/* Testa a 1 string */
	create(&p);  
	if(palindromo(&p,va))
		printf("\nVA e um palindromo\n");
	else
		printf("\nVA nao e um palindromo\n");
	destroy(&p);
	
	/* Testa a 2 string */
	create(&p); 
	if(palindromo(&p,vb))
		printf("\nVB e um palindromo\n");
	else
		printf("\nVB nao e um palindromo\n");
	destroy(&p);
	
	/* Testa a 3 string */
	create(&p); 
	if(palindromo(&p,vc))
		printf("\nVC e um palindromo\n");
	else
		printf("\nVC nao e um palindromo\n");
	destroy(&p);
	
	/* Testa a 4 string */
	create(&p); 
	if(palindromo(&p,vd))
		printf("\nVD e um palindromo\n");
	else
		printf("\nVD nao e um palindromo\n");
	destroy(&p);	
	printf("\n\n");	
	
	// Exercicio 1c) Função que recebe uma string e inverte as palavras da frase //

	char ve[MAX] = "Os ratos roeram a roupa do rei de roma";
	printf("%s", inverte(ve));	
	return 0;
}


	
