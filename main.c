#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "about.h"

void mod_main(void);
char menu_main(void);
void about(void);

int main(void) {
    mod_main();
    
    return 0;
}

char menu_main(void) {
    system("clear");

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
    char op = menu_main();

    while (op != '0') {
        switch (op) {
            case '1':
                mod_customer();

                break;

            case '2':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '3':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '4':
                about();

                break;
                
            default:
                printf("\nOpcao invalida. Por favor, digite uma opcao valida.\n");

                break;
        }

        printf("\nTecle ENTER para continuar...");
        getchar();

        op = menu_main();
    }

    printf("\nPrograma encerrado\n");
}