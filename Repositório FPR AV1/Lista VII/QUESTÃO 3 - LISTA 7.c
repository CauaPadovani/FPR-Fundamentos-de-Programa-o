/*
Questão 03:
Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto).
*/

#include <stdio.h>
#include <string.h>

struct Employee {
    int matricula;
    char nome[100];
    char genero;
    float salario;
};

void moveEmployees(struct Employee employees[], int size, char genero) {
    int i, j;
    struct Employee temp;
    for (i = 0; i < size; i++) {
        if (employees[i].genero == genero && i > 0) {
            temp = employees[i];
            for (j = i; j > 0; j--) {
                employees[j] = employees[j - 1];
            }
            employees[0] = temp;
        }
    }
}

int main() {
    int n;
    printf("Digite o número de funcionários: ");
    scanf("%d", &n);

    struct Employee funcionarios[n];

    // Preencha o vetor com os dados dos funcionários
    for (int i = 0; i < n; i++) {
        printf("Funcionário %d:\n", i + 1);
        funcionarios[i].matricula = i + 1;
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("Gênero (M/F): ");
        scanf(" %c", &funcionarios[i].genero);  // Espaço em branco para evitar problemas com caracteres em branco no buffer.
        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
    }

    char generoAlvo;
    printf("Digite o gênero a ser movido para o início (M/F): ");
    scanf(" %c", &generoAlvo);

    moveEmployees(funcionarios, n, generoAlvo);

    printf("Funcionários após a movimentação:\n");
    for (int i = 0; i < n; i++) {
        printf("Matrícula: %d, Nome: %s, Gênero: %c, Salário: %.2f\n",
               funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].genero, funcionarios[i].salario);
    }

    return 0;
}

