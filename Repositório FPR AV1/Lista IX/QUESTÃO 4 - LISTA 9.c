/*
Quest�o 04:
Fazer uma fun��o recursiva que, dado um
n�mero inteiro N, exiba o mesmo na base 2
(bin�ria).
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
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &N);
    printf("O n�mero %d na base 2 �: ", N);
    binario(N);
    printf("\n");
    return 0;
}

