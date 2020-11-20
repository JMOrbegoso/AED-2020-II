#include <iostream>
#include <string>
#include <windows.h>
#include "Structs.h"

using namespace std;

// Forward declarations
void gotoxy(int x, int y);
string requestText(string message, int minLength);
string requestText(string message, int minLength, int maxLength);
char requestGenre();
int requestAge(int minAge);
int requestAge(int minAge, int maxAge);
string requestDNI();
int requestMedicalSpeciality();
float requestMoney(string message, int minAmount);
float requestMoney(string message, int minAmount, int maxAmount);
void swapValue(patient* array, int i, int j);

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

int requestMedicalSpeciality() {
    int medicalSpeciality;

    do {
        cout << "�En qu� especialidad est� registrado?" << endl;
        cout << "[1: Medicina General]" << endl;
        cout << "[2: Otorrinolaringolog�a]" << endl;
        cout << "[3: Pediatr�a]" << endl;
        cout << "[4: Oftalmolog�a]" << endl;
        cout << "[5: Cardiolog�a]" << endl;
        cout << "[6: Gastroenterolog�a]" << endl;
        cout << "[7: Medicina Interna]" << endl;

        cin >> medicalSpeciality;
    } while (!(1 <= medicalSpeciality && medicalSpeciality <= 7));

    return medicalSpeciality;
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

void swapValue(patient* array, int i, int j) {

    patient temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}