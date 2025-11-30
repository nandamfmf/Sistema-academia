#ifndef CARDIO_H
#define CARDIO_H

#include "Exercicio.h"

/*
 * CLASSE DERIVADA: Cardio
 * HERDA DE: Exercicio
 * EXEMPLOS: Esteira, bicicleta, natação, pular corda
 * 
 * CARACTERÍSTICAS ESPECÍFICAS:
 * - A intensidade é medida em calorias/minuto
 * - Calorias = duração × calorias por minuto
 * 
 * CONCEITOS POO:
 * - HERANÇA: Especializa a classe base Exercicio
 * - POLIMORFISMO: Implementa os métodos virtuais de forma específica
 */

class Cardio : public Exercicio {
private:
    int duracao; // em minutos
    double caloriasPorMinuto;

public:
    // Construtor novo
    Cardio(std::string nome, int duracao, double caloriasPorMinuto);

    // Construtor arquivo
    Cardio(int id, std::string nome, bool ativo, int duracao, double caloriasPorMinuto);

    // Implementação dos métodos virtuais
    void exibirDetalhes() const override;
    double calcularTempoEstimado() const override;
    double calcularCaloriasGastas() const override;
    int getTipo() const override;

    // Getters específicos
    int getDuracao() const;
    double getCaloriasPorMinuto() const;
};

#endif

