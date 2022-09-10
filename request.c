#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "request.h"
#include "readers.h"

char menu_request(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||          Modulo Pedido          ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       2 - Visualizar Pedido       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Pesquisar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       4 - Atualizar Pedidos       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        5 - Deletar Pedidos        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void create_request_screen(void) {
    terminal_clear();

    char cpf[15];
    char product_name[50];
    char quantity[10];
    char identifier[10];

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
    read_product_name(product_name);

    printf("Qual a quantidade? Digite: ");
    read_request_quantity(quantity);

    printf("Digite um identificador para o pedido: ");
    read_request_identifier(identifier);

    printf("\n%s", cpf);
    printf("%s", product_name);
    printf("%s", quantity);
    printf("%s", identifier);

    printf("\nPedido feito com sucesso!\n");
}

void read_request_screen(void) {
    terminal_clear();

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||           Listar Pedidos           ||\n");
    printf("\t\t========================================\n");
}

void search_request_screen(void) {
    terminal_clear();

    char identifier[10];

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
    read_request_identifier(identifier);

    printf("\nPesquisa realizada com sucesso!\n");
}

void update_request_screen(void) {
    terminal_clear();

    char identifier[10];

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
    read_request_identifier(identifier);

    printf("\nPedido atualizado com sucesso!\n");
}

void delete_request_screen(void) {
    terminal_clear();

    char identifier[10];

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
    read_request_identifier(identifier);

    printf("\nPedido deletado com sucesso!\n");
}

void mod_request(void) {
    char op = menu_request();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_request_screen();
                
                break;
                
            case '2':
                read_request_screen();
                
                break;

            case '3':
                search_request_screen();
                
                break;
                
            case '4':
                update_request_screen();
                
                break;
                
            case '5':
                delete_request_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");
                
                break;
        }

        press_enter_to_continue();
        
        op = menu_request();
    }
}