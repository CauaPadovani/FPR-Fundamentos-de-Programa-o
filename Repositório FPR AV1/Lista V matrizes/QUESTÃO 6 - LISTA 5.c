/*
QUEST�O 06:
Considere uma loja que mant�m em uma
matriz o total vendido por cada funcion�rio
pelos diversos meses do ano. Ou seja, uma
matriz de 12 linhas (uma por m�s) e 10 colunas
(10 funcion�rios). Pede-se o desenvolvimento
de uma fun��o para cada item abaixo:
a. Calcular o total vendido durante o ano;
b. Dado um m�s fornecido pelo usu�rio,
determinar o total vendido nesse m�s;
c. Dado um funcion�rio fornecido pelo
usu�rio, determinar o total vendido por ele
durante o ano;
d. Determinar o m�s com maior �ndice de
vendas;
e. Determinar o funcion�rio que menos
vendeu durante o ano.
*/

#include <stdio.h>

#define MESES 12
#define FUNCIONARIOS 10

// Fun��o para calcular o total vendido durante o ano.
float calcularTotalAnual(float vendas[MESES][FUNCIONARIOS]) {
    float total = 0;
    for (int mes = 0; mes < MESES; mes++) {
        for (int funcionario = 0; funcionario < FUNCIONARIOS; funcionario++) {
            total += vendas[mes][funcionario];
        }
    }
    return total;
}

// Fun��o para determinar o total vendido em um m�s fornecido pelo usu�rio.
float calcularTotalMes(float vendas[MESES][FUNCIONARIOS], int mes) {
    if (mes < 1 || mes > MESES) {
        return -1; // M�s inv�lido
    }
    float total = 0;
    for (int funcionario = 0; funcionario < FUNCIONARIOS; funcionario++) {
        total += vendas[mes - 1][funcionario];
    }
    return total;
}

// Fun��o para determinar o total vendido por um funcion�rio durante o ano.
float calcularTotalFuncionario(float vendas[MESES][FUNCIONARIOS], int funcionario) {
    if (funcionario < 1 || funcionario > FUNCIONARIOS) {
        return -1; // Funcion�rio inv�lido
    }
    float total = 0;
    for (int mes = 0; mes < MESES; mes++) {
        total += vendas[mes][funcionario - 1];
    }
    return total;
}

// Fun��o para determinar o m�s com maior �ndice de vendas.
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
    return mesMax + 1; // Adicionamos 1 para tornar o m�s baseado em 1 (em vez de 0).
}

// Fun��o para determinar o funcion�rio que menos vendeu durante o ano.
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

    // Exemplo de uso das fun��es:
    float totalAnual = calcularTotalAnual(vendas);
    printf("Total vendido durante o ano: %.2f\n", totalAnual);

    int mes = 3; // Substitua pelo m�s desejado.
    float totalMes = calcularTotalMes(vendas, mes);
    if (totalMes != -1) {
        printf("Total vendido no m�s %d: %.2f\n", mes, totalMes);
    } else {
        printf("M�s inv�lido.\n");
    }

    int funcionario = 5; // Substitua pelo funcion�rio desejado.
    float totalFuncionario = calcularTotalFuncionario(vendas, funcionario);
    if (totalFuncionario != -1) {
        printf("Total vendido pelo funcion�rio %d: %.2f\n", funcionario, totalFuncionario);
    } else {
        printf("Funcion�rio inv�lido.\n");
    }

    int mesMaiorVendas = encontrarMaiorMes(vendas);
    printf("M�s com maior �ndice de vendas: %d\n", mesMaiorVendas);

    int funcionarioMenosVendendo = encontrarFuncionarioMenosVendendo(vendas);
    printf("Funcion�rio que menos vendeu durante o ano: %d\n", funcionarioMenosVendendo);

    return 0;
}

