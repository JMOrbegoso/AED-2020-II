#include <windows.h>
#include "BasicasDeEstructuras.h"

using namespace std;

// Declaraciones adelantadas

// Metodos

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