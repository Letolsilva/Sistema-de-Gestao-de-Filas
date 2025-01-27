
#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

void inicializarFila(FilaPrioridade* fila) {
    fila->cabeca = NULL;
}

void adicionarClienteFilaPrioridade(FilaPrioridade* fila, Cliente* cliente) {
    if (fila->cabeca == NULL || cliente->prioridade < fila->cabeca->prioridade) {
        cliente->prox = fila->cabeca;
        fila->cabeca = cliente;
    } else {
        Cliente* temp = fila->cabeca;
        while (temp->prox != NULL && temp->prox->prioridade <= cliente->prioridade) {
            temp = temp->prox;
        }
        cliente->prox = temp->prox;
        temp->prox = cliente;
    }
}

// Atende o cliente com maior prioridade (remove da fila e retorna)
Cliente* atenderClienteFilaPrioridade(FilaPrioridade* fila) {
    if (fila->cabeca == NULL) {
        return NULL;
    }

    Cliente* cliente = fila->cabeca;  // O cliente a ser atendido
    fila->cabeca = cliente->prox;    // Remove o cliente da fila
    return cliente;
}
