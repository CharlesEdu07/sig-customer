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
    printf("\t\t|   3 - Listar Clientes Deletados   |\n");
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
    printf("\t\t| 3 - Listar Pedidos Por Quantidade |\n");
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

void list_customer_banner(void) {
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
}

void list_product_banner(void) {
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

void list_request_banner(void) {
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

void list_customer(void) {
    terminal_clear();

    FILE* fp;

    if (access("customer.dat", F_OK) == -1) {
        list_customer_banner();

        printf("\nNao ha clientes cadastrados.\n");
    }

    else {
        fp = fopen("customer.dat", "rb");

        Customer* customer = (Customer*) malloc(sizeof(Customer));

        list_customer_banner();

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
    terminal_clear();

    list_customer_banner();

    printf("\nNome do cliente: %s\n", customer_list->name);
    printf("CPF do cliente: %s\n", customer_list->cpf);
    printf("Celular do cliente: %s\n", customer_list->phone);
    printf("Email do cliente: %s\n", customer_list->email);
    printf("Endereco do cliente: %s\n", customer_list->address);
}

void list_customer_by_name(void) {
    FILE* file;

    int length;

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

                    length = strlen(customer->name) + 1;
                    new_customer->name = (char*) malloc(length * sizeof(char));
                    strcpy(new_customer->name, customer->name);

                    length = strlen(customer->cpf) + 1;
                    new_customer->cpf = (char*) malloc(length * sizeof(char));
                    strcpy(new_customer->cpf, customer->cpf);

                    length = strlen(customer->phone) + 1;
                    new_customer->phone = (char*) malloc(length * sizeof(char));
                    strcpy(new_customer->phone, customer->phone);

                    length = strlen(customer->email) + 1;
                    new_customer->email = (char*) malloc(length * sizeof(char));
                    strcpy(new_customer->email, customer->email);

                    length = strlen(customer->address) + 1;
                    new_customer->address = (char*) malloc(length * sizeof(char));
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

void list_deleted_customer(void) {
    terminal_clear();

    FILE* fp;

    if (access("customer.dat", F_OK) == -1) {
        list_customer_banner();

        printf("\nNao ha clientes cadastrados.\n");
    }

    else {
        fp = fopen("customer.dat", "rb");

        Customer* customer = (Customer*) malloc(sizeof(Customer));

        list_customer_banner();

        int count = 1;

        while (fread(customer, sizeof(Customer), 1, fp)) {
            if (customer->deleted == 1) {
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
            printf("\nNao ha clientes deletados.\n");
        }

        fclose(fp);
    
        free(customer);
    }
}

void list_product(void) {
    terminal_clear();

    FILE* fp;

    if (access("product.dat", F_OK) == -1) {
        list_product_banner();

        printf("\nNao existem produtos registados.\n");
    }

    else {
        fp = fopen("product.dat", "rb");
        Product* product = (Product*) malloc(sizeof(Product));

        list_product_banner();

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

void show_found_product(Product_List* product_list) {
    printf("\nNome do produto: %s\n", product_list->product_name);
    printf("Codigo do produto: %s\n", product_list->product_code);
    printf("Descricao do produto: %s\n", product_list->product_description);
    printf("Tipo do produto: %s\n", product_list->product_type);
    printf("Preco do produto: %.2f\n", product_list->product_price);
}

void list_product_by_name(void) {
    FILE* file;

    int length;

    Product* product;

    Product_List* new_product;
    Product_List* list = NULL;

    if (access("product.dat", F_OK) != -1) {
        file = fopen("product.dat", "rb");

        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");

            exit(1);
        }

        else {
            list = NULL;

            product = (Product*) malloc(sizeof(Product));

            while (fread(product, sizeof(Product), 1, file)) {
                if (product->deleted == 0) {
                    new_product = (Product_List*) malloc(sizeof(Product_List));

                    length = strlen(product->product_name) + 1;
                    new_product->product_name = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_name, product->product_name);

                    length = strlen(product->product_code) + 1;
                    new_product->product_code = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_code, product->product_code);

                    length = strlen(product->product_description) + 1;
                    new_product->product_description = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_description, product->product_description);

                    length = strlen(product->product_type) + 1;
                    new_product->product_type = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_type, product->product_type);

                    new_product->product_price = product->product_price;

                    if (list == NULL) {
                        list = new_product;
                        list->next = NULL;
                    }

                    else if (strcmp(list->product_name, new_product->product_name) > 0) {
                        new_product->next = list;
                        list = new_product;
                    }

                    else {
                        Product_List* before = list;
                        Product_List* current = list->next;

                        while (current != NULL && strcmp(current->product_name, new_product->product_name) < 0) {
                            before = current;
                            current = current->next;
                        }

                        before->next = new_product;
                        new_product->next = current;
                    }
                }
            }

            free(product);

            new_product = list;

            while (new_product != NULL) {
                show_found_product(new_product);

                new_product = new_product->next;
            }

            new_product = list;

            while (new_product != NULL) {
                list = list->next;

                free(new_product->product_name);
                free(new_product->product_code);
                free(new_product->product_description);
                free(new_product->product_type);
                free(new_product);

                new_product = list;
            }
        }

        fclose(file);
    }
}

char* list_product_by_type_screen(void) {
    char* type = (char*) malloc(255 * sizeof(char));

    int op = 0;

    do {
        printf("\n");

        printf("\t\t=====================================\n");
        printf("\t\t||    Informe o tipo do produto    ||\n");
        printf("\t\t=====================================\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|            1 - Perfume            |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|          2 - Hidratantes          |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|            3 - Barbear            |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|           4 - Sabonetes           |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|            5 - Shampoo            |\n");
        printf("\t\t-------------------------------------\n");

        printf("\nDigite a opcao desejada: ");
        op = read_numeric_op();

        switch(op) {
            case 1:
                strcpy(type, "Perfume");

                break;

            case 2:
                strcpy(type, "Hidratante");

                break;

            case 3:
                strcpy(type, "Barbear");

                break;

            case 4:
                strcpy(type, "Sabonete");

                break;

            case 5:
                strcpy(type, "Shampoo");

                break;

            default:
                printf("\nOpcao invalida.\n");

                break;
        }   
    } while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

    return type;
}

void list_product_by_type(void) {
    char* type = list_product_by_type_screen();

    FILE* file;

    int length;

    Product* product;

    Product_List* new_product;
    Product_List* list = NULL;

    if (access("product.dat", F_OK) != -1) {
        file = fopen("product.dat", "rb");

        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");

            exit(1);
        }

        else {
            list = NULL;

            product = (Product*) malloc(sizeof(Product));

            while (fread(product, sizeof(Product), 1, file)) {
                if (product->deleted == 0 && strcmp(product->product_type, type) == 0) {
                    new_product = (Product_List*) malloc(sizeof(Product_List));

                    length = strlen(product->product_name) + 1;
                    new_product->product_name = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_name, product->product_name);

                    length = strlen(product->product_code) + 1;
                    new_product->product_code = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_code, product->product_code);

                    length = strlen(product->product_description) + 1;
                    new_product->product_description = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_description, product->product_description);

                    length = strlen(product->product_type) + 1;
                    new_product->product_type = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_type, product->product_type);

                    new_product->product_price = product->product_price;

                    if (list == NULL) {
                        list = new_product;
                        list->next = NULL;
                    }

                    else if (strcmp(list->product_name, new_product->product_name) > 0) {
                        new_product->next = list;
                        list = new_product;
                    }

                    else {
                        Product_List* before = list;
                        Product_List* current = list->next;

                        while (current != NULL && strcmp(current->product_name, new_product->product_name) < 0) {
                            before = current;
                            current = current->next;
                        }

                        before->next = new_product;
                        new_product->next = current;
                    }
                }
            }

            free(product);

            new_product = list;

            while (new_product != NULL) {
                show_found_product(new_product);

                new_product = new_product->next;
            }

            new_product = list;

            while (new_product != NULL) {
                list = list->next;

                free(new_product->product_name);
                free(new_product->product_code);
                free(new_product->product_description);
                free(new_product->product_type);
                free(new_product);

                new_product = list;
            }
        }

        fclose(file);
    }
}

int list_product_by_price_screen(void) {
    int op = 0;

    int chosen = 0;

    do {
        printf("\n");

        printf("\t\t=====================================\n");
        printf("\t\t||    Informe o tipo do produto    ||\n");
        printf("\t\t=====================================\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|  1 - Do mais barato ao nais caro  |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|  2 - Do mais caro ao mais barato  |\n");
        printf("\t\t-------------------------------------\n");

        printf("\nDigite a opcao desejada: ");
        op = read_numeric_op();

        switch(op) {
            case 1:
                chosen = 1;

                break;

            case 2:
                chosen = 2;

                break;

            default:
                printf("\nOpcao invalida.\n");

                break;
        }   
    } while (op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

    return chosen;
}

void list_product_by_price(void) {
    int chosen = list_product_by_price_screen();

    FILE* file;

    int length;

    Product* product;

    Product_List* new_product;
    Product_List* list = NULL;

    if (access("product.dat", F_OK) != -1) {
        file = fopen("product.dat", "rb");

        if (file == NULL) {
            printf("Erro ao abrir o arquivo.\n");

            exit(1);
        }

        else {
            list = NULL;

            product = (Product*) malloc(sizeof(Product));

            while (fread(product, sizeof(Product), 1, file)) {
                if (product->deleted == 0) {
                    new_product = (Product_List*) malloc(sizeof(Product_List));

                    length = strlen(product->product_name) + 1;
                    new_product->product_name = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_name, product->product_name);

                    length = strlen(product->product_code) + 1;
                    new_product->product_code = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_code, product->product_code);

                    length = strlen(product->product_description) + 1;
                    new_product->product_description = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_description, product->product_description);

                    length = strlen(product->product_type) + 1;
                    new_product->product_type = (char*) malloc(length * sizeof(char));
                    strcpy(new_product->product_type, product->product_type);

                    new_product->product_price = product->product_price;

                    if (list == NULL) {
                        list = new_product;
                        list->next = NULL;
                    }

                    else if (chosen == 1 && new_product->product_price < list->product_price) {
                        new_product->next = list;
                        list = new_product;
                    }

                    else if (chosen == 2 && new_product->product_price > list->product_price) {
                        new_product->next = list;
                        list = new_product;
                    }

                    else {
                        Product_List* before = list;
                        Product_List* current = list->next;

                        while ((current != NULL) && ((chosen == 1 && new_product->product_price > current->product_price) || (chosen == 2 && new_product->product_price < current->product_price))) {
                            before = current;
                            current = current->next;
                        }

                        before->next = new_product;
                        new_product->next = current;
                    }
                }
            }

            free(product);

            new_product = list;

            while (new_product != NULL) {
                show_found_product(new_product);

                new_product = new_product->next;
            }

            new_product = list;

            while (new_product != NULL) {
                list = list->next;

                free(new_product->product_name);
                free(new_product->product_code);
                free(new_product->product_description);
                free(new_product->product_type);
                free(new_product);

                new_product = list;
            }
        }

        fclose(file);
    }
}

void list_deleted_product(void) {
    terminal_clear();

    FILE* fp;

    if (access("product.dat", F_OK) == -1) {
        list_product_banner();

        printf("\nNao existem produtos registados.\n");
    }

    else {
        fp = fopen("product.dat", "rb");
        Product* product = (Product*) malloc(sizeof(Product));

        list_product_banner();

        int count = 1;

        while (fread(product, sizeof(Product), 1, fp)) {
            if (product->deleted == 1) {
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
            printf("\nNao existem produtos deletados\n");
        }

        fclose(fp);
    
        free(product);
    }
}

void list_request(void) {
    terminal_clear();

    FILE* fp;

    if (access("request.dat", F_OK) == -1) {
        list_request_banner();

        printf("\nNao existem pedidos registados.\n");
    }

    else {
        fp = fopen("request.dat", "rb");

        Request* request = (Request*) malloc(sizeof(Request));

        list_request_banner();

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

void list_request_by_date(void) {
    ;
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
                list_customer_by_name();

                break;

            case 3:
                list_deleted_customer();

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

            case 2:
                list_product_by_name();

                break;

            case 3:
                list_product_by_type();

                break;

            case 4:
                list_product_by_price();

                break;

            case 5:
                list_deleted_product();

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