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

    cout << message << " (M�nimo " << minLength << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(minLength <= text.length()));

    return text;
}

string requestText(string message, int minLength, int maxLength) {
    string text;

    cout << message << " (M�nimo " << minLength << " y m�ximo " << maxLength << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(minLength <= text.length() && text.length() <= maxLength));

    return text;
}

char requestGenre() {
    char genre;

    cout << "�Es de genero masculino (m) o femenino (f)?" << endl;
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

    cout << "�Qu� edad tiene (M�nimo " << minAge << " a�os)?" << endl;
    cin >> age;

    while (!(minAge <= age)) {
        cout << "Por favor, ingrese una edad m�nima de " << minAge << " a�os." << endl;
        fflush(stdin);
        cin >> age;
    }

    return age;
}

int requestAge(int minAge, int maxAge) {
    int age;

    cout << "�Qu� edad tiene (M�nimo " << minAge << " a�os y m�ximo " << maxAge << ")?" << endl;
    cin >> age;

    while (!(minAge <= age && age <= maxAge)) {
        cout << "Por favor, ingrese una edad m�nima de " << minAge << " a�os y m�xima de " << maxAge << "." << endl;
        fflush(stdin);
        cin >> age;
    }

    return age;
}

string requestDNI() {
    string dni;

    dni = requestText("�C�al es su DNI?", 8, 8);

    return dni;
}

float requestMoney(string message, int minAmount) {
    float amount;

    cout << message << "(M�nimo S/" << minAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount)) {
        cout << "Por favor, ingrese una cantidad m�nima de S/" << minAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

float requestMoney(string message, int minAmount, int maxAmount) {
    float amount;

    cout << message << "(M�nimo S/" << minAmount << " y m�ximo S/" << maxAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount && amount <= maxAmount)) {
        cout << "Por favor, ingrese una cantidad m�nima de S/" << minAmount << " y m�xima de S/" << maxAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

int requestPresentationType() {
    int presentationTypeId;

    do {
        cout << "�Cu�l es el tipo de presentaci�n del producto?" << endl;

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

    cout << message << "(M�nimo " << minAmount << "% y m�ximo " << maxAmount << "%)" << endl;
    cin >> amount;

    while (!(minAmount <= amount && amount <= maxAmount)) {
        cout << "Por favor, ingrese una cantidad m�nima de " << minAmount << "% y m�xima de " << maxAmount << "%." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

int requestStock(string message, int minAmount) {
    int amount;

    cout << message << "(M�nimo " << minAmount << ")" << endl;
    cin >> amount;

    while (!(minAmount <= amount)) {
        cout << "Por favor, ingrese una cantidad m�nima de " << minAmount << "." << endl;
        fflush(stdin);
        cin >> amount;
    }

    return amount;
}

int requestProductStatus() {
    int productStatusId;

    do {
        cout << "�Cu�l es el estado del producto?" << endl;

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