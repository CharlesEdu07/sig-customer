char read_alpha_op();

void read_name(char* name);
void read_cpf(char* cpf);
void read_phone(char* phone);
void read_email(char* email);
void read_string(char* string);
void read_product_code(char* code);
void read_float(char* number);
void read_int(char* number);

char* generate_request_id(void);

int read_numeric_op();
int name_validation(char* name);
int cpf_validation(char* cpf);
int phone_validation(char* phone);
int email_validation(char* email);
int float_validation(char* num);
int product_code_validation(char* code);
int int_validation(char* num);
