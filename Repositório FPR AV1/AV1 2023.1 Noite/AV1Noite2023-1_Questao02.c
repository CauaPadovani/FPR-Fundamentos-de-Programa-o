/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turmas: Manh� e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Quest�o 02 (AV1 - Noite - 2023/1):
	
	Dadas duas strings s1 e s2, implementar uma fun��o que verifique se todos os caracteres de s1 
	est�o em s2. 
	Dependendo do resultado, os seguintes valores dever�o ser retornados: 
			0: nem todos os caracteres de s1 est�o em s2; 
			1: todos os caracteres de s1 est�o em s2, por�m n�o na mesma frequ�ncia; 
			2: todos os caracteres de s1 est�o em s2, na mesma frequ�ncia. 
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int questao02 (char s1[], char s2[]);
int contagem (char s[], char caracter);

//main
void main ()
{
	printf ("CASA e ASSC: %d\n", questao02 ("CASA", "ASSC"));			//1
	printf ("CASA e ASAC: %d\n", questao02 ("CASA", "ASAC"));			//2
	printf ("CASADO e AADDSC: %d\n", questao02 ("CASADO", "AADDSC"));	//0
	printf ("CASA e CASADO: %d\n", questao02 ("CASA", "CASADO"));		//2
}

//implementa��o das fun��es
int questao02 (char s1[], char s2[])
{
	//declara��o de vari�veis
	int i, quant1, quant2, retorno = 2;
	
	//percorrendo todos os caracteres de 's1'
	for (i=0;s1[i];i++)
	{
		//contando o n�mero de ocorr�ncia de 's1[i]' em 's2'
		quant2 = contagem (s2, s1[i]);
				
		//verificando se s1[i] n�o existe em s2
		if (quant2 == 0)
		{
			return 0;
		}
		else
		{
			//contando o n�mero de ocorr�ncia de 's1[i]' na pr�pria string 's1'
			quant1 = contagem (s1, s1[i]);
			
			//verificando se as quantidades s�o iguais
			if (quant1 != quant2)
			{
				retorno = 1;
			}
		}		
	}
	
	return retorno;
}

int contagem (char s[], char caracter)
{
	//declara��o de vari�veis
	int i, cont = 0;
	
	//percorrendo a string 's'
	for (i=0;s[i];i++)
	{
		if (s[i] == caracter)
		{
			cont++;
		}
	}
	
	return cont;
}
