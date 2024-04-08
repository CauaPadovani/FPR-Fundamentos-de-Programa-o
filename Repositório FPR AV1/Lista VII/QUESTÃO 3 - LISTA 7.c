/*
Quest�o 03:
Considere a exist�ncia de um vetor de structs
com quant posi��es, onde cada uma destas
armazena os seguintes dados sobre os
funcion�rios de uma empresa: matricula (int),
nome (string), g�nero (char) e sal�rio (float).
Pede-se uma fun��o que, dado um g�nero,
desloque todos os funcion�rios deste g�nero
para o in�cio do vetor (e, consequentemente, os
funcion�rios do outro g�nero ficar�o ao final do
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
    printf("Digite o n�mero de funcion�rios: ");
    scanf("%d", &n);

    struct Employee funcionarios[n];

    // Preencha o vetor com os dados dos funcion�rios
    for (int i = 0; i < n; i++) {
        printf("Funcion�rio %d:\n", i + 1);
        funcionarios[i].matricula = i + 1;
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        printf("G�nero (M/F): ");
        scanf(" %c", &funcionarios[i].genero);  // Espa�o em branco para evitar problemas com caracteres em branco no buffer.
        printf("Sal�rio: ");
        scanf("%f", &funcionarios[i].salario);
    }

    char generoAlvo;
    printf("Digite o g�nero a ser movido para o in�cio (M/F): ");
    scanf(" %c", &generoAlvo);

    moveEmployees(funcionarios, n, generoAlvo);

    printf("Funcion�rios ap�s a movimenta��o:\n");
    for (int i = 0; i < n; i++) {
        printf("Matr�cula: %d, Nome: %s, G�nero: %c, Sal�rio: %.2f\n",
               funcionarios[i].matricula, funcionarios[i].nome, funcionarios[i].genero, funcionarios[i].salario);
    }

    return 0;
}

