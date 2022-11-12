#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void terminal_clear(void) {
    system("clear||cls");
}

void press_enter_to_continue(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

char* get_current_date() {
    char* date = (char*) malloc(50 * sizeof(char));

    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    strftime(date, 50, "%d/%m/%Y", t);

    return date;
}