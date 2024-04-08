/*
Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.
*/

#include <stdio.h>

int remove_char(char* str, char ch, int index, int count) {
    if (str[index] == '\0') {
        return count;
    }
    if (str[index] == ch) {
        int i;
        for (i = index; str[i] != '\0'; i++) {
            str[i] = str[i + 1];
        }
        count++;
    }
    return remove_char(str, ch, index + 1, count);
}

int main() {
    char str[100];
    char ch;
    printf("Digite a string: ");
    gets(str);
    printf("Digite o caractere a ser removido: ");
    scanf("%c", &ch);
    int count = remove_char(str, ch, 0, 0);
    printf("String após a remoção do caractere: %s\n", str);
    printf("Total de remoções realizadas: %d\n", count);
    return 0;
}

