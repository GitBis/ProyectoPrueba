#include <iostream>
#include <regex> //Libreria para comparacion de cadenas
#include "Project-PEDv1.h"      //!Header file for keep organizated code

//Mediante un menú se deberán poder agregar, quitar y modificar establecimientos de comida. 
//Además cada comedor deberá poder agregar, quitar y modificar platos de comida a su propio menú. 
//Finalmente un cliente puede ordenar cualquier cantidad de platos y el programa debe calcular el 
//total de dinero a pagar más una comisión de $5.00 por entrega a domicilio.

/**
 * TODO:
 * *Suave
 * !Agregar:
 *  -Por categoria
 * !Eliminar:
 *  -Por categoria
 * !Vaciar:
 *  -Por categoria
 * ?Editar
 * 
 * *yoxd
 * !Todo lo relacionado con el carrito xD
 */

int category = 0;
deque<Product> principal_hardware, storage, cooling;
int pastId = 0;

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
    cout << "Nombre: " << p.id << endl;
    cout << "Nombre: " << p.name << endl;
    cout << "Tipo: " << p.type << endl;
    cout << "Marca: " << p.brand << endl;
    cout << "Precio: " << p.price << endl;
    cout << "-------------------------------------" << endl;
}

void printCategory(deque<Product> q)
{
    if (!q.empty())
    {
        deque<Product> temp;

        while (!q.empty())
        {
            printProduct(q.front());
            temp.push_back(q.front());
            q.pop_front();//xdD
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
        cout << "\t\t\t| 2) Eliminar un producto               |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 3) Vaciar una categoria               |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t\t\t|                                       | " << endl;
        cout << "\t\t\t| 4) Mostrar pruductos de una categoria |" << endl;
        cout << "\t\t\t|_______________________________________|" << endl;
        //cout << "\t\t\t|                                       | " << endl;
        //cout << "\t\t\t| 5) Editar categoria                   |" << endl;
        //cout << "\t\t\t|_______________________________________|" << endl;
        cout << "\t _____________" << endl;
        cout << "\t|             |" << endl;
        cout << "\t| 5) Regresar |" << endl;
        cout << "\t|_____________|" << endl;
        //cout << "\n\t\t\tOpcion elegida: ";
        int option = validation();
        //cin >> opcion;
        system("cls");

        switch (option) {

        case 1: product_agregate(); break;
        //case 2: storage(); break;
        //case 3: cooling(); break;
        case 4: product_show(); break;
        case 5: start_menu(); break;
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
            
            product.id = pastId + 1;
            cout << "\nNombre del producto: " << endl;
            getline(cin, product.name);
            cout << "Tipo de producto: " << endl;
            getline(cin, product.type);
            cout << "Marca del producto: " << endl;
            getline(cin, product.brand);
            cout << "Precio del producto en dolares: $ ";
            cin >> priced;

            while (priced <= 0)
            {
                cout << "\nIngrese un valor valido para el precio, mayor a 0)" << endl;
                cin >> priced;
            }

            product.price = priced;

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



//void principal_hardware() {


    // Procesadores
    // Motherboards
    // Memoria Ram
    // Fuentes de Poder
    // Tarjetas de Video
    // Case

//}

//void storage() {


    // Discos duros
    // Discos Externos
    // SSD
    // M.2
    // Memoria USB
    // Micro SD
    // Enclosure
//}

//void cooling() {

    // Coolers de Aire
    // Enfriamiento Líquido
    // Enfriamiento Custom
    // Cooler Laptops
    // Ventiladores
    // Pasta Térmica
//}

//void peripherals() {


    // Mouse
    // Mousepad
    // Teclados
    // Combos Teclado Mouse
//}
//void audio_video() {


    // Headset
    // Bocinas
    // Monitores
    // Proyectores
    // Cámaras Web
//}

