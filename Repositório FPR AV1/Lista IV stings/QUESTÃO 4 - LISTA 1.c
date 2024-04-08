/*
Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.
*/

#include <stdio.h>
#include <string.h>
#define TAM 10

int remover(char palavra[], char letra);

void main(){
	
	char s1[TAM], caracter;
	
	printf("Insira uma palavra: ");
	scanf("%s", &s1);
	
  fflush(stdin);
	
	printf("Insira a letra a ser removida: ");
	scanf("%c", &caracter);
	
	remover(s1, caracter);
	
	printf("A palavra apos a remocao: %s", s1);
}

int remover(char palavra[], char letra){
	
	int i, j = 0;

    for (i = 0; palavra[i] != '\0'; i++) {
        
		if (palavra[i] != letra) {
            palavra[j] = palavra[i];
            j++;
        }
    }

    palavra[j] = '\0'; 
}

