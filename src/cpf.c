#include "../include/cpf.h"

#include <stdio.h>

int cpf_somente_digitos(const char* cpf) {
    int i = 0;
    while (cpf[i] != '\0') {
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
        int valor_numero = cpf[i] - '0';
        soma += valor_numero * multiplicador;
        multiplicador--;
    }

    int resto = soma % 11;
    int digito_verificador = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    return ((cpf[9] - '0') == digito_verificador);
}

int verificar_segundo_digito_verificador(const char* cpf) {
    int soma = 0;
    int multiplicador = 11;

    for (int i = 0; i < 10; i++) {
        int valor_numero = cpf[i] - '0';
        soma += valor_numero * multiplicador;
        multiplicador--;
    }

    int resto = soma % 11;
    int digito_verificador = (resto == 0 || resto == 1) ? 0 : 11 - resto;

    return ((cpf[10] - '0') == digito_verificador);
}

int validar_cpf(const char* cpf) {
    int somente_digitos = cpf_somente_digitos(cpf);
    if (!somente_digitos) {
        printf("Erro 3 - Digite apenas os digitos do CPF!\n");
        return 0;
    }

    int todos_os_digitos_iguais = todos_digitos_iguais(cpf);
    if (todos_os_digitos_iguais) {
        printf("Erro 3 - Todos os digitos do CPF inserido sao iguais!\n");
        return 0;
    }

    int primeiro_digito_valido = verificar_primeiro_digito_verificador(cpf);
    int segundo_digito_valido = verificar_segundo_digito_verificador(cpf);

    if (!primeiro_digito_valido || !segundo_digito_valido) {
        printf("Erro 3 - Digitos verificadores do CPF invalidos!\n");
        return 0;
    }

    return 1;
}