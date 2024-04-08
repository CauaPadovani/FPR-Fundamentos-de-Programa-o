/*
	FAETERJ-Rio
	Fundamentos de Programa��o - 2023/2 - Turmas: Manh� e Noite
	Professor Leonardo Vianna
	
	Data: 21/10/2023 (aula extra)
	
	Quest�o 03 (AV1 - Noite - 2023/1):
	
	Considere a exist�ncia de um vetor de structs com quant posi��es, onde cada uma destas 
	armazena os seguintes dados sobre um grupo de pessoas: nome (string), g�nero (char) e 
	idade (int). Pede-se uma fun��o que determine se os elementos deste vetor est�o ordenados 
	e retorne 1, caso estejam ordenados, e 0, caso contr�rio. 
	
	Observa��o: o vetor ser� considerado ordenado se estiver organizado crescentemente em fun��o 
	da idade. Por�m, no caso de pessoas com a mesma idade, estas devem estar ordenadas 
	crescentemente pelo nome. 
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de tipos
typedef struct {
	char	nome[20];
	char	genero;
	int  	idade; 	
} TPessoa;

//prot�tipos das fun��es
int verificaOrdenacao (TPessoa vetor[], int quant);

void exibirPessoas (TPessoa vetor[], int quant);

//main
void main ()
{
	//declara��o de vari�veis
	TPessoa vetor[7];
	int quantidade = 7;
	
	//inicializando o vetor de structs
	strcpy (vetor[0].nome, "CARLOS");
	vetor[0].genero = 'M';
	vetor[0].idade = 20;
	
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 23;

	strcpy (vetor[2].nome, "ADRIANA");
	vetor[2].genero = 'F';
	vetor[2].idade = 25;

	strcpy (vetor[3].nome, "JOAO");
	vetor[3].genero = 'M';
	vetor[3].idade = 25;

	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 25;
	
	strcpy (vetor[5].nome, "CLARA");
	vetor[5].genero = 'F';
	vetor[5].idade = 28;
	
	strcpy (vetor[6].nome, "PATRICIA");
	vetor[6].genero = 'F';
	vetor[6].idade = 28;
	

	//exibindo o vetor antes da chamada � fun��o
	exibirPessoas (vetor, quantidade);

	//lendo o genero
		
	//chamando a fun��o
	printf ("\n\nOrdenado? %d\n", verificaOrdenacao (vetor, quantidade));
}
	
//implementa��o das fun��es
int verificaOrdenacao (TPessoa vetor[], int quant)
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo o vetor (at� a pen�ltima posi��o)
	for (i=0;i<quant-1;i++)
	{
		//verificando se a pessoa da posi��o 'i' � mais velha do que a da posi��o 'i+1'
		if (vetor[i].idade > vetor[i+1].idade)
		{
			return 0;
		}
		else
		{
			//verificando se as pessoas das posi��es 'i' e 'i+1' possuem a mesma idade
			if (vetor[i].idade == vetor[i+1].idade)
			{
				//verificando se, alfabeticamente, o nome da posi��o 'i' "vem depois" do 
				//da posi��o 'i+1'
				if (strcmp (vetor[i].nome, vetor[i+1].nome) > 0)
				{
					return 0;
				}
			}
		}
	}
	
	return 1;
}

void exibirPessoas (TPessoa vetor[], int quant)
{
	//declara��o de vari�veis
	int i;
	
	//pulando linha
	printf ("\n\n");
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		printf ("Nome: %s\n", vetor[i].nome);
		printf ("Genero: %c\n", vetor[i].genero);
		printf ("Idade: %d\n\n", vetor[i].idade);
	}
}
