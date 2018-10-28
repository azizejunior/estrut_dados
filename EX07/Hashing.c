/*		
		//P2  - 13/06 - 16:40
		//SUB - 20/06 - 15:00

	******************************************
	*	 Tabelas de Hashing (Espalhamento)   *
	*	 ---------------------------------   *
	******************************************
	
		Menos memória e mais velocidade.
		Hashing prioriza mais a velocidade 
		e abre mão da memória.
	__________________________________________
	|----------------------------------------|
	|		       Tabela Hash               | 
	|________________________________________|
	------------------------------------------
	
	------------------------------------------
	0 | BETO
	------------------------------------------
	1 | MARIO <- Proximo livre
	------------------------------------------
	2 | ANA
	------------------------------------------
	3 |
	------------------------------------------
	4 |
	------------------------------------------
		
	f("ANA") 	= 	1 + 14 + 1 			 = 16 % 7 = -> 2 <- |
	f("BETO") 	= 	2 + 5 + 20 + 15 	 = 42 % 7 = -> 0 <- |*   COLISÃO -> TRATAMENTO
	f("MARIO") 	= 	13 + 1 + 18 + 9 + 15 = 56 % 7 = -> 0 <- |*	

	f(Chave)    =   Posição     
	|
	|
	 -->soma dos valores      				 
	    relativos aos caracteres 
	    da chave como dados das
	    chaves existentes	

	*Formas de tratar as colisões:
		Proxima posição disponível
		N-ésima Posição
		Lita encadeada
		Área auxiliar só para colisões
		
	*Funções de Hashing
		Resto da divisão
		Meio do quadrado
		Particionamento com adição
		Particionamento com adição e rotação
		Re-Hashing

	*Lista de exercícios EX07 - Sabado - 09/06/2018 - 23:59
		
		(Chamar com Recursividade)
		
		Ex1.Construa uma sub-rotina que retorne o maior elemento de uma árvore de busca binária passada como parâmetro;
			(ordenada)	
		Ex2.Construa uma sub-rotina que retorne o maior elemento de uma árvore binária qualquer passada como parâmetro;
			(não-ordenada)
		Ex4.Construa uma sub-rotina que retorne a quantidade de nós-folha de uma árvore binária passada como parâmetro;
			(0 se é nulo, 0 lE e LE nulo, retorna a quantidade de folhas)
		Ex6.Construa uma sub-rotina que retorne a altura de uma árvore binária passada como parâmetro;
			(0 se não tiver elemtento)		
*/	
