#include "Helpers.h"
#include "Structs.h"

using namespace std;

void initializeSupermarket(supermarket& supermarket) {

    supermarket.name = "Supermercado Heroes";
    supermarket.address = "Av. Los Heroes 777";
    supermarket.telephone = "952384721";
    supermarket.admin = "Roman Robles";
    supermarket.ruc = "72122372282";
}

void initializeClients(client* clients, int& quantity) {
    clients[0].id = 1;
    clients[0].lastName = "Oliveira";
    clients[0].firstName = "Cristobal";
    clients[0].address = "Av. Las fuentes 555";
    clients[0].genre = 'm';
    clients[0].telephone = "910809080";
    clients[0].dni = "88502324";

    clients[1].id = 2;
    clients[1].lastName = "Perdomo";
    clients[1].firstName = "Maria";
    clients[1].address = "Av. Las gaviotas 444";
    clients[1].genre = 'f';
    clients[1].telephone = "921725080";
    clients[1].dni = "71402324";

    clients[2].id = 3;
    clients[2].lastName = "Guzman";
    clients[2].firstName = "Angela";
    clients[2].address = "Av. Los aviones 747";
    clients[2].genre = 'f';
    clients[2].telephone = "932625080";
    clients[2].dni = "62562326";

    quantity = 3;
}

void initializeProducts(product* products, int& quantity) {

    products[0].id = 1;
    products[0].name = "Ryzen 5 3600";
    products[0].description = "Procesador de 6 núcleos y 12 hilos";
    products[0].price = 980;
    products[0].presentationTypeId = 2;
    products[0].discount = 0;
    products[0].brand = "AMD";
    products[0].stock = 12;
    products[0].productStatusId = 1;

    products[1].id = 2;
    products[1].name = "Ryzen 5 3400";
    products[1].description = "Procesador de 4 núcleos y 8 hilos";
    products[1].price = 750;
    products[1].presentationTypeId = 2;
    products[1].discount = 0;
    products[1].brand = "AMD";
    products[1].stock = 15;
    products[1].productStatusId = 1;

    products[2].id = 3;
    products[2].name = "Ryzen 3 3100";
    products[2].description = "Procesador de 4 núcleos y 8 hilos";
    products[2].price = 540;
    products[2].presentationTypeId = 2;
    products[2].discount = 0;
    products[2].brand = "AMD";
    products[2].stock = 20;
    products[2].productStatusId = 1;

    quantity = 3;
}

void initializePurchases(purchase* purchases, int& quantity) {

    purchases[0].id = 1;
    purchases[0].clientId = 1;

    purchases[1].id = 2;
    purchases[1].clientId = 2;

    purchases[2].id = 3;
    purchases[2].clientId = 3;

    purchases[3].id = 4;
    purchases[3].clientId = 3;

    quantity = 4;
}

void initializePurchasedProducts(purchasedProduct* purchasedProducts, int& quantity) {

    purchasedProducts[0].id = 1;
    purchasedProducts[0].purchaseId = 1;
    purchasedProducts[0].productId = 2;
    purchasedProducts[0].productquantity = 1;

    purchasedProducts[1].id = 2;
    purchasedProducts[1].purchaseId = 2;
    purchasedProducts[1].productId = 2;
    purchasedProducts[1].productquantity = 1;

    purchasedProducts[2].id = 3;
    purchasedProducts[2].purchaseId = 3;
    purchasedProducts[2].productId = 3;
    purchasedProducts[2].productquantity = 1;

    purchasedProducts[3].id = 4;
    purchasedProducts[3].purchaseId = 4;
    purchasedProducts[3].productId = 1;
    purchasedProducts[3].productquantity = 1;

    quantity = 4;
}

int getSeletectOption(supermarket supermarket) {
    int seletectOption;

    system("cls");

    cout << "------------------------------------------------------------------------" << endl;
    cout << endl << "\tBienvenido al Sistema del supermercado '" << supermarket.name << "'" << endl << endl;
    cout << "Dirección: " << supermarket.address << endl;
    cout << "Administrador: " << supermarket.admin << endl;
    cout << "Telefono: " << supermarket.telephone << endl;
    cout << "RUC: " << supermarket.ruc << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << endl << "¿Qué desea hacer?" << endl << endl;

    cout << "[1] Actualizar datos del supermercado" << endl;
    cout << "[2] Registrar nuevo producto" << endl;
    cout << "[3] Editar un producto" << endl;
    cout << "[4] Buscar producto por nombre" << endl;
    cout << "[5] Buscar producto por marca" << endl;
    cout << "[6] Ver productos ordenados por precio de forma ascendente" << endl;
    cout << "[7] Aplicar descuento del 7% a un producto" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 7)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void updateSupermarketProperties(supermarket& supermarket) {

    cout << "Actualizará los datos del supermercado '" << supermarket.name << "'" << endl;

    supermarket.name = requestText("Ingrese el nuevo nombre del supermercado:", 5);
    supermarket.address = requestText("Ingrese la nueva dirección del supermercado:", 5);
    supermarket.telephone = requestText("Ingrese el nuervo número telefónico del supermercado:", 9, 9);
    supermarket.admin = requestText("Ingrese el nuervo nombre del administrador del supermercado:", 5);
    supermarket.ruc = requestText("Ingrese el nuervo RUC del administrador del supermercado:", 11, 11);

    textWaiting("Actualizando datos");

    cout << endl << "Actualizó correctamente los datos del supermercado." << endl;
}

void registerNewProduct(product* products, int& productsQuantity) {

    cout << "Registrará un nuevo producto" << endl;

    products[productsQuantity].id = productsQuantity + 1;
    products[productsQuantity].name = requestText("Ingrese el nombre del producto:", 1);
    products[productsQuantity].description = requestText("Ingrese la descripcion del producto:", 3);
    products[productsQuantity].price = requestMoney("Ingrese el precio del producto:", 0.5, 1000);
    products[productsQuantity].presentationTypeId = requestPresentationType();
    products[productsQuantity].discount = requestDiscountPercentage("Ingrese el porcentaje de descuento del producto", 0, 99.99);
    products[productsQuantity].brand = requestText("Ingrese la marca del producto:", 1);
    products[productsQuantity].stock = requestStock("Ingrese la cantidad de stock del producto", 0);
    products[productsQuantity].productStatusId = requestProductStatus();

    textWaiting("Registrando nuevo producto");

    cout << endl << "Registró el nuevo producto correctamente." << endl;

    productsQuantity++;
}

void editProduct(product* products, int productsQuantity) {

    int productId;
    int productIndex = -1;

    cout << "Editará un producto" << endl;

    cout << "Ingrese el Id del producto a editar" << endl;
    cin >> productId;

    for (int i = 0; i < productsQuantity; i++) {
        if (products[i].id == productId)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        cout << "El Id del producto no se ha encontrado, por favor intente nuevamente." << endl;
        return;
    }

    products[productIndex].name = requestText("Ingrese el nombre del producto:", 1);
    products[productIndex].description = requestText("Ingrese la descripcion del producto:", 3);
    products[productIndex].price = requestMoney("Ingrese el precio del producto:", 0.5, 1000);
    products[productIndex].presentationTypeId = requestPresentationType();
    products[productIndex].discount = requestDiscountPercentage("Ingrese el porcentaje de descuento del producto", 0, 99.99);
    products[productIndex].brand = requestText("Ingrese la marca del producto:", 1);
    products[productIndex].stock = requestStock("Ingrese la cantidad de stock del producto", 0);
    products[productIndex].productStatusId = requestProductStatus();

    textWaiting("Editando producto");

    cout << endl << "Editó el producto correctamente." << endl;
}

/// <param name="y">y-axis</param>
void showProductsListHeaders(int y) {

    gotoxy(0, y); cout << "#" << endl;
    gotoxy(0, y); cout << "Id" << endl;
    gotoxy(5, y); cout << "Nombre" << endl;
    gotoxy(55, y); cout << "Description" << endl;
    gotoxy(65, y); cout << "Precio" << endl;
    gotoxy(75, y); cout << "Tipo de Presentación" << endl;
    gotoxy(85, y); cout << "Descuento" << endl;
    gotoxy(95, y); cout << "Marca" << endl;
    gotoxy(95, y); cout << "Stock" << endl;
    gotoxy(95, y); cout << "Status" << endl;
}

string getPresentationTypeString(int presentationTypeId) {
    switch (presentationTypeId)
    {
    case 1:
        return "Botella";
    case 2:
        return "Caja";
    case 3:
        return "Bolsa";
    case 4:
        return "Unidad";

    default:
        return "No Encontrado";;
    }
}

string getProductStatusString(int productStatusId) {
    switch (productStatusId)
    {
    case 1:
        return "Vigente";
    case 2:
        return "Vencido";
    case 3:
        return "No Perecible";
    case 4:
        return "Descontinuado";

    default:
        return "No Encontrado";;
    }
}

/// <param name="y">y-axis</param>
/// <param name="i">soldier index</param>
void showProductsListElement(int y, product* products, int i) {

    gotoxy(0, y); cout << (i + 1) << endl;
    gotoxy(0, y); cout << products[i].id << endl;
    gotoxy(5, y); cout << products[i].name << endl;
    gotoxy(55, y); cout << products[i].description << endl;
    gotoxy(65, y); cout << "S/ " << products[i].price << endl;
    gotoxy(75, y); cout << getPresentationTypeString(products[i].presentationTypeId) << endl;
    gotoxy(85, y); cout << products[i].discount << "%" << endl;
    gotoxy(85, y); cout << products[i].brand << endl;
    gotoxy(85, y); cout << products[i].stock << endl;
    gotoxy(95, y); cout << getProductStatusString(products[i].productStatusId) << endl;
}

void searchProductByName(product* products, int productsQuantity) {
    string searchTerm;

    system("cls");

    searchTerm = requestText("Ingrese el nombre del producto a buscar:", 2);

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de productos con un nombre similar a '" << searchTerm << "'" << endl;

    // Headers
    showProductsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < productsQuantity; i++) {
        if (containsString(products[i].name, searchTerm)) {
            showProductsListElement(4 + row, products, i);
            row++;
        }
    }

    cout << endl;
}

void searchProductByBrand(product* products, int productsQuantity) {
    string searchTerm;

    system("cls");

    searchTerm = requestText("Ingrese la marca de productos a buscar:", 2);

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de productos con una marca similar a '" << searchTerm << "'" << endl;

    // Headers
    showProductsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < productsQuantity; i++) {
        if (containsString(products[i].brand, searchTerm)) {
            showProductsListElement(4 + row, products, i);
            row++;
        }
    }

    cout << endl;
}

void swapValue(product* array, int i, int j) {

    product temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void orderProducts(product* products, int productsQuantity) {
    int i, j;
    for (i = 0; i < productsQuantity - 1; i++)
    {
        for (j = 0; j < productsQuantity - i - 1; j++)
        {
            if (products[j].price < products[j + 1].price)
            {
                swapValue(products, j, j + 1);
            }
        }
    }
}

void orderAndShowProducts(product* products, int productsQuantity) {

    orderProducts(products, productsQuantity);

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de productos ordenados por precio de forma descendente" << endl;

    // Headers
    showProductsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < productsQuantity; i++) {
        showProductsListElement(4 + row, products, i);
        row++;
    }

    cout << endl;
}

void applyDiscountToProduct(product* products, int productsQuantity) {

    int productId;
    int productIndex = -1;

    cout << "Aplicará un descuento del 7% a un producto" << endl;

    cout << "Ingrese el Id del producto a aplicar el descuento" << endl;
    cin >> productId;

    for (int i = 0; i < productsQuantity; i++) {
        if (products[i].id == productId)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        cout << "El Id del producto no se ha encontrado, por favor intente nuevamente." << endl;
        return;
    }

    products[productIndex].discount = 7;

    textWaiting("Aplicando descuento al producto");

    cout << endl << "Aplicó el descuento al producto correctamente." << endl;
}