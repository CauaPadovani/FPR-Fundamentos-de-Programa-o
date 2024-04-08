/*
Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.
*/

#include <stdio.h>
#include <string.h>

int verificar(char termo1[], char termo2[]);

void main() {

  int pal;
  char palavra[10], palavra2[10];

  printf("Insira uma palavra: ");
  scanf("%s", &palavra);

  strcpy(palavra2, palavra);
  
  pal = verificar(palavra, palavra2);
  
  if(pal == 0){
	
	printf("A palavra eh um palidromo");
  }
    	else{

            printf("A palavra nao eh um palidromo");
        }
}

int verificar(char termo1[], char termo2[]){
	
  int i = 0;

  strrev(termo2);
  
  for(i=0; termo1[i] && termo2[i] && termo1[i] == termo2[i]; i++);
  
  return termo1[i] - termo2[i];
}
