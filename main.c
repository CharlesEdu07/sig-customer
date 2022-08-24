#include <stdio.h>
#include <locale.h>

int main() {
    int opcao = 0;

    menu_Principal();

    int opcao = 0;
    printf("Digite uma opção:\n");
    scanf("%i", &opcao);

    if (opcao == 4)
    {
        menu_Sobre();
    }
    
    
    return 0;
}


int menu_Principal(){
    setlocale (LC_ALL, "portuguese");

    printf("\n"
    "\t\t==============================\n"
    "\t\tPrograma Controle de Financias\n"
    "\t\t==============================\n"
    "\t\t1 - Módulo clientes\n"
    "\t\t2 - Módulo em desenvolvimento\n"
    "\t\t3 - Módulo em desenvolvimento\n"
    "\t\t4 - Sobre e equipe\n"
    "\t\t0 - Encerrar\n"
    "\n"
    );

    

    return 0;
}

int menu_Sobre(){
    setlocale (LC_ALL, "portuguese");

    printf("\n"

    "\t\tSobre o projeto:\n"
    "\tSIG-Custumer: Um sistema de controle de cliente\n"
    "As empresas da atualidade utilizam complexos sistemas gerenciais para, "
    "entre várias outras funções, gerenciar e manter seus clientes, "
    "além de ajudar a conseguir novos clientes. "
    "O presente projeto tem como objetivo propor um software que implementa "
    "funcionalidades básicas relacionadas ao controle de clientes de uma empresa, "
    "facilitando a gestão\n"
    "\n\n"

    "\t\tDiscentes/Autores do Projeto:\n"
    "\tCharles Eduardo Araújo De Faria, matrícula: 20220042687\n"
    "\tVictor Ryan Galvão Silva, matrícula:20220035163\n"
    "\n"
    );
    getch(); // Aperte enter para continuar
    return 0;
}