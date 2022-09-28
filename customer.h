typedef struct st_customer Customer;

struct st_customer {
    char *name;
    char *cpf;
    char *phone;
    char *email;
    char *address;
};

char menu_customer(void);
void mod_customer(void);
void create_customer(void);
Customer* create_customer_screen(void);
void search_customer_screen(void);
void update_customer_screen(void);
void delete_customer_screen(void);