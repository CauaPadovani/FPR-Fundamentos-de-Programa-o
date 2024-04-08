 /*
 Questão 05:
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
	a. M1: matriz contendo números inteiros quaisquer;
	b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são
definidos da seguinte forma:
	 M2ij = 0 ? M3ij = M1ij
	 M2ij = 1 ? M3ij = soma dos elementos da linha i com os da coluna j da matriz.
 */
 
 #include <stdio.h>

void gerarMatrizM3(int M1[10][10], int M2[10][10], int M3[10][10]) {
    
	int i, j, k;
	
	for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (M2[i][j] == 0) {
                M3[i][j] = M1[i][j];
            } else if (M2[i][j] == 1) {
                int soma = 0;
                for (k = 0; k < 10; k++) {
                    soma += M1[i][k] + M1[k][j];
                }
                M3[i][j] = soma;
            }
        }
    }
}

void main() {
    int M1[10][10];  // Matriz com números inteiros quaisquer
    int M2[10][10];  // Matriz com valores 0 ou 1
    int M3[10][10];  // Matriz resultante
	int i, j;
    // Preencha as matrizes M1 e M2 com seus valores

    gerarMatrizM3(M1, M2, M3);

    // Exiba a matriz resultante M3
    printf("Matriz M3:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", M3[i][j]);
        }
        printf("\n");
    }
}

