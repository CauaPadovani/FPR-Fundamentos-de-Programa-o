/*
Questão 03:
Pede-se o desenvolvimento de uma função recursiva que, dada uma matriz M de L linhas e C colunas, onde L e C são
constantes, e três linhas L1, L2 e L3, altere os elementos de L3, de forma que cada um consista na soma dos elementos
de L1 e L2, conforme ilustrado no exemplo abaixo: 
			ANTES 								DEPOIS	
			0 	1 5 9 2 					0 	1 5 9 2
			1 	0 3 4 8 	L1 				1 	0 3 4 8 	L1
			2 	1 1 3 7 					2 	1 1 3 7
			3 	7 9 6 5 	L2				3 	7 9 6 5 	L2
			4 	1 3 2 4						4 	1 3 2 4
			5 	8 6 8 7						5 	8 6 8 7
			6 	9 7 2 1 	L3 				6 	7 12 10 13 	L3
			7 	4 6 7 8						7 	4 6 7 8
			  	0 1 2 3 						0 1 2 3
*/

#include <stdio.h>

// Defina as constantes L e C
#define L 8
#define C 4

// Função para imprimir a matriz
void imprimirMatriz(int matriz[L][C]) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para alterar a matriz
void alterarMatriz(int matriz[L][C], int l1, int l2, int l3, int col) {
    if (col == C) {
        // Base case: chegamos ao final da coluna, saímos da recursão
        return;
    }
    
    // Altere o elemento em l3 na coluna atual para a soma dos elementos em l1 e l2
    matriz[l3][col] = matriz[l1][col] + matriz[l2][col];
    
    // Chame a função recursivamente para a próxima coluna
    alterarMatriz(matriz, l1, l2, l3, col + 1);
}

int main() {
    int matriz[L][C] = {
        {0, 1, 5, 9},
        {1, 0, 3, 4},
        {2, 1, 1, 3},
        {3, 7, 9, 6},
        {4, 1, 3, 2},
        {5, 8, 6, 8},
        {6, 9, 7, 2},
        {7, 4, 6, 7}
    };

    // Linhas a serem alteradas
    int l1 = 1;
    int l2 = 3;
    int l3 = 6;

    printf("ANTES:\n");
    imprimirMatriz(matriz);

    alterarMatriz(matriz, l1, l2, l3, 0);

    printf("\nDEPOIS:\n");
    imprimirMatriz(matriz);

    return 0;
}

