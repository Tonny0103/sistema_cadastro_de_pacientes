/*
 * @Autor: Anthonny Gabriell Marins Alves
 * @Descrição: Arquivo de cabeçalho para definir as funções de leitura dos campos do paciente durante cadastro.
 */
#ifndef SISTEMA_CADASTRO_DE_PACIENTES_FUNC_LER_CAMPOS_H
#define SISTEMA_CADASTRO_DE_PACIENTES_FUNC_LER_CAMPOS_H
#include <time.h>

#define TAM_NOME_PACIENTE 40
#define TAM_CPF_PACIENTE 11
#define TAM_NOME_MEDICO 40
#define TAM_OBSERVACAO_INICIAL 512

char* ler_nome_paciente();
char* ler_cpf_paciente();
int ler_origem_paciente();
struct tm* ler_data_entrada_paciente();
char* ler_nome_medico_paciente();
char* ler_observacao_inicial_paciente();

#endif //SISTEMA_CADASTRO_DE_PACIENTES_FUNC_LER_CAMPOS_H