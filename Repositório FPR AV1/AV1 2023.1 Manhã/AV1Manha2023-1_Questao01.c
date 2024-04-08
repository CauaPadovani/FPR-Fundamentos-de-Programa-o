/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turmas: Manh� e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Quest�o 01 (AV1 - Manh� - 2023/1):
	
	Considerando a exist�ncia de uma matriz de inteiros M, de ordem N (ou seja, o n� de linhas e o 
	n� de colunas s�o iguais a N), onde N � uma constante, desenvolver uma fun��o que retorne 1 se 
	a seguinte regra for atendida por M (caso contr�rio, o valor 0 dever� ser retornado):
	
		- A soma dos elementos da diagonal principal deve ser igual � soma dos elementos que 
		  est�o acima desta diagonal, assim como � soma dos elementos abaixo da diagonal.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int questao01 (int n, int m[n][n]);

//main
void main ()
{
	int m1[5][5] = {{6,3,1,2,6},
	                {1,3,5,4,2},
	                {3,4,4,2,2},
	                {5,9,1,9,3},
	                {4,0,2,1,8}};
	                
	int m2[5][5] = {{1, 8, 5, 9, 4},
                    {2, 5, 4, 6, 5},
                    {4, 1, 2, 3, 6},
                    {4, 5, 5, 8, 7},
                    {4, 2, 5, 6, 9}};
                    
    //chamando a fun��o
	printf ("M1: %d\n", questao01 (5, m1));
	printf ("M2: %d\n", questao01 (5, m2));	                
}

//implementa��o das fun��es
int questao01 (int n, int m[n][n])
{
	//declara��o de vari�veis
	int i, j;
	int somaDiagonal = 0, somaAbaixo = 0, somaAcima = 0;
	
	//variando as linhas
	for (i=0;i<n;i++)
	{
		//variando as colunas
		for (j=0;j<n;j++)
		{
			//verificando se o elemento est� na diagonal principal
			if (i == j)
			{
				somaDiagonal += m[i][j];
			}
			else
			{
				//verificando se o elemento est� abaixo da diagonal
				if (i > j)
				{
					somaAbaixo += m[i][j];
				}
				else
				{
					//o elemento est� acima da diagonal
					somaAcima += m[i][j];
				}
			}
		}
	}	
	
	//verificando se as tr�s somas s�o iguais
	if ((somaDiagonal == somaAbaixo) && (somaDiagonal == somaAcima))
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}
