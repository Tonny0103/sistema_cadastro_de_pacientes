#include "../include/metodo_busca.h"

t_paciente* busca_linear(t_paciente* pacientes, int n, t_paciente alvo, t_comparar comparar) {
    for (int i = 0; i < n; i++) {
        if (comparar(pacientes[i], alvo) == 0)
            return &pacientes[i];
    }

    return NULL;
}

t_paciente* busca_binaria(t_paciente* pacientes, int esquerda, int direita, t_paciente alvo, t_comparar comparar) {
    if (esquerda > direita) {
        return NULL;
    }

    int meio = (esquerda + direita) / 2;
    int resultado = comparar(pacientes[meio], alvo);

    if (resultado == 0) {
        return &pacientes[meio];
    } else if (resultado < 0) {
        return busca_binaria(pacientes, meio + 1, direita, alvo, comparar);
    } else {
        return busca_binaria(pacientes, esquerda, meio - 1, alvo, comparar);
    }
}