#include <stdio.h>
#include <stdlib.h>
#include "menu_principal.c"
#include "sobre.c"

int main() {
    char op = menu_principal();

    while (op != '0') {
        switch (op) {
            case '1':
                printf("\nModulo de Cliente\n");

                break;

            case '2':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '3':
                printf("\nModulo em Desenvolvimento\n");

                break;

            case '4':
                menu_sobre();

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
    
    return 0;
}