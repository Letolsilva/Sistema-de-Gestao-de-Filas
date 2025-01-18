# Sistema de Gestão de Filas

## Introdução

Este é um sistema desenvolvido em linguagem C para a gestão de filas prioritárias em caixas de atendimento. Ele permite o cadastro e atendimento de clientes com diferentes níveis de prioridade, abertura e fechamento de caixas, realocação de clientes e exibição de relatórios detalhados.

O sistema é projetado para que clientes com maior prioridade sejam atendidos primeiro e que o fluxo nas filas seja mantido mesmo em casos de fechamento de caixas.

## Funcionalidades Principais

### 1. Cadastro de Cliente
- Permite cadastrar clientes com nome, CPF e nível de prioridade (1 a 3).
- Valida o nome (apenas letras e espaços) e o CPF (somente números).

### 2. Atendimento de Cliente
- Atende o cliente com maior prioridade em um caixa selecionado.
- Remove o cliente da fila após o atendimento.

### 3. Gerenciamento de Caixas
- Permite abrir ou fechar caixas.
- Realoca clientes de um caixa fechado para outros caixas abertos com menor carga de trabalho.
- Garante que pelo menos um caixa esteja aberto.

### 4. Relatórios
- Exibe a lista de clientes em espera em todos os caixas, separados por prioridade.
- Mostra o status dos caixas (abertos ou fechados) e o número de clientes em cada fila.

### 5. Realocação de Clientes
- Realoca automaticamente os clientes de caixas fechados para caixas abertos, respeitando as prioridades.

## Estrutura do Código

### Arquivo `main.c`
- Função principal que gerencia o menu e integra as funcionalidades do sistema.

### Arquivo `caixa.c`
- Gerencia os caixas e as filas prioritárias.
- Contém as funções para inicialização de caixas, atendimento de clientes e realocação.

### Arquivo `cliente.c`
- Gerencia o cadastro e validação de clientes.
- Implementa funções auxiliares para validar nomes e CPFs.

### Arquivos de Cabeçalho
- `caixa.h` e `cliente.h` contêm as definições de structs e protótipos das funções.


### Uso do Menu
- Escolha entre as opções do menu:
  1. **Cadastrar Cliente**: Insira os dados do cliente e associe-o a um caixa.
  2. **Atender Cliente**: Selecione um caixa para atender o próximo cliente na fila.
  3. **Abrir ou Fechar um Caixa**: Gerencie o status dos caixas.
  4. **Imprimir a Lista de Clientes em Espera**: Veja todos os clientes e suas prioridades.
  5. **Imprimir Status do Caixa**: Exibe os caixas abertos, fechados e a quantidade de clientes em cada um.
  0. **Sair**: Finaliza o sistema.

## Sobre Filas Prioritárias
- Cada caixa possui três filas separadas por prioridade (1 = mais alta, 3 = mais baixa).
- Clientes de maior prioridade são atendidos primeiro.
- Em caso de caixas fechados, os clientes são redistribuídos de forma equitativa para outros caixas abertos.

## Tratamento de Erros
- Validação de entradas (nome, CPF, número do caixa, ação escolhida).
- Impede o fechamento de todos os caixas.
- Exibe mensagens claras ao usuário para corrigir erros de entrada.

## Como Rodar o Sistema

   | Comando      | Função                                                                                  |
  | ------------ | --------------------------------------------------------------------------------------- |
  | `make clean` | Apaga a última compilação realizada contida na pasta build                              |
  | `make`       | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
  | `make run`   | Executa o programa da pasta build após a realização da compilação                       |
