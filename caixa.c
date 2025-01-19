#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"

// Inicializa os caixas, todos abertos e com filas vazias
void inicializarCaixas(Caixa* caixas, int num_caixas) {
    for (int i = 0; i < num_caixas; i++) {
        caixas[i].id = i + 1;
        caixas[i].aberto = 1;  // Todos os caixas começam abertos
        for (int j = 0; j < 3; j++) {
            inicializarFila(&caixas[i].fila[j]);  // Inicializa as filas de prioridade
        }
    }
}

// Adiciona um cliente à fila do caixa selecionado com base na prioridade
void adicionarClienteFila(Caixa* caixas, int num_caixa, Cliente* cliente) {
    int prioridade = cliente->prioridade - 1;  // Ajusta índice para 0, 1 ou 2

    if (caixas[num_caixa].aberto) {
       adicionarClienteFilaPrioridade(&caixas[num_caixa].fila[prioridade], cliente);
    } else {
        printf("Caixa %d está fechado!\n", num_caixa);
    }
}

// Atende o cliente com maior prioridade (remove da fila e retorna)
Cliente* atenderCliente(Caixa* caixas, int num_caixa) {
    if (!caixas[num_caixa].aberto) {
        printf("Caixa %d está fechado!\n", num_caixa);
        return NULL;
    }

    for (int prioridade = 0; prioridade < 3; prioridade++) {
        Cliente* cliente = atenderClienteFilaPrioridade(&caixas[num_caixa].fila[prioridade]);
        if (cliente != NULL) {
            return cliente;
        }
    }
    
    // printf("Nenhum cliente na fila do caixa %d!\n", num_caixa);
    return NULL;
}

// Função para contar o número de clientes em um caixa
int contarClientesNoCaixa(Caixa* caixa) {
    int num_clientes = 0;
    for (int prioridade = 0; prioridade < 3; prioridade++) {
        Cliente* cliente = caixa->fila[prioridade].cabeca;
        while (cliente != NULL) {
            num_clientes++;
            cliente = cliente->prox;
        }
    }
    return num_clientes;
}

// Realoca os clientes de um caixa fechado para o caixa com menos clientes
void realocarClientes(Caixa* caixas, int num_caixa_fechado, int num_caixas) {
    // Encontrar o caixa aberto com o menor número de clientes
    int caixa_com_menos_clientes = -1;
    int menor_numero_de_clientes = __INT_MAX__; // Usar um valor máximo

    for (int i = 0; i < num_caixas; i++) {
        if (caixas[i].aberto && i != num_caixa_fechado) {
            int num_clientes = contarClientesNoCaixa(&caixas[i]);
            if (num_clientes < menor_numero_de_clientes) {
                menor_numero_de_clientes = num_clientes;
                caixa_com_menos_clientes = i;
            }
        }
    }

    if (caixa_com_menos_clientes != -1) {
        printf("Realocando clientes do caixa %d para o caixa %d...\n", num_caixa_fechado + 1, caixa_com_menos_clientes + 1);
        for (int prioridade = 0; prioridade < 3; prioridade++) {
            while (caixas[num_caixa_fechado].fila[prioridade].cabeca != NULL) {
                Cliente* cliente = atenderClienteFilaPrioridade(&caixas[num_caixa_fechado].fila[prioridade]);
                adicionarClienteFila(caixas, caixa_com_menos_clientes, cliente);
            }
        }
    } else {
        printf("Não há caixas abertos para realocar os clientes.\n");
    }
}


// Imprime a lista de clientes em espera para todos os caixas
void imprimirClientesEmEspera(Caixa* caixas, int num_caixas) {
    for (int i = 0; i < num_caixas; i++) {
        printf("\nCaixa %d (Aberto: %s):\n", i + 1, caixas[i].aberto ? "Sim" : "Não");
        for (int prioridade = 0; prioridade < 3; prioridade++) {
            Cliente* cliente = caixas[i].fila[prioridade].cabeca;
            if (cliente != NULL) {
                printf("Prioridade %d:\n", prioridade + 1);
                while (cliente != NULL) {
                    printf("  - Nome: %s, CPF: %ld\n", cliente->nome, cliente->cpf);
                    cliente = cliente->prox;
                }
            }
        }
    }
}

// Imprime o status de cada caixa
void imprimirStatusCaixas(Caixa* caixas, int num_caixas) {
    for (int i = 0; i < num_caixas; i++) {
        printf("Caixa %d: %s\n", caixas[i].id, caixas[i].aberto ? "Aberto" : "Fechado");

        int num_clientes_em_espera = 0;
        for (int prioridade = 0; prioridade < 3; prioridade++) {
            Cliente* cliente = caixas[i].fila[prioridade].cabeca;
            while (cliente != NULL) {
                num_clientes_em_espera++;
                cliente = cliente->prox;
            }
        }

        printf("Clientes em espera: %d\n", num_clientes_em_espera);
    }
}
