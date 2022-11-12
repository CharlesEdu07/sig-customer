typedef struct st_product Product;

struct st_product {
    char product_code[20];
    char product_name[255];
    char product_type[255];
    char product_description[255];
    float product_price;
    int deleted;
};

char menu_product(void);
void mod_product(void);
void save_product(Product* product);
char* show_product_types(void);
void create_product(void);
Product* search_product(char* product_code);
Product* create_product_screen(void);
void find_product(void);
char* search_product_screen(void);
void update_product_file(Product* product);
void update_product(void);
char* update_product_screen(void);
Product* update_product_data(Product* product);
void delete_product_screen(void);