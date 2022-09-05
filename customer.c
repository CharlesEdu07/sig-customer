#include <stdio.h>
#include <stdlib.h>
#include "customer.h"

char menu_customer(void) {
    system("clear");

    printf("\t\t=====================================\n");
    printf("\t\t||         Modulo Clientes         ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|      2 - Visualizar Clientes      |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Pesquisar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       4 - Atualizar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        5 - Deletar Cliente        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    return op;
}

void create_customer_screen(void) {
    system("clear");

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Cadastrar Cliente         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o nome do cliente: ");
    getchar();

    printf("Digite o CPF do cliente: ");
    getchar();
                
    printf("Digite o celular do cliente: ");
    getchar();

    printf("Digite o email do cliente: ");
    getchar();

    printf("Digite o endereco do cliente: ");
    getchar();

    printf("\nCliente cadastrado com sucesso!\n");
}

void read_customer_screen(void) {
    system("clear");

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

void search_customer_screen(void) {
    system("clear");

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||         Pesquisar Clientes         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o nome do cliente: ");
    getchar();

    printf("Digite o CPF do cliente: ");
    getchar();

    printf("\nPesquisa realizada com sucesso!\n");
}

void update_customer_screen(void) {
    system("clear");

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||         Atualizar Clientes         ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o CPF do cliente: ");
    getchar();

    printf("\nCliente atualizado com sucesso!\n");
}

void delete_customer_screen(void) {
    system("clear");

    printf("\t\t========================================\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||            SIG-Customer            ||\n");
    printf("\t\t||            ------------            ||\n");
    printf("\t\t||                                    ||\n");
    printf("\t\t========================================\n");
    printf("\n");
    printf("\t\t========================================\n");
    printf("\t\t||          Deletar Clientes          ||\n");
    printf("\t\t========================================\n");

    printf("\nDigite o CPF do cliente: ");
    getchar();

    printf("\nCliente deletado com sucesso!\n");
}

void mod_customer(void) {
    char op = menu_customer();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_customer_screen();
                
                break;
                
            case '2':
                read_customer_screen();
                
                break;

            case '3':
                search_customer_screen();
                
                break;
                
            case '4':
                update_customer_screen();
                
                break;
                
            case '5':
                delete_customer_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");
                
                break;
        }
        
        printf("\nTecle ENTER para continuar...");
        getchar();
        
        op = menu_customer();
    }
}