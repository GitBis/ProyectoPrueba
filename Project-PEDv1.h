#include <string>
#include <queue>
using namespace std;

struct Product
{
    int id;
    string name;
    string type;
    string brand;
    float price;
};

void start_menu();
//Primera Lista(Dinamico)
//void principal_hardware();
//void storage();
//void cooling();
//void peripherals();
//void audio_video();
void option_menu();
void product_agregate();
void product_show();
void print_product(Product p);
void printCategory(queue<Product> q);
int selectCategory();
int validation();
void start_menu();