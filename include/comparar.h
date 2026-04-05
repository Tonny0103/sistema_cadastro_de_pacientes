#ifndef SISTEMA_CADASTRO_DE_PACIENTES_COMPARAR_H
#define SISTEMA_CADASTRO_DE_PACIENTES_COMPARAR_H
#include "paciente.h"

typedef int (*t_comparar)(t_paciente a, t_paciente b);

int comparar_nome_crescente(t_paciente a, t_paciente b);
int comparar_nome_decrescente(t_paciente a, t_paciente b);
int comparar_origem_nome_crescente(t_paciente a, t_paciente b);
int comparar_data_entrada_decrescente(t_paciente a, t_paciente b);
int comparar_medico_paciente_crescente(t_paciente a, t_paciente b);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_COMPARAR_H