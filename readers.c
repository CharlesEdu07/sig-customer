#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void terminal_clear(void) {
    system("clear||cls");
}

char read_op(void) {
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

char* read_name(void) {
    char name[50];
    char* str;

    fgets(name, 50, stdin);

    int len = strlen(name) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, name);

    return str;
}

char* read_cpf(void) {
    char cpf[20];
    char* str;

    fgets(cpf, 20, stdin);

    int len = strlen(cpf) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, cpf);

    return str;
}

char* read_phone(void) {
    char phone[20];
    char* str;

    fgets(phone, 20, stdin);

    int len = strlen(phone) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, phone);

    return str;
}

char* read_email(void) {
    char email[50];
    char* str;

    fgets(email, 50, stdin);

    int len = strlen(email) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, email);

    return str;
}

char* read_address(void) {
    char address[50];
    char* str;

    fgets(address, 50, stdin);

    int len = strlen(address) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, address);

    return str;
}

char* read_product_name(void) {
    char name[50];
    char* str;

    fgets(name, 50, stdin);

    int len = strlen(name) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, name);

    return str;
}

char* read_product_type(void) {
    char type[50];
    char* str;

    fgets(type, 50, stdin);

    int len = strlen(type) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, type);

    return str;
}

char* read_product_price(void) {
    char price[10];
    char* str;

    fgets(price, 10, stdin);

    int len = strlen(price) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, price);

    return str;
}

char* read_product_code(void) {
    char code[50];
    char* str;

    fgets(code, 50, stdin);

    int len = strlen(code) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, code);

    return str;
}

char* read_request_quantity(void) {
    char quantity[10];
    char* str;

    fgets(quantity, 10, stdin);

    int len = strlen(quantity) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, quantity);

    return str;
}

char* read_request_identifier(void) {
    char identifier[50];
    char* str;

    fgets(identifier, 50, stdin);

    int len = strlen(identifier) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, identifier);

    return str;
}