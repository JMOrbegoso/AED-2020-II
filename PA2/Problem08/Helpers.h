#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
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
string toLowerCase(string text);
bool containsString(string base, string toSearch);
bool patientsArrayIsEmpty(int patientsQuantity);
void orderPatients(patient* patients, int patientsQuantity);
void showPatientsListHeaders(int y);
void showPatientsListElement(int y, patient* patient, int i);
string getMedicalSpecialityString(int medicalSpeciality);

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

int requestMedicalSpeciality() {
    int medicalSpeciality;

    do {
        cout << "¿En qué especialidad está registrado?" << endl;
        cout << "[1: Medicina General]" << endl;
        cout << "[2: Otorrinolaringología]" << endl;
        cout << "[3: Pediatría]" << endl;
        cout << "[4: Oftalmología]" << endl;
        cout << "[5: Cardiología]" << endl;
        cout << "[6: Gastroenterología]" << endl;
        cout << "[7: Medicina Interna]" << endl;

        cin >> medicalSpeciality;
    } while (!(1 <= medicalSpeciality && medicalSpeciality <= 7));

    return medicalSpeciality;
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

void swapValue(patient* array, int i, int j) {

    patient temp = array[j];

    array[j] = array[i];
    array[i] = temp;
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

bool patientsArrayIsEmpty(int patientsQuantity) {
    if (!(0 < patientsQuantity)) {
        cout << "No se ha encontrado ningún paciente." << endl;
        return true;
    }
    return false;
}

void orderPatients(patient* patients, int patientsQuantity) {

    int i, j;
    for (i = 0; i < patientsQuantity - 1; i++)
    {
        for (j = 0; j < patientsQuantity - i - 1; j++)
        {
            if (patients[j].payment < patients[j + 1].payment)
            {
                swapValue(patients, j, j + 1);
            }
        }
    }
}

/// <param name="y">y-axis</param>
void showPatientsListHeaders(int y) {

    gotoxy(0, y); cout << "#" << endl;
    gotoxy(5, y); cout << "Apellidos y Nombres" << endl;
    gotoxy(55, y); cout << "Género" << endl;
    gotoxy(65, y); cout << "Edad" << endl;
    gotoxy(75, y); cout << "DNI" << endl;
    gotoxy(85, y); cout << "Pago" << endl;
    gotoxy(95, y); cout << "Especialidad Medica" << endl;
}

/// <param name="y">y-axis</param>
/// <param name="i">soldier index</param>
void showPatientsListElement(int y, patient* patients, int i) {

    gotoxy(0, y); cout << (i + 1) << endl;
    gotoxy(5, y); cout << patients[i].lastName << " " << patients[i].firstName << endl;
    gotoxy(55, y); cout << patients[i].genre << endl;
    gotoxy(65, y); cout << patients[i].age << endl;
    gotoxy(75, y); cout << patients[i].dni << endl;
    gotoxy(85, y); cout << patients[i].payment << endl;
    gotoxy(95, y); cout << getMedicalSpecialityString(patients[i].medicalSpeciality) << endl;
}

string getMedicalSpecialityString(int medicalSpeciality) {

    switch (medicalSpeciality)
    {
    case 1:
        return "Medicina General";
    case 2:
        return "Otorrinolaringología";
    case 3:
        return "Pediatría";
    case 4:
        return "Oftalmología";
    case 5:
        return "Cardiología";
    case 6:
        return "Gastroenterología";
    case 7:
        return "Medicina Interna";

    default:
        return "No Encontrado";;
    }
}