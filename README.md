<h1 align="center" font-size="200em"><b>Sistema de Gestão de Filas de supermecado</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)

</div>

### Introdução

Este é um sistema desenvolvido em linguagem C para a gestão de filas prioritárias em caixas de atendimento. Ele permite o cadastro e atendimento de clientes com diferentes níveis de prioridade, abertura e fechamento de caixas, realocação de clientes e exibição de relatórios detalhados.

O sistema foi projetado para garantir que os clientes com maior prioridade sejam atendidos primeiro, mantendo o fluxo nas filas mesmo em situações de fechamento de caixas. Inicialmente, o sistema conta com 5 caixas disponíveis e todos abertos. É possível alterar o número de caixas na função main, modificando a variável NUM_CAIXAS.

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

### Arquivo `filaPrioridade.c`
- Implementa a fila de prioridade, que organiza clientes de acordo com seus níveis de prioridade (1 = alta, 2 = média, 3 = baixa).

## Arquivos de Cabeçalho

Os arquivos de cabeçalho (`.h`) contêm definições de estruturas e declarações de funções.

### Arquivo `caixa.h`

- **`Caixa`**:
  - `id`: Identificação do caixa.
  - `aberto`: Indica se o caixa está aberto (1) ou fechado (0).
  - `fila`: Array de filas para diferentes níveis de prioridade (alta, média e baixa).
  
**Funções Declaradas:**
- Inicialização de caixas.
- Adição e atendimento de clientes.
- Reorganização de clientes em caso de fechamento de caixas.
- Impressão do estado e das filas de cada caixa.

### Arquivo `cliente.h`

- **`Cliente`**:
  - `nome`: Nome do cliente.
  - `cpf`: Número de CPF do cliente.
  - `prioridade`: Nível de prioridade (1 = alta, 2 = média, 3 = baixa).
  - `num_itens`: Quantidade de itens do cliente.
  - `prox`: Ponteiro para o próximo cliente na fila.

**Funções Declaradas:**
- Cadastro de clientes.
- Validação de dados como CPF e nome.

### Arquivo `filaPrioridade.h`

- **`FilaPrioridade`**:
  - Contém um ponteiro para o cliente com maior prioridade na fila.

**Funções Declaradas:**
- **`inicializarFila`**: Prepara a fila para uso.
- **`adicionarClienteFilaPrioridade`**: Insere um cliente na fila.
- **`atenderClienteFilaPrioridade`**: Remove e retorna o cliente de maior prioridade.

## Sobre Filas Prioritárias
- Cada caixa possui uma fila de prioridade.
- Clientes de maior prioridade são atendidos primeiro.
- Em caso de caixas fechados, os clientes são redistribuídos de forma equitativa para outros caixas abertos.

### Uso do Menu
- Escolha entre as opções do menu:
  1. **Cadastrar Cliente**: Insira os dados do cliente e associe-o a um caixa.
  2. **Atender Cliente**: Selecione um caixa para atender o próximo cliente na fila.
  3. **Abrir ou Fechar um Caixa**: Gerencie o status dos caixas.
  4. **Imprimir a Lista de Clientes em Espera**: Veja todos os clientes e suas prioridades.
  5. **Imprimir Status dos Caixa**: Exibe os caixas abertos, fechados e a quantidade de clientes em cada um.
  0. **Sair**: Finaliza o sistema.

## Tratamento de Erros
- Validação de entradas (nome, CPF, número do caixa, ação escolhida).
- Impede o fechamento de todos os caixas.
- Exibe mensagens claras ao usuário para corrigir erros de entrada.

## Resultados

Após cadastrar alguns clientes, selecionei a opção 4 para exibir a lista de clientes em espera. O sistema apresenta os clientes com suas respectivas prioridades e caixas atribuídos:

![image](https://github.com/user-attachments/assets/0de9a8e8-b054-4a06-86a4-5dab47c98a74)

Em seguida, fechei o caixa de número 2. O sistema redistribuiu os clientes para a próxima fila com menos clientes. Adicionando o cliente João Vitor com prioridade 1 à fila de um caixa disponível:

![image](https://github.com/user-attachments/assets/dc822c8c-1182-4343-8cb0-851c682023a8)

Depois, procedi com o atendimento dos clientes atribuídos ao caixa 1. O sistema atendeu o cliente de acordo com sua prioridade:

![image](https://github.com/user-attachments/assets/b8a311fc-310c-45e8-8704-9653b6c3efd3)

Por fim, após fechar o caixa 1, utilizei a função para imprimir o status atual dos caixas. O sistema exibiu quais caixas estavam abertos, fechados e o número de clientes em cada fila:

![image](https://github.com/user-attachments/assets/5776e1f9-aad8-4567-9780-93b9be3b111f)


## Como Rodar o Sistema

   | Comando      | Função                                                                                  |
  | ------------ | --------------------------------------------------------------------------------------- |
  | `make clean` | Apaga a última compilação realizada contida na pasta build                              |
  | `make`       | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build |
  | `make run`   | Executa o programa da pasta build após a realização da compilação                       |
