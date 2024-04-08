/*
Questão 01:

Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.
*/

#include <stdio.h>
#include <string.h>

int tamanho(char s[]);
void copiar(char s1[], char s2[]);
void concatenar(char s1[], char s2[]);
int comparar(char s1[], char s2[]);

void main() {

  int num, tam, comp;
  char palavra[30], palavra1[30], palavra2[30];
  

  printf("Insira o numero correspondente a funcao desejada:");
  printf("\n1. STRLEN \n2. STRCPY \n3. STRCAT \n4. STRCMP \n =>");
  scanf("%d", &num);

  switch (num){

    case 1:

    printf("\nInsira uma palavra: ");
    scanf("%s", &palavra);

    tam = tamanho(palavra);

    printf("O tamanho da palavra eh: %d", tam);
    
    break;

    case 2:

    printf("\nInsira a primeira palavra: ");
    scanf("%s", &palavra1);

    printf("\nInsira a segunda palavra: ");
    scanf("%s", &palavra2);

    copiar(palavra1, palavra2);

    printf("A copia eh: %s", palavra1);
    break;

    case 3:

    printf("\nInsira a primeira palavra: ");
    scanf("%s", &palavra1);

    printf("\nInsira a segunda palavra: ");
    scanf("%s", &palavra2);

    concatenar(palavra1, palavra2);

    printf("A concatenacao eh: %s", palavra1);
    break;

    case 4:

    printf("\nInsira a primeira palavra: ");
    scanf("%s", &palavra1);

    printf("\nInsira a segunda palavra: ");
    scanf("%s", &palavra2);

    comp = comparar(palavra1, palavra2);

    if(comp < 0){
      
      printf("A primeira palavra vem antes no alfabeto");
    }
      else{
        
        if(comp == 0){
          
          printf("As palavras sao iguais");
        }
          else{

            printf("A segunda palavra vem antes no alfabeto");
          }
      }
    break;

    default:

    printf("!!!ERRO:A opcao inserida eh invalida!!!");
  }
    
}

int tamanho(char s[]){

  int i = 0;
  
  while(s[i] != '\0'){

    i++;
  }

  return i;
}

void copiar(char s1[], char s2[]){

  int i = 0;

  for(i = 0; s2[i] != '\0'; i++){

    s1[i] = s2[i];
  }

  s1[i]='\0';
}

void concatenar(char s1[], char s2[]){

  int i = 0, j = 0;

  for(i = tamanho(s1), j = 0; s2[j] != '\0'; i++, j++){

    s1[i]=s2[j];
  }
  
  s1[i] = '\0';
}

int comparar(char s1[], char s2[]){

  int i = 0;

  for(i=0; s1[i] && s2[i] && s1[i] == s2[i]; i++);

  return s1[i] - s2[i];
}
