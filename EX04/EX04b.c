#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

/*

EX04

b) Alterar: 
	- Selection sort, 
	- Bubble sort, 
	- Insertion Sort, 
	para ordenar em ordem crescente mas partindo do lado inverso ao lado dos algoritmos originais do item (a);

*/

void selectionsort(int *v, int n){
	int aux, i ,j, maior;
	for(i = n - 1; i > 0; i--){
		maior = i;
		for(j = i - 1; j > -1; j--)
			if(v[j] > v[maior])
				maior = j;
		aux = v[i];
		v[i] = v[maior];
		v[maior] = aux;
	}
}

void bubblesort(int *v, int n){
	int i, j, aux;
	for(i = 0; i < n - 1; i++)
		for(j = n - 1; j > i; j--)
			if(v[j-1] > v[j]){
				aux = v[j];
				v[j] = v[j - 1];
				v[j-1] = aux;
			}
}

void insertionsort(int *v, int n){
	int i, j, aux;
	for(i = n - 2; i > -1; i--){
		aux = v[i];
		j = i + 1;
		while(j < n && v[j] < aux){
			v[j - 1] = v[j];
			j++;
		}
		v[j - 1] = aux;
	}		
}


int main(void){
	int i, v1[N], v2[N], v3[N], v4[N], v5[N];
	srand(time(NULL));
	for(i = 0; i < N; i++){
		v1[i] = rand() % 99;
		v2[i] = rand() % 99;	
		v3[i] = rand() % 99;	
	}	
	
	printf("\n------------------------------------------------>\n");
	printf("\n----------------->Selection Sort antes\n\n");
	for(i = 0; i < N; i++){
		printf("v1[%i] = %d\n", i, v1[i]);
	}
	printf("\n");
	selectionsort(v1, N);
	printf("\n----------------->Selection Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v1[%i] = %d\n", i, v1[i]);
	}
	

	printf("\n------------------------------------------------>\n");
	printf("\n----------------->Bubble Sort antes\n\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i, v2[i]);
	}
	printf("\n");
	bubblesort(v2, N);
	printf("\n----------------->Bubble Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i, v2[i]);
	}
	


	printf("\n------------------------------------------------>\n");
	printf("\n----------------->Insertion Sort antes\n\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i, v3[i]);
	}
	printf("\n");
	insertionsort(v3, N);
	printf("\n----------------->Insertion Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i, v3[i]);
	}
	

	printf("\n------------------------------------------------>\n\n");
	

	return 0;
}
