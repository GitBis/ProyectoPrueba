#include <string>
#include <deque>
using namespace std;

struct Product
{
    int id;
    string name;
    string type;
    string brand;
    float price;
    int cant;
};

struct Cart
{
    deque<Product> products;
    float total;
};

void start_menu();
void option_menu();
void product_agregate();
void product_show();
void printProduct(Product p);
void printCategory(deque<Product> q);
int selectCategory();
int validation();
void start_menu();

/** Cart methods **/

Product searchItem(int id, deque<Product> dq);
void displayCartOptions();
void addToCart(Product p);
void checkout();
void modifyQuantity(int selledQuant, int id, deque<Product> dq);