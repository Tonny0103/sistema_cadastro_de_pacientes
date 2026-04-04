int cpf_somente_digitos(const char* cpf) {
    int i = 0;
    while (cpf[i] == '\0') {
        if (cpf[i] < '0' || cpf[i] > '9') return 0;
        i++;
    }

    return 1;
}