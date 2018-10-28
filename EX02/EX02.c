#include<stdio.h>
#define MAX 20

typedef struct fila {
	char vet[MAX];
	int front, rear;
} TFila;

int next(int n) {
	return (n + 1) % MAX;
}

void createf(TFila *f) {
	f->rear = f->front = 0;
}

void destroy(TFila *f) {
	f->front = f->rear;
}

int isfull(TFila *f) {
	return next(f->rear) == f->front;
}

int isempty(TFila *f) {
	return f->rear == f->front;
}

void store(TFila *f, char x) {
	if (isfull(f)) {
		printf("overflow\n");
		abort();
	}
	f->vet[f->rear] = x;
	f->rear = next(f->rear);
}

char retrieve(TFila *f) {
	char aux;
	if (isempty(f)) {
		printf("underflow\n");
		abort();
	}
	aux = f->vet[f->front];
	f->front = next(f->front);
	return aux;
}

void inclui(TFila *p1, TFila *p2, TFila *p3, char c, int n){
	if(n == 1)
		store(p1, c);
	else if(n == 2)
		store(p2, c);
	else
		store(p3, c);
}

char prioridade(TFila *p1, TFila *p2, TFila *p3){
	if(!isempty(p1))
		return retrieve(p1);
	else{
		if(!isempty(p2))
			return retrieve(p2);
		else
			return retrieve(p3);
		}
}

int main(void){

	printf("\n\n");
	printf("\tExercicio 1a) Cria fila, insere e retira elementos, verifica rear e front e destroi a fila\t\n");
	printf("\t------------------------------------------------------------------------------------------\t\n\n");

	TFila f;
	createf(&f);

	int i, tam;
	char v[MAX] = {'a','b','c','d','e','f','g'};
	tam = strlen(v);

	printf("\nColocando na Fila\n\n");

	for(i=0; i < tam; i++){
		store(&f,v[i]);
		printf("rear  = %d\n", f.rear);
		printf("front = %d\n", f.front);
	}

	printf("\nRetirando da Fila\n\n");

	for(i=0; i < tam; i++){
		printf("----------->%c\n", retrieve(&f));
		printf("rear  = %d\n", f.rear);
		printf("front = %d\n", f.front);
	}
	printf("\n\n");
	destroy(&f);

	printf("\tExercicio 1b) Cria fila de prioridades e apresenta os itens conforme prioridades\t\n");
	printf("\t--------------------------------------------------------------------------------\t\n\n");

	TFila p1, p2, p3;

	createf(&p1);
	createf(&p2);
	createf(&p3);

	char s[MAX] = {'I', 'A', 'E', 'B', 'C', 'F', 'J', 'K', 'D', 'G', 'H', 'L'};
	int n[12] =   { 3,   1,   2,   1,   1,   2,   3,   3,   1,   2,   2,   3};
	
	printf("Lista de entrada dos itens: \n\n");

	for(i=0; i < 12; i++)
		printf("%2d%c Item de entrada = %c, prioridade: %d\n", i+1,167,s[i],n[i]);

	// Simula a entrada de itens na fila por prioridade.                    //
	// Vetor "n" simula as prioridades e vetor "s" simula os itens da fila  //

	for(i=0; i < 12; i++)
				inclui(&p1, &p2, &p3, s[i], n[i]);
		
	printf("\n");
	printf("Retirando itens na fila por prioridade: \n");

	for(i=0; i < 12; i++)
		printf("\n\t%2d%c item a sair da fila: %c",i+1,167, prioridade(&p1,&p2,&p3));

	destroy(&p1);
	destroy(&p2);
	destroy(&p3);

	printf("\n\n");

	return 0;
}
