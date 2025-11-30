#include "Ficha.h"
#include <iostream>
#include <iomanip>

int Ficha::proximoId = 1;

// Construtor para novos cadastros
Ficha::Ficha(std::string n) : nome(n) {
    this->id = proximoId++;
}

// Construtor para leitura de arquivo
Ficha::Ficha(int idExistente, std::string n) : nome(n) {
    this->id = idExistente;
    if(idExistente >= proximoId){
        proximoId = idExistente + 1;
    }
}

// Destrutor
Ficha::~Ficha() {
    exercicios.clear();
}

// Adicionar exercício à ficha
void Ficha::adicionarExercicio(Exercicio* exercicio) {
    exercicios.push_back(exercicio);
}

// Exibir ficha completa com exercícios e totais
void Ficha::exibirFicha() const {

        std::cout << "FICHA DE TREINO: " << nome << " ID: " << id << std::endl;
        
        if (exercicios.empty()) {
            std::cout << "Nenhum exercício cadastrado nesta ficha." << std::endl;
        } 
        else {

            std::cout << "EXERCÍCIOS:" << std::endl;
            
            for (size_t i = 0; i < exercicios.size(); i++) {
                exercicios[i]->exibirDetalhes();
            }
            
            std::cout << "RESUMO DA FICHA:" << std::endl;
            std::cout << "Total de exercícios: " << exercicios.size() << std::endl;
            std::cout << "Tempo total estimado: " << calcularTempoTotal() << " minutos" << std::endl;
            std::cout << "Calorias totais estimadas: " << calcularCaloriasTotais() << std::endl;
        }
}

// Faz o somatório dos tempos dos exercícios
double Ficha::calcularTempoTotal() const {
    double tempoTotal = 0.0;
    for(Exercicio* ex : exercicios){
        tempoTotal += ex->calcularTempoEstimado();
    }
    return tempoTotal;
}

// Faz o somatório das calorias dos exercícios
double Ficha::calcularCaloriasTotais() const {
    double caloriasTotais = 0.0;
    for(Exercicio* ex : exercicios){
        caloriasTotais += ex->calcularCaloriasGastas();
    }
    return caloriasTotais;;
}

// Getters
int Ficha::getId() const { 
    return id;
}

std::string Ficha::getNome() const { 
    return nome;
}

const std::vector<Exercicio*>& Ficha::getExercicios() const {
    return exercicios;
}

// Atualizar próximo ID
void Ficha::atualizarProximoId(int maiorId) {
    if(maiorId >= proximoId){
        proximoId = maiorId + 1;
    }
}
