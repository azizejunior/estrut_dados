#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
#define N 10

/*

EX04

c) Incluir a quantidade de trocas feitas no vetor (2 elementos trocados = 2 trocas) retorna int:
   - 2 usar variável global nos métodos recursivos (static);
   - Considerar as trocas feitas no vetor original;ok
   - Fazer a média, simular umas 15 trocas;
   - (sugestão função random para gerar os números);ok
*/


int selectionsort(int *v, int n){
	int aux, i ,j, menor, cont = 0;
	for(i=0; i < n - 1; i++){
		menor = i;
		for(j = i + 1; j < n; j++)
			if(v[j] < v[menor])
				menor = j;
		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
		if(v[i] != v[menor])
			cont += 2;
	}
	return cont;
}


int bubblesort(int *v, int n){
	int i, j, aux, cont =0;
	for(i = n - 1; i > 0; i--)
		for(j = 0; j < i; j++)
			if(v[j] > v[j + 1]){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				cont += 2;
			}
	return cont;
}


int insertionsort(int *v, int n){
	int i, j, aux, cont = 0;
	for(i = 1; i < n; i++){
		aux = v[i];
		j = i - 1;
		while(j > -1 && v[j] > aux){
			v[j + 1] = v[j];
			j--;
			cont += 2;
		}
		v[j + 1] = aux;
	}
	return cont;		
}


int main(void){
	int i, v1[N], v2[N], v3[N], aux;
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
	aux = selectionsort(v1, N);

	printf("\n----------------->Selection Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v1[%i] = %d\n", i, v1[i]);
	}
	printf("\nSelection Sort - Numero de trocas realizadas: %d\n", aux);
	

	printf("\n------------------------------------------------>\n");
	printf("\n----------------->Bubble Sort antes\n\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i, v2[i]);
	}
	printf("\n");
	aux = bubblesort(v2, N);
	printf("\n----------------->Bubble Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v2[%i] = %d\n", i, v2[i]);
	}
	printf("\nBubble Sort - Numero de trocas realizadas: %d\n", aux);
	

	printf("\n------------------------------------------------>\n");
	printf("\n----------------->Insertion Sort antes\n\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i, v3[i]);
	}
	printf("\n");
	aux = insertionsort(v3, N);
	printf("\n----------------->Insertion Sort depois\n\n");
	for(i = 0; i < N; i++){
		printf("v3[%i] = %d\n", i, v3[i]);
	}
	printf("\nInsertion Sort - Numero de trocas realizadas: %d\n", aux);
	
	

	return 0;
}



