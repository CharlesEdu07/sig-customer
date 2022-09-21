#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "product.h"
#include "readers.h"

char menu_product(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||         Modulo Produtos         ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|      2 - Visualizar Produtos      |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Pesquisar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       4 - Atualizar Produto       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        5 - Deletar Produto        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void create_product_screen(void) {
    terminal_clear();

    char* product_name;
    char* product_type;
    char* product_price;
    char* product_code;

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

    printf("\nDigite o nome do produto: ");
    product_name = read_product_name();

    printf("Digite o tipo do produto: ");
    product_type = read_product_type();

    printf("Digite o codigo do produto: ");
    product_code = read_product_code();
                
    printf("Digite o preco do produto: ");
    product_price = read_product_price();

    printf("\n%s", product_name);
    printf("%s", product_type);
    printf("%s", product_code);
    printf("%s", product_price);

    printf("\nProduto cadastrado com sucesso!\n");
}

void read_product_screen(void) {
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
    printf("\t\t||           Listar Produtos          ||\n");
    printf("\t\t========================================\n");
}

void search_product_screen(void) {
    terminal_clear();

    char* product_name;
    char* product_code;

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
    product_name = read_product_name();

    printf("Digite o codigo do produto: ");
    product_code = read_product_code();

    printf("\nPesquisa realizada com sucesso!\n");
}

void update_product_screen(void) {
    terminal_clear();

    char* product_code;

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
    product_code = read_product_code();

    printf("\nProduto atualizado com sucesso!\n");
}

void delete_product_screen(void) {
    terminal_clear();

    char* product_code;

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
    product_code = read_product_code();

    printf("\nProduto deletado com sucesso!\n");
}

void mod_product(void) {
    char op = menu_product();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_product_screen();
                
                break;
                
            case '2':
                read_product_screen();
                
                break;

            case '3':
                search_product_screen();
                
                break;
                
            case '4':
                update_product_screen();
                
                break;
                
            case '5':
                delete_product_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");
                
                break;
        }
        
        press_enter_to_continue();
        
        op = menu_product();
    }
}