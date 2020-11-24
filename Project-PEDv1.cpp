#include <iostream>
#include <regex> //Libreria para comparacion de cadenas
#include "Project-PEDv1.h"      //!Header file for keep organizated code

//Mediante un menú se deberán poder agregar, quitar y modificar establecimientos de comida. 
//Además cada comedor deberá poder agregar, quitar y modificar platos de comida a su propio menú. 
//Finalmente un cliente puede ordenar cualquier cantidad de platos y el programa debe calcular el 
//total de dinero a pagar más una comisión de $5.00 por entrega a domicilio.

/**
 * TODO:
 * *Agregar a carrito:
 *  ?Cantidad de productos agregado al carrito
 * *Eliminar del carrito
 *  ?Eliminar por ID
 * *Vaciar carrito
 * *Factura bonita:
 *  ?Subtotales
 *  ?Total
 */

int category = 0;
int pastId = 0;

deque<Product> principal_hardware, storage, cooling;
Cart cart;

int main() {
    //Mensaje de Bienvenida
    cout << "\n\t\t\t __________________________" << endl;
    cout << "\t\t\t|                          |" << endl;
    cout << "\t\t\t|  Bienvenido a *********  |" << endl;
    cout << "\t\t\t|                          |" << endl;
    cout << "\t\t\t|   Tienda Gaming Online   |" << endl;
    cout << "\t\t\t|__________________________|\n\n" << endl;
    system("pause");
    system("cls");
    
    cart.total = 0.0f;

    start_menu();
    return 0;
}

//Menu inicial
void start_menu() {

    int repeat = 1;

    do {
        int opcion = 0;
        cout << "\n\t  Inicio\n";
        cout << "\t-----------" << endl;
        cout << "\n\t\t\t ____________________________" << endl;
        cout << "\t\t\t|                            | " << endl;
        cout << "\t\t\t| 1) Hardware Principal      |" << endl;
        cout << "\t\t\t|____________________________|" << endl;
        cout << "\t\t\t|                            | " << endl;
        cout << "\t\t\t| 2) Almacenamiento          |" << endl;
        cout << "\t\t\t|____________________________|" << endl;
        cout << "\t\t\t|                            | " << endl;
        cout << "\t\t\t| 3) Enfriamiento            |" << endl;
        cout << "\t\t\t|____________________________|" << endl;
        cout << "\t\t\t|                            | " << endl;
        cout << "\t\t\t| 4) Perifericos             |" << endl;
        cout << "\t\t\t|____________________________|" << endl;
        cout << "\t\t\t|                            | " << endl;
        cout << "\t\t\t| 5) Audio & Video           |" << endl;
        cout << "\t\t\t|____________________________|" << endl;
        cout << "\t ___________" << endl;
        cout << "\t|           |" << endl;
        cout << "\t| 6) Salir  |" << endl;
        cout << "\t|___________|" << endl;
        //cout << "\n\t\t\tOpcion elegida: ";
        int option = validation();
        //cin >> opcion;
        system("cls");

        switch (option) {

        case 1: option_menu(); break;
        //case 2: storage(); break;
        //case 3: cooling(); break;
       // case 4: peripherals(); break;
        //case 5: audio_video(); break;
        case 6:
            cout << "\n\n\n\t\t ____________________________" << endl;
            cout << "\t\t|                            | " << endl;
            cout << "\t\t|         Saliendo...        |" << endl;
            cout << "\t\t|____________________________|\n\n\n" << endl;
            exit(0); break;
        default: cout << "\n\n\n\t\t    Esa opcion no existe en el menu :(\n" << endl;
            cout << "\t\t-----------------------------------------\n\n\n" << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (repeat == 1);
}

void printProduct(Product p)
{
    cout << "-------------------------------------" << endl;
    cout << "ID: " << p.id << endl;
    cout << "Nombre: " << p.name << endl;
    cout << "Tipo: " << p.type << endl;
    cout << "Marca: " << p.brand << endl;
    cout << "Precio: " << p.price << endl;
    cout << "Cantidad: " << p.cant << endl;
    cout << "-------------------------------------" << endl;
}

void printCategory(deque<Product> q)    //it cpuld be an error
{
    if (!q.empty())
    {
        deque<Product> temp;

        while (!q.empty())
        {
            printProduct(q.front());
            temp.push_back(q.front());
            q.pop_front();
        }

        while (!temp.empty())
        {
            q.push_back(temp.front());
            temp.pop_front();
        }
    }
    else
    {
        cout << "Esta Categoria esta Vacia" << endl;
    }
}

int selectCategory()
{
    int selected = 0;

    cout << "Seleccione la categoria que necesita:" << endl;
    cout << "1. Hardware Principal " << endl;
    cout << "2. Almacenamiento" << endl;
    cout << "3. Enfriamiento" << endl;
    cin >> selected;
    cin.ignore();

    return selected;
}

//Validacion si ingresa algo que no sea numero entero
int validation() {
    string input;
    while (true) {
        cout << "\n\t\t\tOpcion elegida: ";
        cin >> input;
        cin.ignore();
        if (regex_match(input, regex("^[1-9]*$"))) {
            return atoi(&input[0]);
        }
        else {
            cout << "\n\n\n\tOpcion invalida, ingrese un numero entero '_'\n" << endl;
            //system("pause");
            //system("cls");
        }
    }
}

void option_menu() {
    int repeat = 1;

    do {
        //int option = 0;
        cout << "\n\t  Categorias\n";
        cout << "\t----------------" << endl;
        cout << "\n\t\t\t _______________________________________" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 1) Agregar producto a una categoria   |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 2) Eliminar un producto de la tienda  |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 3) Vaciar una categoria               |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 4) Mostrar pruductos de una categoria |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 5) Carrito                            |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t _____________" << endl;
        cout << "\t|             |" << endl;
        cout << "\t| 6) Regresar |" << endl;
        cout << "\t|_____________|" << endl;
        //cout << "\n\t\t\tOpcion elegida: ";
        int option = validation();
        //cin >> opcion;
        system("cls");

        switch (option) {

            case 1:
                product_agregate();
                break;
            //case 2: storage(); break;
            //case 3: cooling(); break;
            case 4:
                product_show();
                break;
            case 5:
                displayCartOptions();
                break;
            case 6: 
                start_menu(); 
                break;
            default: cout << "\n\n\n\t\t    Esa opcion no existe en el menu :(\n" << endl;
                cout << "\t\t-----------------------------------------\n\n\n" << endl;
                break;
        }
        system("pause");
        system("cls");
    } while (repeat == 1);
}

void product_agregate() {
    Product product;
    cout << "----------------------Agregar Producto---------------------" << endl;

    do
    {
        category = selectCategory();

        if (category >= 1 && category <= 3)
        {
           // Product product;
            int priced = 0;
            int cantity = 0;
            
            product.id = pastId + 1;
            cout << "\nNombre del producto: " << endl;
            getline(cin, product.name);
            cout << "Tipo de producto: " << endl;
            getline(cin, product.type);
            cout << "Marca del producto: " << endl;
            getline(cin, product.brand);
            cout << "Cantidad de productos: ";
            cin >> cantity;
            cout << "Precio del producto en dolares: $ ";
            cin >> priced;
            cin.ignore();

            while (priced <= 0)
            {
                cout << "\nIngrese un valor valido para el precio (mayor a 0)" << endl;
                cin >> priced;
            }

            while (cantity <= 0)
            {
                cout << "\nIngrese mas de un producto (mayor a 0)" << endl;
                cin >> cantity;
            }

            product.price = priced;
            product.cant = cantity;

            if (category == 1)
            {
                principal_hardware.push_back(product);
            }
            else if (category == 2)
            {
                storage.push_back(product);
            }
            else if (category == 3)
            {
                cooling.push_back(product);
            }

            cout << "\nProducto agregado correctamente" << endl;
            printProduct(product);
            cout << endl;
        }
        else
        {
            cout << "Seleccione una categoria correcta" << endl;
        }
    } while (category < 1 || category > 3);
}

void product_show() {
    //queue<Product> principal_hardware, storage, cooling;
    cout << "----------------------Mostrar un producto---------------------" << endl;

    do
    {
        category = selectCategory();

        if (category >= 1 && category <= 3)
        {
            if (category == 1)
            {
                printCategory(principal_hardware);
            }
            else if (category == 2)
            {
                printCategory(storage);
            }
            else if (category == 3)
            {
                printCategory(cooling);
            }
        }
        else
        {
            cout << "Seleccione una categoria valida" << endl;
        }

        cout << endl;
    } while (category < 1 || category > 3);
}

void displayCartOptions() {
    cout << "----------------------Carrito---------------------" << endl;

    bool keepGoing = false;

    do
    {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Agregar producto al carrito" << endl;
        cout << "2. Ver productos del carrito" << endl;
        cout << "3. Vaciar Carrito" << endl;
        cout << "4. Pagar" << endl;
        cout << "5. Volver" << endl;
        
        int selected = validation();

        if(selected >= 1 && selected <= 5) {
            if(selected == 1) {
                printCategory(cart.products);
                cout << "Ingrese la ID del producto deseado de la lista (tener en cuenta la cantidad disponible)" << endl;
                int selectedProduct = validation();

                addToCart(searchItem(selectedProduct, principal_hardware));
                addToCart(searchItem(selectedProduct, storage));
                addToCart(searchItem(selectedProduct, cooling)); 
            } else if(selected == 2) {
                if(!cart.products.empty()) {
                    printCategory(cart.products);
                } else{
                    cout << "Lo sentimos, pero el carrito esta vacio!" << endl;
                }
            } else if(selected == 3) {
                if(!cart.products.empty()) {
                    cart.products.clear();
                } else{
                    cout << "Lo sentimos, pero el carrito esta vacio!" << endl;
                }
            } else if(selected == 4) {
                if(!cart.products.empty()) {
                    checkout();
                } else{
                    cout << "Lo sentimos, pero el carrito esta vacio!" << endl;
                }
            } else if(selected == 5) {
                option_menu();
            }

            keepGoing = false;
        } else{
            cout << "Seleccione una categoria correcta" << endl;
            keepGoing = true;
        }
    } while (keepGoing);
}

/*Function to search an item on any deque,
 *if the item is in the deque return the Product, 
 *if the item isn't found return a Product with id = -1
 */
Product searchItem(int id, deque<Product> dq) {
    Product p = {-1, "", "", "", 0.0, 0};
    deque<Product> temp;

    while(!dq.empty()) {
        Product searched = dq.front();
        
        if(searched.id == id) {
            p = searched;
        }

        temp.push_back(searched);
        dq.pop_front();
    }

    while(!temp.empty()) {
        dq.push_back(temp.front());
        temp.pop_front();
    }

    return p;
}

void addToCart(Product p) {
    if(p.id <= 0) {
        cout << ".";
        return;
    } else{
        bool notEnough = false;

        print_product(p);

        do{
            cout << "\nCantidad a comprar: ";
            int quantity = validation();

            if(quantity > 0) {
                notEnough = false;
                
                Product intoCart = p;
                intoCart.cant = quantity;

                if(intoCart.cant > p.cant) {
                    cout << "Lo sentimos no hay suficientes en stock!!" << endl;
                    cout << "Seleccione una cantidad disponible en stock" << endl;
                    notEnough = true;
                } else{
                    cart.products.push_back(intoCart);
                    cart.total += (intoCart.cant * intoCart.price);
                    cout << "Producto agregado correctamente" << endl;
                    p.cant = p.cant - intoCart.cant;  //i dont think this its going to work
                }
                
            } else{
                cout << "Debe agregar almenos un producto" << endl;
                notEnough = true;
            }
        }while(notEnough);
    }
}

void checkout() {
    printCategory(cart.products);
    cout << "Su total es de $" << cart.total << endl;
    cout << "Gracias por comprar con nosotros :)" << endl;
    cart.products.clear();
    cart.total = 0.0f;
}