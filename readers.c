#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "readers.h"

char read_op(void) {
    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    return op;
}

char* read_name(void) {
    char name[50];
    char* str;

    fgets(name, 50, stdin);

    while (!name_validation(name)) {
        printf("\nNome invalido. Digite novamente: ");
        fgets(name, 50, stdin);
    }

    int len = strlen(name) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, name);

    return str;
}

char* read_cpf(void) {
    char cpf[20];
    char* str;

    fgets(cpf, 20, stdin);

    while (!cpf_validation(cpf)) {
        printf("\nCPF invalido. Digite novamente: ");
        fgets(cpf, 20, stdin);
    }

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

int name_validation(char* name) {
    char invalid_characters[] = {"0123456789,-:;[]{}*#"};

    for (int i = 0; i < strlen(name); i++) {
        for (int j = 0; j < strlen(invalid_characters); j++) {
            if (name[i] == invalid_characters[j]) {
                return 0;
            }
        }
    }

    return 1;
}

int cpf_validation(char* cpf) {
    int accumulator = 0;
    int d1 = 0;
    int d2 = 0;

    if (strlen(cpf) != 12) {
        return 0;
    }

    for (int i = 0; i < strlen(cpf) - 1; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    for (int i = 0; i < 9; i++) {
        accumulator += (cpf[i] - '0') * (10 - i);
    }

    d1 = 11 - (accumulator % 11);

    if (d1 == 10 || d1 == 11) {
        d1 = 0;
    }

    if (d1 != (cpf[9] - '0')) {
        return 0;
    }

    accumulator = 0;

    for (int i = 0; i < 10; i++) {
        accumulator += (cpf[i] - '0') * (11 - i);
    }

    d2 = 11 - (accumulator % 11);

    if (d2 == 10 || d2 == 11) {
        d2 = 0;
    }

    if (d2 != (cpf[10] - '0')) {
        return 0;
    }

    return 1;
}
