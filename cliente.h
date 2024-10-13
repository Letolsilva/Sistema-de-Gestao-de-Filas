#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_NOME 100

typedef struct Cliente {
    char nome[MAX_NOME];
    long cpf;  
    int prioridade;  // 1 = alta, 2 = média, 3 = baixa
    int num_itens;   
    struct Cliente* prox;  // Aponta para o próximo cliente na fila
} Cliente;

Cliente* cadastrarCliente(); 

#endif
