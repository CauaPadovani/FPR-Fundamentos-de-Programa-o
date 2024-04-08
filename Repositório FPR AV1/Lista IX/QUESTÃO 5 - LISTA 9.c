/*
Questão 05:
Pede-se a implementação de uma função
recursiva que exiba os n primeiros termos de
uma PG (Progressão Geométrica), onde a1 é o
seu primeiro termo e q a razão.
Observação: uma PG consiste em uma
sequência de valores, iniciadas pelo valor a1. Os
demais elementos são definidos como o
anterior multiplicado pela razão.
*/

#include<stdio.h>

void print_pg(int a1, int q, int n) {
    if(n > 0) {
        printf("%d ", a1);
        print_pg(a1*q, q, n-1);
    }
}

int main() {
    int a1 = 2; // Primeiro termo
    int q = 3;  // Razão
    int n = 5;  // Número de termos

    printf("Os primeiros %d termos da PG são: ", n);
    print_pg(a1, q, n);

    return 0;
}

