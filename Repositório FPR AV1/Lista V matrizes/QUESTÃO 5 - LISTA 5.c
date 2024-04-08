/*
QUESTÃO 05:
Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante. */

#include <stdio.h>

void somaColunas(int M[10][8], int V[8]) {
    for (int coluna = 0; coluna < 8; coluna++) {
        V[coluna] = 0; // Inicialize o elemento do vetor com zero
        for (int linha = 0; linha < 10; linha++) {
            V[coluna] += M[linha][coluna]; // Adicione o valor da célula à soma da coluna
        }
    }
}

int main() {
    int M[10][8] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {9, 10, 11, 12, 13, 14, 15, 16},
        {17, 18, 19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30, 31, 32},
        {33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48},
        {49, 50, 51, 52, 53, 54, 55, 56},
        {57, 58, 59, 60, 61, 62, 63, 64},
        {65, 66, 67, 68, 69, 70, 71, 72},
        {73, 74, 75, 76, 77, 78, 79, 80}
    };
    
    int V[8];
    
    somaColunas(M, V);
    
    for (int i = 0; i < 8; i++) {
        printf("V[%d] = %d\n", i, V[i]);
    }
    
    return 0;
}

