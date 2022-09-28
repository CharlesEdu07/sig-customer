#include <stdio.h>
#include <stdlib.h>

void terminal_clear(void) {
    system("clear||cls");
}

void press_enter_to_continue(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}