typedef struct st_customer Customer;

struct st_customer {
    char name[255];
    char cpf[20];
    char phone[20];
    char email[255];
    char address[255];
    int deleted;
};

int menu_customer(void);
int confirm_customer_delete(Customer* customer);

void mod_customer(void);
void create_customer(void);
void find_customer(void);
void update_customer(void);
void delete_customer(void);
void save_customer(Customer* customer);
void show_customer(Customer* customer);
void update_customer_file(Customer* customer);
void delete_customer_file(Customer* customer);

char* search_customer_screen(void);
char* update_customer_screen(void);
char* delete_customer_screen(void);
char* get_customer_name(char* cpf);

Customer* create_customer_screen(void);
Customer* search_customer(char *cpf);
Customer* update_customer_data(Customer* customer);