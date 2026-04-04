cmake_minimum_required(VERSION 4.1)
project(sistema_cadastro_de_pacientes C)

set(CMAKE_C_STANDARD 11)

add_executable(sistema_cadastro_de_pacientes src/main.c
        include/paciente.h
        src/paciente.c
        include/func_ler_campos.h
        src/func_ler_campos.c
        include/utils.h
        src/utils.c
        include/cpf.h
        src/cpf.c)
