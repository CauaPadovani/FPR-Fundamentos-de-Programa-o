/*
QUESTÃO 01:
Faça uma função que, dada uma matriz M8×5 de
reais, gere a matriz Mt, sua transposta.
*/

#include <stdio.h>


void transposeMatrix(float M[8][5], float Mt[5][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 5; j++) {
            Mt[j][i] = M[i][j];
        }
    }
}


int main() {
    float M[8][5]; // Sua matriz M 8x5
    float Mt[5][8]; // Matriz transposta Mt

    // Preencha a matriz M com os valores desejados

    // Chame a função para calcular a matriz transposta
    transposeMatrix(M, Mt);

    // Imprima a matriz transposta Mt
    printf("Matriz transposta Mt:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%f ", Mt[i][j]);
        }
        printf("\n");
    }

    return 0;
}


