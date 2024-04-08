/*
Questão 05:
O histórico de um aluno é representado por um
vetor de structs onde cada posição armazena o
código da disciplina cursada, semestre e ano
que a cumpriu e a média final na disciplina.
Implementar uma função que exiba o histórico
do aluno com o seguinte formato:
	NomeDisciplina1 (código1) MédiaDisciplina1
	NomeDisciplina2 (código2) MédiaDisciplina2
	.
	.
	.
	NomeDisciplinaN (códigoN) MédiaDisciplinaN
	Coeficiente de rendimento: CR

Observações:
	1. Para obter os dados da disciplina, um outro
	vetor de structs deve ser consultado. Este,
	por sua vez, armazena para cada disciplina
	do curso as seguintes informações: código,
	nome e número de créditos;
	2. O coeficiente de rendimento consiste em
	uma média ponderada de todos os graus
	atribuídos às disciplinas cursadas, onde os
	pesos são representados pelo número de
	créditos da disciplina;
	3. Todos os dados em negrito apresentados no
	formato do histórico devem ser obtidos a
	partir dos vetores.
*/

#include <stdio.h>
#include <string.h>

struct disciplina {
    int codigo;
    char nome[50];
    int creditos;
};

struct historico {
    int codigo;
    int semestre;
    int ano;
    float media;
};

void exibirHistorico(struct disciplina *disciplinas, struct historico *historico, int n) {
    float cr = 0.0;
    printf("Histórico do aluno:\n");
    for (int i = 0; i < n; i++) {
        int codigo = historico[i].codigo;
        int semestre = historico[i].semestre;
        int ano = historico[i].ano;
        float media = historico[i].media;
        char nome[50];
        int creditos;
        for (int j = 0; j < n; j++) {
            if (disciplinas[j].codigo == codigo) {
                strcpy(nome, disciplinas[j].nome);
                creditos = disciplinas[j].creditos;
                break;
            }
        }
        printf("%s (%d) %.2f\n", nome, codigo, media);
        cr += media * creditos;
    }
    cr /= n;
    printf("Coeficiente de rendimento: %.2f\n", cr);
}

int main() {
    struct disciplina disciplinas[] = {
        {1, "Matemática", 4},
        {2, "Física", 4},
        {3, "Química", 4},
        {4, "Programação", 6},
        {5, "Inglês", 2}
    };
    
    struct historico historico[] = {
        {1, 1, 2019, 8.5},
        {2, 1, 2019, 7.0},
        {3, 2, 2019, 6.5},
        {4, 2, 2019, 9.0},
        {5, 2, 2019, 10.0}
    };
    
    int n_disciplinas = sizeof(disciplinas) / sizeof(disciplinas[0]);
    int n_historico = sizeof(historico) / sizeof(historico[0]);
    
    exibirHistorico(disciplinas, historico, n_historico);
    
    return 0;
}

