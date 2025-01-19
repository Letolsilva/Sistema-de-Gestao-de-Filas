#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

#define MAX_NOME 100

int validaNome(const char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; 
        }
    }
    return 1; 
}

int validaCPF(const char *cpf) {
    int len = strlen(cpf);
    if (len != 11) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }
    return 1;
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Cliente* cadastrarCliente() {
    Cliente *novo = (Cliente*)malloc(sizeof(Cliente));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        exit(1);
    }

    do {
        printf("Digite o nome do cliente: ");
        fgets(novo->nome, MAX_NOME, stdin);
        size_t len = strlen(novo->nome);
        if (len > 0 && novo->nome[len - 1] == '\n') {
            novo->nome[len - 1] = '\0';
        }
        if (!validaNome(novo->nome)) {
            printf("O nome deve conter apenas letras e espaços. Tente novamente.\n");
        }
    } while (!validaNome(novo->nome));

    // Validação do CPF
    char cpfStr[12];
    do {
        printf("Digite o CPF (11 números): ");
        fgets(cpfStr, sizeof(cpfStr), stdin);
        size_t len = strlen(cpfStr);
        if (len > 0 && cpfStr[len - 1] == '\n') {
            cpfStr[len - 1] = '\0';
        }
        if (!validaCPF(cpfStr)) {
            printf("O CPF deve conter exatamente 11 números. Tente novamente.\n");
        }
    } while (!validaCPF(cpfStr));
    novo->cpf = atol(cpfStr);

    // Validação da prioridade
    do {
        printf("Digite a prioridade (1: Alta, 2: Média, 3: Baixa): ");
        if (scanf("%d", &novo->prioridade) != 1) {
            printf("Entrada inválida. Digite um número.\n");
            limparBuffer();
            continue;
        }
        if (novo->prioridade < 1 || novo->prioridade > 3) {
            printf("Prioridade inválida. Digite novamente.\n");
        }
        limparBuffer();
    } while (novo->prioridade < 1 || novo->prioridade > 3);

    do {
        printf("Digite o número de itens no carrinho: ");
        if (scanf("%d", &novo->num_itens) != 1) {
            printf("Entrada inválida. Digite um número.\n");
            limparBuffer();
            continue;
        }
        if (novo->num_itens < 0) {
            printf("O número de itens deve ser um valor positivo. Tente novamente.\n");
        }
        limparBuffer();
    } while (novo->num_itens < 0);

    novo->prox = NULL;
    return novo;
}
