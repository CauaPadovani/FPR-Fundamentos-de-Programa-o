/*
Quest�o 01:
Pede-se o desenvolvimento de uma fun��o que, dada uma string representando um n�mero bin�rio (ou seja, contendo
apenas os caracteres 0 e 1), converta-o para a base decimal.
Notas:
- A fun��o solicitada dever� chamar outra fun��o que validar� se a string representa um n�mero bin�rio. Se n�o
consistir em um n�mero bin�rio, o valor -1 dever� ser retornado; caso contr�rio, o n�mero inteiro decimal
equivalente ser� retornado;
- Durante a leitura das quest�es da prova, ser� apresentado um exemplo que evidencie o processo de transforma��o
de um n�mero bin�rio em decimal.
*/

#include <stdio.h>
#include <string.h>

// Fun��o para validar se a string � um n�mero bin�rio
int valida_binario(char *binario) {
    
	int i;
	
	for(i = 0; binario[i] != '\0'; i++) {
        if(binario[i] != '0' && binario[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Fun��o para converter bin�rio para decimal
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
        printf("A string fornecida n�o � um n�mero bin�rio v�lido.\n");
    }

    return 0;
}

