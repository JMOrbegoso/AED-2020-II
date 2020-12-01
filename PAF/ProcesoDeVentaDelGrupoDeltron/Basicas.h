#include <windows.h>
#include <algorithm>
#include "BasicasDeEstructuras.h"

using namespace std;

void esperarMostrandoTexto(string mensaje) {

    cout << mensaje << " ";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
}

void mostrarAppTitulo() {

    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
    cout << endl << "\t\t\tSistema del Grupo Deltron S.A." << endl;
    cout << endl << "--------------------------------------------------------------------------------------------" << endl;
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

string pedirTexto(string mensaje, int minimoDeCaracteres) {
    string texto;

    cout << mensaje << " (Mínimo " << minimoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length()));

    return texto;
}

string pedirTexto(string mensaje, int minimoDeCaracteres, int maximoDeCaracteres) {
    string texto;

    cout << mensaje << " (Mínimo " << minimoDeCaracteres << " y máximo " << maximoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length() && texto.length() <= maximoDeCaracteres));

    return texto;
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

int pedirEdad(int edadMinima, int edadMaxima) {
    int edad;

    cout << "¿Qué edad tiene (Mínimo " << edadMinima << " años y máximo " << edadMaxima << ")?" << endl;
    cin >> edad;

    while (!(edadMinima <= edad && edad <= edadMaxima)) {
        cout << "Por favor, ingrese una edad mínima de " << edadMinima << " años y máxima de " << edadMaxima << "." << endl;
        fflush(stdin);
        cin >> edad;
    }

    return edad;
}

string pedirDNI() {
    string dni;

    dni = pedirTexto("¿Cúal es su DNI?", 8, 8);

    return dni;
}

string pedirRUC() {
    string dni;

    dni = pedirTexto("¿Cúal es el RUC?", 11, 11);

    return dni;
}

float pedirDinero(string mensaje, int montoMinimo) {
    float monto;

    cout << mensaje << "(Mínimo S/" << montoMinimo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << montoMinimo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

float pedirDinero(string mensaje, int montoMinimo, int montoMaximo) {
    float monto;

    cout << mensaje << "(Mínimo S/" << montoMinimo << " y máximo S/" << montoMaximo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto && monto <= montoMaximo)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << montoMinimo << " y máxima de S/" << montoMaximo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

string convertirEnMinusculas(string texto) {
    for_each(texto.begin(), texto.end(), [](char& c) {
        c = ::tolower(c);
    });

    return texto;
}

bool contieneTexto(string textoBase, string textoPorBuscar) {
    if (convertirEnMinusculas(textoBase).find(convertirEnMinusculas(textoPorBuscar), 0) != string::npos) {
        return true;
    }
    return false;
}