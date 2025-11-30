#include "Cardio.h"
#include <iostream>

// COnstrutor para novos cadastros
Cardio::Cardio(std::string n, int t, double intens) :
    Exercicio(n), caloriasPorMinuto(intens), duracao(t) {};

// Construtor para leitura de arquivo
Cardio::Cardio(int id, std::string nome, bool ativo, int t, double intens)
    : Exercicio(id, nome, ativo), caloriasPorMinuto(intens), duracao(t) {};

// Exibir detalhes do exercício
void Cardio::exibirDetalhes() const {
    std::cout << "Tipo de exercício: " << getTipo() << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Status: " << (ativo ? "Ativo" : "Inativo") << std::endl;
    std::cout << "Intensidade (calorias/minuto) : " << caloriasPorMinuto << std::endl;
    std:: cout << "Duração (minutos) : " << duracao << std::endl;
}

// Calcular tempo estimado (duração em minutos)
double Cardio::calcularTempoEstimado() const {
    return getDuracao();
}

// Calcular calorias gastas
double Cardio::calcularCaloriasGastas() const {
    return caloriasPorMinuto * duracao;
}

// Retornar tipo do exercício (1 = Cardio)
int Cardio::getTipo() const {
    return 1;
}

// Getter de duração
int Cardio::getDuracao() const {
    return duracao;
}

// Getter de calorias por minuto
double Cardio::getCaloriasPorMinuto() const {
    return caloriasPorMinuto;
}
