#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void tentar_novamente() {
    printf("Pressione qualquer tecla para tentar novamente...\n");
    getchar();
}

void limpar_console() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

char* ler_string(int tamanho_string) {
    char* string = (char*) malloc((tamanho_string + 1) * sizeof(char));

    if (fgets(string, tamanho_string + 2, stdin) == NULL) {
        printf("Erro 0 - Problema ao ler entrada do usuario\n");
        free(string);
        return NULL;
    }

    if (string[0] == '\n') {
        printf("Erro 1 - Nenhum dado digitado!\n");

        free(string);
        return NULL;
    }

    size_t tamanho = strlen(string);

    if (tamanho == (tamanho_string + 1) && string[tamanho_string] != '\n') {
        printf("Erro 2 - Numero de caracteres excede o limite (%d)!\n", tamanho_string);

        limpar_buffer_entrada();

        free(string);
        return NULL;
    }

    string[strcspn(string, "\n")] = '\0';

    return string;
}

void imprimir_titulo(char* titulo) {
    printf("========================================\n");
    printf("%s\n", titulo);
    printf("========================================\n");
}

char* converte_data_para_string(struct tm* data) {
    char* data_formatada = (char*) malloc(20 * sizeof(char));
    strftime(data_formatada, 20, "%d/%m/%Y %H:%M", data);
    return data_formatada;
}

void limpa_registro_da_memoria(t_paciente paciente) {
    free(paciente.nome);
    free(paciente.cpf);
    free(paciente.nome_medico);
    free(paciente.observacao_inicial);
}

int proximo_id() {
    FILE *arquivo = fopen("/data/pacientes.csv", "r");

    int id = 0;
    char linha[256];

    while (fgets(linha, 256, arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';

        char* tokens = strtok(linha, ",");
        int temp = atoi(tokens);
        id = temp;
    }

    fclose(arquivo);
    return id + 1;
}