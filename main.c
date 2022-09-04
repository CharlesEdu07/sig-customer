#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "util.h"

void mod_main(void);
void mod_cliente(void);
char menu_principal(void);
char menu_cliente(void);
void sobre(void);

int main(void) {
    mod_main();
    
    return 0;
}

char menu_principal(void) {
    system("clear");

    printf("\t\t=====================================\n");
    printf("\t\t||           SIG-Cliente           ||\n");
    printf("\t\t=====================================\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|       1 - Modulo de Cliente       |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   2 - Modulo em Desenvolvimento   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|   3 - Modulo em Desenvolvimento   |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|             4 - Sobre             |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Finalizar           |\n");
    printf("\t\t-------------------------------------\n");

    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    return op;
}

void mod_main(void) {
    char op = menu_principal();

    while (op != '0') {
        switch (op) {
            case '1':
                mod_cliente();

                break;

            case '2':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '3':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '4':
                sobre();

                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");

                break;
        }

        printf("\nTecle ENTER para continuar...");
        getchar();

        op = menu_principal();
    }

    printf("\nPrograma encerrado\n");
}

char menu_cliente(void) {
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

void mod_cliente(void) {
    char op = menu_cliente();
    
    while (op != '0') {
        switch (op) {
            case '1':
                system("clear");

                printf("\nCadastrar Cliente\n\n");

                printf("Nome: ");
                read_nome();

                printf("CPF: ");
                read_cpf();
                
                printf("Celular: ");
                read_celular();

                printf("Endereco");
                read_endereco();

                printf("Email: ");
                read_email();

                cadastrar_cliente();
                
                break;
                
            case '2':
                visualizar_cliente();
                
                break;

            case '3':
                system("clear");

                printf("\nPesquisar Clientes\n\n");

                pesquisar_cliente();
                
                break;
                
            case '4':
                system("clear");

                printf("\nAtualizar Cliente\n\n");

                atualizar_cliente();
                
                break;
                
            case '5':
                system("clear");

                printf("\nDeletar Cliente\n\n");

                deletar_cliente();
                
                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");
                
                break;
        }
        
        printf("\nTecle ENTER para continuar...");
        getchar();
        
        op = menu_cliente();
    }
}

void sobre(void) {
    system("clear");

    printf("\n\n");

    printf("|============================================================================|\n");
    printf("|                             Sobre o projeto                                |\n");
    printf("|============================================================================|\n");
    printf("|                                                                            |\n");
    printf("|              SIG-Custumer: Um sistema de controle de cliente               |\n");
    printf("|   As empresas da atualidade utilizam complexos sistemas gerenciais para,   |\n");
    printf("|   entre varias outras coisas, controlar seus clientes, alem de ajudar a    |\n");
    printf("|   a conseguir novos clientes. O presente projeto tem como objetivo propor  |\n");
    printf("|   um software que implementa funcionalidades basicas relacionadas ao con-  |\n");
    printf("|   trole de clientes de uma empresa, facilitando a gestao                   |\n");
    printf("|____________________________________________________________________________|\n");
    printf("|                                                                            |\n");
    printf("|   Discente/Autor do Projeto:                                               |\n");
    printf("|       -> Charles Eduardo Araujo De Faria. Matricula: 20220042687           |\n");
    printf("|____________________________________________________________________________|\n");
    printf("\n");
}