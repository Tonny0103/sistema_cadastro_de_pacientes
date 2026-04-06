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
        src/cpf.c
        include/menu.h
        src/menu.c
        include/listagem.h
        src/listagem.c
        include/ordena.h
        src/ordena.c
        include/comparar.h
        src/comparar.c
        include/busca.h
        src/busca.c
        include/metodo_busca.h
        src/metodo_busca.c
)
