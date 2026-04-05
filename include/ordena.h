#ifndef SISTEMA_CADASTRO_DE_PACIENTES_ORDENA_H
#define SISTEMA_CADASTRO_DE_PACIENTES_ORDENA_H
#include "comparar.h"
#include "paciente.h"

void ordena_por_troca(t_paciente* pacientes, t_comparar comparar);

void merge(t_paciente* pacientes, int inicio, int meio, int fim, t_comparar comparar);
void merge_sort(t_paciente* pacientes, int inicio, int fim, t_comparar comparar);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_ORDENA_H