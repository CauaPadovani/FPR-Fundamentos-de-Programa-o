/*
QUEST�O 02:
Desenvolver uma fun��o que, dada uma matriz
M15�20, determine se um n�mero X se encontra
na linha L da matriz. 
*/

#include <stdio.h>

// Fun��o para verificar se um n�mero X est� presente na linha L da matriz
int verificaNumeroNaLinha(int matriz[15][20], int L, int X) {
    // Verifica se L est� dentro dos limites da matriz
    if (L < 0 || L >= 15) {
        return 0; // L est� fora dos limites da matriz
    }

    for (int coluna = 0; coluna < 20; coluna++) {
        if (matriz[L][coluna] == X) {
            return 1; // O n�mero X est� presente na linha L
        }
    }

    return 0; // O n�mero X n�o est� presente na linha L
}

int main() {
    int matriz[15][20] = {
        // Aqui voc� deve inicializar a matriz com seus valores
        // Por exemplo, voc� pode preench�-la com valores de teste.
    };

    int L = 7; // Linha que voc� deseja verificar
    int X = 42; // N�mero que voc� deseja encontrar

    int resultado = verificaNumeroNaLinha(matriz, L, X);

    if (resultado) {
        printf("O n�mero %d est� presente na linha %d da matriz.\n", X, L);
    } else {
        printf("O n�mero %d n�o est� presente na linha %d da matriz.\n", X, L);
    }

    return 0;
}

