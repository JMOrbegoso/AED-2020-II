#include <iostream>
#include <string>
#include <windows.h>
#include "Structs.h"

using namespace std;

// Forward declarations
void gotoxy(int x, int y);
string requestText(string message);
char requestGenre();
int requestAge(int minAge, int maxAge);
void swapValue(string* array, int i, int j);
void swapValue(char* array, int i, int j);
void swapValue(int* array, int i, int j);
void swapValue(soldier* array, int i, int j);
bool soldiersArrayIsEmpty(int soldiersQuantity);
void orderSoldiers(soldier* soldiers, int soldiersQuantity);
void mixNames(soldier* soldiers, string* fullNamesArray, int soldiersQuantity);

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

string requestText(string message) {
    string text;

    cout << message << ":" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(2 <= text.length()));

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

void swapValue(char* array, int i, int j) {

    char temp = array[j];

    array[j] = array[i];
    array[i] = temp;
}

void swapValue(int* array, int i, int j) {

    int temp = array[j];

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