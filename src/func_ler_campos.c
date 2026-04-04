#include "../include/func_ler_campos.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/cpf.h"
#include "../include/utils.h"

char* ler_nome_paciente() {
    char* nome_paciente = NULL;

    while (nome_paciente == NULL) {
        limpar_console();
        imprimir_titulo("CADASTRAR PACIENTE");
        printf("Digite o nome do paciente: \n");
        nome_paciente = ler_string(TAM_NOME_PACIENTE);
        if (nome_paciente == NULL) tentar_novamente();
    }

    return nome_paciente;
}

char* ler_cpf_paciente() {
    char* cpf = NULL;
    int cpf_valido = 0;

    while (cpf == NULL || !cpf_valido) {
        limpar_console();
        imprimir_titulo("CADASTRAR PACIENTE");

        printf("Digite o CPF do paciente (somente os digitos): \n");
        cpf = ler_string(TAM_CPF_PACIENTE);
        if (cpf == NULL) tentar_novamente();

        if (!validar_cpf(cpf)) tentar_novamente(); else cpf_valido = 1;
    }
}