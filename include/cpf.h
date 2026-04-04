#ifndef SISTEMA_CADASTRO_DE_PACIENTES_CPF_H
#define SISTEMA_CADASTRO_DE_PACIENTES_CPF_H

// uso const para evitar modificar o array original por acidente
int validar_cpf(const char* cpf);
int cpf_somente_digitos(const char* cpf);
int todos_digitos_iguais(const char* cpf);
int calcular_primeiro_digito_verificador(const char* cpf);
int calcular_segundo_digito_verificador(const char* cpf);

#endif //SISTEMA_CADASTRO_DE_PACIENTES_CPF_H