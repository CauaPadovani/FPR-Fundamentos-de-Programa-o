/*
Questão 04 [2,5 pontos]:
Considerando a existência de um vetor, onde cada posição armazena os seguintes dados: nome do aluno, código da
disciplina, nota na AV1 e nota na AV2, pede-se o desenvolvimento de uma função que, dado um vetor nos moldes do
descrito, crie (e retorne) um outro vetor com os seguintes dados em cada posição: código da disciplina, status
(Aprovado, Reprovado ou Em AVF) e a quantidade de alunos nesta situação.

Exemplo:
JOAO PEDRO MARIA ANA CARLOS PAULO KATIA SILVIA GLORIA ANTONIO
FAC   ESD   FPR  FAC  FAC    FPR   ESD   FAC    FPR    ESD
10,0  6,0  10,0  8,0  7,0    5,0   5,0   2,0    4,0    3,0
8,0   7,0   5,0  3,0  7,0    2,0   9,0   4,0    1,0    4,0

FAC        ESD      FPR      FAC      FPR       FAC      ESD
aprovado aprovado aprovado  em AVF reprovado reprovado reprovado
2           2         1        1       2         1        1
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char codigo[10];
    float nota1;
    float nota2;
} Aluno;

typedef struct {
    char codigo[10];
    char status[10];
    int quantidade;
} Resultado;

Resultado* calcularStatus(Aluno* alunos, int tamanho) {
    Resultado* resultados = malloc(tamanho * sizeof(Resultado));
    int contador = 0;

    for(int i = 0; i < tamanho; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2;

        strcpy(resultados[contador].codigo, alunos[i].codigo);

        if(media >= 7) {
            strcpy(resultados[contador].status, "Aprovado");
        } else if(media >= 4) {
            strcpy(resultados[contador].status, "Em AVF");
        } else {
            strcpy(resultados[contador].status, "Reprovado");
        }

        resultados[contador].quantidade = 1;

        for(int j = i + 1; j < tamanho; j++) {
            if(strcmp(alunos[i].codigo, alunos[j].codigo) == 0 && strcmp(resultados[contador].status, alunos[j].status) == 0) {
                resultados[contador].quantidade++;
                i = j;
            }
        }

        contador++;
    }

    return resultados;
}

