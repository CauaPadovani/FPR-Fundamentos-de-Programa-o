
#include <stdio.h>

void decimalParaBinario(int decimal, char binario[]) {
    int indice = 0;

    // Caso especial para o n�mero 0
    if (decimal == 0) {
        binario[indice++] = '0';
    }

    while (decimal > 0) {
        binario[indice++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Adicionando o caractere nulo ao final da string
    binario[indice] = '\0';

    // Invertendo a string bin�ria
    int i, j;
    for (i = 0, j = indice - 1; i < j; i++, j--) {
        char temp = binario[i];
        binario[i] = binario[j];
        binario[j] = temp;
    }
}

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    int decimal;
    char binario[32];  // Assumindo que o n�mero bin�rio ter� no m�ximo 32 bits

    // Solicitar o nome do arquivo ao usu�rio
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Abrir o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;  // Encerrar o programa com c�digo de erro
    }

    // Ler o n�mero decimal do arquivo
    fscanf(arquivo, "%d", &decimal);

    // Fechar o arquivo
    fclose(arquivo);

    // Realizar a convers�o
    decimalParaBinario(decimal, binario);

    printf("O numero na base binaria eh: %s\n", binario);

    return 0;
}

