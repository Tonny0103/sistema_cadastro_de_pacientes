#include "../include/busca.h"

#include <stdio.h>
#include <string.h>

#include "../include/utils.h"
#include "../include/metodo_busca.h"
#include "../include/ordena.h"

void buscar_por_nome(t_paciente* registros, int metodo_busca) {
    limpar_console();
    imprimir_titulo("Buscar por nome");

    char nome[40];
    printf("Digite o nome do paciente: \n");

    if (fgets(nome, sizeof(nome), stdin) == NULL) {
        printf("Erro ao ler o nome!\n");
        return;
    }

    nome[strcspn(nome, "\n")] = '\0';
    t_paciente paciente;
    paciente.nome = nome;

    t_paciente* resultado = NULL;
    if (metodo_busca == 1) {
        resultado = busca_linear(registros, obter_quantidade_de_registros(), paciente, comparar_nomes_iguais);
    } else {
        merge_sort(registros, 0, obter_quantidade_de_registros() - 1, comparar_nome_crescente);
        resultado = busca_binaria(registros, 0, obter_quantidade_de_registros() - 1, paciente, comparar_nomes_iguais);
    }

    if (resultado == NULL) {
        printf("Paciente nao encontrado!\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getchar();
        return;
    }

    printf("|ID|\t\t |Nome|\t\t |CPF|\t\t |Origem|\t\t |Data de entrada|\t\t |Nome medico|\t\t |Observacao inicial|\n");
    printar_dados_paciente(*resultado);

    printf("Pressione qualquer tecla para continuar...\n");
    limpar_buffer_entrada();
    getchar();
}

void buscar_por_cpf(t_paciente* registros, int metodo_busca) {
    limpar_console();
    imprimir_titulo("Buscar por CPF");

    char cpf[11];
    printf("Digite o CPF do paciente: \n");

    if (fgets(cpf, sizeof(cpf), stdin) == NULL) {
        printf("Erro ao ler o nome!\n");
        return;
    }

    cpf[strcspn(cpf, "\n")] = '\0';
    t_paciente paciente;
    paciente.cpf = cpf;

    t_paciente* resultado = NULL;
    if (metodo_busca == 1) {
        resultado = busca_linear(registros, obter_quantidade_de_registros(), paciente, comparar_cpf_paciente);
    } else {
        merge_sort(registros, 0, obter_quantidade_de_registros() - 1, comparar_cpf_paciente);
        resultado = busca_binaria(registros, 0, obter_quantidade_de_registros() - 1, paciente, comparar_cpf_paciente);
    }

    if (resultado == NULL) {
        printf("Paciente nao encontrado!\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getchar();
        return;
    }

    printf("|ID|\t |Nome|\t |CPF|\t |Origem|\t |Data de entrada|\t |Nome medico|\t |Observacao inicial|\n");
    printar_dados_paciente(*resultado);
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}

void buscar_todos_por_medico(t_paciente* registros, int n, char* nome_medico) {
    int encontrou = 0;

    printf("|ID|\t |Nome|\t |Nome medico|\t\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(registros[i].nome_medico, nome_medico) == 0) {
            if (!encontrou) {
                printf("Pacientes encontrados para o medico \"%s\":\n", nome_medico);
                printf("|ID|\t |Nome|\t |CPF|\t |Nome medico|\n");
            }

            printf("|%d|\t |%s|\t |%s|\t |%s|\n",
                   registros[i].id,
                   registros[i].nome,
                   registros[i].cpf,
                   registros[i].nome_medico);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum paciente encontrado para esse medico.\n");
    }
}

void buscar_por_medico(t_paciente* registros) {
    limpar_buffer_entrada();
    limpar_console();
    imprimir_titulo("Buscar por nome do medico");

    char nome_medico[40];
    printf("Digite o nome do medico do paciente: \n");
    fgets(nome_medico, sizeof(nome_medico), stdin);
    nome_medico[strcspn(nome_medico, "\n")] = '\0';
    t_paciente paciente;
    paciente.nome_medico = nome_medico;

    buscar_todos_por_medico(registros, obter_quantidade_de_registros(), nome_medico);


    limpar_buffer_entrada();
    printf("Pressione qualquer tecla para continuar...\n");
    getchar();
}