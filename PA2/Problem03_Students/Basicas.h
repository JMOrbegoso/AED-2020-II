#include <iostream>
#include <windows.h>
#include <string>

#define max 10
#define maxPracticas 3
#define maxExamenes 2
#define maxNotas 7

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
    gotoxy(35, 5);  cout << "REGISTRO DE ESCUELA MASTER ACADEMICO" << endl;
    gotoxy(35, 6);  cout << "================" << endl;
    gotoxy(32, 7);  cout << "1. Registrar estudiantes" << endl;
    gotoxy(32, 8);  cout << "2. Mostrar estudiantes" << endl;
    gotoxy(32, 9);  cout << "4. Ordenar Listas de Promedios" << endl;
    gotoxy(32, 10);  cout << "3. Calcular Promedio" << endl;
    gotoxy(32, 11); cout << "5. Salir del programa" << endl;
    do {
        gotoxy(32, 12);
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
    cout << mensaje;
    fflush(stdin);
    getline(cin, valor);
    return valor;
}