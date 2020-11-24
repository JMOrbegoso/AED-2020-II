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
void showProblem();
void showCredits();

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
                system("pause");
                break;

            case 7:
                showCredits();
                system("pause");
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
    cout << "[7] Ver Créditos" << endl;
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

    soldiers[soldiersQuantity].firstName = requestText("¿Cúal es el nombre del infante?", 2);

    soldiers[soldiersQuantity].lastName = requestText("¿Cúal es el apellido del infante?", 2);

    soldiers[soldiersQuantity].city = requestText("¿Cúal es su ciudad de procedencia? (Solo en minúscula)", 2);

    soldiers[soldiersQuantity].genre = requestGenre();

    soldiers[soldiersQuantity].age = requestAge(15, 60);

    soldiersQuantity++;

    cout << endl << "El infante fue añadido correctamente." << endl;
}

void showSoldiersByGenre(soldier* soldiers, int soldiersQuantity) {
    int womenQuantity = 0;
    int menQuantity = 0;

    system("cls");

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

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

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

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

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

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

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

    orderSoldiers(soldiers, soldiersQuantity);

    // Title
    gotoxy(40, 0); cout << "\t\tRelación ordenada de infantes" << endl;

    // Headers
    showSoldiersListHeaders(2);

    // Rows
    for (int i = 0; i < soldiersQuantity; i++) {
        showSoldiersListElement(4 + i, soldiers, i);
    }
}

void showProblem() {

    system("cls");

    cout << "Una compañía de infantería tiene 100 cantidad de reclutas." << endl;
    cout << "Se desea desarrollar un programa que mediante arreglos se pueda determinar:" << endl;
    cout << "\t-> Cuántos infantes son mujeres y cuantos hombres." << endl;
    cout << "\t-> Cuantos son mayores de edad." << endl;
    cout << "\t-> Cuantos son de la ciudad de Lima." << endl;
    cout << "\t-> Mostrar la lista ordenados por nombre." << endl;
}

void showCredits() {

    system("cls");

    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}