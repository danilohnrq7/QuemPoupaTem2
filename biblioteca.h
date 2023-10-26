#ifndef QUEMPOUPATEM2_BIBLIOTECA_H
#define QUEMPOUPATEM2_BIBLIOTECA_H

//Definindo a struct do cadastro de um clientes
typedef struct {
    char nome[30];
    char cpf[12];
    char tipo_conta[7];
    char valor_inicial[12];
    char senha[11]
}Cliente; // Nomeando este tipo de struct como: Cliente


//Definindo a struct que conterá as structs Cliente
typedef struct {
    Cliente clientes[1001];
    int qtd;
} ListaDeClientes; // Nomeando este tipo de struct como: ListaDeClientes


//Função para cadastrar tarefas, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int cadastrar_cliente(ListaDeClientes *lt);

void listar_clientes(ListaDeClientes lt);

#endif //QUEMPOUPATEM2_BIBLIOTECA_H
