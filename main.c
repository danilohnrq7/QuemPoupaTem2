#include <stdio.h>
#include "biblioteca.h"

int main()
{
    ListaDeClientes ListaGeral;

    printf("\n>>>>> Quem Poupa Tem 2.0 <<<<<\n");
    printf("Seja bem-vindo ao banco Quem Poupa Tem 2.0!!!\n\n");

    //variaveis para o funcionamento do menu
    char opcao;
    int LoopOpcao = 1;

    //loop infinito enquanto LoopOpcao =1, reinicia o menu ao termino de uma operacao
    while (LoopOpcao = 1){
        printf("Selecione a operacao que deseja realizar:\nMENU:\n");
        //opcoes em apenas um printf por economia de linhas de codigo e organizacao
        printf("1 - Novo Cliente (cadastro)\n2 - Excluir Conta\n3 - Listar Clientes\n4 - Realizar Debito\n5 - Realizar Deposito\n6 - Extrato\n7 - Fazer uma Tranferencia\n0 - Sair\n");

        scanf("%c", &opcao);
        //limpar buffer
        getchar();

        //switch case para um menu funcional, chama a funcao respectiva ao numero escolhido
        switch (opcao) {
            case '0':
                //iguala LoopOpcao a 0 e quebra o while
                LoopOpcao = 0;
                printf("Obrigado por utilizar o Quem Poupa Tem! Volte sempre!");
                return 0;
            case '1':
                printf("Entrou na operacao 'Novo Cliente'\n");
                cadastrar_cliente(&ListaGeral);
                break;
            case '2':
                printf("Entrou na operacao 'Excluir Conta'\n");
                break;
            case '3':
                printf("Entrou na operacao 'Listar Clientes'\n");
                listar_clientes(ListaGeral);
                break;
            case '4':
                printf("Entrou na operacao 'Debito'\n");
                break;
            case '5':
                printf("Entrou na operacao 'Deposito'\n");
                break;
            case '6':
                printf("Entrou na operacao 'Extrato'\n");
                break;
            case '7':
                printf("Entrou na operacao 'Transferencia'\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente");
        }
        printf("\nPressione ENTER para prosseguir\n\n");
        //limpa o buffer
        getchar();
        continue;
    }
}
