#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>
#include <iostream>

/*
 * CONCEITOS POO APLICADOS:
 * - ABSTRAÇÃO: Classe genérica "exercício físico"
 * - ENCAPSULAMENTO: Atributos protegidos, interface pública controlada
 * - POLIMORFISMO: Métodos virtuais permitem comportamentos específicos
 * - HERANÇA: Classes derivadas especializam o comportamento
*/

class Exercicio {
protected:
    int id;
    std::string nome;
    bool ativo;

    // Variável estática para controlar o próximo ID gerado
    static int proximoId;

public:
    // CONSTRUTOR 1: Cria novo exercício (gera ID automático)
    Exercicio(std::string n);

    // CONSTRUTOR 2: Cria exercício a partir do arquivo (usa ID existente)
    Exercicio(int idExistente, std::string n, bool a);

    virtual ~Exercicio();

    // Métodos virtuais puros (serão sobrescritos nas classes derivadas)
    virtual void exibirDetalhes() const = 0;
    virtual double calcularTempoEstimado() const = 0;
    virtual double calcularCaloriasGastas() const = 0;
    virtual int getTipo() const = 0; // 1 = Cardio, 2 = Força

    // Getters
    int getId() const;
    std::string getNome() const;
    bool isAtivo() const;

    // Setters
    void desativar();
    
    // Atualiza o contador estático se o ID lido for maior
    static void atualizarProximoId(int maiorId);
};

#endif

