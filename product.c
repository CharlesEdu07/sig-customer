#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "product.h"
#include "inputs.h"
#include "util.h"

char menu_product(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||         Modulo Produtos         ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       2 - Pesquisar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Atualizar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        4 - Deletar Produto        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void create_product_screen(void) {
    terminal_clear();

    char product_code[255];
    char product_name[255];
    char product_type[255];
    char product_description[255];
    char product_price[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Cadastrar Produto         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o codigo de barras do produto: ");
    read_product_code(product_code);
    
    printf("Digite o nome do produto: ");
    read_name(product_name);

    printf("Digite o tipo do produto: ");
    read_name(product_type);

    printf("Digite a descricao do produto: ");
    read_string(product_description);
                
    printf("Digite o preco do produto: ");
    read_float(product_price);

    printf("\nNome do produto: %s", product_name);
    printf("Tipo do produto: %s", product_type);
    printf("Codigo do produto: %s", product_code);
    printf("Preco do produto: %s", product_price);

    printf("\nProduto cadastrado com sucesso!\n");
}

void search_product_screen(void) {
    terminal_clear();

    char product_name[255];
    char product_code[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||         Pesquisar Produtos         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o nome do produto: ");
    read_name(product_name);

    printf("Digite o codigo do produto: ");
    read_product_code(product_code);

    printf("\nNome do produto: %s", product_name);
    printf("Codigo do produto: %s", product_code);

    printf("\nPesquisa realizada com sucesso!\n");
}

void update_product_screen(void) {
    terminal_clear();

    char product_code[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||         Atualizar Produtos         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o codigo do produto: ");
    read_product_code(product_code);

    printf("\nProduto de codigo %satualizado com sucesso!\n", product_code);
}

void delete_product_screen(void) {
    terminal_clear();

    char product_code[255];

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Deletar Produtos          ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o codigo do produto: ");
    read_product_code(product_code);

    printf("\nProduto de codigo %sdeletado com sucesso!\n", product_code);
}

void mod_product(void) {
    char op = menu_product();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_product_screen();
                
                break;

            case '2':
                search_product_screen();
                
                break;
                
            case '3':
                update_product_screen();
                
                break;
                
            case '4':
                delete_product_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");
                
                break;
        }
        
        press_enter_to_continue();
        
        op = menu_product();
    }
}