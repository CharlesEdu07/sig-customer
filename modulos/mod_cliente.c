#include "../entidades/cliente.c"
#include "../util/read_data.c"

void mod_cliente(void) {
    char op = menu_cliente();
    
    while (op != '0') {
        switch (op) {
            case '1':
                system("clear");

                printf("\nCadastrar Cliente\n\n");
                
                read_nome();
                read_cpf();
                read_celular();
                read_endereco();
                read_email();

                cadastrar_cliente();
                
                break;
                
            case '2':
                visualizar_cliente();
                
                break;

            case '3':
                system("clear");

                printf("\nPesquisar Clientes\n\n");
    
                read_nome();
                read_cpf();

                pesquisar_cliente();
                
                break;
                
            case '4':
                system("clear");

                printf("\nAtualizar Cliente\n\n");

                read_cpf();

                atualizar_cliente();
                
                break;
                
            case '5':
                system("clear");

                printf("\nDeletar Cliente\n\n");

                read_cpf();

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