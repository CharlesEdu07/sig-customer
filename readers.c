#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void terminal_clear(void) {
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

void read_name(char *str) {
    char name[50];

    fgets(name, 50, stdin);

    strcpy(str, name);
}

void read_cpf(char *str) {
    char cpf[20];

    fgets(cpf, 20, stdin);

    strcpy(str, cpf);
}

void read_phone(char *str) {
    char phone[20];

    fgets(phone, 20, stdin);

    strcpy(str, phone);
}

void read_email(char *str) {
    char email[50];

    fgets(email, 50, stdin);

    strcpy(str, email);
}

void read_address(char *str) {
    char address[50];

    fgets(address, 50, stdin);

    strcpy(str, address);
}

void read_product_name(char *str) {
    char name[50];

    fgets(name, 50, stdin);

    strcpy(str, name);
}

void read_product_type(char *str) {
    char type[50];

    fgets(type, 50, stdin);

    strcpy(str, type);
}

void read_product_price(char *str) {
    char price[10];

    fgets(price, 10, stdin);

    strcpy(str, price);
}

void read_product_code(char *str) {
    char code[50];

    fgets(code, 50, stdin);

    strcpy(str, code);
}

void read_request_quantity(char *str) {
    char quantity[10];

    fgets(quantity, 10, stdin);

    strcpy(str, quantity);
}

void read_request_identifier(char *str) {
    char identifier[50];

    fgets(identifier, 50, stdin);

    strcpy(str, identifier);
}