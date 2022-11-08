#include <stdio.h>
#include <stdlib.h>

#include "report.h"
#include "customer.h"
#include "product.h"
#include "request.h"
#include "inputs.h"
#include "util.h"

char menu_report(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||        Modulo Relatorios        ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        1 - Listar Clientes        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        2 - Listar Produtos        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|         3 - Listar Pedido         |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void list_customer(void) {
    terminal_clear();

    FILE *fp = fopen("customer.dat", "rb");

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
        printf("\nCliente %d:\n", count);
        printf("\nNome do cliente: %s\n", customer->name);
        printf("CPF do cliente: %s\n", customer->cpf);
        printf("Celular do cliente: %s\n", customer->phone);
        printf("Email do cliente: %s\n", customer->email);
        printf("Endereco do cliente: %s\n", customer->address);

        count++;
    }

    fclose(fp);
    
    free(customer);
}

void list_product(void) {
    terminal_clear();

    FILE *fp = fopen("product.dat", "rb");

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
        printf("\nProduto %d\n ", count);
        printf("\nCodigo do produto: %s", product->product_code);
        printf("Nome do produto: %s\n", product->product_name);
        printf("Tipo do produto: %s\n", product->product_type);
        printf("Descricao do produto: %s\n", product->product_description);
        printf("Preco do produto: %s", product->product_price);

        count++;
    }

    fclose(fp);

    free(product);
}

void list_request(void) {
    terminal_clear();

    FILE *fp = fopen("request.dat", "rb");

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
    printf("\t\t||           Listar Pedidos           ||\n");
    printf("\t\t========================================\n");

    int count = 1;

    while (fread(request, sizeof(Request), 1, fp)) {
        printf("\nPedido %d:\n", count);
        printf("\nCodigo do pedido: %s", request->id);
        printf("Codigo do cliente: %s\n", request->customer_cpf);
        printf("Codigo do produto: %s", request->product_code);
        printf("Quantidade do produto: %s", request->quantity);

        count++;
    }

    fclose(fp);

    free(request);
}

void mod_report(void) {
    char op = menu_report();

    while (op != '0') {
        switch (op) {
            case '1':
                list_customer();

                break;

            case '2':
                list_product();

                break;

            case '3':
                list_request();

                break;

            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");

                break;
        }

        press_enter_to_continue();

        op = menu_report();
    }
}