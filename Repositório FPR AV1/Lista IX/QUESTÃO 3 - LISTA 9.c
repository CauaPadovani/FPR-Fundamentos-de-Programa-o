/*
Quest�o 03:
Desenvolver uma fun��o recursiva que exiba
todos os m�ltiplos do n�mero N, inferiores ou
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
    printf("Os m�ltiplos de %d que s�o inferiores ou iguais a %d s�o: ", N, V);
    exibir_multiplos(N, V);
    return 0;
}

