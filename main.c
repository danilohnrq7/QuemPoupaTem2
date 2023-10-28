#include <stdio.h>
#include "biblioteca.h"

int main()
{
    ListaDeClientes ListaGeral;
    char cpf_excluir[15];
    char senha_excluir[15];

    printf("\n>>>>> Quem Poupa Tem 2.0 <<<<<\n");
    printf("Seja bem-vindo ao banco Quem Poupa Tem 2.0!!!\n\n");

    //variaveis para o funcionamento do menu
    char opcao = '0';

    do {
        printf("Selecione a operacao que deseja realizar:\nMENU:\n");
        //opcoes em apenas um printf por economia de linhas de codigo e organizacao
        printf("1 - Novo Cliente (cadastro)\n2 - Excluir Conta\n3 - Listar Clientes\n4 - Realizar Debito\n5 - Realizar Deposito\n6 - Extrato\n7 - Fazer uma Tranferencia\n0 - Sair\n");

        scanf("%c", &opcao);
        //limpar buffer
        getchar();

        //switch case para um menu funcional, chama a funcao respectiva ao numero escolhido
        switch (opcao) {
            case '0':             
                printf("Obrigado por utilizar o Quem Poupa Tem! Volte sempre!");
                return 0;
            case '1':
                printf("\nEntrou na operacao 'Novo Cliente'\n");
                cadastrar_cliente(&ListaGeral);
                break;
            case '2':
                printf("\nEntrou na operacao 'Excluir Conta'\n");
                excluir_conta(&ListaGeral, cpf_excluir, senha_excluir);
                break;
            case '3':
                printf("\nEntrou na operacao 'Listar Clientes'\n");
                listar_clientes(ListaGeral);
                break;
            case '4':
                printf("\nEntrou na operacao 'Debito'\n");
                break;
            case '5':
                printf("\nEntrou na operacao 'Deposito'\n");
                break;
            case '6':
                printf("\nEntrou na operacao 'Extrato'\n");
                break;
            case '7':
                printf("\nEntrou na operacao 'Transferencia'\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente");
        }
        printf("\nPressione ENTER para prosseguir\n\n");
        //limpa o buffer
        getchar();
        continue;
        
    //loop infinito enquanto opcao =1, reinicia o menu ao termino de uma operacao
    }while (opcao != '0');
}
