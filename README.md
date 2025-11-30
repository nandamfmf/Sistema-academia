# Aluna: Maria Fernanda Magalhães Freitas
# Matéria: Programação 1

## Implementação

- Estrutura completa de classes (headers)
- Classe base Exercicio completamente implementada
- Menu principal e submenus (main.cpp)
- Funções utilitárias (Utils.h)
- Makefile configurado

### Classes Derivadas (Cardio.cpp e Forca.cpp)
- Construtores (novo cadastro e leitura de arquivo)
- Método exibirDetalhes()
- Método calcularTempoEstimado()
- Método calcularCaloriasGastas()
- Método getTipo()
- Getters específicos

### Classe Ficha (Ficha.cpp)
- Inicialização da variável estática proximoId
- Construtores
- Destrutor (importante: não deletar exercícios!)
- Método adicionarExercicio()
- Método exibirFicha()
- Métodos calcularTempoTotal() e calcularCaloriasTotais()
- Getters
- Método atualizarProximoId()

### Classe Historico (Historico.cpp)
- Método adicionarRegistro()
- Método exibirHistorico()
- Método getRegistros()
- Método carregarDeArquivo()
- Método salvarEmArquivo()

### Classe Sistema (Sistema.cpp)
- Destrutor (deletar ponteiros)
- Método carregarDados() (exercícios e fichas)
- Método salvarDados() (exercícios e fichas)
- Método buscarExercicioPorId()
- Método buscarFichaPorId()
- Método cadastrarExercicio()
- Método listarExercicios()
- Método excluirExercicio()
- Método criarFicha()
- Método adicionarExercicioFicha()
- Método listarFichas()
- Método registrarTreino()
- Método exibirHistorico()

## Compilação

O código compila mesmo incompleto (com warnings esperados):

```bash
make clean
make
```

## Objetivos de Aprendizado

- Herança e polimorfismo
- Classes abstratas e métodos virtuais
- Gerenciamento de memória com ponteiros
- Manipulação de arquivos de texto
- Estruturas de dados (vector)
- Variáveis estáticas

## Estrutura do Projeto

```
codigo_base/
├── Exercicio.h          Completo
├── Exercicio.cpp        Completo
├── Cardio.h             Completo
├── Cardio.cpp           TODO
├── Forca.h              Completo
├── Forca.cpp            TODO
├── Ficha.h              Completo
├── Ficha.cpp            TODO
├── Historico.h          Completo
├── Historico.cpp        TODO
├── Sistema.h            Completo
├── Sistema.cpp           TODO
├── main.cpp             Completo
├── Utils.h              Completo
└── Makefile             Completo
```

