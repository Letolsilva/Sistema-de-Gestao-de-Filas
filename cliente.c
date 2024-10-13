#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cadastrarCliente() {
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        exit(1);
    }

    printf("Digite o nome do cliente: ");
    fgets(novo->nome, MAX_NOME, stdin);
    size_t len = strlen(novo->nome);
    if (len > 0 && novo->nome[len - 1] == '\n') {
        novo->nome[len - 1] = '\0';
    }
    
    printf("Digite o CPF (somente números): ");
    scanf("%ld", &novo->cpf);
    getchar(); 

    do {
        printf("Digite a prioridade (1: Alta, 2: Média, 3: Baixa): ");
        scanf("%d", &novo->prioridade);
        if (novo->prioridade < 1 || novo->prioridade > 3) {
            printf("Prioridade inválida. Digite novamente.\n");
        }
    } while(novo->prioridade < 1 || novo->prioridade > 3);
    
    printf("Digite o número de itens no carrinho: ");
    scanf("%d", &novo->num_itens);
    
    novo->prox = NULL;  
    return novo;
}
