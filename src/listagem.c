#include <stdlib.h>
#include "../include/listagem.h"
#include <stdio.h>

#include "../include/ordena.h"
#include "../include/utils.h"

void listar_por_ordem_alfabetica_crescente(t_paciente* pacientes, int opcao_ordenacao) {
    limpar_buffer_entrada();
    limpar_console();

    switch (opcao_ordenacao) {
        case 1: ordena_por_troca(pacientes, comparar_nome_crescente); break;
        case 2: merge_sort(pacientes, 0, obter_quantidade_de_registros() - 1, comparar_nome_crescente); break;
    }

    imprimir_titulo("LISTAGEM DE PACIENTES - ORDEM ALFABETICA CRESCENTE");
    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    for (int i = 0; i < obter_quantidade_de_registros(); i++) {
        printar_dados_paciente(pacientes[i]);
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void listar_por_ordem_alfabetica_decrescente(t_paciente* pacientes, int opcao_ordenacao) {
    limpar_buffer_entrada();
    limpar_console();

    switch (opcao_ordenacao) {
        case 1: ordena_por_troca(pacientes, comparar_nome_decrescente); break;
        case 2: merge_sort(pacientes, 0, obter_quantidade_de_registros() - 1, comparar_nome_decrescente); break;
    }

    imprimir_titulo("LISTAGEM DE PACIENTES - ORDEM ALFABETICA DECRESCENTE");
    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    for (int i = 0; i < obter_quantidade_de_registros(); i++) {
        printar_dados_paciente(pacientes[i]);
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void listar_por_origem_nome_crescente(t_paciente* pacientes, int opcao_ordenacao) {
    limpar_buffer_entrada();
    limpar_console();

    switch (opcao_ordenacao) {
        case 1: ordena_por_troca(pacientes, comparar_origem_nome_crescente); break;
        case 2: merge_sort(pacientes, 0, obter_quantidade_de_registros() - 1, comparar_origem_nome_crescente); break;
    }

    imprimir_titulo("LISTAGEM DE PACIENTES - POR ORIGEM E NOME CRESCENTE");
    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    for (int i = 0; i < obter_quantidade_de_registros(); i++) {
        printar_dados_paciente(pacientes[i]);
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void listar_por_data_entrada_decrescente(t_paciente* pacientes, int opcao_ordenacao) {
    limpar_buffer_entrada();
    limpar_console();

    switch (opcao_ordenacao) {
        case 1: ordena_por_troca(pacientes, comparar_data_entrada_decrescente); break;
        case 2: merge_sort(pacientes, 0, obter_quantidade_de_registros() - 1, comparar_data_entrada_decrescente); break;
    }

    imprimir_titulo("LISTAGEM DE PACIENTES - POR DATA DE ENTRADA");
    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    for (int i = 0; i < obter_quantidade_de_registros(); i++) {
        printar_dados_paciente(pacientes[i]);
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void listar_por_medico_paciente_crescente(t_paciente* pacientes, int opcao_ordenacao) {
    limpar_buffer_entrada();
    limpar_console();

    switch (opcao_ordenacao) {
        case 1: ordena_por_troca(pacientes, comparar_medico_paciente_crescente); break;
        case 2: merge_sort(pacientes, 0, obter_quantidade_de_registros() - 1, comparar_medico_paciente_crescente); break;
    }

    imprimir_titulo("LISTAGEM DE PACIENTES - POR MEDICO E NOME DO PACIENTE");
    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    for (int i = 0; i < obter_quantidade_de_registros(); i++) {
        printar_dados_paciente(pacientes[i]);
    }

    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}