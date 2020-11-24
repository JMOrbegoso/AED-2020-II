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
char requestGenre();
int requestAge(int minAge, int maxAge);
void swapValue(string* array, int i, int j);
void swapValue(soldier* array, int i, int j);
bool soldiersArrayIsEmpty(int soldiersQuantity);
void orderSoldiers(soldier* soldiers, int soldiersQuantity);
void mixNames(soldier* soldiers, string* fullNamesArray, int soldiersQuantity);
string toLowerCase(string text);
bool containsString(string base, string toSearch);
void showSoldiersListHeaders(int y);
void showSoldiersListElement(int y, soldier* soldiers, int i);

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

void swapValue(string* array, int i, int j) {

    string temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void swapValue(soldier* array, int i, int j) {

    soldier temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

bool soldiersArrayIsEmpty(int soldiersQuantity) {
    if (!(0 < soldiersQuantity)) {
        cout << "No se ha encontrado ningún infante." << endl;
        return true;
    }
    return false;
}

void orderSoldiers(soldier* soldiers, int soldiersQuantity) {

    string fullNamesArray[100];
    mixNames(soldiers, fullNamesArray, soldiersQuantity);

    int i, j;
    for (i = 0; i < soldiersQuantity - 1; i++)
    {
        for (j = 0; j < soldiersQuantity - i - 1; j++)
        {
            if (fullNamesArray[j] > fullNamesArray[j + 1])
            {
                swapValue(fullNamesArray, j, j + 1);

                swapValue(soldiers, j, j + 1);
            }
        }
    }
}

/// <summary>
/// Mix firstName and lastNames and save it in a string array called "fullNamesArray"
/// </summary>
void mixNames(soldier* soldiers, string* fullNamesArray, int soldiersQuantity) {
    for (int i = 0; i < soldiersQuantity; i++) {
        fullNamesArray[i] = soldiers[i].lastName + " " + soldiers[i].firstName;
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
void showSoldiersListHeaders(int y) {

    gotoxy(0, y); cout << "#" << endl;
    gotoxy(5, y); cout << "Apellidos y Nombres" << endl;
    gotoxy(55, y); cout << "Género" << endl;
    gotoxy(65, y); cout << "Edad" << endl;
    gotoxy(75, y); cout << "Ciudad" << endl;
}

/// <param name="y">y-axis</param>
/// <param name="i">soldier index</param>
void showSoldiersListElement(int y, soldier* soldiers, int i) {

    gotoxy(0, y); cout << (i + 1) << endl;
    gotoxy(5, y); cout << soldiers[i].lastName << " " << soldiers[i].firstName << endl;
    gotoxy(55, y); cout << soldiers[i].genre << endl;
    gotoxy(65, y); cout << soldiers[i].age << endl;
    gotoxy(75, y); cout << soldiers[i].city << endl;
}