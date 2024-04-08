/*
Questão 03:
Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.
*/

#include <stdio.h>

void exibir_multiplos(int N, int V) {
    if (V < N) {
        return;
    }
    exibir_multiplos(N, V - N);
    printf("%d ", V);
}

int main() {
    int N = 3;
    int V = 20;
    printf("Os múltiplos de %d que são inferiores ou iguais a %d são: ", N, V);
    exibir_multiplos(N, V);
    return 0;
}

