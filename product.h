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
void create_product_screen(void);
void search_product_screen(void);
void update_product_screen(void);
void delete_product_screen(void);