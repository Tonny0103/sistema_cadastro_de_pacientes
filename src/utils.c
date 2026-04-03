#include "../include/utils.h"
#include <stdio.h>

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}