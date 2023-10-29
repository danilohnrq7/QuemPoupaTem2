#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

// Função para validar o CPF
int validar_cpf(char* cpf, ListaDeClientes *lt) {
    for (int x = 0; x < lt->qtd; x++) {
        if (strcmp(lt->clientes[x].cpf, cpf) == 0) {
            return x; // CPF já existe na lista
        }
    }
    return -1; // CPF não existe na lista
}


int validar_cpf_senha(char* cpf_origem, char* senha_origem, ListaDeClientes* lista_clientes) {
  int validador = -1;
    for (int x = 0; x < lista_clientes->qtd; x++) {
        if (strcmp(lista_clientes->clientes[x].cpf, cpf_origem) == 0 && strcmp(lista_clientes->clientes[x].senha, senha_origem) == 0) {
            validador = x;
        }
    }
    return validador;
}

int debitar(ListaDeClientes *lt, int indice_cliente, float valor){
  lt->clientes[indice_cliente].saldo -= valor;
  return 0;
}

int depositar(ListaDeClientes *lt, int indice_cliente, float valor){
  lt->clientes[indice_cliente].saldo += valor;
  return 0;
}


int cadastrar_cliente(ListaDeClientes *lt){
    char cpf_verif[15];
    int validacao_cpf;
    // Lendo o CPF do usuário
    printf("Digite o seu cpf: ");
    scanf(" %[^\n]", cpf_verif);

    validacao_cpf = validar_cpf(cpf_verif, lt);

    // Verificando se o CPF já está em uso
    if (validar_cpf(cpf_verif, lt) != -1) {
        printf("CPF já está em uso. Tente novamente com um CPF diferente.\n");
        return 1; // Retorna 1 para indicar falha no cadastro
    }
    strcpy(lt->clientes[lt->qtd].cpf, cpf_verif);


    //lendo o nome do usuario
    printf("Digite seu nome (maximo de 60 caracteres): ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].nome);


    //Lendo o tipo de conta escolhida pelo usuario
    printf("Insira o tipo de conta\nConta Comum = tipo 1\nConta Plus = tipo 2:\n ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].tipo_conta);

    //Lendo o valor inicial da conta
    printf("Digite o valor incial da conta (primeiro deposito): ");
    scanf("%f",&lt->clientes[lt->qtd].saldo);

    //Lendo a senha do usuario
    printf("Crie uma senha para sua conta (maximo 10 caracteres): ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].senha);

    //Aumentando a variável do número de structs
    lt->qtd ++;

    /*Guardando a nova struct em um arquivo binário e verificando retorno da função
    controle = salvarTarefas(lt);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }*/

    printf("\nSeja bem vindo %s! Seu cadastro foi realizado com sucesso\n",lt->clientes[lt->qtd-1].nome);
  
    return 0; // Retorna 0 para indicar sucesso no cadastro
}


int listar_clientes(ListaDeClientes lt) {
    //Verificando se existe algum cadastro
    if (lt.qtd == 0){
        printf("\nNao existe nenhum cadastro na base de dados.\n");
      return 1;
    }
        //Caso exista
    else {
        for (int i = 0; i < lt.qtd; i++) {
            printf("Nome: %s\n", lt.clientes[i].nome);
            printf("CPF : %s\n", lt.clientes[i].cpf);
            printf("Tipo da Conta : %s\n", lt.clientes[i].tipo_conta);
            printf("Saldo Atual : %.2f\n", lt.clientes[i].saldo);
            printf("Senha : %s\n\n", lt.clientes[i].senha);
            ;
        }
    }
  printf("\nPressione ENTER para prosseguir\n\n");
  return 0;

}


int excluir_conta(ListaDeClientes *lt, char *cpf_excluir, char *senha_excluir) {
    printf("Digite o CPF do cliente a ser excluído: ");
    scanf(" %[^\n]", cpf_excluir);
    printf("Digite a senha do cliente: ");
    scanf(" %[^\n]", senha_excluir);

    int posicao_excluir = validar_cpf_senha(cpf_excluir, senha_excluir, lt);

    if (posicao_excluir == -1) {
        printf("CPF ou senha incorretos, ou conta não encontrada na lista de clientes.\n\n");

      return 1;

    } else {
        for (int i = posicao_excluir; i < lt->qtd - 1; i++) {
            strcpy(lt->clientes[i].nome, lt->clientes[i + 1].nome);
            strcpy(lt->clientes[i].cpf, lt->clientes[i + 1].cpf);
            strcpy(lt->clientes[i].tipo_conta, lt->clientes[i + 1].tipo_conta);
            lt->clientes[i].saldo = lt->clientes[i + 1].saldo;
            strcpy(lt->clientes[i].senha, lt->clientes[i + 1].senha);
        }
        lt->qtd--;
        printf("\nCliente com o CPF %s foi removido com sucesso.\n\n", cpf_excluir);

      return 0;
    }
}

int debito(ListaDeClientes *lt){
  char cpf_verif[15];
  char senha_verif[11];
  float valor;

  printf("Digite o valor que deseja debitar:\n");
  scanf("%f", &valor);
  getchar();

  printf("Digite o CPF do cliente:\n");
  scanf("%[^\n]", cpf_verif);
  getchar();

  printf("Digite a SENHA do cliente:\n");
  scanf("%[^\n]", senha_verif);
  getchar();

  int indice_cliente = validar_cpf_senha(cpf_verif, senha_verif, lt);
  if (indice_cliente != -1){
    if(valor > lt->clientes[indice_cliente].saldo){
      printf("Saldo insuficiente");
      return 1;
    }
    else{
      lt->clientes[indice_cliente].saldo -= valor;
        printf("O valor %.2f foi debitado com sucesso.\nSaldo atual: %.2f", valor, lt->clientes[indice_cliente].saldo);
      return 0;
      }
  }
  else{
    printf("CPF ou SENHA incorretos");
    return 1;
  }
}

float debito(ListaDeClientes *lt){
  char cpf_verif[15];
  char senha_verif[11];
  float valor;

  printf("Digite o valor que deseja debitar:\n");
  scanf("%f", &valor);
  getchar();

  printf("Digite o CPF do cliente:\n");
  scanf("%[^\n]", cpf_verif);
  getchar();
  
  printf("Digite a SENHA do cliente:\n");
  scanf("%[^\n]", senha_verif);
  getchar();

  int indice_cliente = -1;
  for (int i = 0; i < lt->qtd; i++) {
        if(validar_cpf_senha(cpf_verif, senha_verif, lt) == 1){
            if(valor > lt->clientes[i].saldo){
              printf("Saldo insuficiente");
            }
            else{
              verif_func = debitar(lt, indice_cliente, valor);
              printf("O valor %.2f foi debitado com sucesso.\nSaldo atual: %.2f", valor, lt->clientes[i].saldo);
              
            }
        }
        else{
            printf("CPF ou SENHA incorretos");
        }
    }
};

int deposito(ListaDeClientes *lt){
  char cpf_verif[15];
  float valor;
  int verif_func;

  printf("Digite o valor que deseja depositar:\n");
  scanf("%f", &valor);
  getchar();

  printf("Digite o CPF do cliente:\n");
  scanf("%[^\n]", cpf_verif);
  getchar();


  int indice_cliente = validar_cpf(cpf_verif, lt);
  if (indice_cliente != -1){
        verif_func = depositar(lt, indice_cliente, valor);
        printf("O valor %.2f foi depositado com sucesso.\nSaldo atual: %.2f", valor, lt->clientes[indice_cliente].saldo);
      return 0;
  }
  else{
    printf("CPF incorreto");
    return 1;
  }
}

int transferencia(ListaDeClientes *lt){
  char cpf_verif_ori[15];
  char cpf_verif_dest[15];
  char senha_verif_ori[11];
  int indice_cliente_ori;
  int indice_cliente_dest;
  float valor;
  int verif_func;

  printf("Digite o valor que deseja debitar:\n");
  scanf("%f", &valor);
  getchar();

  printf("Digite o CPF do cliente origem:\n");
  scanf("%[^\n]", cpf_verif_ori);
  getchar();

  printf("Digite a SENHA do cliente origem:\n");
  scanf("%[^\n]", senha_verif_ori);
  getchar();

  printf("Digite o CPF do cliente destino:\n");
  scanf("%[^\n]", cpf_verif_dest);
  getchar();

  indice_cliente_ori = validar_cpf_senha(cpf_verif_ori, senha_verif_ori, lt);
  if (indice_cliente_ori != -1){
    if(valor > lt->clientes[indice_cliente_ori].saldo){
      printf("Saldo insuficiente");
      return 1;
    }
    else{
        indice_cliente_dest = validar_cpf(cpf_verif_dest, lt);
        if (indice_cliente_dest != -1){
          verif_func = debitar(lt, indice_cliente_ori, valor);
          verif_func = depositar(lt, indice_cliente_dest, valor);

          printf("O valor %.2f foi transferido com sucesso.\nSaldo atual do cliente origem: %.2f \nSaldo atual do cliente destino: %.2f", valor, lt->clientes[indice_cliente_ori].saldo,lt->clientes[indice_cliente_dest].saldo);
          return 0;        
        }
        else{
          printf("CPF de destino incorreto");
          return 1;
        }
      }
  }
  else{
    printf("CPF, ou SENHA, da origem, incorretos");
    return 1;
  }
}
