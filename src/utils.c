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
    free(paciente.data_entrada);
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

struct tm* ler_data_entrada_resgistro(char* token) {
    struct tm* data = (struct tm*) malloc(sizeof(struct tm));
    sscanf(token, "%d/%d/%d %d:%d", &data->tm_mday, &data->tm_mon, &data->tm_year, &data->tm_hour, &data->tm_min);
    data->tm_year -= 1900;
    data->tm_mon -= 1;
    data->tm_sec = 0;
    data->tm_isdst = -1;
    return data;
}

int obter_quantidade_de_registros() {
    return proximo_id() - 1;
}

t_paciente* ler_registros() {
    FILE *arquivo = fopen("pacientes.csv", "r");

    int quantidade_registros = obter_quantidade_de_registros();
    t_paciente* pacientes = (t_paciente*) malloc(quantidade_registros * sizeof(t_paciente));

    char linha[256];
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) && i < quantidade_registros) {
        linha[strcspn(linha, "\n")] = '\0';

        t_paciente paciente;
        char* token = strtok(linha, ",");
        paciente.id = atoi(token);

        token = strtok(NULL, ",");
        paciente.nome = strdup(token);

        token = strtok(NULL, ",");
        paciente.cpf = strdup(token);

        token = strtok(NULL, ",");
        paciente.origem = atoi(token);

        token = strtok(NULL, ",");
        paciente.data_entrada = ler_data_entrada_resgistro(token);

        token = strtok(NULL, ",");
        paciente.nome_medico = strdup(token);

        token = strtok(NULL, ",");
        paciente.observacao_inicial = strdup(token);

        pacientes[i] = paciente;
        i++;
    }

    fclose(arquivo);
    return pacientes;
}

char* obtem_origem_registrada(int origem) {
    char* origem_string = (char*) malloc(30 * sizeof(char));

    switch (origem) {
        case 1: sprintf(origem_string, "Sistema publico"); break;
        case 2: sprintf(origem_string, "Sistema privado"); break;
        case 3: sprintf(origem_string, "Plano de saude"); break;
        case 4: sprintf(origem_string, "Outros convenios"); break;
    }

    return origem_string;
}