#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

// Função para validar o CPF
int validar_cpf(char* cpf, ListaDeClientes *lt) {
    for (int x = 0; x < lt->qtd; x++) {
        if (strcmp(lt->clientes[x].cpf, cpf) == 0) {
            return 1; // CPF já existe na lista
        }
    }
    return 0; // CPF não existe na lista
}


int validar_cpf_senha(char* cpf_origem, char* senha_origem, ListaDeClientes* lista_clientes) {
    int validador = 0;
    for (int x = 0; x < lista_clientes->qtd; x++) {
        if (strcmp(lista_clientes->clientes[x].cpf, cpf_origem) == 0 && strcmp(lista_clientes->clientes[x].senha, senha_origem) == 0) {
            validador = 1;
        }
    }
    if (validador == 1){
        return 1;
    }
    else {
        return 0;
    }
}


int cadastrar_cliente(ListaDeClientes *lt){
    char cpf_verif[15];

    // Lendo o CPF do usuário
    printf("Digite o seu cpf: ");
    scanf(" %[^\n]", cpf_verif);

    // Verificando se o CPF já está em uso
    if (validar_cpf(cpf_verif, lt) == 1) {
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
    //return 0;
}


void listar_clientes(ListaDeClientes lt) {
    //Verificando se existe algum cadastro
    if (lt.qtd == 0){
        printf("\nNao existe nenhum cadastro na base de dados.\n");
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
}


void excluir_conta(ListaDeClientes *lt, char *cpf_excluir, char *senha_excluir) {
    printf("Digite o CPF do cliente a ser excluído: ");
    scanf(" %[^\n]", cpf_excluir);
    printf("Digite a senha do cliente: ");
    scanf(" %[^\n]", senha_excluir);

    int posicao_excluir = -1;
    for (int i = 0; i < lt->qtd; i++) {
        if (strcmp(lt->clientes[i].cpf, cpf_excluir) == 0 && strcmp(lt->clientes[i].senha, senha_excluir) == 0) {
            posicao_excluir = i;
            break;
        }
    }

    if (posicao_excluir == -1) {
        printf("CPF ou senha incorretos, ou conta não encontrada na lista de clientes.\n\n");
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
                lt->clientes[i].saldo -= valor;
                printf("O valor %.2f foi debitado com sucesso.\nSaldo atual: %.2f", valor, lt->clientes[i].saldo);

            }
        }
        else{
            printf("CPF ou SENHA incorretos");
        }
    }
};