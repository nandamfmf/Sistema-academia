#ifndef HISTORICO_H
#define HISTORICO_H

#include <string>
#include <vector>

/**
 * CLASSE: Historico
 * - Gerencia o registro de treinos realizados
 * - Salva dados em arquivo
 * - Exibe histórico cronológico
 */

struct RegistroTreino {
    std::string dataHora;
    int idFicha;
    std::string nomeFicha;
    double tempoTotal;
    double caloriasTotal;
};

class Historico {
private:
    std::vector<RegistroTreino> registros;
    std::string nomeArquivo = "historico.txt";

public:
    void adicionarRegistro(const RegistroTreino& registro);
    void exibirHistorico() const;
    const std::vector<RegistroTreino>& getRegistros() const;
    
    // Métodos para persistência
    void carregarDeArquivo();
    void salvarEmArquivo() const;
};

#endif

