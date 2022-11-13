#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "inputs.h"

char read_op(void) {
    char op;

    printf("\nDigite a opcao desejada: ");
    scanf("%c", &op);
    getchar();

    return op;
}

void read_name(char* name) {
    fgets(name, 255, stdin);

    while (!name_validation(name)) {
        printf("\nNome invalido. Digite novamente: ");
        fgets(name, 255, stdin);
    }

    name[strlen(name) - 1] = '\0';
}

void read_cpf(char* cpf) {
    fgets(cpf, 20, stdin);

    while (!cpf_validation(cpf)) {
        printf("\nCPF invalido. Digite novamente: ");
        fgets(cpf, 20, stdin);
    }

    cpf[strlen(cpf) - 1] = '\0';
}

void read_phone(char* phone) {
    fgets(phone, 20, stdin);

    while (!phone_validation(phone)) {
        printf("\nTelefone invalido. Digite novamente: ");
        fgets(phone, 20, stdin);
    }

    phone[strlen(phone) - 1] = '\0';
}

void read_email(char* email) {
    fgets(email, 255, stdin);

    while (!email_validation(email)) {
        printf("\nEmail invalido. Digite novamente: ");
        fgets(email, 255, stdin);
    }

    email[strlen(email) - 1] = '\0';
}

void read_string(char* string) {
    fgets(string, 255, stdin);

    string[strlen(string) - 1] = '\0';
}

void read_float(char *number) {
    fgets(number, 20, stdin);

    while (!float_validation(number)) {
        printf("\nPreco invalido. Digite novamente: ");
        fgets(number, 20, stdin);
    }

    number[strlen(number) - 1] = '\0';
}

void read_product_code(char *code) {
    fgets(code, 50, stdin);

    while (!product_code_validation(code)) {
        printf("\nCodigo invalido. Digite novamente: ");
        fgets(code, 50, stdin);
    }

    code[strlen(code) - 1] = '\0';
}

void read_int(char *number) {
    fgets(number, 10, stdin);

    while (!int_validation(number)) {
        printf("\nQuantidade invalida. Digite novamente: ");
        fgets(number, 10, stdin);
    }

    number[strlen(number) - 1] = '\0';
}

char* generate_request_id(void) {
    char* date = (char*) malloc(50 * sizeof(char));

    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    strftime(date, 50, "%d%m%Y%H%M%S", t);

    return date;
}

int name_validation(char* name) {
    char invalid_characters[] = {"0123456789,-:;[]{}*#"};

    if (strlen(name) < 3) {
        return 0;
    }

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

    if (strlen(num) < 3) {
        return 0;
    }

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
    char check_digit;
    int accumulator = 0;

    if (strlen(code) != 14) {
        return 0;
    }

    for (int i = 0; i < strlen(code) - 2; i++) {
        if (!isdigit(code[i])) {
            return 0;
        }
    }

    int multiplier = 1;

    for (int i = 0; i < strlen(code) - 2; i++) {
        accumulator += (code[i] - '0') * multiplier;
        
        if (multiplier == 1) {
            multiplier = 3;
        }

        else {
            multiplier = 1;
        }
    }

    int starting_sum = accumulator; 

    accumulator = (accumulator / 10) + 1;
    accumulator *= 10;
    accumulator -= starting_sum;

    if (accumulator % 10 == 0) {
        check_digit = '0';
    }

    else {
        check_digit = accumulator + '0';
    }

    //printf("%c", check_digit);

    if (check_digit != code[12]) {
        return 0;
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