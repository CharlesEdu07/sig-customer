#include <stdio.h>
#include <stdlib.h>

void clear_terminal(void) {
    system("clear||cls");
}

char read_op() {
    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    return op;
}

void press_enter_to_continue(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}