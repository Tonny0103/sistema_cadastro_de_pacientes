#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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