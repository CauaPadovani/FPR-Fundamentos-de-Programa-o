/*
Questão 04:
Desenvolver uma função que remova de uma
string s os caracteres compreendidos entre as
posições p1 e p2.
Caso p1 ou p2 seja uma posição inválida, a
função deverá retornar o valor 0 e a remoção de
caracteres solicitada não será realizada; caso
contrário, deverá retornar 1 e proceder com o
que foi pedido.
*/

#include <stdio.h>
#include <string.h>

int remove_substring(char* s, int p1, int p2) {
    int len = strlen(s);
    if (p1 < 0 || p2 >= len || p1 > p2) {
        return 0;
    }
    memmove(&s[p1], &s[p2 + 1], len - p2);
    return 1;
}

int main() {
    char s[] = "Hello, World!";
    int p1 = 5, p2 = 7;
    
    if (remove_substring(s, p1, p2)) {
        printf("String após remoção: %s\n", s);
    } else {
        printf("Posições inválidas.\n");
    }
    
    return 0;
}

