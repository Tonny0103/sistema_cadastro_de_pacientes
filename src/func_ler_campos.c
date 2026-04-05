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

struct tm* ler_data_entrada_paciente() {
    struct tm data;
    time_t data_entrada = 0;
    int dia, mes, ano, hora, minuto;
    int data_valida = 0;

    while (data_valida != 1) {
        limpar_console();
        printf("Digite a data de entrada do paciente (dd/mm/aaaa hh:mm): \n");
        scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
        data.tm_year = ano - 1900;
        data.tm_mon = mes - 1;
        data.tm_mday = dia;
        data.tm_hour = hora;
        data.tm_min = minuto;
        data.tm_sec = 0;
        data.tm_isdst = -1;
        data_entrada = mktime(&data);

        if (data_entrada == -1) {
            printf("Erro 5 - Data de entrada do paciente invalida!\n");
            limpar_buffer_entrada();
            tentar_novamente();
        }

        if (data_entrada != -1) data_valida = 1;
    }

    struct tm* data_entrada_formatada = localtime(&data_entrada);

    return data_entrada_formatada;
}

char* ler_nome_medico_paciente() {
    char* nome_medico = NULL;

    while (nome_medico == NULL) {
        limpar_console();
        imprimir_titulo("CADASTRAR PACIENTE");
        printf("Digite o nome do medico: \n");
        nome_medico = ler_string(TAM_NOME_MEDICO);
        if (nome_medico == NULL) tentar_novamente();
    }

    return nome_medico;
}