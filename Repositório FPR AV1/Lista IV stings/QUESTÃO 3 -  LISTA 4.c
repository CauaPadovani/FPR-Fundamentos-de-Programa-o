/*
Quest�o 03:
Desenvolver uma fun��o que, dada uma string
s, crie uma substring que inicie na posi��o p de s e contenha n caracteres.
	Observa��es: se p e/ou n forem inv�lidos, a
	substring ser� vazia; ii) se s n�o possuir n
	caracteres al�m de p, a substring a ser criada
	come�ar� em p e terminar� no final de s.
*/
#include <stdio.h>
#include <string.h>

char *criarSubstring(const char *s, int p, int n) {
    int tamanhoS = strlen(s);

    // Verifique se p � um �ndice v�lido
    if (p < 0 || p >= tamanhoS) {
        return 0; // Retorna NULL para indicar erro
    }

    // Verifique se n � negativo ou zero
    if (n <= 0) {
        return 0; // Retorna NULL para indicar erro
    }

    // Se p estiver al�m do comprimento da string original, n�o podemos criar uma substring
    if (p >= tamanhoS) {
        return 0; // Retorna NULL para indicar erro
    }

    // Calcular o comprimento da substring
    int comprimentoSubstring = (p + n <= tamanhoS) ? n : tamanhoS - p;

    // Aloque mem�ria para a substring
    char *substring = (char *)malloc(comprimentoSubstring + 1);

    if (substring == NULL) {
        return 0; // Retorna NULL em caso de falha na aloca��o de mem�ria
    }

    // Copiar a substring da string original
    strncpy(substring, s + p, comprimentoSubstring);

    // Adicionar o caractere nulo final � substring
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
        free(substring); // Liberar a mem�ria alocada para a substring
    } else {
        printf("N�o foi poss�vel criar a substring.\n");
    }

    return 0;
}

