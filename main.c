#include <stdio.h>
#include "menu_principal.c"
#include "sobre.c"

int main() {
    char op = menu_principal();

    while (op != '0') {
        if (op == '4') {
            menu_sobre();
        }

        printf("\n");
        printf("Tecle ENTER para continuar");

        getch();

        op = menu_principal();
    }

    printf("\nPrograma encerrado\n");
    
    return 0;
}