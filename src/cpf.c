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

int verificar_primeiro_digito_verificador(const char* cpf) {
    int soma = 0;
    int multiplicador = 10;

    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * multiplicador;
        multiplicador--;
    }

    int resto = soma % 11;
    int digito_verificador = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    return (cpf[9] == digito_verificador);
}

int verificar_segundo_digito_verificador(const char* cpf) {
    int soma = 0;
    int multiplicador = 11;

    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * multiplicador;
        multiplicador--;
    }

    int resto = soma % 11;
    int digito_verificador = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    return (cpf[10] == digito_verificador);
}