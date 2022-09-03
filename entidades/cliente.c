#include "../util/read_data.c"

void cadastrar_cliente() {
    system("clear");
    printf("\nCadastrar Cliente\n\n");

    read_nome();
    read_cpf();
    read_celular();
    read_endereco();
    read_email();
}

void visualizar_cliente() {
    printf("\nVisualizar Clientes\n");
}

void pesquisar_cliente() {
    printf("\nPesquisar Clientes\n\n");
    
    read_nome();
    read_cpf();
}

void atualizar_cliente() {
    printf("\nAtualizar Cliente\n");
}

void deletar_cliente() {
    printf("\nDeletar Cliente\n");
}