#include <iostream>
#include <string>
#include <windows.h>
#include "Structs.h"

using namespace std;

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

    cout << "�Es de genero masculino (m) o femenino (f)?" << endl;
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

    cout << "�Qu� edad tiene (M�nimo " << minAge << " a�os y m�ximo " << maxAge << ")?" << endl;
    cin >> age;

    while (!(minAge <= age && age <= maxAge)) {
        cout << "Por favor, ingrese una edad m�nima de " << minAge << " a�os y m�xima de " << maxAge << "." << endl;
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
        cout << "No se ha encontrado ning�n infante." << endl;
        return true;
    }
    return false;
}