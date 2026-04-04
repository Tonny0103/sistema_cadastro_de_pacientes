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

        cpf_valido = cpf != NULL && validar_cpf(cpf);

        if (cpf == NULL || !cpf_valido) tentar_novamente();
    }

    return cpf;
}

int ler_origem_paciente() {
    int origem = 0;
    int resultado = 0;

    while (resultado != 1 || origem < 1 || origem > 4) {
        limpar_console();
        imprimir_titulo("CADASTRAR PACIENTE");

        printf("Selecione a origem do paciente: \n");
        printf("1 - Sistema publico\n");
        printf("2 - Sistema privado\n");
        printf("3 - Plano de saude\n");
        printf("4 - Outros convenios\n");

        resultado = scanf("%d", &origem);

        if (resultado != 1) {
            printf("Erro 4 - Entrada invalida!\n");
            limpar_buffer_entrada();
            tentar_novamente();
        } else if (origem < 1 || origem > 4) {
            printf("Erro 5 - Digite uma opcao valida!\n");
            limpar_buffer_entrada();
            tentar_novamente();
        }
    }

    return origem;
}