/*
Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não
estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.
*/

#include <stdio.h>
#include <string.h>

void removeDuplicados(char* str) {
    int hash[256] = {0};
    int indiceAtual = 0;
    int ultimoIndiceUnico = 0;

    while(*(str + indiceAtual)) {
        char temp = *(str + indiceAtual);
        if(0 == hash[temp]) {
            hash[temp] = 1;
            *(str + ultimoIndiceUnico) = temp;
            ultimoIndiceUnico++;
        }
        indiceAtual++;
    }      
    *(str + ultimoIndiceUnico) = '\0';
}

void criarNovaString(char* s1, char* s2, char* s3) {
    int hash[256] = {0};
    while(*s2) {
        hash[*s2] = 1;
        s2++;
    }

    while(*s1) {
        if(0 == hash[*s1]) {
            *s3 = *s1;
            s3++;
        }
        s1++;
    }
    *s3 = '\0';
}

int main() {
    char s1[100], s2[100], s3[100];

    printf("Digite a primeira string: ");
    gets(s1);

    printf("Digite a segunda string: ");
    gets(s2);

    criarNovaString(s1, s2, s3);
    removeDuplicados(s3);

    printf("A nova string é: %s", s3);

    return 0;
}

