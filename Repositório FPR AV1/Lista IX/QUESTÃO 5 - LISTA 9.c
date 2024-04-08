/*
Quest�o 05:
Pede-se a implementa��o de uma fun��o
recursiva que exiba os n primeiros termos de
uma PG (Progress�o Geom�trica), onde a1 � o
seu primeiro termo e q a raz�o.
Observa��o: uma PG consiste em uma
sequ�ncia de valores, iniciadas pelo valor a1. Os
demais elementos s�o definidos como o
anterior multiplicado pela raz�o.
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
    int q = 3;  // Raz�o
    int n = 5;  // N�mero de termos

    printf("Os primeiros %d termos da PG s�o: ", n);
    print_pg(a1, q, n);

    return 0;
}

