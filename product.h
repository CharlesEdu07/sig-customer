typedef struct st_product Product;

struct st_product {
    char product_code[20];
    char product_name[255];
    char product_type[255];
    char product_description[255];
    float product_price;
    int deleted;
};

int menu_product(void);

void mod_product(void);
void create_product(void);
void find_product(void);
void update_product(void);
void delete_product_screen(void);
void save_product(Product* product);
void update_product_file(Product* product);

char* show_product_types(void);
char* search_product_screen(void);
char* update_product_screen(void);

float get_product_price(char* product_code);

Product* search_product(char* product_code);
Product* create_product_screen(void);
Product* update_product_data(Product* product);
