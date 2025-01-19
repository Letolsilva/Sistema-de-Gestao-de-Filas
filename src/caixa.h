#ifndef CAIXA_H
#define CAIXA_H

#include "cliente.h"
#include "filaPrioridade.h"

typedef struct Caixa {
    int id;                     // Número de identificação do caixa
    int aberto;                 // 1 = aberto, 0 = fechado
    FilaPrioridade fila[3];    // Filas separadas para prioridades 1, 2 e 3
} Caixa;

// Funções para gerenciar o caixa e as filas
void inicializarCaixas(Caixa* caixas, int num_caixas);
void adicionarClienteFila(Caixa* caixas, int num_caixa, Cliente* cliente);
Cliente* atenderCliente(Caixa* caixas, int num_caixa);
int contarClientesNoCaixa(Caixa* caixas);
void realocarClientes(Caixa* caixas, int num_caixa_fechado, int num_caixa_aberto);
void imprimirClientesEmEspera(Caixa* caixas, int num_caixas);
void imprimirStatusCaixas(Caixa* caixas, int num_caixas); 

#endif
