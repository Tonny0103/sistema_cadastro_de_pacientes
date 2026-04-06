//
// Created by antho on 05/04/2026.
//

#include <stdio.h>

#include "../include/busca.h"
#include "../include/listagem.h"
#include "../include/paciente.h"
#include "../include/utils.h"
#include "../include/menu.h"

void menu_cadastrar_paciente() {
    cadastrar_paciente();
    printf("Paciente cadastrado com sucesso!\n");
    printf("Pressione qualquer tecla para continuar...");
    getchar();
}

int menu_ordenacao(char* titulo) {
    int opcao_ordenacao = 0;
    int termina = 0;

    while (!termina) {
        limpar_buffer_entrada();
        limpar_console();
        imprimir_titulo(titulo);

        printf("Qual metodo de ordenacao deseja utilizar?\n");
        printf("1 - Por trocas\n");
        printf("2 - Merge sort\n");
        int retorno = scanf("%d", &opcao_ordenacao);

        if (retorno != 1) {
            printf("Entrada invalida!\n");
            limpar_buffer_entrada();
            continue;
        }

        if (opcao_ordenacao < 1 || opcao_ordenacao > 2) {
            printf("Opcao invalida!\n");
            limpar_buffer_entrada();
        } else {
            termina = 1;
        }
    }

    return opcao_ordenacao;
}

int menu_busca(char* titulo) {
    int opcao_busca = 0;
    int termina = 0;

    while (!termina) {
        limpar_buffer_entrada();
        limpar_console();
        imprimir_titulo(titulo);

        printf("Qual metodo de ordenacao deseja utilizar?\n");
        printf("1 - Busca linear\n");
        printf("2 - Busca binaria\n");
        int retorno = scanf("%d", &opcao_busca);

        if (retorno != 1) {
            printf("Entrada invalida!\n");
            limpar_buffer_entrada();
            continue;
        }

        if (opcao_busca < 1 || opcao_busca > 2) {
            printf("Opcao invalida!\n");
            limpar_buffer_entrada();
        } else {
            termina = 1;
        }
    }

    return opcao_busca;
}

void menu_listar_pacientes() {
    t_paciente* pacientes = ler_registros();

    int termina = 0;

    while (!termina) {
        limpar_buffer_entrada();
        limpar_console();
        imprimir_titulo("Listagem de Pacientes");

        int opcao_listagem = 0;

        printf("Selecione a forma de listagem: \n");
        printf("1 - Ordem Alfabetica Crescente\n");
        printf("2 - Ordem Alfabetica Decrescente\n");
        printf("3 - Por origem\n");
        printf("4 - Por data de entrada\n");
        printf("5 - Por medico\n");
        printf("6 - Sair\n");
        int retorno = scanf("%d", &opcao_listagem);

        if (retorno != 1) {
            printf("Entrada invalida!\n");
            limpar_buffer_entrada();
            continue;
        }

        limpar_buffer_entrada();
        limpar_console();
        imprimir_titulo("Listagem de Pacientes");

        int opcao_ordenacao = menu_ordenacao("Listagem de Pacientes");

        switch (opcao_listagem) {
            case 1: listar_por_ordem_alfabetica_crescente(pacientes, opcao_ordenacao); break;
            case 2: listar_por_ordem_alfabetica_decrescente(pacientes, opcao_ordenacao); break;
            case 3: listar_por_origem_nome_crescente(pacientes, opcao_ordenacao); break;
            case 4: listar_por_data_entrada_decrescente(pacientes, opcao_ordenacao); break;
            case 5: listar_por_medico_paciente_crescente(pacientes, opcao_ordenacao); break;
            case 6: termina = 1; break;
            default: printf("Opcao invalida!\n");
        }
    }
}

void menu_buscar_pacientes() {
    t_paciente* pacientes = ler_registros();

    int termina = 0;

    while (!termina) {
        limpar_buffer_entrada();
        limpar_console();
        imprimir_titulo("Buscar Pacientes");

        int opcao_busca = 0;
        printf("1 - Buscar por nome\n");
        printf("2 - Buscar por CPF\n");
        printf("3 - Buscar por medico\n");
        printf("4 - Sair\n");
        int retorno = scanf("%d", &opcao_busca);

        if (retorno != 1) {
            printf("Entrada invalida!\n");
            limpar_buffer_entrada();
            continue;
        }

        int metodo_busca = menu_busca("Buscar Pacientes");

        switch (opcao_busca) {
            case 1: buscar_por_nome(pacientes, metodo_busca); break;
            case 2: buscar_por_cpf(pacientes, metodo_busca); break;
            case 3: buscar_por_medico(pacientes, metodo_busca); break;
            case 4: termina = 1; break;
            default: printf("Opcao invalida!\n");
        }
    }
}

void menu_principal() {
    int termina = 0;

    while (!termina) {
        imprimir_titulo("SCP - SISTEMA DE CADASTRO DE PACIENTES");

        int opcao_menu = 0;
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Buscar pacientes\n");
        printf("4 - Sair\n");
        int retorno = scanf("%d", &opcao_menu);

        if (retorno != 1) {
            printf("Entrada invalida!\n");
            limpar_buffer_entrada();
            continue;
        }

        switch (opcao_menu) {
            case 1: menu_cadastrar_paciente(); break;
            case 2: menu_listar_pacientes(); break;
            case 3: menu_buscar_pacientes(); break;
            case 4: termina = 1; break;
            default: printf("Opcao invalida!\n");
        }
    }
}