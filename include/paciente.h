/*
 * @Autor: Anthonny Gabriell Marins Alves
 * @Descrição: Arquivo de cabeçalho para definir o TAD do paciente e também suas funções.
 */
#ifndef SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H
#define SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H
#include <time.h>

typedef struct {
    int id;
    char* nome;
    char* cpf;
    int origem; // 1 - Sistema público; 2 - Sistema privado; 3 - Plano de saúde; 4 - Outros convênios
    time_t data_entrada;
    char* nome_medico;
    char* observacao_inicial;
} t_paciente;

void cadastrar_paciente();
void listar_pacientes();
void buscar_pacientes();

#endif //SISTEMA_CADASTRO_DE_PACIENTES_PACIENTE_H