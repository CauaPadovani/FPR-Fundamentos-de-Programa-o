/*
QUESTÃO 03:
Desenvolver uma função que gere a seguinte
matriz M5x5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

*/

#include <stdio.h>

void gerarMatriz(int matriz[5][5]) {
    int valor = 1;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = valor + j;
        }
        valor++;
    }
}

int main() {
    int matriz[5][5];
    gerarMatriz(matriz);

    // Exibir a matriz gerada
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

