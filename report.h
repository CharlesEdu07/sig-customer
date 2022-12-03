typedef struct customer_list Customer_List;

struct customer_list {
    char* name;
    char* cpf;
    char* phone;
    char* email;
    char* address;
    Customer_List* next;
};

int menu_report(void);
int menu_customer_report(void);
int menu_product_report(void);
int menu_request_report(void);

void list_customer(void);
void list_product(void);
void list_request(void);
void mod_report(void);

void show_found_customer(Customer_List* customer);

void mod_customer_report(void);
void mod_product_report(void);
void mod_request_report(void);