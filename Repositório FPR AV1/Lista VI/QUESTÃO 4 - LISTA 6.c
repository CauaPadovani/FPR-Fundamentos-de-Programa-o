/*
Questão 04:
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão
ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
	a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual
	àquele da mesma linha, porém da coluna anterior – caso exista);
	b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista).
	Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0. 

*/

#include <stdio.h>

#define LINHAS 3
#define COLUNAS 4

int verifica_matriz(int matriz[][COLUNAS], int linhas, int colunas) {
    int i, j;
	
	for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (j < colunas - 1 && matriz[i][j] > matriz[i][j + 1]) {
                return 0;
            }
            if (i > 0 && matriz[i][0] < matriz[i - 1][colunas - 1]) {
                return 0;
            }
        }
    }
    return 1;
}

void main() {
    int M[LINHAS][COLUNAS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("%d\n", verifica_matriz(M, LINHAS, COLUNAS));


}

