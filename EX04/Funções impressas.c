#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define N 10


void selectionsort(int *v, int n){
	printf("void selectionsort(int *v, int n){\n");
	int aux, i ,j, menor;
	printf("\tint aux, i ,j, menor;\n");	
	for(i=0; i < n - 1; i++){
		printf("\tfor(i = 0; %d < %d; i++){\n", i,n-1);
		menor = i;
		printf("\t\tmenor = %d;\n",i);
		for(j = i + 1; j < n; j++){
			printf("\t\tfor(j = %d; %d < %d; j++){\n", i+1, j, n);
			printf("\t\t\tif(v[%d] < v[%d])\n",j, menor);
			if(v[j] < v[menor]){
				printf("\t\t\t\tmenor = %d;\n",j);
				menor = j;
			}
			printf("\t\t}\n");
		}
		aux = v[i];
		printf("aux = %d;\n",v[i]);
		v[i] = v[menor];
		printf("v[%d] = %d;\n",i,v[menor]);
		v[menor] = aux;
		printf("v[%d] = %d;\n",menor, aux);
		printf("}\n");
		system("pause");
	}	
	printf("}\n");
}

void bubblesort(int *v, int n){
	printf("void bubblesort(int *v, int n){\n");
	int i, j, aux;
	srand(time(NULL));
	printf("\tint aux, i ,j;\n");
	for(i = n - 1; i > 0; i--){
		printf("\tfor(i = %d; %d > 0; i--)\n", n-1, i);
		for(j = 0; j < i; j++){
			printf("\t\tfor(j = 0; %d < %d; j++)\n", j, i);
			printf("\t\t\tif(v[%d] > v[%d])\n",j, j + 1);
			if(v[j] > v[j + 1]){
				aux = v[j];
				printf("\t\t\t\taux = %d;\n",v[j]);
				v[j] = v[j + 1];
				printf("\t\t\t\tv[%d] = %d;\n", j, v[j + 1]);
				v[j + 1] = aux;
				printf("\t\t\t\tv[%d] = %d;\n",j + 1, aux);
				printf("\n");
			}
		}
		printf("\t\t}\n");
		system("pause");
	}
	printf("\t}\n");
}


void insertionsort(int *v, int n){
	printf("void insertionsort(int *v, int n){\n");
	int i, j, aux;
	printf("\tint aux, i ,j;\n");	
	for(i = 1; i < n; i++){
		printf("\tfor(i = 1; %d < %d; i++){\n", i, n);
		aux = v[i];
		printf("\t\taux = %d;\n",v[i]);
		j = i - 1;
		printf("\t\tj = %d;\n", i-1);
		printf("\t\twhile(%d > -1 && %d > %d)\n",j,v[j], aux);
		while(j > -1 && v[j] > aux){			
			v[j + 1] = v[j];
			printf("\t\t\t\tv[%d] = %d;\n", j + 1, v[j]);
			j--;
			printf("\t\t\t\tj = %d;\n", j);
		}
		v[j + 1] = aux;
		printf("\n\t\tv[%d] = %d;\n", j + 1, aux);
		system("pause");
	}		
}


