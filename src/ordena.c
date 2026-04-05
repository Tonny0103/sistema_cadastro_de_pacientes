#include "../include/ordena.h"

#include <stdlib.h>

#include "../include/utils.h"

void troca(t_paciente* pacientes, t_comparar comparar) {
    int quantidade_registros = obter_quantidade_de_registros();

    int i, j;
    for (i = 1; i < quantidade_registros; i++) {
        for (j = 0; j < quantidade_registros - i; j++) {
            if (comparar(pacientes[j], pacientes[j + 1]) > 0) {
                t_paciente aux = pacientes[j];
                pacientes[j] = pacientes[j + 1];
                pacientes[j + 1] = aux;
            }
        }
    }
}

void merge(t_paciente* pacientes, int inicio, int meio, int fim, t_comparar comparar) {
    int com1 = inicio, com2 = meio + 1, comAux = 0, tam = fim - inicio + 1;
    t_paciente* vetAux = (t_paciente*) malloc(tam * sizeof(t_paciente));

    while (com1 <= meio && com2 <= fim) {
        if (comparar(pacientes[com1], pacientes[com2]) <= 0) {
            vetAux[comAux] = pacientes[com1];
            com1++;
        } else {
            vetAux[comAux] = pacientes[com2];
            com2++;
        }
        comAux++;
    }

    while (com1 <= meio) {
        vetAux[comAux] = pacientes[com1];
        comAux++;
        com1++;
    }

    while (com2 <= fim) {
        vetAux[comAux] = pacientes[com2];
        comAux++;
        com2++;
    }

    for (comAux = inicio; comAux <= fim; comAux++) {
        pacientes[comAux] = vetAux[comAux - inicio];
    }

    free(vetAux);
}

void merge_sort(t_paciente* pacientes, int inicio, int fim, t_comparar comparar) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        merge_sort(pacientes, inicio, meio, comparar);
        merge_sort(pacientes, meio + 1, fim, comparar);

        merge(pacientes, inicio, meio, fim, comparar);
    }
}