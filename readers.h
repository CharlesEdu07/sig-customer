char read_op(void);
void read_name(char* name);
void read_cpf(char* cpf);
void read_phone(char* phone);
void read_email(char* email);
void read_address(char* address);
// char* read_product_code(void);
// char* read_float(void);
// char* read_int(void);
// char* read_request_id(void);
// char* generate_request_id(char* cpf, char* product_code);

int name_validation(char* name);
int cpf_validation(char* cpf);
int phone_validation(char* phone);
int email_validation(char* email);
int float_validation(char* num);
int product_code_validation(char* code);
int int_validation(char* num);
