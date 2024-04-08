/*
Questão 03 [2,5 pontos]:
Dadas duas strings s1 e s2, implementar uma função que crie duas outras strings – s3 e s4 – com as seguintes
características:
- s3: conterá todos os caracteres de s1 que também estão em s2;
- s4: conterá todos os caracteres de s1 que não estão em s2.
Exemplo:
s1: “PROGRAMACAO” 	s3: “ROGRAMAAO”
s2: “ALGORITMOS” 	s4: “PC”
*/

#include <stdio.h>
#include <string.h>

void split_string(char *s1, char *s2, char *s3, char *s4) {
    int i3 = 0, i4 = 0;
    for (int i = 0; i < strlen(s1); i++) {
        if (strchr(s2, s1[i])) {
            s3[i3++] = s1[i];
        } else {
            s4[i4++] = s1[i];
        }
    }
    s3[i3] = '\0';
    s4[i4] = '\0';
}

int main() {
    char *s1 = "PROGRAMACAO";
    char *s2 = "ALGORITMOS";
    char s3[50], s4[50];

    split_string(s1, s2, s3, s4);

    printf("s3: %s\n", s3);
    printf("s4: %s\n", s4);

    return 0;
}

