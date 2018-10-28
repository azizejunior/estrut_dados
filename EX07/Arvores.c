#include<stdio.h>
#include<stdlib.h>

typedef struct nodo { 
	int data; 
	struct nodo *linkE, *linkD; 
} nodo; 

typedef nodo* ptr;

void preordem(ptr raiz) { 
	if (raiz != NULL) { 
		printf("%d\n", raiz->data); 
		preordem(raiz->linkE); 
		preordem(raiz->linkD); 
	} 
}

void emordem(ptr raiz) { 
	if (raiz != NULL) { 
		emordem(raiz->linkE); 
		printf("%d\n", raiz->data); 
		emordem(raiz->linkD); 
	} 
}

void posordem(ptr raiz) { 
	if (raiz != NULL) { 
		posordem(raiz->linkE); 
		posordem(raiz->linkD); 
		printf("%d\n", 
			raiz->data); 
	} 
}

void emnivel(ptr raiz) { 
	if (raiz != NULL) { 
		TFila f; 
		createf(&f); 
		store(&f, raiz); 
		while (!isemptyf(&f)) { 
			raiz = retrieve(&f); 
			printf("%d\n", raiz->data); 
			if (raiz->linkE != NULL) 
				store(&f, raiz->linkE); 
			if (raiz->linkD != NULL) 
				store(&f, raiz->linkD); 
		} 
	} 
}

void create(ptr *raiz) { 
	*raiz = NULL; 
}

int isempty(ptr raiz) { 
	return raiz == NULL; 
}

void destroy(ptr *raiz) { 
	if (!isempty(*raiz)) { 
		destroy(&(*raiz)->linkE); 
		destroy(&(*raiz)->linkD); 
		free(*raiz); *raiz = NULL; 
	} 
}

int busca(ptr raiz, int x) { 
	if (isempty(raiz)) return 0; 
	else if (x == raiz->data) return 1; 
	else return busca(raiz->linkE, x) || busca(raiz->linkD, x); 
}

void inclui(ptr *raiz, int x) { 
	if (isempty(*raiz)) { 
		*raiz = malloc(sizeof(nodo)); 
		(*raiz)->data = x; 
		(*raiz)->linkE = (*raiz)->linkD = NULL; 
	} 
	else if (x > (*raiz)->data) inclui(&(*raiz)->linkD, x); 
	else inclui(&(*raiz)->linkE, x);
}

int busca(ptr raiz, int x) { 
	if (isempty(raiz)) 
		return 0; 
	else if (x == raiz->data) 
		return 1; 
	else if (x > raiz->data) 
		return busca(raiz->linkD, x);
	else 
		return busca(raiz->linkE, x); 
}

void rem(ptr *raiz, int x) { 
	ptr aux; 
	if (isempty(*raiz)) 
		return; 
	if (x == (*raiz)->data) { 
		if ((*raiz)->linkE == NULL) { 
			aux = *raiz; 
			(*raiz) = (*raiz)->linkD; 
			free(aux); 
		} 
		else if ((*raiz)->linkD == NULL) { 
			aux = *raiz; 
			(*raiz) = (*raiz)->linkE; 
			free(aux); 
		} 
		else { 
			(*raiz)->data = maior((*raiz)->linkE); 
			rem(&(*raiz)->linkE,(*raiz)->data); 
		} 
	} 
	else if (x < (*raiz)->data) 
		rem(&(*raiz)->linkE, x); 
	else 
		rem(&(*raiz)->linkD, x); 
}

int main(void){

	return 0;
}
