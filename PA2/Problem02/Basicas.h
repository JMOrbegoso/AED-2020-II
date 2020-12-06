#include <iostream>
#include <windows.h>
#include <string>

#define max 30

using namespace std;

void gotoxy(int x, int y);

int menu() {
    system("cls");
    int op;
    gotoxy(25, 5); cout << "MENU DE OPCIONES" << endl;
    gotoxy(25, 6); cout << "================" << endl;
    gotoxy(20, 7); cout << "1. Registrar libro " << endl;
    gotoxy(20, 8); cout << "2. Buscar Libros " << endl;
    gotoxy(20, 9); cout << "3. Ordenar Libros " << endl;
    gotoxy(20, 10); cout << "4. Mostrar libros" << endl;
    gotoxy(20, 11); cout << "5. Salir del programa" << endl;
    do {
        gotoxy(20, 13);
        cout << "Ingrese opcion:";
        cin >> op;
    } while (!(op > 0 && op < 6));
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


