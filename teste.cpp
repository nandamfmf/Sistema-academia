#include <iostream>
#include <vector>
#include "Exercicio.h"
#include "Cardio.h"
#include "Forca.h"

using namespace std;

int main() {
    cout << "=== TESTE SIMPLES ===" << endl;
    
    // Teste 1: Criar exercícios
    cout << "1. Criando exercícios..." << endl;
    Cardio* esteira = new Cardio("Esteira", 30, 12);
    Forca* supino = new Forca("Supino", 40, 3, 12, 60);
    
    cout << "2. Exercícios criados!" << endl;
    
    // Teste 2: Verificar dados
    cout << "Esteira - ID: " << esteira->getId() << ", Ativo: " << esteira->isAtivo() << endl;
    cout << "Supino - ID: " << supino->getId() << ", Ativo: " << supino->isAtivo() << endl;
    
    // Teste 3: Exibir detalhes
    cout << "3. Exibindo detalhes:" << endl;
    esteira->exibirDetalhes();
    cout << "---" << endl;
    supino->exibirDetalhes();
    
    // Teste 4: Cálculos
    cout << "4. Cálculos:" << endl;
    cout << "Esteira - Tempo: " << esteira->calcularTempoEstimado() << " min, Calorias: " << esteira->calcularCaloriasGastas() << endl;
    cout << "Supino - Tempo: " << supino->calcularTempoEstimado() << " min, Calorias: " << supino->calcularCaloriasGastas() << endl;
    
    delete esteira;
    delete supino;
    
    return 0;
}