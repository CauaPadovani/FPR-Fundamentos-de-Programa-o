/*
Questão 03:
Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de s e contenha n caracteres.
	Observações: se p e/ou n forem inválidos, a
	substring será vazia; ii) se s não possuir n
	caracteres além de p, a substring a ser criada
	começará em p e terminará no final de s.
*/
#include <stdio.h>
#include <string.h>

char *criarSubstring(const char *s, int p, int n) {
    int tamanhoS = strlen(s);

    // Verifique se p é um índice válido
    if (p < 0 || p >= tamanhoS) {
        return 0; // Retorna NULL para indicar erro
    }

    // Verifique se n é negativo ou zero
    if (n <= 0) {
        return 0; // Retorna NULL para indicar erro
    }

    // Se p estiver além do comprimento da string original, não podemos criar uma substring
    if (p >= tamanhoS) {
        return 0; // Retorna NULL para indicar erro
    }

    // Calcular o comprimento da substring
    int comprimentoSubstring = (p + n <= tamanhoS) ? n : tamanhoS - p;

    // Aloque memória para a substring
    char *substring = (char *)malloc(comprimentoSubstring + 1);

    if (substring == NULL) {
        return 0; // Retorna NULL em caso de falha na alocação de memória
    }

    // Copiar a substring da string original
    strncpy(substring, s + p, comprimentoSubstring);

    // Adicionar o caractere nulo final à substring
    substring[comprimentoSubstring] = '\0';

    return substring;
}

int main() {
    const char *s = "Esta e uma string de exemplo";
    int p = 5;
    int n = 7;

    char *substring = criarSubstring(s, p, n);

    if (substring) {
        printf("Substring: %s\n", substring);
        free(substring); // Liberar a memória alocada para a substring
    } else {
        printf("Não foi possível criar a substring.\n");
    }

    return 0;
}

