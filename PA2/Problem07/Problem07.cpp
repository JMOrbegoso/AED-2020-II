/*
Una compa��a de infanter�a tiene 100 cantidad de reclutas.
Se desea desarrollar un programa que mediante arreglos se pueda determinar:

- Cu�ntos infantes son mujeres y cuantos hombres.
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
void initialize(soldier* soldiers, int& soldiersQuantity);
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

    initialize(soldiers, soldiersQuantity);

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerSoldier(soldiers, soldiersQuantity);
                Sleep(750);
                break;

            case 2:
                showSoldiersByGenre(soldiers, soldiersQuantity);
                system("pause");
                break;

            case 3:
                showSoldiersByAgeStatus(soldiers, soldiersQuantity);
                system("pause");
                break;

            case 4:
                showSoldiersInLimaCity(soldiers, soldiersQuantity);
                system("pause");
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
    cout << "[2] Calcular cu�ntos infantes son mujeres y cuantos hombres" << endl;
    cout << "[3] Calcular cu�ntos infantes son mayores de edad" << endl;
    cout << "[4] Calcular cu�ntos infantes son de la ciudad de Lima" << endl;
    cout << "[5] Mostrar lista de infantes ordenados por nombre" << endl;
    cout << "[6] Ver planteamiento del problema" << endl;
    cout << "[7] Ver Cr�ditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 7)) {
        cout << "Introdujo una opci�n incorrecta, por favor seleccione una opci�n v�lida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void initialize(soldier* soldiers, int& soldiersQuantity) {

    soldiers[0].firstName = "Cristobal";
    soldiers[0].lastName = "Oliveira";
    soldiers[0].genre = 'm';
    soldiers[0].city = "Lima";
    soldiers[0].age = 27;

    soldiers[1].firstName = "Maria";
    soldiers[1].lastName = "Soledad Perdomo";
    soldiers[1].genre = 'f';
    soldiers[1].city = "Trujillo";
    soldiers[1].age = 26;

    soldiers[2].firstName = "Angela";
    soldiers[2].lastName = "Guzman";
    soldiers[2].genre = 'f';
    soldiers[2].city = "Chiclayo";
    soldiers[2].age = 14;

    soldiers[3].firstName = "Karim ";
    soldiers[3].lastName = "Fernandez";
    soldiers[3].genre = 'f';
    soldiers[3].city = "Lima";
    soldiers[3].age = 52;

    soldiers[4].firstName = "Constantino";
    soldiers[4].lastName = "Cervantes";
    soldiers[4].genre = 'm';
    soldiers[4].city = "Cuzco";
    soldiers[4].age = 17;

    soldiersQuantity = 5;
}

void registerSoldier(soldier* soldiers, int& soldiersQuantity) {

    system("cls");

    if (soldiersQuantity >= 100) {
        cout << "Ya ingres� 100 infantes, no puede seguir registrando m�s." << endl;
        Sleep(2000);
        return;
    }

    cout << "\tRegistrar� un nuevo infante" << endl << endl;

    soldiers[soldiersQuantity].firstName = requestText("�C�al es el nombre del infante?", 2);

    soldiers[soldiersQuantity].lastName = requestText("�C�al es el apellido del infante?", 2);

    soldiers[soldiersQuantity].city = requestText("�C�al es su ciudad de procedencia?", 2);

    soldiers[soldiersQuantity].genre = requestGenre();

    soldiers[soldiersQuantity].age = requestAge(15, 60);

    soldiersQuantity++;

    cout << endl << "El infante fue a�adido correctamente." << endl;
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

    cout << "En total de infantes est� compuesto de " << womenQuantity << " mujer/es y " << menQuantity << " hombre/s." << endl;
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

    cout << "En total de infantes est� compuesto de " << adultsQuantity << " mayores de edad y " << youngsQuantity << " menores de edad." << endl;
}

void showSoldiersInLimaCity(soldier* soldiers, int soldiersQuantity) {
    int soldiersInLimaQuantity = 0;
    int soldiersOutLimaQuantity = 0;

    system("cls");

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

    // Title
    gotoxy(30, 0); cout << "Relaci�n de infantes de la ciudad de Lima" << endl;

    // Headers
    showSoldiersListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < soldiersQuantity; i++) {
        if (containsString(soldiers[i].city, "lima")) {
            showSoldiersListElement(4 + row, soldiers, i);
            soldiersInLimaQuantity++;
            row++;
        }
    }

    soldiersOutLimaQuantity = soldiersQuantity - soldiersInLimaQuantity;

    cout << endl << "En total hay " << soldiersInLimaQuantity << " infantes en Lima, y " << soldiersOutLimaQuantity << " fuera de Lima." << endl << endl;
}

void orderAndShowAllSoldiers(soldier* soldiers, int soldiersQuantity) {

    system("cls");

    if (soldiersArrayIsEmpty(soldiersQuantity)) {
        return;
    }

    orderSoldiers(soldiers, soldiersQuantity);

    // Title
    gotoxy(30, 0); cout << "Relaci�n ordenada de infantes" << endl;

    // Headers
    showSoldiersListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < soldiersQuantity; i++) {
        showSoldiersListElement(4 + row, soldiers, i);
        row++;
    }
}

void showProblem() {

    system("cls");

    // Title
    gotoxy(30, 0); cout << "Problema 07" << endl;

    // Body
    cout << "Una compa��a de infanter�a tiene 100 cantidad de reclutas." << endl;
    cout << "Se desea desarrollar un programa que mediante arreglos se pueda determinar:" << endl;
    cout << "\t-> Cu�ntos infantes son mujeres y cuantos hombres." << endl;
    cout << "\t-> Cuantos son mayores de edad." << endl;
    cout << "\t-> Cuantos son de la ciudad de Lima." << endl;
    cout << "\t-> Mostrar la lista ordenados por nombre." << endl;
}

void showCredits() {

    system("cls");

    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}