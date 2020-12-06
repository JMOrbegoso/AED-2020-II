#include <iostream>
#include "Estructuras.h"

using namespace std;

void inicializar(persona personas[max], int& nP);
void registrarPersona(persona personas[max], int& nP);
void buscarPersona(persona personas[max], int nP);
void mostrarPersonas(persona personas[max], int nP);

int main()
{
    persona personas[max];
    int nP = 0;  // numero de personas 

    inicializar(personas, nP);

    int opc;
    do {
        opc = menu();
        switch (opc) {
        case 1:
            registrarPersona(personas, nP);
            break;
        case 2:
            buscarPersona(personas, nP);
            system("pause");
            break;
        case 3:
            mostrarPersonas(personas, nP);
            break;
        }
    } while (!(opc == 4));

    return 0;
}

void inicializar(persona personas[max], int& nP) {
    personas[0].nombre = "Maria Rosalia";
    personas[0].apellido = "Sanchez Suarez";
    personas[0].sexo = "Mujer";
    personas[0].edad = 18;
    personas[0].peso = "55";
    personas[0].colorPelo = "Marron";
    personas[0].colorPiel = "Trigeña";
    personas[0].colorOjos = "Marrones";
    personas[0].nacionalidad = "Peruana";
    personas[0].telefono = "986745321";

    personas[1].nombre = "Julio Cesar";
    personas[1].apellido = "Purihuaman Manayalle";
    personas[1].sexo = "Varon";
    personas[1].edad = 18;
    personas[1].peso = "59";
    personas[1].colorPelo = "Rubio";
    personas[1].colorPiel = "Blanco";
    personas[1].colorOjos = "Verdes";
    personas[1].nacionalidad = "Argentino";
    personas[1].telefono = "914325678";

    personas[2].nombre = "Monika Jubitza";
    personas[2].apellido = "Salazar Saazar";
    personas[2].sexo = "Mujer";
    personas[2].edad = 15;
    personas[2].peso = "49";
    personas[2].colorPelo = "Marron";
    personas[2].colorPiel = "Blanca";
    personas[2].colorOjos = "Marrones";
    personas[2].nacionalidad = "Peruana";
    personas[2].telefono = "998765122";

    personas[3].nombre = "Heidi Danna";
    personas[3].apellido = "Tenorio Leonardo";
    personas[3].sexo = "Mujer";
    personas[3].edad = 25;
    personas[3].peso = "56";
    personas[3].colorPelo = "Negro";
    personas[3].colorPiel = "Morena";
    personas[3].colorOjos = "Negro";
    personas[3].nacionalidad = "Peruana";
    personas[3].telefono = "979568412";

    personas[4].nombre = "Juan Carlos";
    personas[4].apellido = "Soriano Sigueñas";
    personas[4].sexo = "Varon";
    personas[4].edad = 23;
    personas[4].peso = "60";
    personas[4].colorPelo = "Negro";
    personas[4].colorPiel = "Blanco";
    personas[4].colorOjos = "Marrones";
    personas[4].nacionalidad = "Chino";
    personas[4].telefono = "9134256779";

    nP = 5;
}

void registrarPersona(persona personas[max], int& nP)
{
    system("cls");

    if (nP < max) {
        gotoxy(35, 5); personas[nP].nombre = leerTexto("Ingrese el nombre:", 3);
        gotoxy(36, 6); personas[nP].apellido = leerTexto("Ingrese el apellido: ", 3);
        gotoxy(37, 7); personas[nP].sexo = pedirGenero();
        gotoxy(38, 8); personas[nP].edad = pedirEdad(0);
        gotoxy(39, 9); personas[nP].peso = leerTexto("Ingrese el peso:", 0);
        gotoxy(40, 10); personas[nP].colorPelo = leerTexto("Ingrese el color de pelo:", 1);
        gotoxy(41, 11); personas[nP].colorPiel = leerTexto("Ingrese el color de piel:", 1);
        gotoxy(42, 12); personas[nP].colorOjos = leerTexto("Ingrese el color de ojos:", 1);
        gotoxy(43, 13); personas[nP].nacionalidad = leerTexto("Ingrese la nacionalidad:", 1);
        gotoxy(44, 14); personas[nP].telefono = leerTexto("Ingrese el telefono:", 9);
        nP++;
    }
    else {
        gotoxy(35, 16); cout << "Caracteristicas de personas Completos";
        Sleep(2000);
    }
}

bool encontroTexto(string base, string terminoDeBusqueda) {
    if (base.find(terminoDeBusqueda, 0) != string::npos) {
        return true;
    }
    return false;
}

void buscarPersona(persona personas[max], int nP) {
    int similares = 0;

    system("cls");

    string terminoDeBusqueda;
    terminoDeBusqueda = leerTexto("Ingrese el nombre de la persona a buscar", 3);

    for (int i = 0; i < nP; i++) {
        if (encontroTexto(personas[i].nombre, terminoDeBusqueda))
        {
            cout << personas[i].nombre << "caracteristicas: Ojos:" << personas[i].colorOjos << " Pelo: " << personas[i].colorPelo;
            similares++;
        }
    }

    if (similares == 0) {
        cout << "No se encontró ninguno.";
    }
}

void mostrarPersonas(persona personas[max], int nP) {
    system("cls");
    int fila = 0;
    for (int y = 0; y < nP; y++)
    {
        gotoxy(5, 5 + fila); cout << "Nombre  : " << personas[y].nombre;
        gotoxy(15, 5 + fila); cout << "Apellido: " << personas[y].apellido;
        gotoxy(25, 5 + fila); cout << "Sexo: " << personas[y].sexo;
        gotoxy(35, 5 + fila); cout << "Edad:" << personas[y].edad;
        gotoxy(45, 5 + fila); cout << "Peso:" << personas[y].peso;
        gotoxy(55, 5 + fila); cout << "Color de Pelo:" << personas[y].colorPelo;
        gotoxy(65, 5 + fila); cout << "Color de Piel:" << personas[y].colorPiel;
        gotoxy(75, 5 + fila); cout << "Color de Ojos:" << personas[y].colorOjos;
        gotoxy(85, 5 + fila); cout << "Nacionalidad:" << personas[y].nacionalidad;
        gotoxy(95, 5 + fila); cout << "Telefono:" << personas[y].telefono;
        fila++;
        Sleep(500);
    }
    system("pause");
}
