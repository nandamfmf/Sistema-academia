#include "Historico.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

// Adicionar registro ao histórico
void Historico::adicionarRegistro(const RegistroTreino& registro) {
    registros.push_back(registro);
}

// Exibir histórico completo
void Historico::exibirHistorico() const {
    std::cout << "HISTÓRICO DE TREINOS: " << std::endl;
    if(registros.empty()){
        std::cout << "Nenhum registro disponível." << std::endl;
        return;
    }

    for(auto reg : registros){
        std::cout << "Data/Hora: " << reg.dataHora << std::endl;
        std::cout << "ID Ficha: " << reg.idFicha << std::endl;
        std::cout << "Nome Ficha: " << reg.nomeFicha << std::endl;
        std::cout << "Tempo Total: " << reg.tempoTotal << " minutos" << std::endl;
        std::cout << "Calorias Totais: " << reg.caloriasTotal << std::endl;
    }
}

// Getter de registros
const std::vector<RegistroTreino>& Historico::getRegistros() const {
    return registros;
}

// Carregar histórico do arquivo
void Historico::carregarDeArquivo() {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return; 
    }

    registros.clear();
    std::string linha;
    
    while (std::getline(arquivo, linha)) {

        if (linha.empty()) {
            continue;
        }
        
        std::stringstream ss(linha);
        std::string t;
        RegistroTreino registro;
        
        // Data/Hora
        std::getline(ss, t, ';');
        registro.dataHora = t;
        
        // ID Ficha
        std::getline(ss, t, ';');
        registro.idFicha = std::stoi(t);
        
        // Nome Ficha
        std::getline(ss, t, ';');
        registro.nomeFicha = t;
        
        // Tempo Total
        std::getline(ss, t, ';');
        registro.tempoTotal = std::stod(t);
        
        // Calorias Totais
        std::getline(ss, t, ';');
        registro.caloriasTotal = std::stod(t);
        
        registros.push_back(registro);
    }
    
    arquivo.close();
}

void Historico::salvarEmArquivo() const {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return;
    }

    for (auto reg : registros) {
        arquivo << reg.dataHora << ";"
                << reg.idFicha << ";"
                << reg.nomeFicha << ";"
                << reg.tempoTotal << ";"
                << reg.caloriasTotal << std::endl;
    }
    
    arquivo.close();
}
