#include<stdio.h>

/*

EX04

d) Fazer o mesmo que o item (c) mas contando somente as comparações;
	- Comparação externa do loop e 'n' comparações internas

*/

void selectionsort(int *v, int n){
	int aux, i ,j, menor;
	for(i=0; i < n - 1; i++){
		menor = i;
		for(j = i + 1; j < n; j++)
			if(v[j] < v[menor])
				menor = j;
		aux = v[j];
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

void quicksort(int *v, int ini, int fim) {
	int pivo;
	if (ini < fim) {
		pivo = particao(v, ini, fim);
		quicksort(v, ini, pivo - 1);
		quicksort(v, pivo + 1, fim);
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



int main(void){
	
	return 0;
}
