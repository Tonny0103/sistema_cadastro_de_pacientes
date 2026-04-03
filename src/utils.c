#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

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