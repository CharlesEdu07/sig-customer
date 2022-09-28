#include <stdio.h>
#include <stdlib.h>
#include "report.h"
#include "readers.h"
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

    printf("\nNome do cliente: ");
    printf("\nCPF do cliente: ");
    printf("\nCelular do cliente: ");
    printf("\nEmail do cliente: ");
    printf("\nEndereco do cliente: ");
    printf("\n");
}

void list_product(void) {
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

    printf("\nNome do produto: ");
    printf("\nTipo do produto: ");
    printf("\nCodigo do produto: ");
    printf("\nPreco do produto: ");
    printf("\n");
}

void list_request(void) {
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

    printf("\nCPF do cliente: ");
    printf("\nNome do produto: ");
    printf("\nQuantidade do pedido: ");
    printf("\nIdentificador do pedido: ");
    printf("\n");
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