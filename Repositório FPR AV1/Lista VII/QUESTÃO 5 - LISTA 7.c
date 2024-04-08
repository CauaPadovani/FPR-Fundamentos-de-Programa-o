/*
Quest�o 05:
O hist�rico de um aluno � representado por um
vetor de structs onde cada posi��o armazena o
c�digo da disciplina cursada, semestre e ano
que a cumpriu e a m�dia final na disciplina.
Implementar uma fun��o que exiba o hist�rico
do aluno com o seguinte formato:
	NomeDisciplina1 (c�digo1) M�diaDisciplina1
	NomeDisciplina2 (c�digo2) M�diaDisciplina2
	.
	.
	.
	NomeDisciplinaN (c�digoN) M�diaDisciplinaN
	Coeficiente de rendimento: CR

Observa��es:
	1. Para obter os dados da disciplina, um outro
	vetor de structs deve ser consultado. Este,
	por sua vez, armazena para cada disciplina
	do curso as seguintes informa��es: c�digo,
	nome e n�mero de cr�ditos;
	2. O coeficiente de rendimento consiste em
	uma m�dia ponderada de todos os graus
	atribu�dos �s disciplinas cursadas, onde os
	pesos s�o representados pelo n�mero de
	cr�ditos da disciplina;
	3. Todos os dados em negrito apresentados no
	formato do hist�rico devem ser obtidos a
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
    printf("Hist�rico do aluno:\n");
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
        {1, "Matem�tica", 4},
        {2, "F�sica", 4},
        {3, "Qu�mica", 4},
        {4, "Programa��o", 6},
        {5, "Ingl�s", 2}
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

