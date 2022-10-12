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
    char name[255];
    char* str;

    fgets(name, 255, stdin);

    while (!name_validation(name)) {
        printf("\nNome invalido. Digite novamente: ");
        fgets(name, 255, stdin);
    }

    int len = strlen(name) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, name);

    return str;
}

char* read_cpf(void) {
    char cpf[255];
    char* str;

    fgets(cpf, 255, stdin);

    while (!cpf_validation(cpf)) {
        printf("\nCPF invalido. Digite novamente: ");
        fgets(cpf, 255, stdin);
    }

    int len = strlen(cpf) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, cpf);

    return str;
}

char* read_phone(void) {
    char phone[255];
    char* str;

    fgets(phone, 255, stdin);

    while (!phone_validation(phone)) {
        printf("\nTelefone invalido. Digite novamente: ");
        fgets(phone, 255, stdin);
    }

    int len = strlen(phone) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, phone);

    return str;
}

char* read_email(void) {
    char email[255];
    char* str;

    fgets(email, 255, stdin);

    while (!email_validation(email)) {
        printf("\nEmail invalido. Digite novamente: ");
        fgets(email, 255, stdin);
    }

    int len = strlen(email) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, email);

    return str;
}

char* read_address(void) {
    char address[255];
    char* str;

    fgets(address, 255, stdin);

    int len = strlen(address) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, address);

    return str;
}

char* read_float(void) {
    char price[255];
    char* str;

    fgets(price, 255, stdin);

    while (!float_validation(price)) {
        printf("\nPreco invalido. Digite novamente: ");
        fgets(price, 255, stdin);
    }

    int len = strlen(price) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, price);

    return str;
}

char* read_product_code(void) {
    char code[255];
    char* str;

    fgets(code, 255, stdin);

    while (!product_code_validation(code)) {
        printf("\nCodigo invalido. Digite novamente: ");
        fgets(code, 255, stdin);
    }

    int len = strlen(code) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, code);

    return str;
}

char* read_int(void) {
    char quantity[255];
    char* str;

    fgets(quantity, 255, stdin);

    while (!int_validation(quantity)) {
        printf("\nQuantidade invalida. Digite novamente: ");
        fgets(quantity, 255, stdin);
    }

    int len = strlen(quantity) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, quantity);

    return str;
}

char* read_request_id(void) {
    char id[255];
    char* str;

    fgets(id, 255, stdin);

    int len = strlen(id) + 1;
    str = (char*) malloc(len * sizeof(char));

    strcpy(str, id);

    return str;
}

char* generate_request_id(char* cpf, char* product_code) {
    char* request_id = (char*) malloc(255 * sizeof(char));

    strcpy(request_id, cpf);
    strcat(request_id, product_code);

    return request_id;
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

int phone_validation(char* phone) {
    if (strlen(phone) != 12) {
        return 0;
    }

    for (int i = 0; i < strlen(phone) - 1; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }

    return 1;
}

int email_validation(char* email) {
    int at = 0;
    int dot = 0;

    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            at++;
        }

        if (email[i] == '.') {
            dot++;
        }
    }

    if (at != 1 || dot != 1) {
        return 0;
    }

    return 1;
}

int float_validation(char* num) {
    int dot = 0;

    for (int i = 0; i < strlen(num); i++) {
        if (num[i] == '.') {
            dot++;
        }
    }

    if (dot != 1) {
        return 0;
    }

    return 1;
}

int product_code_validation(char* code) {
    if (strlen(code) != 14) {
        return 0;
    }

    for (int i = 0; i < strlen(code) - 1; i++) {
        if (!isdigit(code[i])) {
            return 0;
        }
    }

    return 1;
}

int int_validation(char* num) {
    for (int i = 0; i < strlen(num) - 1; i++) {
        if (!isdigit(num[i])) {
            return 0;
        }
    }

    return 1;
}