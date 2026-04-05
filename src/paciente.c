#include "../include/paciente.h"
#include "../include/func_ler_campos.h"
#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

void cadastrar_paciente() {
    FILE *arquivo_paciente = fopen("pacientes.csv", "a+");
    if (arquivo_paciente == NULL) {
        printf("Erro ao abrir o arquivo de armazenamento de pacientes!\n");
    }

    t_paciente paciente;
    paciente.id = proximo_id();

    if (paciente.id > TAM_MAX_REGISTROS) {
        printf("Número de pacientes máximo cadastrados!\n");
        return;
    }

    paciente.nome = ler_nome_paciente();
    paciente.cpf = ler_cpf_paciente();
    paciente.origem = ler_origem_paciente();
    paciente.data_entrada = ler_data_entrada_paciente();
    paciente.nome_medico = ler_nome_medico_paciente();
    paciente.observacao_inicial = ler_observacao_inicial_paciente();

    char* data_formatada = converte_data_para_string(paciente.data_entrada);

    fprintf(arquivo_paciente, "%d,%s,%s,%d,%s,%s,%s\n",
                                        paciente.id,
                                        paciente.nome,
                                        paciente.cpf,
                                        paciente.origem,
                                        data_formatada,
                                        paciente.nome_medico,
                                        paciente.observacao_inicial);

    free(data_formatada);
    limpa_registro_da_memoria(paciente);
    fclose(arquivo_paciente);
}
