
#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    char binario[32];  // Assumindo que o n�mero bin�rio ter� no m�ximo 32 bits
    int decimal = 0, base = 1;

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

    // Ler o n�mero bin�rio do arquivo
    fscanf(arquivo, "%s", binario);

    // Fechar o arquivo
    fclose(arquivo);

    int tamanho = strlen(binario);

    for (int i = tamanho - 1; i >= 0; i--) {
        if (binario[i] != '0' && binario[i] != '1') {
            printf("O numero eh invalido\n");
            return 1;  // Encerrar o programa com c�digo de erro
        }

        decimal += (binario[i] - '0') * base;
        base *= 2;
    }

    printf("O numero na base decimal eh: %d\n", decimal);

    return 0;
}

