#include <iostream>
#include <windows.h>
#include <string>

#define max 30

using namespace std;

void gotoxy(int x, int y);

int menu() {
    system("cls");
    int op;
    gotoxy(35, 5); cout << "MENU DE OPCIONES" << endl;
    gotoxy(35, 6); cout << "================" << endl;
    gotoxy(32, 7); cout << "1. Registrar datos " << endl;
    gotoxy(32, 8); cout << "2. Mostrar datos " << endl;
    gotoxy(32, 9); cout << "3. Buscar por telefono " << endl;
    gotoxy(32, 10); cout << "4. Buscar por apellido" << endl;
    gotoxy(32, 11); cout << "5. Buscar por direccion" << endl;
    gotoxy(32, 12); cout << "6 Orden por edad" << endl;
    gotoxy(32, 13); cout << "7. Salir del programa" << endl;
    do {
        gotoxy(32, 14);
        cout << "Ingrese opcion:";
        cin >> op;
    } while (!(op > 0 && op < 8));
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

string leerTexto(string mensaje) {
    string valor;
    cout << mensaje << ":";
    fflush(stdin);
    getline(cin, valor);
    return valor;
}