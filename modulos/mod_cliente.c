#include "../entidades/cliente.c"

void mod_cliente(void) {
    char op = menu_cliente();
    
    while (op != '0') {
        switch (op) {
            case '1':
                cadastrar_cliente();
                
                break;
                
            case '2':
                visualizar_cliente();
                
                break;

            case '3':
                pesquisar_cliente();
                
                break;
                
            case '4':
                atualizar_cliente();
                
                break;
                
            case '5':
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