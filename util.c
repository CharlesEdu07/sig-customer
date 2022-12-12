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

int is_this_year(char* date) {
    int day, month, year;

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    int current_year = t->tm_year + 1900;

    if (current_year == year) {
        return 1;
    }

    return 0;
}

int is_this_month(char* date) {
    int day, month, year;

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    int current_month = t->tm_mon + 1;
    int current_year = t->tm_year + 1900;

    if (current_year == year) {
        if (current_month == month) {
            return 1;
        }
    }

    return 0;
}

int is_this_week(char* date) {
    int day, month, year;

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    int current_day = t->tm_mday;
    int current_month = t->tm_mon + 1;
    int current_year = t->tm_year + 1900;

    if (current_year == year) {
        if (current_month == month) {
            if (current_day - day < 7) {
                return 1;
            }
        }
    }

    return 0;
}