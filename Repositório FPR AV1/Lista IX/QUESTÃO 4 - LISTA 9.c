/*
Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).
*/

#include <stdio.h>

void binario(int n) {
    if(n > 0) {
        binario(n / 2);
        printf("%d", n % 2);
    }
}

int main() {
    int N;
    printf("Digite um número inteiro: ");
    scanf("%d", &N);
    printf("O número %d na base 2 é: ", N);
    binario(N);
    printf("\n");
    return 0;
}

