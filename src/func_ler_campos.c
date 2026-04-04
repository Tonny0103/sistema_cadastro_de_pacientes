#include "../include/func_ler_campos.h"
#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"

char* ler_nome_paciente() {
    char* nome_paciente = NULL;

    while (nome_paciente == NULL) {
        limpar_console();
        printf("==========CADASTRAR PACIENTE==========\n");
        printf("Digite o nome do paciente: \n");
        nome_paciente = ler_string(TAM_NOME_PACIENTE);
        if (nome_paciente == NULL) tentar_novamente();
    }

    return nome_paciente;
}
