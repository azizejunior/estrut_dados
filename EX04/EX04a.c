#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

/*
EX04a) 
	Testar os 5 métodos de ordenação vetor fixo de "n" posições 
	(sugestão função random para gerar os números);
*/

void intercala(int *v, int ini, int meio, int fim) {
	int i = ini, j = meio + 1, k = 0, *aux;
	if (aux = malloc(sizeof(int) * (fim - ini + 1))) {
		while (i <= meio && j <= fim){
			if (v[i] <= v[j]) 
				aux[k++] = v[i++];
			else 
				aux[k++] = v[j++];
		}
		while (i <= meio) 
			aux[k++] = v[i++];
		while (j <= fim) 
			aux[k++] = v[j++];
		for (i = ini, j = 0; i <= fim; i++, j++)
			v[i] = aux[j];
		free(aux);
	}
}

int particao(int *v, int ini, int fim) {
	int pivo = v[ini], esq = ini + 1, dir = fim, aux;
	while(esq <= dir) {
		while(esq <= dir && v[esq] <= pivo)
			esq++;
		while (v[dir] > pivo) 
			dir--;
		if (esq < dir) {
			aux = v[esq]; 
			v[esq] = v[dir]; 
			v[dir] = aux;
			esq++; 
			dir--;
		}
	}
	v[ini] = v[dir]; 
	v[dir] = pivo;
	return dir;
} 

void selectionsort(int *v, int n){
	int aux, i ,j, menor;
	for(i=0; i < n - 1; i++){
		menor = i;
		for(j = i + 1; j < n; j++)
			if(v[j] < v[menor])
				menor = j;
		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	}
}

void bubblesort(int *v, int n){
	int i, j, aux;
	for(i = n - 1; i > 0; i--)
		for(j = 0; j < i; j++)
			if(v[j] > v[j + 1]){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
}

void insertionsort(int *v, int n){
	int i, j, aux;
	for(i = 1; i < n; i++){
		aux = v[i];
		j = i - 1;
		while(j > -1 && v[j] > aux){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}		
}

void mergesort(int *v, int ini, int fim) {
	int meio;
	if (ini < fim) {
		meio = (ini + fim) / 2;
		mergesort(v, ini, meio);
		mergesort(v, meio + 1, fim);
		intercala(v, ini, meio, fim);
	}
}

void quicksort(int *v, int ini, int fim) {
	int pivo;
	if (ini < fim) {
		pivo = particao(v, ini, fim);
		quicksort(v, ini, pivo - 1);
		quicksort(v, pivo + 1, fim);
	}
}

int main(void){
	int i, v1[N], v2[N], v3[N], v4[N], v5[N];
	srand(time(NULL));
	for(i = 0; i < N; i++){
		v1[i] = rand() % 99;
		v2[i] = rand() % 99;
		v3[i] = rand() % 99;
		v4[i] = rand() % 99;
		v5[i] = rand() % 99;
	}
	
	printf("\n----------->Vetor 1 antes\n");
	for(i = 0; i < N; i++){
		printf("v1[%i] = %d\n", i, v1[i]);
	}
	selectionsort(v1, N);
	printf("\n----------------->Vetor 1 depois\n");
	for(i = 0; i < N; i++){
		printf("v1[%i] = %d\n", i, v1[i]);
	}
	
	printf("\n----------->Vetor 2 antes\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i,v2[i]);
	}
	bubblesort(v2, N);
	printf("\n----------------->Vetor 2 depois\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i, v2[i]);
	}

	printf("\n----------->Vetor 3 antes\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i,v3[i]);
	}
	insertionsort(v3, N);
	printf("\n----------------->Vetor 3 depois\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i,v3[i]);
	}

	printf("\n----------->Vetor 4 antes\n");
	for(i = 0; i < N; i++){
		printf("v4[%i] = %d\n", i, v4[i]);
	}
	mergesort(v4, 0, N-1);
	printf("\n----------------->Vetor 4 depois\n");
	for(i = 0; i < N; i++){
		printf("v4[%i] = %d\n", i, v4[i]);
	}

	printf("\n----------->Vetor 5 antes\n");
	for(i = 0; i < N; i++){
		printf("v5[%i] = %d\n", i, v5[i]);
	}
	quicksort(v5, 0, N-1);
	printf("\n----------------->Vetor 5 depois\n");
	for(i = 0; i < N; i++){
		printf("v5[%i] = %d\n", i, v5[i]);
	}


	return 0;
}
