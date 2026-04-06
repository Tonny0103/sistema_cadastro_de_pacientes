#include "../include/comparar.h"

#include <stdio.h>
#include <string.h>

int comparar_nome_crescente(t_paciente a, t_paciente b) {
    return strcmp(a.nome, b.nome);
}

int comparar_nome_decrescente(t_paciente a, t_paciente b) {
    return strcmp(b.nome, a.nome); // só inverter
}

int comparar_origem_nome_crescente(t_paciente a, t_paciente b) {
    char chave_a[41]; // tamanho máximo do nome + 1 da origem
    char chave_b[41];

    sprintf(chave_a, "%d%s", a.origem, a.nome);
    sprintf(chave_b, "%d%s", b.origem, b.nome);

    return strcmp(chave_a, chave_b);
}

int comparar_data_entrada_decrescente(t_paciente a, t_paciente b) {
    return (int) difftime(mktime(b.data_entrada), mktime(a.data_entrada));
}

int comparar_medico_paciente_crescente(t_paciente a, t_paciente b) {
    char chave_a[80];
    char chave_b[80];

    sprintf(chave_a, "%s%s", a.nome_medico, a.nome);
    sprintf(chave_b, "%s%s", b.nome_medico, b.nome);

    return strcmp(chave_a, chave_b);
}

int comparar_cpf_paciente(t_paciente a, t_paciente b) {
    return strcmp(a.cpf, b.cpf) == 0;
}