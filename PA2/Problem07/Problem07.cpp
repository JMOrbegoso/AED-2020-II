/*
Una compañía de infantería tiene 100 cantidad de reclutas.
Se desea desarrollar un programa que mediante arreglos se pueda determinar:

- Cuántos infantes son mujeres y cuantos hombres.
- Cuantos son mayores de edad.
- Cuantos son de la ciudad de Lima.
- Mostrar la lista ordenados por nombre
*/

#include <iostream>
#include <string>
#include <windows.h>
#include "Helpers.h"

using namespace std;

// Forward declarations
int getSeletectOption();
void registerSoldier(soldier* soldiers, int& soldiersQuantity);
void showSoldiersByGenre(soldier* soldiers, int soldiersQuantity);
void showSoldiersByAgeStatus(soldier* soldiers, int soldiersQuantity);
void showSoldiersInLimaCity(soldier* soldiers, int soldiersQuantity);
void orderAndShowAllSoldiers(soldier* soldiers, int soldiersQuantity);
void orderSoldiers(soldier* soldiers, int soldiersQuantity);
void mixNames(soldier* soldiers, string* fullNamesArray, int soldiersQuantity);

int main()
{
    int seletectMenuOption;

    soldier soldiers[100];
    int soldiersQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerSoldier(soldiers, soldiersQuantity);
                Sleep(2000);
                break;

            case 2:
                showSoldiersByGenre(soldiers, soldiersQuantity);
                Sleep(2000);
                break;

            case 3:
                showSoldiersByAgeStatus(soldiers, soldiersQuantity);
                Sleep(2000);
                break;

            case 4:
                showSoldiersInLimaCity(soldiers, soldiersQuantity);
                Sleep(2000);
                break;

            case 5:
                orderAndShowAllSoldiers(soldiers, soldiersQuantity);
                system("pause");
                break;

            case 6:
                showProblem();
                Sleep(3000);
                break;

            case 7:
                showCredits();
                Sleep(3000);
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 07" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar infante" << endl;
    cout << "[2] Calcular cuántos infantes son mujeres y cuantos hombres" << endl;
    cout << "[3] Calcular cuántos infantes son mayores de edad" << endl;
    cout << "[4] Calcular cuántos infantes son de la ciudad de Lima" << endl;
    cout << "[5] Mostrar lista de infantes ordenados por nombre" << endl;
    cout << "[6] Ver planteamiento del problema" << endl;
    cout << "[7] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 7)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void registerSoldier(soldier* soldiers, int& soldiersQuantity) {

    system("cls");

    if (soldiersQuantity >= 100) {
        cout << "Ya ingresó 100 infantes, no puede seguir registrando más." << endl;
        Sleep(2000);
        return;
    }

    cout << "\t\tRegistrará un nuevo infante" << endl << endl;

    soldiers[soldiersQuantity].firstName = requestText("¿Cúal es el nombre del infante? (Mínimo 2 letras)");

    soldiers[soldiersQuantity].lastName = requestText("¿Cúal es el apellido del infante? (Mínimo 2 letras)");

    soldiers[soldiersQuantity].city = requestText("¿Cúal es su ciudad de procedencia? (Mínimo 2 letras y solo en minúscula)");

    soldiers[soldiersQuantity].genre = requestGenre();

    soldiers[soldiersQuantity].age = requestAge(15, 60);

    soldiersQuantity++;

    cout << endl << "El infante fue añadido correctamente." << endl;
}

void showSoldiersByGenre(soldier* soldiers, int soldiersQuantity) {
    int womenQuantity = 0;
    int menQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (soldiers[i].genre == 'f') {
            womenQuantity++;
        }
        else {
            menQuantity++;
        }
    }

    cout << "En total de infantes está compuesto de " << womenQuantity << " mujer/es y " << menQuantity << " hombre/s." << endl;
}

void showSoldiersByAgeStatus(soldier* soldiers, int soldiersQuantity) {
    int adultsQuantity = 0;
    int youngsQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (18 <= soldiers[i].age) {
            adultsQuantity++;
        }
    }

    youngsQuantity = soldiersQuantity - adultsQuantity;

    cout << "En total de infantes está compuesto de " << adultsQuantity << " mayores de edad y " << youngsQuantity << " menores de edad." << endl;
}

void showSoldiersInLimaCity(soldier* soldiers, int soldiersQuantity) {
    int soldiersInLimaQuantity = 0;
    int soldiersOutLimaQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (soldiers[i].city == "lima") {
            soldiersInLimaQuantity++;
        }
    }

    soldiersOutLimaQuantity = soldiersQuantity - soldiersInLimaQuantity;

    cout << "En total hay " << soldiersInLimaQuantity << " infantes en Lima, y " << soldiersOutLimaQuantity << " fuera de Lima." << endl;
}

void orderAndShowAllSoldiers(soldier* soldiers, int soldiersQuantity) {

    system("cls");

    if (!(0 < soldiersQuantity)) {
        cout << "No se ha encontrado ningún infante." << endl;
        return;
    }

    orderSoldiers(soldiers, soldiersQuantity);

    // Title
    gotoxy(40, 0); cout << "\t\tRelación ordenada de infantes" << endl;

    // Headers
    gotoxy(0, 2); cout << "#" << endl;
    gotoxy(5, 2); cout << "Apellidos y Nombres" << endl;
    gotoxy(55, 2); cout << "Género" << endl;
    gotoxy(65, 2); cout << "Edad" << endl;
    gotoxy(75, 2); cout << "Ciudad" << endl;

    // Rows
    for (int i = 0; i < soldiersQuantity; i++) {
        gotoxy(0, 4 + i); cout << (i + 1) << endl;
        gotoxy(5, 4 + i); cout << soldiers[i].lastName << " " << soldiers[i].firstName << endl;
        gotoxy(55, 4 + i); cout << soldiers[i].genre << endl;
        gotoxy(65, 4 + i); cout << soldiers[i].age << endl;
        gotoxy(75, 4 + i); cout << soldiers[i].city << endl;
    }
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
/// Mix firstName and lastNames
/// </summary>
void mixNames(soldier* soldiers, string* fullNamesArray, int soldiersQuantity) {
    for (int i = 0; i < soldiersQuantity; i++) {
        fullNamesArray[i] = soldiers[i].lastName + " " + soldiers[i].firstName;
    }
}