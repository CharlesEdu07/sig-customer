typedef struct st_product Product;

struct st_product {
    char product_code[20];
    char product_name[255];
    char product_type[255];
    char product_description[255];
    char product_price[20];
    int deleted;
};

char menu_product(void);
void mod_product(void);
void save_product(Product* product);
void create_product(void);
Product* create_product_screen(void);
Product* search_product(char *product_code);
void search_product_screen(void);
void update_product_screen(void);
void delete_product_screen(void);