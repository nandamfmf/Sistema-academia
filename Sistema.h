#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Exercicio.h"
#include "Ficha.h"
#include "Historico.h"

/**
 * CLASSE: Sistema
 * É a classe principal que orquestra todo o sistema
 * Coordena todas as operações do sistema
*/

class Sistema {
private:
    std::vector<Exercicio*> exercicios;
    std::vector<Ficha*> fichas;
    Historico historico;

    // Métodos auxiliares privados
    Exercicio* buscarExercicioPorId(int id);
    Ficha* buscarFichaPorId(int id);

public:
    Sistema();
    ~Sistema();

    // Gerenciamento de Dados
    void carregarDados();
    void salvarDados();

    // Funcionalidades de Exercícios
    void cadastrarExercicio();
    void listarExercicios();
    void excluirExercicio(); 
    void desativar(Exercicio* exercicio);

    // Funcionalidades de Fichas
    void criarFicha();
    void adicionarExercicioFicha();
    void listarFichas();

    // Execução
    void registrarTreino();
    void exibirHistorico();
};

#endif

