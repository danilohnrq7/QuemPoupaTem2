#ifndef QUEMPOUPATEM2_BIBLIOTECA_H
#define QUEMPOUPATEM2_BIBLIOTECA_H

//Definindo a struct do cadastro de um clientes
typedef struct {
    char nome[60];
    char cpf[12];
    char tipo_conta[7];
    float saldo;
    char senha[11];
}Cliente; // Nomeando este tipo de struct como: Cliente


//Definindo a struct que conterá as structs Cliente
typedef struct {
    Cliente clientes[1001];
    int qtd;
} ListaDeClientes; // Nomeando este tipo de struct como: ListaDeClientes


//Função para cadastrar tarefas, que recebe um ponteiro de ListaDeTarefas como parâmetro e retorna um inteiro
int cadastrar_cliente(ListaDeClientes *lt);

void listar_clientes(ListaDeClientes lt);

void excluir_conta(ListaDeClientes *lt, char *cpf_excluir, char *senha_excluir);

int validar_cpf(char* cpf, ListaDeClientes *lt);

int validar_cpf_senha(char* cpf_origem, char* senha_origem, ListaDeClientes* lista_clientes);

#endif //QUEMPOUPATEM2_BIBLIOTECA_H
