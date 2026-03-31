/*
 * @Autor: Anthonny Gabriell Marins Alves
 * @Descrição: Arquivo de cabeçalho para definir o TAD do paciente e também suas funções.
 */
#ifndef SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H
#define SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H
#include <time.h>

typedef struct {
    int id;
    char nome[40];
    char cpf[11];
    int origem; // 1 - Sistema público; 2 - Sistema privado; 3 - Plano de saúde; 4 - Outros convênios
    struct tm data_entrada;
    char nome_medico[40];
    char *observacao_inicial;
} paciente;

void cadastrar_paciente();
void editar_paciente();
void listar_pacientes();
void excluir_paciente();

#endif //SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H