/*
Quest�o 04:
Dada uma matriz MLxC, onde L e C s�o constantes, desenvolver uma fun��o que verifique se os elementos da matriz est�o
ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
	a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento ser� maior ou igual
	�quele da mesma linha, por�m da coluna anterior � caso exista);
	b. O primeiro elemento de cada linha deve ser maior ou igual ao �ltimo da linha anterior (caso exista).
	Caso a matriz M atenda aos crit�rios definidos, o valor 1 dever� ser retornado pela fun��o; caso contr�rio, 0. 

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

