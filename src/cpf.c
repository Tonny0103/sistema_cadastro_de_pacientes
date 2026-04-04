#include "../include/cpf.h"

int cpf_somente_digitos(const char* cpf) {
    int i = 0;
    while (cpf[i] == '\0') {
        if (cpf[i] < '0' || cpf[i] > '9') return 0;
        i++;
    }

    return 1;
}

int todos_digitos_iguais(const char* cpf) {
    int contador = 0;

    int i = 0;
    while (cpf[i] != '\0') {
        if (cpf[i] == cpf[i + 1]) contador++;
        i++;
    }

    return (contador == i - 1);
}