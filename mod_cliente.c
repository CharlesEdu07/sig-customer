#include <stdio.h>
#include <stdlib.h>
#include "menus/menu_cliente.c"

char menu_cliente(void);

void mod_cliente(void) {
    char op = menu_cliente();
    
    while (op != '0') {
        switch (op) {
            case '1':
                printf("\nCadastrar Cliente\n");
                
                break;
                
            case '2':
                printf("\nVisualizar Clientes\n");
                
                break;
                
            case '3':
                printf("\nAtualizar Cliente\n");
                
                break;
                
            case '4':
                printf("\nDeletar Cliente\n");
                
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