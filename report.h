typedef struct customer_list Customer_List;
typedef struct product_list Product_List;
typedef struct request_list Request_List;

struct customer_list {
    char* name;
    char* cpf;
    char* phone;
    char* email;
    char* address;
    Customer_List* next;
};

struct product_list {
    char* product_code;
    char* product_name;
    char* product_type;
    char* product_description;
    float product_price;
    Product_List* next;
};

struct request_list {
    char* id;
    char* date;
    char* customer_cpf;
    char* product_code;
    int quantity;
    float amount_to_pay;
    int deleted;
    Request_List* next;
};

int menu_report(void);
int menu_customer_report(void);
int menu_product_report(void);
int menu_request_report(void);

void list_customer_banner(void);
void list_customer(void);
void list_customer_by_name(void);
void list_deleted_customer(void);
void list_product(void);
void list_product_by_name(void);
void list_product_by_type(void);
void list_request(void);
void mod_report(void);

void show_found_customer(Customer_List* customer);

char* list_product_by_type_screen(void);

void mod_customer_report(void);
void mod_product_report(void);
void mod_request_report(void);