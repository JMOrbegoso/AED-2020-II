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

void initializePresentationTypes(presentationType* presentationTypes, int& quantity) {

    presentationTypes[0].id = 1;
    presentationTypes[0].name = "botella";

    presentationTypes[1].id = 2;
    presentationTypes[1].name = "caja";

    presentationTypes[2].id = 3;
    presentationTypes[2].name = "bolsa";

    presentationTypes[3].id = 4;
    presentationTypes[3].name = "unidad";

    quantity = 4;
}

void initializeProductStatuses(productStatus* productStatuses, int& quantity) {

    productStatuses[0].id = 1;
    productStatuses[0].name = "Vigente";

    productStatuses[1].id = 2;
    productStatuses[1].name = "Vencido";

    productStatuses[2].id = 3;
    productStatuses[2].name = "Descontinuado";

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