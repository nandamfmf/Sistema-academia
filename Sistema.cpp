#include "Sistema.h"
#include "Cardio.h"
#include "Forca.h"
#include "Utils.h"
#include "Exercicio.h"
#include "Ficha.h"
#include "Historico.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

Sistema::Sistema() {
    carregarDados();
}

// Destrutor 
Sistema::~Sistema() {
    salvarDados();
    for(auto ex : exercicios){
        delete ex;
    }

    for(auto f : fichas){
        delete f;
    }
}

// Carregar dados dos arquivos
void Sistema::carregarDados() {
    std::ifstream arqExercicios("exercicios.txt");
    if (arqExercicios.is_open()) {
        std::string linha;

            while (std::getline(arqExercicios, linha)) {
                if (linha.empty()) {
                    continue;
                }
            
            std::stringstream ss(linha);
            std::string token;
            std::vector<std::string> tokens;
            
            while (std::getline(ss, token, ';')) {
                tokens.push_back(token);
            }
            
            try {
                int tipo = std::stoi(tokens[0]);
                int id = std::stoi(tokens[1]);
                std::string nome = tokens[2];
                bool ativo = std::stoi(tokens.back()) == 1;
                
                if (tipo == 1 && tokens.size() >= 6) {
                    int duracao = std::stoi(tokens[3]);
                    double caloriasPorMin = std::stod(tokens[4]);
                    exercicios.push_back(new Cardio(id, nome, ativo, duracao, caloriasPorMin));
                }
                else if (tipo == 2 && tokens.size() >= 8) {
                    double carga = std::stod(tokens[3]);
                    int series = std::stoi(tokens[4]);
                    int repeticoes = std::stoi(tokens[5]);
                    int descanso = std::stoi(tokens[6]);
                    exercicios.push_back(new Forca(id, nome, ativo, carga, series, repeticoes, descanso));
                }
            } catch (...) {}
        }

        arqExercicios.close();
    }
    
    // Carregar fichas
    std::ifstream arqFichas("fichas.txt");
    if (arqFichas.is_open()) {
        std::string linha;
        while (std::getline(arqFichas, linha)) {
            if (linha.empty()) continue;
            
            std::stringstream ss(linha);
            std::string token;
            std::vector<std::string> tokens;
            
            while (std::getline(ss, token, ';')) {
                tokens.push_back(token);
            }
            
            try {
                if (tokens.size() >= 3) {
                    int idFicha = std::stoi(tokens[0]);
                    std::string nomeFicha = tokens[1];
                    int totalExercicios = std::stoi(tokens[2]);
                    
                    Ficha* ficha = new Ficha(idFicha, nomeFicha);
                    
                    for (int i = 0; i < totalExercicios && i + 3 < tokens.size(); i++) {
                        int idExercicio = std::stoi(tokens[i + 3]);
                        Exercicio* exercicio = buscarExercicioPorId(idExercicio);
                        if (exercicio) {
                            ficha->adicionarExercicio(exercicio);
                        }
                    }
                    
                    fichas.push_back(ficha);
                }
            } catch (...) {
                // Ignora erro na leitura
            }
        }

        arqFichas.close();
    }
    
    historico.carregarDeArquivo();
}

// Salvar dados nos arquivos
void Sistema::salvarDados() {
    std::ofstream arqExercicios("exercicios.txt");
    if (arqExercicios.is_open()) {
        for (auto ex : exercicios) {
            if (ex->getTipo() == 1) {
                Cardio* cardio = dynamic_cast<Cardio*>(ex);
                arqExercicios << "1;" << ex->getId() << ";" << ex->getNome() << ";"
                    << cardio->getDuracao() << ";" << cardio->getCaloriasPorMinuto() << ";"
                    << (ex->isAtivo() ? "1" : "0") << std::endl;
            } 

            else if (ex->getTipo() == 2) {
                Forca* forca = dynamic_cast<Forca*>(ex);
                arqExercicios << "2;" << ex->getId() << ";" << ex->getNome() << ";"
                    << forca->getCarga() << ";" << forca->getSeries() << ";"
                    << forca->getRepeticoes() << ";" << forca->getTempoDescanso() << ";"
                    << (ex->isAtivo() ? "1" : "0") << std::endl;
            }
        }

        arqExercicios.close();
    }
    
    // Salvar fichas.txt
    std::ofstream arqFichas("fichas.txt");
    if (arqFichas.is_open()) {
        for (auto ficha : fichas) {
            arqFichas << ficha->getId() << ";" << ficha->getNome() << ";" 
                    << ficha->getExercicios().size();
            
            for (auto exercicio : ficha->getExercicios()) {
                arqFichas << ";" << exercicio->getId();
            }
            
            arqFichas << std::endl;
        }
        arqFichas.close();
    }
    
    historico.salvarEmArquivo();
}

// Buscar exercício por ID
Exercicio* Sistema::buscarExercicioPorId(int id) {
    for(auto ex : exercicios){
        if(ex->getId() == id && ex->isAtivo()){
            return ex;
        }
    }

    return nullptr; // Se não foi encontrado 
}

// Buscar ficha por ID
Ficha* Sistema::buscarFichaPorId(int id) {
    for(auto f : fichas){
        if(f->getId() == id){
            return f;
        }
    }

    return nullptr; // Se não foi encontrado
}

// Cadastrar novo exercício
void Sistema::cadastrarExercicio() {
    std::cout << "1 == Cardio" << std::endl;
    std::cout << "2 == Força" << std::endl;
    std::cout << "Escolha o tipo: ";
    
    int tipo;
    std::cin >> tipo;
    std::cin.ignore();
    
    if (tipo != 1 && tipo != 2) {
        return;
    }
    
    std::cout << "Nome do exercício: ";
    std::string nome;
    getline(std::cin, nome);
    
    if (tipo == 1) { // Cardio
        std::cout << "Duração (minutos): ";
        int duracao;
        std::cin >> duracao;
        
        std::cout << "Calorias por minuto: ";
        double caloriasPorMin;
        std::cin >> caloriasPorMin;
        
        exercicios.push_back(new Cardio(nome, duracao, caloriasPorMin));
        std::cout << "Exercício de Cardio cadastrado com sucesso!" << std::endl;
    }
    else { 
        std::cout << "Carga (kg): ";
        double carga;
        std::cin >> carga;
        
        std::cout << "Séries: ";
        int series;
        std::cin >> series;
        
        std::cout << "Repetições: ";
        int repeticoes;
        std::cin >> repeticoes;
        
        std::cout << "Tempo de descanso (segundos): ";
        int descanso;
        std::cin >> descanso;
        
        exercicios.push_back(new Forca(nome, carga, series, repeticoes, descanso));
        std::cout << "Exercício de Força cadastrado com sucesso!" << std::endl;
    }
}

// Listar exercícios ativos
void Sistema::listarExercicios() {
    bool encontrou = false;
    for(auto ex : exercicios){
        if(ex->isAtivo()){
            ex->exibirDetalhes();
            encontrou = true;
        }
    }

    if(!encontrou){
        std::cout << "Nenhum exercício ativo" << std::endl;
    }

    pausar();

}

// Desativar exercício
void Sistema::excluirExercicio() {
    std::cout << "ID do exercício a excluir: ";
    int id;
    std::cin >> id;
    
    Exercicio* exercicio = buscarExercicioPorId(id);

    if (!exercicio) {
        std::cout << "Exercício não encontrado!" << std::endl;
        return;
    }

    exercicio->desativar();
    std::cout << "Exercício desativado!" << std::endl;

}

// Criar nova ficha
void Sistema::criarFicha() {
    std::cout << "Nome da ficha: ";
    std::string nome;
    std::cin.ignore();
    getline(std::cin, nome);
    
    if(nome.empty()){
        std::cout << "Nome inválido." << std::endl;
        return;
    }

    if(fichas.empty()){
        int novoId = 1;
        fichas.push_back(new Ficha(novoId, nome));
        return;
    }

    int maiorId = 0;
    for (auto f : fichas) {
        if (f->getId() > maiorId) {
            maiorId = f->getId();
        }
    }
    
    int novoId = maiorId + 1;
    fichas.push_back(new Ficha(novoId, nome));
    
    std::cout << "Ficha criada com sucesso!" << std::endl;
}

// Adicionar exercício à ficha
void Sistema::adicionarExercicioFicha() {
    if(fichas.empty()){
        std::cout << "Nenhuma ficha cadastrada." << std::endl;
        return;
    }

    std::cout << "Fichas disponíveis:" << std::endl;
    for (auto ficha : fichas) {
        std::cout << "ID: " << ficha->getId() << " - " << ficha->getNome() << std::endl;
    }

    std::cout << "ID da ficha: ";
    int idFicha;
    std::cin >> idFicha;
    Ficha *ficha = buscarFichaPorId(idFicha);
    
    if (!ficha) {
        std::cout << "Ficha não encontrada" << std::endl;
        return;
    }

    std::cout << "Exercícios ativos:" << std::endl;
    for (auto ex : exercicios) {
        if (ex->isAtivo()) {
            std::cout << "ID: " << ex->getId() << " - " << ex->getNome() << std::endl;
        }
    }
    
    std::cout << "ID do exercício: ";
    int idExercicio;
    std::cin >> idExercicio;
    
    Exercicio* exercicio = buscarExercicioPorId(idExercicio);
    if (exercicio) {
        ficha->adicionarExercicio(exercicio);
        std::cout << "Exercício adicionado à ficha" << std::endl;
    } else {
        std::cout << "Exercício não encontrado" << std::endl;
    }
}

// Listar todas as fichas
void Sistema::listarFichas() {
    if (fichas.empty()) {
        std::cout << "Nenhuma ficha cadastrada." << std::endl;
        return;
    }
    
    for (auto f : fichas) {
        f->exibirFicha();
        std::cout << std::endl;
    }

    pausar();
    
}

// Registrar treino realizado
void Sistema::registrarTreino() {
    if(fichas.empty()){
        std::cout << "Nenhuma ficha cadastrada." << std::endl;
        return;
    }

    // Listar fichas
    for (auto ficha : fichas) {
        std::cout << "ID: " << ficha->getId() << " - " << ficha->getNome() << std::endl;
    }

    std::cout << "ID da ficha: ";
    int idFicha;
    std::cin >> idFicha;

    Ficha* ficha = buscarFichaPorId(idFicha);

    if (!ficha) {
        std::cout << "Ficha não encontrada!" << std::endl;
        return;
    }

    if (!ficha->getExercicios().empty()) {
        RegistroTreino registro;
        registro.dataHora = getDataHoraAtual();
        registro.idFicha = ficha->getId();
        registro.nomeFicha = ficha->getNome();
        registro.tempoTotal = ficha->calcularTempoTotal();
        registro.caloriasTotal = ficha->calcularCaloriasTotais();
        
        historico.adicionarRegistro(registro);

        std::cout << "Treino registrado no histórico" << std::endl;
    } else {
        std::cout << "Ficha não encontrada ou vazia" << std::endl;
    }
}

// Exibir histórico de treinos
void Sistema::exibirHistorico() {
    historico.exibirHistorico();
    pausar();
}
