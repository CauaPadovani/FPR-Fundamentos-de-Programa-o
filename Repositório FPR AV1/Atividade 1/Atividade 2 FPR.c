/*
Questão 02:
Considere a existência de um vetor V1 de inteiros, contendo quant elementos. Implementar uma função que, dado o
vetor V1, preencha um vetor V2, do qual cada posição consistirá em um struct com os seguintes campos:
- valor: cada valor do vetor V1;
- ocorrencias: quantidade de ocorrências deste valor em V1;
- posicao: posição da primeira ocorrência do valor em V1.
*/
#include <stdio.h>

typedef struct {
    int valor;
    int ocorrencias;
    int posicao;
} Elemento;

void preencheVetor(int* V1, Elemento* V2, int quant) {
    for (int i = 0; i < quant; i++) {
        V2[i].valor = V1[i];
        V2[i].ocorrencias = 0;
        V2[i].posicao = -1;

        for (int j = 0; j < quant; j++) {
            if (V1[j] == V1[i]) {
                V2[i].ocorrencias++;
                if (V2[i].posicao == -1) {
                    V2[i].posicao = j;
                }
            }
        }
    }
}

int main() {
    int quant = 5;
    int V1[5] = {1, 2, 2, 3, 3};
    Elemento V2[5];

    preencheVetor(V1, V2, quant);

    for (int i = 0; i < quant; i++) {
        printf("Valor: %d, Ocorrencias: %d, Posicao: %d\n", V2[i].valor, V2[i].ocorrencias, V2[i].posicao);
    }

    return 0;
}

