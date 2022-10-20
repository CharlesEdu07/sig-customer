#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#include "customer.h"
#include "inputs.h"
#include "util.h"

char menu_customer(void) {
    terminal_clear();

    printf("\t\t=====================================\n");
    printf("\t\t||         Modulo Clientes         ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Cadastrar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       2 - Pesquisar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       3 - Atualizar Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|        4 - Deletar Cliente        |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Regressar           |\n");
    printf("\t\t-------------------------------------\n");

    char op = read_op();

    return op;
}

void create_customer(void) {
    Customer *customer = create_customer_screen();

    if (search_customer(customer->cpf) == NULL) {
        save_customer(customer);

        printf("\nCliente cadastrado com sucesso.\n");
    }

    else {
        printf("\nCliente ja cadastrado.\n");
    }

    free(customer);
}

void save_customer(Customer *customer) {
    FILE *file = fopen("customer.dat", "ab");

    if (file == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        exit(1);
    }

    fwrite(customer, sizeof(Customer), 1, file);

    fclose(file);
}

Customer* create_customer_screen(void) {
    terminal_clear();

    Customer* customer;
    customer = (Customer*) malloc(sizeof(Customer));

    char name[255];
    char cpf[20];
    char phone[20];
    char email[255];
    char address[255];

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
    read_name(name);

    printf("Digite o CPF do cliente: ");
    read_cpf(cpf);
                
    printf("Digite o celular do cliente: ");
    read_phone(phone);

    printf("Digite o email do cliente: ");
    read_email(email);

    printf("Digite o endereco do cliente: ");
    read_string(address);

    strcpy(customer->name, name);
    strcpy(customer->cpf, cpf);
    strcpy(customer->phone, phone);
    strcpy(customer->email, email);
    strcpy(customer->address, address);
    customer->deleted = 0;

    printf("\nNome do cliente: %s\n", customer->name);
    printf("CPF do cliente: %s\n", customer->cpf);
    printf("Telefone do cliente: %s\n", customer->phone);
    printf("Email do cliente: %s\n", customer->email);
    printf("Endereco do cliente: %s\n", customer->address);

    return customer;
}

Customer* search_customer(char* cpf) {
    FILE* file;
    Customer* customer;

    customer = (Customer*) malloc(sizeof(Customer));

    if (access("customer.dat", F_OK) != -1) {
        file = fopen("customer.dat", "rb");

        if (file == NULL) {
            printf("\nErro ao abrir o arquivo.\n");

            exit(1);
        }

        while (fread(customer, sizeof(Customer), 1, file)) {
            if (strcmp(customer->cpf, cpf) == 0 && customer->deleted == 0) {
                fclose(file);

                return customer;
            }
        }

        fclose(file);
    }

    return NULL;
}

void search_customer_screen(void) {
    terminal_clear();

    char name[255];
    char cpf[20];

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
    read_name(name);

    printf("Digite o CPF do cliente: ");
    read_cpf(cpf);

    printf("\nNome do cliente: %s", name);
    printf("CPF do cliente: %s", cpf);
    
    printf("\nPesquisa realizada com sucesso!\n");
}

void update_customer_screen(void) {
    terminal_clear();

    char cpf[20];

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
    read_cpf(cpf);

    printf("\nCliente do CPF %satualizado com sucesso!\n", cpf);
}

void delete_customer_screen(void) {
    terminal_clear();

    char cpf[20];

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
    read_cpf(cpf);

    printf("\nCliente do CPF %sdeletado com sucesso!\n", cpf);
}

void mod_customer(void) {
    char op = menu_customer();
    
    while (op != '0') {
        switch (op) {
            case '1':
                create_customer();
                
                break;

            case '2':
                search_customer_screen();
                
                break;
                
            case '3':
                update_customer_screen();
                
                break;
                
            case '4':
                delete_customer_screen();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida\n");
                
                break;
        }
        
        press_enter_to_continue();
        
        op = menu_customer();
    }
}