/*
QUESTÃO 06:
Considere uma loja que mantém em uma
matriz o total vendido por cada funcionário
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por mês) e 10 colunas
(10 funcionários). Pede-se o desenvolvimento
de uma função para cada item abaixo:
a. Calcular o total vendido durante o ano;
b. Dado um mês fornecido pelo usuário,
determinar o total vendido nesse mês;
c. Dado um funcionário fornecido pelo
usuário, determinar o total vendido por ele
durante o ano;
d. Determinar o mês com maior índice de
vendas;
e. Determinar o funcionário que menos
vendeu durante o ano.
*/

#include <stdio.h>

#define MESES 12
#define FUNCIONARIOS 10

// Função para calcular o total vendido durante o ano.
float calcularTotalAnual(float vendas[MESES][FUNCIONARIOS]) {
    float total = 0;
    for (int mes = 0; mes < MESES; mes++) {
        for (int funcionario = 0; funcionario < FUNCIONARIOS; funcionario++) {
            total += vendas[mes][funcionario];
        }
    }
    return total;
}

// Função para determinar o total vendido em um mês fornecido pelo usuário.
float calcularTotalMes(float vendas[MESES][FUNCIONARIOS], int mes) {
    if (mes < 1 || mes > MESES) {
        return -1; // Mês inválido
    }
    float total = 0;
    for (int funcionario = 0; funcionario < FUNCIONARIOS; funcionario++) {
        total += vendas[mes - 1][funcionario];
    }
    return total;
}

// Função para determinar o total vendido por um funcionário durante o ano.
float calcularTotalFuncionario(float vendas[MESES][FUNCIONARIOS], int funcionario) {
    if (funcionario < 1 || funcionario > FUNCIONARIOS) {
        return -1; // Funcionário inválido
    }
    float total = 0;
    for (int mes = 0; mes < MESES; mes++) {
        total += vendas[mes][funcionario - 1];
    }
    return total;
}

// Função para determinar o mês com maior índice de vendas.
int encontrarMaiorMes(float vendas[MESES][FUNCIONARIOS]) {
    float maxVendas = -1;
    int mesMax = 0;
    for (int mes = 0; mes < MESES; mes++) {
        float totalMes = 0;
        for (int funcionario = 0; funcionario < FUNCIONARIOS; funcionario++) {
            totalMes += vendas[mes][funcionario];
        }
        if (totalMes > maxVendas) {
            maxVendas = totalMes;
            mesMax = mes;
        }
    }
    return mesMax + 1; // Adicionamos 1 para tornar o mês baseado em 1 (em vez de 0).
}

// Função para determinar o funcionário que menos vendeu durante o ano.
int encontrarFuncionarioMenosVendendo(float vendas[MESES][FUNCIONARIOS]) {
    float minVendas = calcularTotalFuncionario(vendas, 1);
    int funcionarioMin = 1;

    for (int funcionario = 2; funcionario <= FUNCIONARIOS; funcionario++) {
        float totalFuncionario = calcularTotalFuncionario(vendas, funcionario);
        if (totalFuncionario < minVendas) {
            minVendas = totalFuncionario;
            funcionarioMin = funcionario;
        }
    }
    return funcionarioMin;
}

int main() {
    float vendas[MESES][FUNCIONARIOS]; // Substitua isso pelos valores reais.

    // Exemplo de uso das funções:
    float totalAnual = calcularTotalAnual(vendas);
    printf("Total vendido durante o ano: %.2f\n", totalAnual);

    int mes = 3; // Substitua pelo mês desejado.
    float totalMes = calcularTotalMes(vendas, mes);
    if (totalMes != -1) {
        printf("Total vendido no mês %d: %.2f\n", mes, totalMes);
    } else {
        printf("Mês inválido.\n");
    }

    int funcionario = 5; // Substitua pelo funcionário desejado.
    float totalFuncionario = calcularTotalFuncionario(vendas, funcionario);
    if (totalFuncionario != -1) {
        printf("Total vendido pelo funcionário %d: %.2f\n", funcionario, totalFuncionario);
    } else {
        printf("Funcionário inválido.\n");
    }

    int mesMaiorVendas = encontrarMaiorMes(vendas);
    printf("Mês com maior índice de vendas: %d\n", mesMaiorVendas);

    int funcionarioMenosVendendo = encontrarFuncionarioMenosVendendo(vendas);
    printf("Funcionário que menos vendeu durante o ano: %d\n", funcionarioMenosVendendo);

    return 0;
}

