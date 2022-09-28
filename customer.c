#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "customer.h"
#include "readers.h"

char menu_customer(void) {
    terminal_clear();

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

    char op = read_op();

    return op;
}

void create_customer(void) {
    Customer *customer = create_customer_screen();

    free(customer);
}

Customer* create_customer_screen(void) {
    terminal_clear();

    Customer* customer;
    customer = (Customer*) malloc(sizeof(Customer));

    char* name;
    char* cpf;
    char* phone;
    char* email;
    char* address;

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
    name = read_name();

    printf("Digite o CPF do cliente: ");
    cpf = read_cpf();
                
    printf("Digite o celular do cliente: ");
    phone = read_phone();

    printf("Digite o email do cliente: ");
    email = read_email();

    printf("Digite o endereco do cliente: ");
    address = read_address();

    customer->name = name;
    customer->cpf = cpf;
    customer->phone = phone;
    customer->email = email;
    customer->address = address;

    printf("\nNome do cliente: %s", customer->name);
    printf("CPF do cliente: %s", customer->cpf);
    printf("Telefone do cliente: %s", customer->phone);
    printf("Email do cliente: %s", customer->email);
    printf("Endereco do cliente: %s", customer->address);

    printf("\nCliente cadastrado com sucesso!\n");

    return customer;
}

void read_customer_screen(void) {
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

void search_customer_screen(void) {
    terminal_clear();

    char* name;
    char* cpf;

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
    name = read_name();

    printf("Digite o CPF do cliente: ");
    cpf = read_cpf();

    printf("\nNome do cliente: %s", name);
    printf("CPF do cliente: %s", cpf);
    
    printf("\nPesquisa realizada com sucesso!\n");
}

void update_customer_screen(void) {
    terminal_clear();

    char* cpf;

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
    cpf = read_cpf();

    printf("\nCliente do CPF %satualizado com sucesso!\n", cpf);
}

void delete_customer_screen(void) {
    terminal_clear();

    char* cpf;

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
    cpf = read_cpf();

    printf("\nCliente do CPF %sdeletado com sucesso!\n", cpf);
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
        
        press_enter_to_continue();
        
        op = menu_customer();
    }
}