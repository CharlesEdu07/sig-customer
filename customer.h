typedef struct st_customer Customer;

struct st_customer {
    char name[255];
    char cpf[20];
    char phone[20];
    char email[255];
    char address[255];
    int deleted;
};

char menu_customer(void);
void mod_customer(void);
void create_customer(void);
void save_customer(Customer* customer);
Customer* search_customer(char *cpf);
Customer* create_customer_screen(void);
void find_customer(void);
char* search_customer_screen(void);
void update_customer(void);
char* update_customer_screen(void);
Customer* update_customer_data(Customer* customer);
void delete_customer_screen(void);