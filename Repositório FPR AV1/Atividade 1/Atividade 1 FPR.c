/*
Questão 01:
Pede-se o desenvolvimento de uma função que, dada uma string representando um número binário (ou seja, contendo
apenas os caracteres 0 e 1), converta-o para a base decimal.
Notas:
- A função solicitada deverá chamar outra função que validará se a string representa um número binário. Se não
consistir em um número binário, o valor -1 deverá ser retornado; caso contrário, o número inteiro decimal
equivalente será retornado;
- Durante a leitura das questões da prova, será apresentado um exemplo que evidencie o processo de transformação
de um número binário em decimal.
*/

#include <stdio.h>
#include <string.h>

// Função para validar se a string é um número binário
int valida_binario(char *binario) {
    
	int i;
	
	for(i = 0; binario[i] != '\0'; i++) {
        if(binario[i] != '0' && binario[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Função para converter binário para decimal
int binario_para_decimal(char *binario) {
    if(!valida_binario(binario)) {
        return -1;
    }

    int decimal = 0;
    int base = 1;
    int len = strlen(binario);
    int i;
    
    for(i = len - 1; i >= 0; i--) {
        if(binario[i] == '1') {
            decimal += base;
        }
        base = base * 2;
    }

    return decimal;
}

int main() {
    char binario[] = "1011";
    int decimal = binario_para_decimal(binario);

    if(decimal != -1) {
        printf("O numero decimal equivalente de %s eh %d\n", binario, decimal);
    } else {
        printf("A string fornecida não é um número binário válido.\n");
    }

    return 0;
}

