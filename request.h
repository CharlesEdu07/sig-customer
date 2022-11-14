typedef struct st_request Request;

struct st_request {
    char id[50];
    char date[50];
    char customer_cpf[20];
    char product_code[20];
    int quantity;
    float amount_to_pay;
    int deleted;
};

int menu_request(void);
int confirm_request_delete(Request *request);

void mod_request(void);
void create_request(void);
void find_request(void);
void update_request(void);
void delete_request(void);
void save_request(Request* request);
void update_request_file(Request* request);

char* search_request_screen(void);
char* update_request_screen(void);
char* delete_request_screen(void);

Request* create_request_screen(void);
Request* search_request(char *id);
Request* update_request_data(Request* request);