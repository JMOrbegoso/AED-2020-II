/*
Hallar la menor y mayor venta de un cliente de una tienda que registra los datos de sus clientes (apellidos
nombres, dirección y monto de venta).
Se debe mostrar:
- La lista de clientes con todos sus datos
- Ordenar la lista de clientes por monto de venta
- Buscar a un cliente
- Mostrar la mayor venta
- La menor venta
*/

#include <iostream>
#include <windows.h>
#include "Helpers.h"

using namespace std;

// Forward declarations
int getSeletectOption();
void initialize(client* clients, int& clientsQuantity);
void registerClient(client* clients, int& clientsQuantity);
void showClientsList(client* clients, int clientsQuantity);
void orderClientsAndShowThem(client* clients, int clientsQuantity);
void searchClientsByLastName(client* clients, int clientsQuantity);
void GetHighestSell(client* clients, int clientsQuantity);
void GetLowestSell(client* clients, int clientsQuantity);
void showProblem();
void showCredits();

int main()
{
    int seletectMenuOption;

    client clients[100];
    int clientsQuantity = 0;

    initialize(clients, clientsQuantity);

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerClient(clients, clientsQuantity);
                Sleep(750);
                break;

            case 2:
                showClientsList(clients, clientsQuantity);
                system("pause");
                break;

            case 3:
                orderClientsAndShowThem(clients, clientsQuantity);
                system("pause");
                break;

            case 4:
                searchClientsByLastName(clients, clientsQuantity);
                system("pause");
                break;

            case 5:
                GetHighestSell(clients, clientsQuantity);
                system("pause");
                break;

            case 6:
                GetLowestSell(clients, clientsQuantity);
                system("pause");
                break;

            case 7:
                showProblem();
                system("pause");
                break;

            case 8:
                showCredits();
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 03 (Tienda)" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar cliente" << endl;
    cout << "[2] Lista de clientes con todos sus datos" << endl;
    cout << "[3] Ordenar la lista de clientes por monto de venta" << endl;
    cout << "[4] Buscar a un cliente por apellido" << endl;
    cout << "[5] Mostrar la mayor venta" << endl;
    cout << "[6] La menor venta" << endl;
    cout << "[7] Ver planteamiento del problema" << endl;
    cout << "[8] Ver Créditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 8)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void initialize(client* clients, int& clientsQuantity) {

    clients[0].firstName = "Cristobal";
    clients[0].lastName = "Oliveira";
    clients[0].address = "Av. sun 478";
    clients[0].dni = "12569215";
    clients[0].payment = 1000;

    clients[1].firstName = "Maria";
    clients[1].lastName = "Soledad Perdomo";
    clients[1].address = "Av. Threes 999";
    clients[1].dni = "23549215";
    clients[1].payment = 1200;

    clients[2].firstName = "Angela";
    clients[2].lastName = "Guzman";
    clients[2].address = "Av. Roses 444";
    clients[2].dni = "75773215";
    clients[2].payment = 2000;

    clients[3].firstName = "Karim ";
    clients[3].lastName = "Fernandez";
    clients[3].address = "Av. Dogs 111";
    clients[3].dni = "77777915";
    clients[3].payment = 1200;

    clients[4].firstName = "Constantino";
    clients[4].lastName = "Cervantes";
    clients[4].address = "Av. Roads 121";
    clients[4].dni = "11777915";
    clients[4].payment = 1100;

    clientsQuantity = 5;
}

void registerClient(client* clients, int& clientsQuantity) {

    system("cls");

    cout << "\tRegistrará un nuevo cliente" << endl << endl;

    clients[clientsQuantity].firstName = requestText("¿Cúal es el nombre del cliente?", 2);
    clients[clientsQuantity].lastName = requestText("¿Cúal es el apellido del cliente?", 2);
    clients[clientsQuantity].address = requestText("¿Cúal es la dirección del cliente?", 2);
    clients[clientsQuantity].dni = requestDNI();
    clients[clientsQuantity].payment = requestMoney("¿Qué pago le corresponde?", 1);

    clientsQuantity++;

    cout << endl << "El cliente fue añadido correctamente." << endl;

}

void showClientsList(client* clients, int clientsQuantity) {

    system("cls");

    if (clientsArrayIsEmpty(clientsQuantity)) {
        return;
    }

    // Title
    gotoxy(40, 0); cout << "Lista de clientes" << endl;

    // Headers
    showClientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < clientsQuantity; i++) {
        showClientsListElement(4 + row, clients, i);
        row++;
    }

    cout << endl;
}

void orderClientsAndShowThem(client* clients, int clientsQuantity) {

    system("cls");

    if (clientsArrayIsEmpty(clientsQuantity)) {
        return;
    }

    orderClients(clients, clientsQuantity);

    // Title
    gotoxy(40, 0); cout << "Lista de clientes de acuerdo al monto de venta en forma descendente" << endl;

    // Headers
    showClientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < clientsQuantity; i++) {
        showClientsListElement(4 + row, clients, i);
        row++;
    }

    cout << endl;
}

void searchClientsByLastName(client* clients, int clientsQuantity) {

    string searchTerm;

    system("cls");

    if (clientsArrayIsEmpty(clientsQuantity)) {
        return;
    }

    searchTerm = requestText("Ingrese el apellido a buscar:", 2);

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de clientes con un apellido similar a '" << searchTerm << "'" << endl;

    // Headers
    showClientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < clientsQuantity; i++) {
        if (containsString(clients[i].lastName, searchTerm)) {
            showClientsListElement(4 + row, clients, i);
            row++;
        }
    }

    cout << endl;
}

void GetHighestSell(client* clients, int clientsQuantity) {

    float highestSell = 0;

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Mayor Pago" << endl;

    // Body
    for (int i = 0; i < clientsQuantity; i++) {

        if (clients[i].payment > highestSell) {
            highestSell = clients[i].payment;
        }
    }

    cout << endl << "El mayor pago es de S/" << highestSell << "." << endl;

    cout << endl;
}

void GetLowestSell(client* clients, int clientsQuantity) {

    if (clientsArrayIsEmpty(clientsQuantity)) {
        return;
    }

    float lowestSell = clients[0].payment;

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Menor Pago" << endl;

    // Body
    for (int i = 0; i < clientsQuantity; i++) {

        if (lowestSell > clients[i].payment) {
            lowestSell = clients[i].payment;
        }
    }

    cout << endl << "El menor pago es de S/" << lowestSell << "." << endl;

    cout << endl;
}

void showProblem() {

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Problema 08" << endl;

    // Body
    cout << "Hallar la menor y mayor venta de un cliente de una tienda que registra los datos de sus clientes" << endl;
    cout << "(apellidos, nombres, dirección y monto de venta)." << endl;
    cout << "Se debe mostrar:" << endl;
    cout << "\t-> La lista de clientes con todos sus datos." << endl;
    cout << "\t-> Ordenar la lista de clientes por monto de venta." << endl;
    cout << "\t-> Buscar a un cliente." << endl;
    cout << "\t-> Mostrar la mayor venta." << endl;
    cout << "\t-> La menor venta." << endl;

    cout << endl;
}

void showCredits() {

    system("cls");

    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;

    cout << endl;
}