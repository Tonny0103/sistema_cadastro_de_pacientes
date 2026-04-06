#include "../include/busca.h"

#include <stdio.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/metodo_busca.h"

void buscar_por_nome(t_paciente* registros, int metodo_busca) {
    limpar_buffer_entrada();
    limpar_console();
    imprimir_titulo("Buscar por nome");

    char nome[40];
    printf("Digite o nome do paciente: \n");
    scanf("%s", nome);
    nome[strcspn(nome, "\n")] = '\0';
    t_paciente paciente;
    paciente.nome = nome;

    t_paciente* resultado = NULL;
    if (metodo_busca == 1) {
        resultado = busca_linear(registros, obter_quantidade_de_registros(), paciente, comparar_nomes_iguais);
    } else {
        resultado = busca_binaria(registros, 0, obter_quantidade_de_registros() - 1, paciente, comparar_nomes_iguais);
    }

    if (resultado == NULL) {
        printf("Paciente não encontrado!\n");
        return;
    }

    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    printar_dados_paciente(*resultado);
}

void buscar_por_cpf(t_paciente* registros, int metodo_busca) {
    limpar_buffer_entrada();
    limpar_console();
    imprimir_titulo("Buscar por CPF");

    char nome[11];
    printf("Digite o CPF do paciente: \n");
    scanf("%s", nome);
    nome[strcspn(nome, "\n")] = '\0';
    t_paciente paciente;
    paciente.nome = nome;

    t_paciente* resultado = NULL;
    if (metodo_busca == 1) {
        resultado = busca_linear(registros, obter_quantidade_de_registros(), paciente, comparar_cpf_paciente);
    } else {
        resultado = busca_binaria(registros, 0, obter_quantidade_de_registros() - 1, paciente, comparar_cpf_paciente);
    }

    if (resultado == NULL) {
        printf("Paciente não encontrado!\n");
        return;
    }

    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    printar_dados_paciente(*resultado);
}

void buscar_por_medico(t_paciente* registros, int metodo_busca) {
    limpar_buffer_entrada();
    limpar_console();
    imprimir_titulo("Buscar por nome do medico");

    char nome[11];
    printf("Digite o nome do medico do paciente: \n");
    scanf("%s", nome);
    nome[strcspn(nome, "\n")] = '\0';
    t_paciente paciente;
    paciente.nome = nome;

    t_paciente* resultado = NULL;
    if (metodo_busca == 1) {
        resultado = busca_linear(registros, obter_quantidade_de_registros(), paciente, comparar_nome_medico_igual);
    } else {
        resultado = busca_binaria(registros, 0, obter_quantidade_de_registros() - 1, paciente, comparar_nome_medico_igual);
    }

    if (resultado == NULL) {
        printf("Paciente não encontrado!\n");
        return;
    }

    printf("|ID|\t |Nome|\t |Nome medico|\t\n");
    printf("|%d|\t |%s|\t |%s|\n", resultado->id, resultado->nome, resultado->nome_medico);
}