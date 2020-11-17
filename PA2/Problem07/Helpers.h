#include <iostream>
#include <string>
#include <windows.h>

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

    string text = array[j];

    array[j] = array[i];
    array[i] = text;
}

void swapValue(char* array, int i, int j) {

    char character = array[j];

    array[j] = array[i];
    array[i] = character;
}

void swapValue(int* array, int i, int j) {

    int number = array[j];

    array[j] = array[i];
    array[i] = number;
}

void showProblem() {
    cout << "Una compañía de infantería tiene 100 cantidad de reclutas." << endl;
    cout << "Se desea desarrollar un programa que mediante arreglos se pueda determinar:" << endl;
    cout << "\t-> Cuántos infantes son mujeres y cuantos hombres." << endl;
    cout << "\t-> Cuantos son mayores de edad." << endl;
    cout << "\t-> Cuantos son de la ciudad de Lima." << endl;
    cout << "\t-> Mostrar la lista ordenados por nombre." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}