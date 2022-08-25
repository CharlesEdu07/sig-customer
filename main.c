#include <stdio.h>

char menu_principal(void) {
    system("cls");

    printf("\t\t=====================================\n");
    printf("\t\t||           SIG-Customer          ||\n");
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
    printf("\t\t|        4 - Sobre e Equipe         |\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t-------------------------------------\n");
    printf("\t\t|           0 - Encerrar            |\n");
    printf("\t\t-------------------------------------\n");

    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%s", &op);

    return op;
}

void menu_sobre(void) {
    system("cls");

    printf("\n\n");
    printf("\t\tSobre o projeto:\n");
    printf("\n");
    printf("\tSIG-Custumer: Um sistema de controle de cliente\n");
    printf("As empresas da atualidade utilizam complexos sistemas gerenciais para,\n");
    printf("entre varias outras coisas, controlar seus clientes\n");
    printf("alem de ajudar a conseguir novos clientes.\n");
    printf("O presente projeto tem como objetivo propor um software que implementa\n");
    printf("funcionalidades basicas relacionadas ao controle de clientes de uma empresa,\n");
    printf("facilitando a gestao\n");
    printf("\n\n");
    printf("\t\tDiscentes/Autores do Projeto:\n\n");
    printf("\tCharles Eduardo Araujo De Faria. Matricula: 20220042687\n");
    printf("\tVictor Ryan Galvao Silva. Matricula: 20220035163\n");
    printf("\n");

    getch(); // Aperte enter para continuar
}

int main() {
    char op = menu_principal();

    if (op == '4') {
        menu_sobre();
    }
    
    return 0;
}