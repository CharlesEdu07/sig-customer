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
    Customer* customer = create_customer_screen();

    if (search_customer(customer->cpf) == NULL) {
        save_customer(customer);

        printf("\nCliente cadastrado com sucesso.\n");
    }

    else {
        printf("\nCliente ja cadastrado.\n");
    }

    free(customer);
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

void save_customer(Customer* customer) {
    FILE* file = fopen("customer.dat", "ab");

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

    return customer;
}

void find_customer(void) {
    terminal_clear();

    Customer* customer;
    char* cpf = search_customer_screen();
    
    if (search_customer(cpf) != NULL) {
        customer = search_customer(cpf);

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
        printf("\t\t||        Visualizando Cliente        ||\n");
        printf("\t\t========================================\n");

        printf("\nNome do cliente: %s\n", customer->name);
        printf("CPF do cliente: %s\n", customer->cpf);
        printf("Celular do cliente: %s\n", customer->phone);
        printf("Email do cliente: %s\n", customer->email);
        printf("Endereco do cliente: %s\n", customer->address);

        free(customer);
    }

    else {
        printf("\nCliente nao encontrado ou inexistente.\n");
    }

    free(cpf);
}

char* search_customer_screen(void) {
    terminal_clear();

    char *cpf = (char*) malloc(sizeof(char) * 20);

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

    printf("\nDigite o CPF do cliente: ");
    read_cpf(cpf);

    return cpf;
}

void update_customer_file(Customer* customer) {
    FILE* file;

    Customer* aux_customer = (Customer*) malloc(sizeof(Customer));

    int found = 0;

    if (access("customer.dat", F_OK) != -1) {
        file = fopen("customer.dat", "r+b");

        if (file == NULL) {
            printf("\nErro ao abrir o arquivo.\n");

            exit(1);
        }

        while ((fread(aux_customer, sizeof(Customer), 1, file) && found == 0)) {
            if (strcmp(aux_customer->cpf, customer->cpf) == 0 && aux_customer->deleted == 0) {
                found = 1;

                fseek(file, -sizeof(Customer), SEEK_CUR);

                fwrite(customer, sizeof(Customer), 1, file);
            }
        }

        fclose(file);
    }

    free(aux_customer);
}

void update_customer(void) {
    Customer* customer;

    char* cpf = update_customer_screen();

    if (search_customer(cpf) != NULL) {
        customer = search_customer(cpf);
        customer = update_customer_data(customer);

        strcpy(customer->cpf, cpf);

        update_customer_file(customer);

        free(customer);
    }

    else {
        printf("\nCliente nao encontrado ou inexistente.\n");
    }

    free(cpf);
}

char* update_customer_screen(void) {
    terminal_clear();

    char* cpf = malloc(sizeof(char) * 20);

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

    return cpf;
}

Customer* update_customer_data(Customer* customer) {
    char op;

    do {
        op = '0';

        terminal_clear();

        printf("\t\t=====================================\n");
        printf("\t\t||  Qual(is) dado(s) quer editar?  ||\n");
        printf("\t\t=====================================\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|        1 - Nome do Cliente        |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|      2 - Telefone ou Celular      |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|             3 - Email             |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|           4 - Domicilio           |\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t-------------------------------------\n");
        printf("\t\t|     0 - Encerrar Atualizacoes     |\n");
        printf("\t\t-------------------------------------\n");

        op = read_op();

        if (op != 0) {
            switch (op) {
                case '1':
                    printf("\nDigite o novo nome do cliente: ");
                    read_name(customer->name);

                    printf("\nNome do cliente atualizado com sucesso.\n");

                    press_enter_to_continue();

                    break;

                case '2':
                    printf("\nDigite o novo telefone ou celular do cliente: ");
                    read_phone(customer->phone);

                    printf("\nTelefone ou celular do cliente atualizado com sucesso.\n");

                    press_enter_to_continue();

                    break;

                case '3':
                    printf("\nDigite o novo email do cliente: ");
                    read_email(customer->email);

                    printf("\nEmail do cliente atualizado com sucesso.\n");

                    press_enter_to_continue();

                    break;

                case '4':
                    printf("\nDigite o novo domicilio do cliente: ");
                    read_string(customer->address);

                    printf("\nDomicilio do cliente atualizado com sucesso.\n");

                    press_enter_to_continue();

                    break;

                default:
                    printf("\nOpcao invalida.\n");

                    break;
            }
        }
    } while (op != '0');

    terminal_clear();

    return customer;
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
                find_customer();
                
                break;
                
            case '3':
                update_customer();
                
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