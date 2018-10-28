
/*
char *pop(ptr *p) { 
	ptr aux; 
	char n; 
	if (isempty(*p)) { 
		printf("underflow\n"); 
		exit(1); 
	} 
	aux = *p; 
	*p = (*p)->link; 
	n = aux->data; 
	free(aux); 
	return n; 
}

void push(ptr *p, int elem) { 
	ptr aux = malloc(sizeof(struct nodo)); 
	aux->data = elem; 
	aux->link = *p; 
	*p = aux; 
}
*/

void rem(ptr *lista) { 
	ptr aux; 
	aux = *lista; 
	*lista = aux->link; 
	free(aux); 
}
