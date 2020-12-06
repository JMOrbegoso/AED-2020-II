#include <iostream>
#include <windows.h>
#include <string>

#define max 50

using namespace std;

void gotoxy(int x, int y);

int leerEntero(string mensaje, int y) {
    int x;
    do {
        cout << mensaje << y << ":";
        cin >> x;
    } while (!(x > 0 && x <= 100));
    return x;
}

int menu() {
    int op;
    system("cls");
    gotoxy(35, 5);  cout << "MENU DE OPCIONES" << endl;
    gotoxy(35, 6);  cout << "================" << endl;
    gotoxy(32, 7);  cout << "1. Registrar persona" << endl;
    gotoxy(32, 8);  cout << "2. Buscar una persona" << endl;
    gotoxy(32, 9);  cout << "3. Mostrar la lista" << endl;
    gotoxy(32, 10); cout << "4. Salir del programa" << endl;
    do {
        gotoxy(32, 12);
        cout << "Ingrese opcion:";
        cin >> op;
    } while (!(op > 0 && op < 5));
    return op;
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

string leerTexto(string mensaje, int minLength)
{
    string text;

    cout << mensaje << " (Mínimo " << minLength << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(minLength <= text.length()));

    return text;
}

char pedirGenero() {
    char genero;

    cout << "¿Es de genero masculino (m) o femenino (f)?" << endl;
    cin >> genero;

    while (!(genero == 'm' || genero == 'f')) {
        cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
        fflush(stdin);
        cin >> genero;
    }

    return genero;
}

int pedirEdad(int edadMinima) {
    int edad;

    cout << "¿Qué edad tiene (Mínimo " << edadMinima << " años)?" << endl;
    cin >> edad;

    while (!(edadMinima <= edad)) {
        cout << "Por favor, ingrese una edad mínima de " << edadMinima << " años." << endl;
        fflush(stdin);
        cin >> edad;
    }

    return edad;
}