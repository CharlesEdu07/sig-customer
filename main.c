#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu_principal.c"
#include "sobre.c"

char menu_principal(void);
void menu_sobre(void);

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

        printf("\n");
        printf("Tecle ENTER para continuar");

        getch();

        op = menu_principal();
    }

    printf("\nPrograma encerrado\n");
    
    return 0;
}