#include stdbool.h

typedef struct TLista {
    int valor;
    struct TLista prox;
} TLista;

bool verificaIgualdade(TLista lista1, TLista lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1-valor != lista2-valor) {
            return false;
        }
        lista1 = lista1-prox;
        lista2 = lista2-prox;
    }

    // Se ambas as listas são nulas, então são iguais
    // Se apenas uma delas é nula, então são diferentes
    return (lista1 == NULL && lista2 == NULL);
}

