#include <stdio.h>
#include <stdlib.h>
#include "menus/menu_principal.c"
#include "menus/menu_cliente.c"
#include "sobre.c"
#include "modulos/mod_cliente.c"

// Versao 0.1

int main(void) {
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
    
    return 0;
}