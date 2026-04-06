#ifndef SISTEMA_CADASTRO_DE_PACIENTES_METODO_BUSCA_H
#define SISTEMA_CADASTRO_DE_PACIENTES_METODO_BUSCA_H
#include "comparar.h"
#include "paciente.h"

t_paciente* busca_linear(t_paciente* pacientes, int n, t_paciente alvo, t_comparar comparar);
t_paciente* busca_binaria(t_paciente* pacientes, int esquerda, int direita, t_paciente alvo, t_comparar comparar);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_METODO_BUSCA_H