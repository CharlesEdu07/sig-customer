void mod_cliente(void) {
    char op = menu_cliente();
    
    while (op != '0') {
        switch (op) {
            case '1':
                cadastrar();
                
                break;
                
            case '2':
                visualizar();
                
                break;
                
            case '3':
                atualizar();
                
                break;
                
            case '4':
                deletar();
                
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