#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;

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

char requestGenre() {
    char genre;

    cout << "¿Es de genero masculino (m) o femenino (f)?" << endl;
    cin >> genre;

    while (!(genre == 'm' || genre == 'f')) {
        cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
        fflush(stdin);
        cin >> genre;
    }

    return genre;
}

int requestAge(int minAge) {
    int age;

    cout << "¿Qué edad tiene (Mínimo " << minAge << " años)?" << endl;
    cin >> age;

    while (!(minAge <= age)) {
        cout << "Por favor, ingrese una edad mínima de " << minAge << " años." << endl;
        fflush(stdin);
        cin >> age;
    }

    return age;
}

int requestAge(int minAge, int maxAge) {
    int age;

    cout << "¿Qué edad tiene (Mínimo " << minAge << " años y máximo " << maxAge << ")?" << endl;
    cin >> age;

    while (!(minAge <= age && age <= maxAge)) {
        cout << "Por favor, ingrese una edad mínima de " << minAge << " años y máxima de " << maxAge << "." << endl;
        fflush(stdin);
        cin >> age;
    }

    return age;
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

int requestPresentationType() {
    int presentationTypeId;

    do {
        cout << "¿Cuál es el tipo de presentación del producto?" << endl;

        cout << "[1: Botella]" << endl;
        cout << "[2: Caja]" << endl;
        cout << "[3: Bolsa]" << endl;
        cout << "[4: Unidad]" << endl;

        cin >> presentationTypeId;
    } while (!(1 <= presentationTypeId && presentationTypeId <= 4));

    return presentationTypeId;
}

float requestDiscountPercentage(string message, int minAmount, int maxAmount) {
    float amount;

    cout << message << "(Mínimo " << minAmount << "% y máximo " << maxAmount << "%)" << endl;
    cin >> amount;

    while (!(minAmount <= amount && amount <= maxAmount)) {
        cout << "Por favor, ingrese una cantidad mínima de " << minAmount << "% y máxima de " << maxAmount << "%." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

int requestStock(string message, int minAmount) {
    int amount;

    cout << message << "(Mínimo " << minAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount)) {
        cout << "Por favor, ingrese una cantidad mínima de " << minAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

int requestProductStatus() {
    int productStatusId;

    do {
        cout << "¿Cuál es el estado del producto?" << endl;

        cout << "[1: Vigente]" << endl;
        cout << "[2: Vencido]" << endl;
        cout << "[3: No Perecible]" << endl;
        cout << "[4: Descontinuado]" << endl;

        cin >> productStatusId;
    } while (!(1 <= productStatusId && productStatusId <= 4));

    return productStatusId;
}

void textWaiting(string message) {

    cout << endl << message << " ";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
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