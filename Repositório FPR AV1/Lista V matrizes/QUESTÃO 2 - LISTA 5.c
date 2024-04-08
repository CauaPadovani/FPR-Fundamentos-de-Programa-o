/*
QUESTÃO 02:
Desenvolver uma função que, dada uma matriz
M15×20, determine se um número X se encontra
na linha L da matriz. 
*/

#include <stdio.h>

// Função para verificar se um número X está presente na linha L da matriz
int verificaNumeroNaLinha(int matriz[15][20], int L, int X) {
    // Verifica se L está dentro dos limites da matriz
    if (L < 0 || L >= 15) {
        return 0; // L está fora dos limites da matriz
    }

    for (int coluna = 0; coluna < 20; coluna++) {
        if (matriz[L][coluna] == X) {
            return 1; // O número X está presente na linha L
        }
    }

    return 0; // O número X não está presente na linha L
}

int main() {
    int matriz[15][20] = {
        // Aqui você deve inicializar a matriz com seus valores
        // Por exemplo, você pode preenchê-la com valores de teste.
    };

    int L = 7; // Linha que você deseja verificar
    int X = 42; // Número que você deseja encontrar

    int resultado = verificaNumeroNaLinha(matriz, L, X);

    if (resultado) {
        printf("O número %d está presente na linha %d da matriz.\n", X, L);
    } else {
        printf("O número %d não está presente na linha %d da matriz.\n", X, L);
    }

    return 0;
}

