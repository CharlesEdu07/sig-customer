#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "report.h"
#include "customer.h"
#include "product.h"
#include "request.h"
#include "inputs.h"
#include "util.h"

int menu_report(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||        Modulo Relatorios        ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|     1 - Relatorio de Clientes     |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|     2 - Relatorio de Produtos     |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|      3 - Relatorio de Pedido      |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    printf("\nDigite a opcao desejada: ");
    int op = read_numeric_op();

    return op;
}

int menu_customer_report(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||      Relatorio de Clientes      ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|     1 - Listar Todos Clientes     |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   2 - Listar em Ordem Alfabetica  |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|      3 - Pedidos Por Cliente      |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   4 - Listar Clientes Deletados   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    printf("\nDigite a opcao desejada: ");
    int op = read_numeric_op();

    return op;
}

int menu_product_report(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||      Relatorio de Produtos      ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|     1 - Listar Todos Produtos     |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   2 - Listar em Ordem Alfabetica  |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   3 - Listar Produtos Por Tipos   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   4 - Listar Produtos Por Preco   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   5 - Listar Produtos Deletados   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    printf("\nDigite a opcao desejada: ");
    int op = read_numeric_op();

    return op;
}

int menu_request_report(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||      Relatorio de Pedidos       ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|     1 - Listar Todos Pedidos      |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|    2 - Listar Pedidos Por Data    |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        3 - Maior Quantidade       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        4 - Menor Quantidade       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|    5 - Listar Pedidos Deletados   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    printf("\nDigite a opcao desejada: ");
    int op = read_numeric_op();

    return op;
}

void list_customer(void) {
    terminal_clear();

    FILE* fp;

    if (access("customer.dat", F_OK) == -1) {
        printf("\t\t========================================\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||            SIG-Customer            ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t========================================\n");
        printf("\n");
        printf("\t\t========================================\n");
        printf("\t\t||           Listar Clientes          ||\n");
        printf("\t\t========================================\n");

        printf("\nNao ha clientes cadastrados.\n");
    }

    else {
        fp = fopen("customer.dat", "rb");
        Customer* customer = (Customer*) malloc(sizeof(Customer));

        printf("\t\t========================================\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||            SIG-Customer            ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t========================================\n");
        printf("\n");
        printf("\t\t========================================\n");
        printf("\t\t||           Listar Clientes          ||\n");
        printf("\t\t========================================\n");

        int count = 1;

        while (fread(customer, sizeof(Customer), 1, fp)) {
            if (customer->deleted == 0) {
                printf("\nCliente %d:\n", count);
                printf("\nNome do cliente: %s\n", customer->name);
                printf("CPF do cliente: %s\n", customer->cpf);
                printf("Celular do cliente: %s\n", customer->phone);
                printf("Email do cliente: %s\n", customer->email);
                printf("Endereco do cliente: %s\n", customer->address);

                count++;
            }
        }

        if (count == 1) {
            printf("\nNao ha clientes cadastrados.\n");
        }

        fclose(fp);
    
        free(customer);
    }
}

void show_found_customer(Customer_List* customer_list) {
    printf("\nNome do cliente: %s\n", customer_list->name);
    printf("CPF do cliente: %s\n", customer_list->cpf);
    printf("Celular do cliente: %s\n", customer_list->phone);
    printf("Email do cliente: %s\n", customer_list->email);
    printf("Endereco do cliente: %s\n", customer_list->address);
}

void list_customer_alpha_order(void) {
    FILE* file;

    int lenght;

    Customer* customer;

    Customer_List* new_customer;
    Customer_List* list;

    if (access("customer.dat", F_OK) != -1) {
        file = fopen("customer.dat", "rb");

        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }

        else {
            list = NULL;

            customer = (Customer*) malloc(sizeof(Customer));

            while (fread(customer, sizeof(Customer), 1, file)) {
                if (customer->deleted == 0) {
                    new_customer = (Customer_List*) malloc(sizeof(Customer_List));

                    lenght = strlen(customer->name) + 1;
                    new_customer->name = (char*) malloc(lenght * sizeof(char));
                    strcpy(new_customer->name, customer->name);

                    lenght = strlen(customer->cpf) + 1;
                    new_customer->cpf = (char*) malloc(lenght * sizeof(char));
                    strcpy(new_customer->cpf, customer->cpf);

                    lenght = strlen(customer->phone) + 1;
                    new_customer->phone = (char*) malloc(lenght * sizeof(char));
                    strcpy(new_customer->phone, customer->phone);

                    lenght = strlen(customer->email) + 1;
                    new_customer->email = (char*) malloc(lenght * sizeof(char));
                    strcpy(new_customer->email, customer->email);

                    lenght = strlen(customer->address) + 1;
                    new_customer->address = (char*) malloc(lenght * sizeof(char));
                    strcpy(new_customer->address, customer->address);

                    if (list == NULL) {
                        list = new_customer;
                        list->next = NULL;
                    }

                    else if (strcmp(list->name, new_customer->name) > 0) {
                        new_customer->next = list;
                        list = new_customer;
                    }

                    else {
                        Customer_List* before = list;
                        Customer_List* current = list->next;

                        while (current != NULL && strcmp(current->name, new_customer->name) < 0) {
                            before = current;
                            current = current->next;
                        }

                        before->next = new_customer;
                        new_customer->next = current;
                    }
                }
            }

            free(customer);

            new_customer = list;

            while (new_customer != NULL) {
                show_found_customer(new_customer);
                
                new_customer = new_customer->next;
            }

            new_customer = list;

            while (new_customer != NULL) {
                list = new_customer->next;

                free(new_customer->name);
                free(new_customer->cpf);
                free(new_customer->phone);
                free(new_customer->email);
                free(new_customer->address);
                free(new_customer);

                new_customer = list;
            }
        }

        fclose(file);
    }
}

void list_request_by_customer(void) {
    ;
}

void list_product(void) {
    terminal_clear();

    FILE* fp;

    if (access("product.dat", F_OK) == -1) {
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

        printf("\nNao existem produtos registados.\n");
    }

    else {
        fp = fopen("product.dat", "rb");
        Product* product = (Product*) malloc(sizeof(Product));

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

        int count = 1;

        while (fread(product, sizeof(Product), 1, fp)) {
            if (product->deleted == 0) {
                printf("\nProduto %d:\n", count);
                printf("\nNome do produto: %s\n", product->product_name);
                printf("Codigo do produto: %s\n", product->product_code);
                printf("Descricao do produto: %s\n", product->product_description);
                printf("Tipo do produto: %s\n", product->product_type);
                printf("Preco do produto: %.2f\n", product->product_price);

                count++;
            }
        }

        if (count == 1) {
            printf("\nNao existem produtos registados.\n");
        }

        fclose(fp);
    
        free(product);
    }
}

void list_request(void) {
    terminal_clear();

    FILE* fp;

    if (access("request.dat", F_OK) == -1) {
        printf("\t\t========================================\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||            SIG-Customer            ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t========================================\n");
        printf("\n");
        printf("\t\t========================================\n");
        printf("\t\t||            Listar Pedido           ||\n");
        printf("\t\t========================================\n");

        printf("\nNao existem pedidos registados.\n");
    }

    else {
        fp = fopen("request.dat", "rb");
        Request* request = (Request*) malloc(sizeof(Request));

        printf("\t\t========================================\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||            SIG-Customer            ||\n");
        printf("\t\t||            ------------            ||\n");
        printf("\t\t||                                    ||\n");
        printf("\t\t========================================\n");
        printf("\n");
        printf("\t\t========================================\n");
        printf("\t\t||            Listar Pedido           ||\n");
        printf("\t\t========================================\n");

        int count = 1;

        while (fread(request, sizeof(Request), 1, fp)) {
            if (request->deleted == 0) {
                printf("\nPedido %d:\n", count);
                printf("\nID do pedido: %s\n", request->id);
                printf("Nome do cliente: %s\n", get_customer_name(request->customer_cpf));
                printf("CPF do cliente: %s\n", request->customer_cpf);
                printf("Codigo do produto: %s\n", request->product_code);
                printf("Nome do produto: %s\n", get_product_name(request->product_code));
                printf("Data do pedido: %s\n", request->date);
                printf("Quantidade do produto: %d\n", request->quantity);
                printf("Total a pagar: %.2f\n", request->amount_to_pay);

                count++;
            }
        }

        if (count == 1) {
            printf("\nNao existem pedidos registados.\n");
        }

        fclose(fp);
    
        free(request);
    }
}

void mod_report(void) {
    int op = menu_report();

    while (op != 0) {
        switch (op) {
            case 1:
                mod_customer_report();

                break;

            case 2:
                mod_product_report();

                break;

            case 3:
                mod_request_report();

                break;

            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");

                break;
        }

        press_enter_to_continue();

        op = menu_report();
    }
}

void mod_customer_report(void) {
    int op = menu_customer_report();

    while (op != 0) {
        switch (op) {
            case 1:
                list_customer();

                break;

            case 2:
                list_customer_alpha_order();

                break;

            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");

                break;
        }

        press_enter_to_continue();

        op = menu_customer_report();
    }
}

void mod_product_report(void) {
    int op = menu_product_report();

    while (op != 0) {
        switch (op) {
            case 1:
                list_product();

                break;

            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");

                break;
        }

        press_enter_to_continue();

        op = menu_product_report();
    }
}

void mod_request_report(void) {
    int op = menu_request_report();

    while (op != 0) {
        switch (op) {
            case 1:
                list_request();

                break;

            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");

                break;
        }

        press_enter_to_continue();

        op = menu_request_report();
    }
}