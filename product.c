#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

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

void create_product(void) {
    Product* product = create_product_screen();

    if (search_product(product->product_code) == NULL) {
        save_product(product);

        printf("\nProduto cadastrado com sucesso.\n");
    }

    else {
        printf("\nProduto ja cadastrado.\n");
    }

    free(product);
}

Product* search_product(char* product_code) {
    FILE* file;
    Product* product;

    product = (Product*) malloc(sizeof(Product));

    if (access("product.dat", F_OK) != -1) {
        file = fopen("product.dat", "rb");

        if (file == NULL) {
            printf("\nErro ao abrir o arquivo.\n");
            
            exit(1);
        }

        while (fread(product, sizeof(Product), 1, file)) {
            if (strcmp(product->product_code, product_code) == 0 && product->deleted == 0) {
                fclose(file);

                return product;
            }
        }

        fclose(file);
    }

    return NULL;
}

void save_product(Product *product) {
    FILE* file = fopen("product.dat", "ab");

    if (file == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }

    fwrite(product, sizeof(Product), 1, file);

    fclose(file);
}

Product* create_product_screen(void) {
    terminal_clear();

    Product* product = (Product*) malloc(sizeof(Product));

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

    strcpy(product->product_code, product_code);
    strcpy(product->product_name, product_name);
    strcpy(product->product_type, product_type);
    strcpy(product->product_description, product_description);
    strcpy(product->product_price, product_price);

    printf("\nCodigo do produto: %s\n", product->product_code);
    printf("Nome do produto: %s\n", product->product_name);
    printf("Tipo do produto: %s\n", product->product_type);
    printf("Descricao do produto: %s\n", product->product_description);
    printf("Preco do produto: %s\n", product->product_price);

    return product;
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
                create_product();
                
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