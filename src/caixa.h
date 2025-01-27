#ifndef CAIXA_H
#define CAIXA_H

#include "cliente.h"
#include "filaPrioridade.h"

typedef struct Caixa {
    int id;                     // Número de identificação do caixa
    int aberto;                 // 1 = aberto, 0 = fechado
    FilaPrioridade fila;        // Única fila para o caixa, com atendimento baseado em prioridade
} Caixa;

// Funções para gerenciar o caixa e a fila
void inicializarCaixas(Caixa* caixas, int num_caixas);
void adicionarClienteFila(Caixa* caixas, int num_caixa, Cliente* cliente);
Cliente* atenderCliente(Caixa* caixas, int num_caixa);
int contarClientesNoCaixa(Caixa* caixa);
void realocarClientes(Caixa* caixas, int num_caixa_fechado, int num_caixas);
void imprimirClientesEmEspera(Caixa* caixas, int num_caixas);
void imprimirStatusCaixas(Caixa* caixas, int num_caixas);

#endif