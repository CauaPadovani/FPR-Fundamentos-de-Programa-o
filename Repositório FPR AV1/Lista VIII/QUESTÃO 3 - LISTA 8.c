/*
Questão 03:
Desenvolver uma função, em C, que, dada uma
string s e dada uma posição p desta string, crie duas
novas strings: s1 com os caracteres de s das
posições 0 a p-1; e s2 com os caracteres de s da
posição p à última.
Nota: Caso p seja uma posição inválida, a função
deverá retornar o valor 0; caso contrário,
procederá com a criação das duas strings e
retornará o valor 1.
*/

#include <stdio.h>
#include <string.h>

int split_string(char* s, int p, char* s1, char* s2) {
    int len = strlen(s);
    if (p < 0 || p > len) {
        return 0;
    }
    strncpy(s1, s, p);
    s1[p] = '\0';
    strcpy(s2, s + p);
    return 1;
}

int main() {
    char s[] = "Hello, World!";
    char s1[50], s2[50];
    int p = 5;
    
    if (split_string(s, p, s1, s2)) {
        printf("s1: %s\n", s1);
        printf("s2: %s\n", s2);
    } else {
        printf("Posição inválida.\n");
    }
    
    return 0;
}

