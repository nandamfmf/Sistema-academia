#include "Forca.h"
#include <iostream>

// Construtores
Forca::Forca(std::string n, double c, int s, int r, int d) 
    : Exercicio(n), carga(c), series(s), repeticoes(r), tempoDescanso(d) {}
    
Forca::Forca(int idExistente, std::string n, bool status, double c, int s, int r, int d)
    : Exercicio(idExistente, n, status), carga(c), series(s), repeticoes(r), tempoDescanso(d) {}

// Exibir detalhes do exercício
void Forca::exibirDetalhes() const {
    std::cout << "Tipo de exercício: " << getTipo() << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Status: " << (ativo ? "1" : "0") << std::endl;
    std::cout << "Carga (kg): " << carga << std::endl;
    std::cout << "Séries: " << series << std::endl;
    std::cout << "Repetições por série: " << repeticoes << std::endl;
    std::cout << "Descanso entre séries (segundos): " << tempoDescanso << std::endl;
}

// Calcular tempo estimado (em minutos)
double Forca::calcularTempoEstimado() const {
    double tempoExecucao = series * repeticoes * 3; // 3 segundos por repetição
    double tempoDescansoTotal = series * tempoDescanso;
    return (tempoExecucao + tempoDescansoTotal) / 60.0; // converte para minutos
}

// Calcular calorias gastas
double Forca::calcularCaloriasGastas() const {
    return (series * repeticoes * carga * 0.15);
}

// Retornar tipo do exercício (2 = Força)
int Forca::getTipo() const {
    return 2;
}

// Getters
double Forca::getCarga() const { 
    return carga;
}

int Forca::getSeries() const { 
    return series;
}

int Forca::getRepeticoes() const { 
    return repeticoes;
}

int Forca::getTempoDescanso() const { 
    return tempoDescanso;
}
