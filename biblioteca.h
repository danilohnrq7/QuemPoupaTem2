#ifndef QUEMPOUPATEM2_BIBLIOTECA_H
#define QUEMPOUPATEM2_BIBLIOTECA_H
//Definindo a struct do cadastro de um clientes
typedef struct {
    char nome[60];
    char cpf[12];
    char tipo_conta[7];
    float saldo;
    char senha[11];
    char extrato[100][40];
    int qtdExtratos;
}Cliente; // Nomeando este tipo de struct como: Cliente


//Definindo a struct que conterá as structs Cliente
typedef struct {
    Cliente clientes[1000];
    int qtd;
} ListaDeClientes; // Nomeando este tipo de struct como: ListaDeClientes


//Função para cadastrar clientes, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int cadastrar_cliente(ListaDeClientes *lt);


//Função para listar clientes, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int listar_clientes(ListaDeClientes lt);


//Função para deletar clientes da ListaDeClientes, novamente usando ponteiro
int excluir_conta(ListaDeClientes *lt, char *cpf_excluir, char *senha_excluir);


// Função para validar CPF, que recebe um ponteiro para a string cpf e um ponteiro para ListaDeClientes como parâmetro e retorna um inteiro
int validar_cpf(char* cpf, ListaDeClientes *lt);


// Função para validar CPF e senha, que recebe ponteiros para as strings cpf_origem, senha_origem e um ponteiro para ListaDeClientes como parâmetro e retorna um inteiro
int validar_cpf_senha(char* cpf_origem, char* senha_origem, ListaDeClientes* lista_clientes);


// Função para realizar um depósito, que recebe um ponteiro para ListaDeClientes como parâmetro e retorna um inteiro
int deposito(ListaDeClientes *lt);


// Função para depositar um valor em uma conta específica, que recebe um ponteiro para ListaDeClientes, um inteiro indice_cliente e um float valor como parâmetros e retorna um inteiro
int depositar(ListaDeClientes *lt, int indice_cliente, float valor);


// Função para debitar um valor de uma conta específica, que recebe um ponteiro para ListaDeClientes, um inteiro indice_cliente e um float valor como parâmetros e retorna um inteiro
int debitar(ListaDeClientes *lt, int indice_cliente, float valor, int tipo);


// Função para verificar o débito total de uma ListaDeClientes, que recebe um ponteiro para ListaDeClientes como parâmetro e retorna um float
float debito(ListaDeClientes *lt);


// Função para realizar transferência entre contas, que recebe um ponteiro para ListaDeClientes como parâmetro e retorna um inteiro
int transferencia(ListaDeClientes *lt);


//Função para salvar clientes em um arquivo binário, que recebe um ponteiro de ListaDeTClientes como parâmetro e retorna um inteiro
int salvarClientes(ListaDeClientes *lt);


//Função para carregar clientes lidos do arquivo binário, que recebe um ponteiro de ListaDeClientes como parâmetro e retorna um inteiro
int carregarClientes(ListaDeClientes *lt);


// Função para gerar extratos de clientes
int gerarExtatos(ListaDeClientes *lt, int indiceCliente, int tipo, float valor, char *op);


//funcao para escrever os extratos em um arquivo exclusivo à cada cliente
int Extatos(ListaDeClientes *lt, int indiceCliente);


// Função para chamar o extrato de clientes, recebe um ponteiro para ListaDeClientes
int chamarExtrato(ListaDeClientes *lt);

#endif //QUEMPOUPATEM2_BIBLIOTECA_H