/*
Questão 04:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.
	Observação: o vetor será considerado ordenado se
	estiver organizado crescentemente em função da
	idade. Porém, no caso de pessoas com a mesma
	idade, estas devem estar ordenadas crescentemente
	pelo nome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    char genero;
    int idade;
};

int comparar_pessoas(const void *p1, const void *p2) {
    const struct Pessoa *a = p1;
    const struct Pessoa *b = p2;

    if (a->idade < b->idade) {
        return -1;
    } else if (a->idade > b->idade) {
        return 1;
    } else {
        return strcmp(a->nome, b->nome);
    }
}

int esta_ordenado(struct Pessoa *pessoas, int n) {
    qsort(pessoas, n, sizeof(struct Pessoa), comparar_pessoas);

    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade < pessoas[i - 1].idade) {
            return 0;
        } else if (pessoas[i].idade == pessoas[i - 1].idade &&
                   strcmp(pessoas[i].nome, pessoas[i - 1].nome) < 0) {
            return 0;
        }
    }

    return 1;
}

