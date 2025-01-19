#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "cliente.h"

typedef struct FilaPrioridade
{
    Cliente *cabeca;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *fila);
void adicionarClienteFilaPrioridade(FilaPrioridade *fila, Cliente *cliente);
Cliente *atenderClienteFilaPrioridade(FilaPrioridade *fila);

#endif
