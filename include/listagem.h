#ifndef SISTEMA_CADASTRO_DE_PACIENTES_LISTAGEM_H
#define SISTEMA_CADASTRO_DE_PACIENTES_LISTAGEM_H
#include "paciente.h"

void listar_por_ordem_alfabetica_crescente(t_paciente* pacientes, int opcao_ordenacao);
void listar_por_ordem_alfabetica_decrescente(t_paciente* pacientes, int opcao_ordenacao);
void listar_por_origem_nome_crescente(t_paciente* pacientes, int opcao_ordenacao);
void listar_por_data_entrada_decrescente(t_paciente* pacientes, int opcao_ordenacao);
void listar_por_medico_paciente_crescente(t_paciente* pacientes, int opcao_ordenacao);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_LISTAGEM_H