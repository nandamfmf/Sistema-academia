#ifndef FICHA_H
#define FICHA_H

#include <string>
#include <vector>
#include "Exercicio.h"

/**
 * CLASSE: Ficha
 * Uma ficha é um conjunto de exercícios para um dia de treino
 * EXEMPLOS: "Treino A - Peito", "Treino B - Pernas", "Cardio Moderado"
 * - Agrupa múltiplos exercícios (Cardio e Força misturados)
 * - Calcula totais automáticos de tempo e calorias
 * - Gerencia IDs automaticamente.
 * 
 * CONCEITOS POO:
 * - POLIMORFISMO: Lista heterogênea (ponteiros para base)
 * - ENCAPSULAMENTO: Gerencia própria sequência de IDs
 */

class Ficha {
private:
    int id;
    std::string nome;
    std::vector<Exercicio*> exercicios; // Polimorfismo: guarda ponteiros para base
    
    static int proximoId;

public:
    // Construtores
    Ficha(std::string nome);
    Ficha(int id, std::string nome); // Para arquivo

    ~Ficha();

    void adicionarExercicio(Exercicio* exercicio);
    void exibirFicha() const;
    
    double calcularTempoTotal() const;
    double calcularCaloriasTotais() const;
    
    int getId() const;
    std::string getNome() const;
    const std::vector<Exercicio*>& getExercicios() const;
    
    static void atualizarProximoId(int maiorId);
};

#endif

