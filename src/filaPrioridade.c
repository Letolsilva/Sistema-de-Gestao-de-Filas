#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

void inicializarFila(FilaPrioridade* fila) {
    fila->cabeca = NULL;
}

void adicionarClienteFilaPrioridade(FilaPrioridade* fila, Cliente* cliente) {
    if (fila->cabeca == NULL) {
        fila->cabeca = cliente;  // Se a fila estiver vazia, o cliente é o primeiro
        cliente->prox = NULL;    // Final da fila
    } else {
        Cliente* temp = fila->cabeca;
        while (temp->prox != NULL) {
            temp = temp->prox;  // Navega até o final da lista
        }
        temp->prox = cliente;  // Adiciona o novo cliente ao final
        cliente->prox = NULL;  // Final da fila
    }
}

// Atende o cliente com maior prioridade (remove da fila e retorna)
Cliente* atenderClienteFilaPrioridade(FilaPrioridade* fila) {
    if (fila->cabeca == NULL) {
        // printf("Nenhum cliente na fila!\n");
        return NULL;
    }

    Cliente* cliente = fila->cabeca;  // O cliente a ser atendido
    fila->cabeca = cliente->prox;      // Remove o cliente da fila
    return cliente;
}
