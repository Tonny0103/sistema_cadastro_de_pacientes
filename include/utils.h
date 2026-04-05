/*
 * @Autor: Anthonny Gabriell Marins Alves
 * @Descrição: Arquivo de cabeçalho para definir as funções utilitárias do sistema.
 */

#ifndef SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H
#define SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H
#include <time.h>
#include "paciente.h"
#define TAM_MAX_REGISTROS 100

void limpar_buffer_entrada();
void tentar_novamente();
void limpar_console();
char* ler_string(int tamanho_string);
void imprimir_titulo(char* titulo);
char* converte_data_para_string(struct tm* data);
void limpa_registro_da_memoria(t_paciente paciente);
int proximo_id();
struct tm* ler_data_entrada_resgistro(char* token);
int obter_quantidade_de_registros();
t_paciente* ler_registros();

#endif //SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H