/*
Una clínica guarda los nombres de sus pacientes, su DNI, su edad, la especialidad en que se atiende
(medicina general, otorrinolaringología, pediatría, oftalmología, etc.).

Además, el pago que realiza.

Se debe:
    - Ordena la lista de acuerdo al pago en forma descendente
    - Buscar un paciente
    - Mostrar el total del pago
*/

#include <iostream>
#include <windows.h>
#include "Helpers.h"

using namespace std;

// Forward declarations
int getSeletectOption();
void initialize(patient* patients, int& patientsQuantity);
void registerPatient(patient* patients, int& patientsQuantity);
void orderAndShowAllPatients(patient* patients, int patientsQuantity);
void searchPatientByLastName(patient* patients, int patientsQuantity);
void searchPatientByMedicalSpeciality(patient* patients, int patientsQuantity);
void getTotalPayments(patient* patients, int patientsQuantity);
void showProblem();
void showCredits();

int main()
{
    int seletectMenuOption;

    patient patients[100];
    int patientsQuantity = 0;

    initialize(patients, patientsQuantity);

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerPatient(patients, patientsQuantity);
                Sleep(750);
                break;

            case 2:
                orderAndShowAllPatients(patients, patientsQuantity);
                system("pause");
                break;

            case 3:
                searchPatientByLastName(patients, patientsQuantity);
                system("pause");
                break;

            case 4:
                searchPatientByMedicalSpeciality(patients, patientsQuantity);
                system("pause");
                break;

            case 5:
                getTotalPayments(patients, patientsQuantity);
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

    cout << "\tBienvenido al Problema 08" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar paciente" << endl;
    cout << "[2] Ver la lista de pacientes de acuerdo al pago en forma descendente" << endl;
    cout << "[3] Buscar un paciente por apellidos" << endl;
    cout << "[4] Buscar un paciente por especialidad" << endl;
    cout << "[5] Ver el total de pagos" << endl;
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

void initialize(patient* patients, int& patientsQuantity) {

    patients[0].firstName = "Cristobal";
    patients[0].lastName = "Oliveira";
    patients[0].genre = 'm';
    patients[0].dni = "12569215";
    patients[0].age = 27;
    patients[0].payment = 1000;
    patients[0].medicalSpeciality = 1;

    patients[1].firstName = "Maria";
    patients[1].lastName = "Soledad Perdomo";
    patients[1].genre = 'f';
    patients[1].dni = "23549215";
    patients[1].age = 26;
    patients[1].payment = 1200;
    patients[1].medicalSpeciality = 2;

    patients[2].firstName = "Angela";
    patients[2].lastName = "Guzman";
    patients[2].genre = 'f';
    patients[2].dni = "75773215";
    patients[2].age = 14;
    patients[2].payment = 2000;
    patients[2].medicalSpeciality = 3;

    patients[3].firstName = "Karim ";
    patients[3].lastName = "Fernandez";
    patients[3].genre = 'f';
    patients[3].dni = "77777915";
    patients[3].age = 52;
    patients[3].payment = 1200;
    patients[3].medicalSpeciality = 4;

    patients[4].firstName = "Constantino";
    patients[4].lastName = "Cervantes";
    patients[4].genre = 'm';
    patients[4].dni = "11777915";
    patients[4].age = 17;
    patients[4].payment = 1100;
    patients[4].medicalSpeciality = 1;

    patientsQuantity = 5;
}

void registerPatient(patient* patients, int& patientsQuantity) {

    system("cls");

    cout << "\tRegistrará un nuevo paciente" << endl << endl;

    patients[patientsQuantity].firstName = requestText("¿Cúal es el nombre del paciente?", 2);
    patients[patientsQuantity].lastName = requestText("¿Cúal es el apellido del paciente?", 2);
    patients[patientsQuantity].genre = requestGenre();
    patients[patientsQuantity].dni = requestDNI();
    patients[patientsQuantity].age = requestAge(00);
    patients[patientsQuantity].payment = requestMoney("¿Qué pago le corresponde?", 1);
    patients[patientsQuantity].medicalSpeciality = requestMedicalSpeciality();

    patientsQuantity++;

    cout << endl << "El paciente fue añadido correctamente." << endl;
}

void orderAndShowAllPatients(patient* patients, int patientsQuantity) {

    system("cls");

    if (patientsArrayIsEmpty(patientsQuantity)) {
        return;
    }

    orderPatients(patients, patientsQuantity);

    // Title
    gotoxy(40, 0); cout << "Lista de pacientes de acuerdo al pago en forma descendente" << endl;

    // Headers
    showPatientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < patientsQuantity; i++) {
        showPatientsListElement(4 + row, patients, i);
        row++;
    }

    cout << endl;
}

void searchPatientByLastName(patient* patients, int patientsQuantity) {

    string searchTerm;

    system("cls");

    if (patientsArrayIsEmpty(patientsQuantity)) {
        return;
    }

    searchTerm = requestText("Ingrese el apellido a buscar:", 2);

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de pacientes con un apellido similar a '" << searchTerm << "'" << endl;

    // Headers
    showPatientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < patientsQuantity; i++) {
        if (containsString(patients[i].lastName, searchTerm)) {
            showPatientsListElement(4 + row, patients, i);
            row++;
        }
    }

    cout << endl;
}

void searchPatientByMedicalSpeciality(patient* patients, int patientsQuantity) {

    int medicalSpeciality;

    system("cls");

    if (patientsArrayIsEmpty(patientsQuantity)) {
        return;
    }

    medicalSpeciality = requestMedicalSpeciality();

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Lista de pacientes registrados en la especialidad de '" << getMedicalSpecialityString(medicalSpeciality) << "'" << endl;

    // Headers
    showPatientsListHeaders(2);

    // Rows
    int row = 0;
    for (int i = 0; i < patientsQuantity; i++) {
        if (patients[i].medicalSpeciality == medicalSpeciality) {
            showPatientsListElement(4 + row, patients, i);
            row++;
        }
    }

    cout << endl;
}

void getTotalPayments(patient* patients, int patientsQuantity) {

    float totalPayment = 0;
    float averagePayment;

    system("cls");

    if (patientsArrayIsEmpty(patientsQuantity)) {
        return;
    }

    // Title
    gotoxy(40, 0); cout << "Total de pagos de todos los pacientes" << endl;

    // Body
    for (int i = 0; i < patientsQuantity; i++) {

        totalPayment += patients[i].payment;
    }

    averagePayment = totalPayment / patientsQuantity;

    cout << endl << "El pago total de todos los pacientes es de S/" << totalPayment << ", siendo el pago promedio de S/" << averagePayment << "." << endl;

    cout << endl;
}

void showProblem() {

    system("cls");

    // Title
    gotoxy(40, 0); cout << "Problema 08" << endl;

    // Body
    cout << "Una clínica guarda los nombres de sus pacientes, su DNI, su edad, el pago que realiza y la especialidad en que se atiende" << endl;
    cout << "(medicina general, otorrinolaringología, pediatría, oftalmología, etc.)." << endl;
    cout << "Se debe:" << endl;
    cout << "\t-> Ordena la lista de acuerdo al pago en forma descendente." << endl;
    cout << "\t-> Buscar un paciente." << endl;
    cout << "\t-> Mostrar el total del pago." << endl;
}

void showCredits() {

    system("cls");

    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}