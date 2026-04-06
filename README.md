Aqui está um guia didático passo a passo para que seu professor consiga compilar e rodar o projeto:

---

# 📋 Guia de Compilação — Sistema de Cadastro de Pacientes

## Pré-requisitos

Antes de começar, certifique-se de ter instalado na sua máquina:

| Ferramenta | Para quê serve | Download |
|---|---|---|
| **CMake** (≥ 4.1) | Gerenciar a compilação | [cmake.org](https://cmake.org/download/) |
| **GCC / MinGW** (Windows) ou **GCC** (Linux/macOS) | Compilador C | [mingw-w64.org](https://www.mingw-w64.org/) |

> 💡 **Dica:** Para verificar se já estão instalados, abra o terminal e execute:
>```shell script
> cmake --version
> gcc --version
> ```

---

## 📁 Estrutura do Projeto

Após baixar/clonar o projeto, você verá a seguinte estrutura:

```
sistema-cadastro-de-pacientes/
├── CMakeLists.txt   ← arquivo de configuração do CMake
├── include/         ← arquivos de cabeçalho (.h)
└── src/             ← arquivos de código-fonte (.c)
```

---

## 🔨 Passo a Passo para Compilar

### 1. Abra o terminal na pasta do projeto

Navegue até a raiz do projeto (onde está o `CMakeLists.txt`):

```bash
cd caminho/para/sistema-cadastro-de-pacientes
```

---

### 2. Crie uma pasta de build

É uma boa prática separar os arquivos de compilação do código-fonte:

```bash
mkdir build
cd build
```

---

### 3. Configure o projeto com o CMake

Ainda dentro da pasta `build`, execute:

```bash
cmake ..
```

> O `..` indica que o `CMakeLists.txt` está na pasta **acima** (a raiz do projeto).

**No Windows com MinGW**, use:

```bash
cmake .. -G "MinGW Makefiles"
```

---

### 4. Compile o projeto

```bash
cmake --build .
```

Isso irá gerar o executável do programa.

---

### 5. Execute o programa

**No Linux/macOS:**
```bash
./sistema_cadastro_de_pacientes
```

**No Windows:**
```bash
sistema_cadastro_de_pacientes.exe
```

---

## ✅ Resumo Rápido (todos os comandos de uma vez)

```bash
# Na raiz do projeto:
mkdir build
cd build
cmake ..           # (ou: cmake .. -G "MinGW Makefiles" no Windows)
cmake --build .

# Executar:
./sistema_cadastro_de_pacientes       # Linux/macOS
sistema_cadastro_de_pacientes.exe     # Windows
```

---

## ❓ Problemas Comuns

| Problema | Solução |
|---|---|
| `cmake: command not found` | Instale o CMake e adicione ao PATH |
| `gcc: command not found` | Instale o GCC/MinGW e adicione ao PATH |
| `No CMAKE_C_COMPILER found` | No Windows, use `-G "MinGW Makefiles"` no passo 3 |
| Erro de versão do CMake | Atualize o CMake para a versão **4.1 ou superior** |
```
