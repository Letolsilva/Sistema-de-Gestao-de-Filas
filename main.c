#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caixa.h"
#include "cliente.h" 

#define NUM_CAIXAS 5

int main() {
    Caixa caixas[NUM_CAIXAS];
    inicializarCaixas(caixas, NUM_CAIXAS);


    int opcao;
    do {
        printf("\n1. Cadastrar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Abrir ou Fechar um Caixa\n");
        printf("4. Imprimir a Lista de Clientes em Espera\n");
        printf("5. Imprimir status do caixa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: {
                // Cadastrar cliente
                Cliente* novo_cliente = cadastrarCliente(); 
                if (novo_cliente != NULL) {
                    int num_caixa;
                    printf("Escolha o número do caixa (1-5): ");
                    scanf("%d", &num_caixa);
                    getchar(); 

                    adicionarClienteFila(caixas, num_caixa - 1, novo_cliente);
                }
                break;
            }
            case 2: {
                // Atender cliente
                int num_caixa;
                printf("Escolha o número do caixa para atender (1-5): ");
                scanf("%d", &num_caixa);
                getchar(); 

                Cliente* atendido = atenderCliente(caixas, num_caixa - 1);
                if (atendido != NULL) {
                    printf("Cliente atendido: %s (CPF: %ld)\n", atendido->nome, atendido->cpf);
                    free(atendido);  
                } else {
                    printf("Nenhum cliente para atender no caixa %d.\n", num_caixa);
                }
                break;
            }
            case 3: {
                // Abrir ou fechar um caixa
                int num_caixa, acao;
                printf("Escolha o número do caixa (1-5): ");
                scanf("%d", &num_caixa);
                getchar(); 

                printf("Ação (1 = Abrir, 2 = Fechar): ");
                scanf("%d", &acao);
                getchar(); 

                switch (acao) {
                    case 1:  // Abrir caixa
                        if (caixas[num_caixa - 1].aberto) {
                            printf("O caixa %d já está aberto!\n", num_caixa);
                        } else {
                            caixas[num_caixa - 1].aberto = 1;  // Abre o caixa
                            printf("Caixa %d aberto com sucesso!\n", num_caixa);
                        }
                        break;
                    case 2:  // Fechar caixa
                        if (!caixas[num_caixa - 1].aberto) {
                            printf("O caixa %d já está fechado!\n", num_caixa);
                        } else {
                            // Realoca clientes para outro caixa aberto
                            int caixa_aberto = -1;
                            for (int i = 0; i < NUM_CAIXAS; i++) {
                                if (caixas[i].aberto && i != (num_caixa - 1)) {
                                    caixa_aberto = i;
                                    break;
                                }
                            }
                            if (caixa_aberto != -1) {
                                realocarClientes(caixas, num_caixa - 1, caixa_aberto);
                                caixas[num_caixa - 1].aberto = 0;  // Fecha o caixa
                                printf("Caixa %d fechado com sucesso!\n", num_caixa);
                            } else {
                                printf("Não há caixas abertos para realocar os clientes.\n");
                            }
                        }
                        break;
                    default:
                        printf("Ação inválida! Tente novamente.\n");
                }
                break;
            }
            case 4: {
                // Imprimir a lista de clientes em espera
                imprimirClientesEmEspera(caixas, NUM_CAIXAS);
                break;
            }
            case 5: {
                imprimirStatusCaixas(caixas, NUM_CAIXAS);
                break;
            }
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
