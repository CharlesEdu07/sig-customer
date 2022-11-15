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

int menu_request(void) {
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

    printf("\nDigite a opcao desejada: ");
    int op = read_numeric_op();

    return op;
}

void create_request(void) {
    Request* request = create_request_screen();

    if (request != NULL) {
        if (search_request(request->id) == NULL) {
            save_request(request);

            printf("\nPedido cadastrado com sucesso.\n");
        }

        else {
            printf("\nPedido ja cadastrado.\n");
        }

        free(request);
    }

    else {
        printf("\nNao foi possivel cadastrar o pedido.\n");
        printf("Verifique se o cliente e produto digitados estao cadastrados.\n");
    }
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

        while (!feof(file)) {
            fread(request, sizeof(Request), 1, file);

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

    if (search_customer(customer_cpf) == NULL) {
        return NULL;
    }

    printf("Qual o produto? Digite o codigo: ");
    read_product_code(product_code);

    if (search_product(product_code) == NULL) {
        return NULL;
    }

    printf("Qual a quantidade? Digite: ");
    read_int(quantity);

    int integer_quantity = atoi(quantity);
    
    strcpy(request->id, generate_request_id());
    strcpy(request->date, get_current_date());
    strcpy(request->customer_cpf, customer_cpf);
    strcpy(request->product_code, product_code);

    request->quantity = integer_quantity;
    request->amount_to_pay = get_product_price(product_code) * integer_quantity;
    request->deleted = 0;

    return request;
}

void show_request(Request* request) {
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
    printf("\t\t||            Vendo Pedido            ||\n");
    printf("\t\t========================================\n");

    printf("\nID do pedido: %s\n", request->id);
    printf("Nome do cliente: %s\n", get_customer_name(request->customer_cpf));
    printf("CPF do cliente: %s\n", request->customer_cpf);
    printf("Nome do produto: %s\n", get_product_name(request->product_code));
    printf("Codigo do produto: %s\n", request->product_code);
    printf("Data do pedido: %s\n", request->date);
    printf("Quantidade: %d\n", request->quantity);
    printf("Total a pagar: %.2f", request->amount_to_pay);
}

void find_request(void) {
    terminal_clear();

    Request* request;
    char* id = search_request_screen();

    if (search_request(id) != NULL) {
        request = search_request(id);

        show_request(request);

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

void update_request_file(Request* request) {
    FILE* file = fopen("request.dat", "r+b");

    Request* request_aux = (Request*) malloc(sizeof(Request));

    int found = 0;
    long int minus_one = -1;

    if (file == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }

    while (!feof(file) && !found) {
        fread(request_aux, sizeof(Request), 1, file);

        if (strcmp(request_aux->id, request->id) == 0 && request_aux->deleted == 0) {
            found = 1;

            fseek(file, (minus_one) * sizeof(Request), SEEK_CUR);

            fwrite(request, sizeof(Request), 1, file);
        }
    }

    fclose(file);

    free(request_aux);
}

void update_request(void) {
    Request* request;

    char* id = update_request_screen();

    if (search_request(id) != NULL) {
        request = search_request(id);
        request = update_request_data(request);

        strcpy(request->id, id);

        update_request_file(request);

        free(request);
    }

    else {
        printf("\nPedido nao encontrado ou inexistente.\n");
    }

    free(id);
}

char* update_request_screen(void) {
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
    printf("\t\t||          Atualizar Pedido          ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o identificador do pedido: ");
    read_string(id);

    return id;
}

Request* update_request_data(Request* request) {
    int op;
    char quantity[10];

    do {
        op = 0;

        terminal_clear();

        printf("\t\t=====================================\n");
        printf("\t\t||  Qual(is) dado(s) quer editar?  ||\n");
        printf("\t\t=====================================\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|       1 - Cliente do Pedido       |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|       2 - Produto do Pedido       |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|       3 - Quantia do Pedido       |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|     0 - Encerrar Atualizacoes     |\n");
        printf("\t\t-------------------------------------\n");

        printf("\nDigite a opcao desejada: ");
        op = read_numeric_op();

        if (op != 0) {
            switch (op) {
                case 1:
                    printf("\nDigite o novo cliente do pedido: ");
                    read_cpf(request->customer_cpf);

                    if (search_customer(request->customer_cpf) != NULL) {
                        printf("\nCliente do pedido atualizado com sucesso.\n");
                    }

                    else {
                        printf("\nCliente nao cadastrado.\n");
                    }

                    press_enter_to_continue();
                    terminal_clear();

                    break;

                case 2:
                    printf("\nDigite o novo produto do pedido: ");
                    
                    read_product_code(request->product_code);

                    if (search_product(request->product_code) != NULL) {
                        printf("\nProduto do pedido atualizado com sucesso.\n");
                    }

                    else {
                        printf("\nProduto nao cadastrado.\n");
                    }

                    press_enter_to_continue();
                    terminal_clear();

                    break;

                case 3:
                    printf("\nDigite a nova quantidade do pedido: ");
                    read_int(quantity);

                    int integer_quantity = atoi(quantity);

                    request->quantity = integer_quantity;
                    request->amount_to_pay = get_product_price(request->product_code) * integer_quantity;

                    printf("\nQuantidade do pedido atualizada com sucesso.\n");

                    press_enter_to_continue();
                    terminal_clear();

                    break;

                default:
                    printf("\nOpcao invalida.\n");

                    break;
            }
        }
    } while (op != 0);

    return request;
}

void delete_request_file(Request* request) {
    FILE* file;
    Request* aux_request;

    int found = 0;
    long int minus_one = -1;

    if (confirm_request_delete(request)) {
        file = fopen("request.dat", "r+b");

        aux_request = (Request*) malloc(sizeof(Request));

        if (file == NULL) {
            printf("\nErro ao abrir o arquivo.\n");

            exit(1);
        }

        while (!feof(file) && !found) {
            fread(aux_request, sizeof(Request), 1, file);

            if (strcmp(aux_request->id, request->id) == 0 && aux_request->deleted == 0) {
                found = 1;

                fseek(file, (minus_one) * sizeof(Request), SEEK_CUR);

                aux_request->deleted = 1;

                fwrite(aux_request, sizeof(Request), 1, file);

                printf("\nPedido deletado com sucesso.\n");
            }
        }

        fclose(file);

        free(aux_request);
    }
}

int confirm_request_delete(Request* request) {
    char op;

    terminal_clear();

    show_request(request);

    printf("\nDeseja realmente excluir este pedido? (s/n): ");
    op = read_alpha_op();

    if (tolower(op) == 's') {
        return 1;
    }

    return 0;
}

void delete_request(void) {
    Request* request;

    char* id = delete_request_screen();

    if (search_request(id) != NULL) {
        request = search_request(id);

        delete_request_file(request);

        free(request);
    }

    else {
        printf("\nPedido nao encontrado ou inexistente.\n");
    }

    free(id);
}

char* delete_request_screen(void) {
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
    printf("\t\t||           Deletar Pedido           ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o identificador do pedido: ");
    read_string(id);

    return id;
}

void mod_request(void) {
    int op = menu_request();
    
    while (op != 0) {
        switch (op) {
            case 1:
                create_request();
                
                break;

            case 2:
                find_request();
                
                break;
                
            case 3:
                update_request();
                
                break;
                
            case 4:
                delete_request();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");
                
                break;
        }

        press_enter_to_continue();
        
        op = menu_request();
    }
}