#include <stdio.h>
#include "biblioteca.h"
int cadastrar_cliente(ListaDeClientes *lt){
    //lendo o nome do usuario
    printf("Digite seu nome (maximo de 30 caracteres): ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].nome);

    //Lendo o cpf do usuario
    printf("Digite o seu cpf: ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].cpf);

    //Lendo o tipo de conta escolhida pelo usuario
    printf("Insira o tipo de conta\nConta Comum = tipo 1\nConta Plus = tipo 2: ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].tipo_conta);

    //Lendo o valor inicial da conta
    printf("Digite o valor incial da conta (primeiro deposito): ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].valor_inicial);

    //Lendo a senha do usuario
    printf("Crie uma senha para sua senha (maximo 10 caracteres): ");
    scanf(" %[^\n]",lt->clientes[lt->qtd].senha);

    //Aumentando a variável do número de structs
    lt->qtd ++;

    /*Guardando a nova struct em um arquivo binário e verificando retorno da função
    controle = salvarTarefas(lt);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }*/

    return 0;
}
