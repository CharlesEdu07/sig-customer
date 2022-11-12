#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "customer.h"
#include "product.h"
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

void create_request(void) {
    Request* request = create_request_screen();

    if (search_request(request->id) == NULL) {
        save_request(request);

        printf("\nPedido cadastrado com sucesso.\n");
    }

    else {
        printf("\nPedido ja cadastrado.\n");
    }

    free(request);
}

Request* search_request(char* id) {
    FILE* file;
    Request* request;

    request = (Request*) malloc(sizeof(Request));

    if (access("request.dat", F_OK) != -1) {
        file = fopen("request.dat", "rb");

        if (file == NULL) {
            printf("\nErro ao abrir o arquivo.\n");

            exit(1);
        }

        while (fread(request, sizeof(Request), 1, file)) {
            if (strcmp(request->id, id) == 0) {
                fclose(file);

                return request;
            }
        }

        fclose(file);
    }

    return NULL;
}

void save_request(Request* request) {
    FILE* file = fopen("request.dat", "ab");

    if (file == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }

    fwrite(request, sizeof(Request), 1, file);

    fclose(file);
}

Request* create_request_screen(void) {
    terminal_clear();

    Request* request = (Request*) malloc(sizeof(Request));

    char customer_cpf[20];
    char product_code[50];
    char quantity[10];

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
    read_cpf(customer_cpf);

    printf("Qual o produto? Digite o codigo: ");
    read_product_code(product_code);

    printf("Qual a quantidade? Digite: ");
    read_int(quantity);

    strcpy(request->id, generate_request_id());
    strcpy(request->date, get_current_date());
    strcpy(request->customer_cpf, customer_cpf);
    strcpy(request->product_code, product_code);
    strcpy(request->price, "0");
    strcpy(request->quantity, quantity);
    request->deleted = 0;

    return request;
}

void find_request(void) {
    terminal_clear();

    Request* request;
    char* id = search_request_screen();

    if (search_request(id) != NULL) {
        request = search_request(id);

        printf("\t\t========================================\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||            SIG-Customer            ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t========================================\n");
        printf("\n");
        printf("\t\t========================================\n");
        printf("\t\t||          Pesquisar Pedidos         ||\n");
        printf("\t\t========================================\n");

        printf("\nID: %s", request->id);
        printf("\nCPF: %s", request->customer_cpf);
        printf("\nCodigo do produto: %s", request->product_code);
        printf("\nQuantidade: %s", request->quantity);

        printf("\n");

        free(request);
    }

    else {
        printf("\nPedido nao encontrado.\n");
    }

    free(id);
}

char* search_request_screen(void) {
    terminal_clear();

    char* id = (char*) malloc(sizeof(char) * 50);

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

    return id;
}

void update_request_screen(void) {
    terminal_clear();

    char id[50];

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

    char id[50];

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
                create_request();
                
                break;

            case '2':
                find_request();
                
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