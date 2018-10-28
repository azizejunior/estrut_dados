/*		
		//P2  - 13/06 - 16:40
		//SUB - 20/06 - 15:00

	******************************************
	*	 Tabelas de Hashing (Espalhamento)   *
	*	 ---------------------------------   *
	******************************************
	
		Menos mem�ria e mais velocidade.
		Hashing prioriza mais a velocidade 
		e abre m�o da mem�ria.
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
	f("BETO") 	= 	2 + 5 + 20 + 15 	 = 42 % 7 = -> 0 <- |*   COLIS�O -> TRATAMENTO
	f("MARIO") 	= 	13 + 1 + 18 + 9 + 15 = 56 % 7 = -> 0 <- |*	

	f(Chave)    =   Posi��o     
	|
	|
	 -->soma dos valores      				 
	    relativos aos caracteres 
	    da chave como dados das
	    chaves existentes	

	*Formas de tratar as colis�es:
		Proxima posi��o dispon�vel
		N-�sima Posi��o
		Lita encadeada
		�rea auxiliar s� para colis�es
		
	*Fun��es de Hashing
		Resto da divis�o
		Meio do quadrado
		Particionamento com adi��o
		Particionamento com adi��o e rota��o
		Re-Hashing

	*Lista de exerc�cios EX07 - Sabado - 09/06/2018 - 23:59
		
		(Chamar com Recursividade)
		
		Ex1.Construa uma sub-rotina que retorne o maior elemento de uma �rvore de busca bin�ria passada como par�metro;
			(ordenada)	
		Ex2.Construa uma sub-rotina que retorne o maior elemento de uma �rvore bin�ria qualquer passada como par�metro;
			(n�o-ordenada)
		Ex4.Construa uma sub-rotina que retorne a quantidade de n�s-folha de uma �rvore bin�ria passada como par�metro;
			(0 se � nulo, 0 lE e LE nulo, retorna a quantidade de folhas)
		Ex6.Construa uma sub-rotina que retorne a altura de uma �rvore bin�ria passada como par�metro;
			(0 se n�o tiver elemtento)		
*/	
