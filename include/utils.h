/*
 * @Autor: Anthonny Gabriell Marins Alves
 * @Descrição: Arquivo de cabeçalho para definir as funções utilitárias do sistema.
 */

#ifndef SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H
#define SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H

void limpar_buffer_entrada();
void tentar_novamente();
void limpar_console();
char* ler_string(int tamanho_string);
void imprimir_titulo(char* titulo);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_UTILS_H