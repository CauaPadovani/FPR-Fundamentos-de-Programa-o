/*
Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s.
*/

#include <stdio.h>
#define ASCII_SIZE 256

int contaCaracteresDistintos(char *str) {
    int count[ASCII_SIZE] = {0};
    int i;
    for (i = 0; *(str+i); i++)
        count[*(str+i)]++;
    int distinctCharCount = 0;
    for (i = 0; i < ASCII_SIZE; i++)
        if(count[i])
            distinctCharCount++;
    return distinctCharCount;
}

int main() {
    char str[] = "exemplo";
    printf("Numero de caracteres distintos eh: %d\n", contaCaracteresDistintos(str));
    return 0;
}

