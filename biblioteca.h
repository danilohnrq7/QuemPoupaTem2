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

//Função para cadastrar clientes, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int cadastrar_cliente(ListaDeClientes *lt);

//Função para listar clientes, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int listar_clientes(ListaDeClientes lt);

int excluir_conta(ListaDeClientes *lt, char *cpf_excluir, char *senha_excluir);

int validar_cpf(char* cpf, ListaDeClientes *lt);

int validar_cpf_senha(char* cpf_origem, char* senha_origem, ListaDeClientes* lista_clientes);

/*int debito(ListaDeClientes *lt, int indice_cliente, float valor);*/

int deposito(ListaDeClientes *lt);

int depositar(ListaDeClientes *lt, int indice_cliente, float valor);

int debitar(ListaDeClientes *lt, int indice_cliente, float valor);

float debito(ListaDeClientes *lt);
//int debito(ListaDeClientes *lt);

int transferencia(ListaDeClientes *lt);

//Função para salvar clientes em um arquivo binário, que recebe um ponteiro de ListaDeTClientes como parâmetro e retorna um inteiro
int salvarClientes(ListaDeClientes *lt);

//Função para carregar clientes lidos do arquivo binário, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int carregarClientes(ListaDeClientes *lt);

#endif //QUEMPOUPATEM2_BIBLIOTECA_H
