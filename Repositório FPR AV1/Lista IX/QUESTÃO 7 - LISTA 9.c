/*
Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.
*/
#include <stdio.h>
#include <string.h>

int common_chars(char *s1, char *s2, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    else if (s1[m-1] == s2[n-1])
        return 1 + common_chars(s1, s2, m-1, n-1);
    else
        return max(common_chars(s1, s2, m, n-1), common_chars(s1, s2, m-1, n));
}

int max(int a, int b) {
    return (a > b)? a : b;
}

int main() {
    char s1[100], s2[100];
    printf("Digite a primeira string: ");
    gets(s1);
    printf("Digite a segunda string: ");
    gets(s2);
    printf("Número de caracteres comuns: %d", common_chars(s1, s2, strlen(s1), strlen(s2)));
    return 0;
}

