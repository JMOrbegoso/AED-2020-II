#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include "Structs.h"

using namespace std;

// Forward declarations
void gotoxy(int x, int y);
string requestText(string message, int minLength);
string requestText(string message, int minLength, int maxLength);
string requestDNI();
float requestMoney(string message, int minAmount);
float requestMoney(string message, int minAmount, int maxAmount);
void swapValue(string* array, int i, int j);
void swapValue(client* array, int i, int j);
bool clientsArrayIsEmpty(int clientsQuantity);
void orderClients(client* clients, int clientsQuantity);
string toLowerCase(string text);
bool containsString(string base, string toSearch);
void showClientsListHeaders(int y);
void showClientsListElement(int y, client* clients, int i);

// Methods

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

string requestText(string message, int minLength) {
    string text;

    cout << message << " (Mínimo " << minLength << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(minLength <= text.length()));

    return text;
}

string requestText(string message, int minLength, int maxLength) {
    string text;

    cout << message << " (Mínimo " << minLength << " y máximo " << maxLength << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(minLength <= text.length() && text.length() <= maxLength));

    return text;
}

string requestDNI() {
    string dni;

    dni = requestText("¿Cúal es su DNI?", 8, 8);

    return dni;
}

float requestMoney(string message, int minAmount) {
    float amount;

    cout << message << "(Mínimo S/" << minAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << minAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

float requestMoney(string message, int minAmount, int maxAmount) {
    float amount;

    cout << message << "(Mínimo S/" << minAmount << " y máximo S/" << maxAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount && amount <= maxAmount)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << minAmount << " y máxima de S/" << maxAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

void swapValue(string* array, int i, int j) {

    string temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void swapValue(client* array, int i, int j) {

    client temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

bool clientsArrayIsEmpty(int clientsQuantity) {
    if (!(0 < clientsQuantity)) {
        cout << "No se ha encontrado ningún cliente." << endl;
        return true;
    }
    return false;
}

void orderClients(client* clients, int clientsQuantity) {

    int i, j;
    for (i = 0; i < clientsQuantity - 1; i++)
    {
        for (j = 0; j < clientsQuantity - i - 1; j++)
        {
            if (clients[j].payment < clients[j + 1].payment)
            {
                swapValue(clients, j, j + 1);
            }
        }
    }
}

/// <summary>
/// Receives a string and returns it in lowercase.
/// </summary>
string toLowerCase(string text) {

    for_each(text.begin(), text.end(), [](char& c) {
        c = ::tolower(c);
    });

    return text;
}

/// <summary>
/// Return bool if found the "toSearch" text parameter on the "base" text parameter.
/// </summary>
bool containsString(string base, string toSearch) {
    if (toLowerCase(base).find(toLowerCase(toSearch), 0) != string::npos) {
        return true;
    }
    return false;
}

/// <param name="y">y-axis</param>
void showClientsListHeaders(int y) {

    gotoxy(0, y); cout << "#" << endl;
    gotoxy(5, y); cout << "Apellidos y Nombres" << endl;
    gotoxy(55, y); cout << "Dirección" << endl;
    gotoxy(85, y); cout << "DNI" << endl;
    gotoxy(95, y); cout << "Pago" << endl;
}

/// <param name="y">y-axis</param>
/// <param name="i">client index</param>
void showClientsListElement(int y, client* clients, int i) {

    gotoxy(0, y); cout << (i + 1) << endl;
    gotoxy(5, y); cout << clients[i].lastName << " " << clients[i].firstName << endl;
    gotoxy(55, y); cout << clients[i].address << endl;
    gotoxy(85, y); cout << clients[i].dni << endl;
    gotoxy(95, y); cout << clients[i].payment << endl;
}