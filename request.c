#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "request.h"
#include "inputs.h"
#include "util.h"

char menu_request(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||          Modulo Pedido          ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       2 - Pesquisar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Atualizar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        4 - Deletar Pedidos        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void create_request_screen(void) {
    terminal_clear();

    char cpf[255];
    char product_code[255];
    char quantity[255];
    char request_id[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Cadastrar Pedidos         ||\n");
    printf("\t\t========================================\n");

    printf("\nQual o cliente fez o pedido? Digite o CPF: ");
    read_cpf(cpf);

    printf("Qual o produto? Digite o codigo: ");
    read_product_code(product_code);

    printf("Qual a quantidade? Digite: ");
    read_int(quantity);

    generate_request_id(cpf, product_code, request_id);

    printf("\nCPF do cliente: %s", cpf);
    printf("Codigo do produto: %s", product_code);
    printf("Quantidade do pedido: %s", quantity);
    printf("ID do pedido: %s", request_id);

    printf("\nPedido feito com sucesso!\n");
}

void search_request_screen(void) {
    terminal_clear();

    char id[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Pesquisar Pedido          ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o identificador do pedido: ");
    read_string(id);

    printf("\nIdentificador do pedido: %s", id);

    printf("\nPesquisa realizada com sucesso!\n");
}

void update_request_screen(void) {
    terminal_clear();

    char id[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Atualizar Pedido          ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o identificador do pedido: ");
    read_string(id);

    printf("\nPedido com o identificador %satualizado com sucesso!\n", id);
}

void delete_request_screen(void) {
    terminal_clear();

    char id[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||           Deletar Pedido           ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o identificador do pedido: ");
    read_string(id);

    printf("\nPedido com identificador %sdeletado com sucesso!\n", id);
}

void mod_request(void) {
    char op = menu_request();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_request_screen();
                
                break;

            case '2':
                search_request_screen();
                
                break;
                
            case '3':
                update_request_screen();
                
                break;
                
            case '4':
                delete_request_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");
                
                break;
        }

        press_enter_to_continue();
        
        op = menu_request();
    }
}