#include <iostream>
#include <windows.h>
#include "basicas.h"
#include "structs.h"

using namespace std;

// Forward declarations
int getSeletectOption();
void registerStudent(student* students, int& studentsQuantity);
void showStudents(student* students, int studentsQuantity);
void showProblem();
void showCredits();

int main()
{
    student students[20];
    int seletectMenuOption;
    int studentsQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerStudent(students, studentsQuantity);
                Sleep(750);
                break;

            case 2:
                showStudents(students, studentsQuantity);
                system("pause");
                break;

            case 3:
                showProblem();
                system("pause");
                break;

            case 4:
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

    cout << "\tBienvenido al Problema 01" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar estudiante" << endl;
    cout << "[2] Mostrar estudiantes" << endl;
    cout << "[3] Ver planteamiento del problema" << endl;
    cout << "[4] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opción deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 4)) {
        cout << "Introdujo una opción incorrecta, por favor seleccione una opción válida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void registerStudent(student* students, int& studentsQuantity) {

    students[studentsQuantity].lastName = requestText("¿Cuál es el apellido del estudiante?");
    students[studentsQuantity].firstName = requestText("¿Cuál es el nombre del estudiante?");
    students[studentsQuantity].genre = requestGenre();
    students[studentsQuantity].age = requestAge(3, 50);
    students[studentsQuantity].score[0] = requestScore("¿Cúal es su primera nota?", 0, 20);
    students[studentsQuantity].score[1] = requestScore("¿Cúal es su segunda nota?", 0, 20);
    students[studentsQuantity].score[2] = requestScore("¿Cúal es su tercera nota?", 0, 20);

    studentsQuantity++;

    cout << "Estudiante registrado correctamente." << endl;
}

void showStudents(student* students, int studentsQuantity) {
    float scoreAverage;

    system("cls");

    if (!(0 < studentsQuantity)) {
        cout << "No se ha encontrado ningún estudiante." << endl;
        return;
    }

    // Title
    gotoxy(40, 0); cout << "\t\tRelación de estudiantes" << endl;

    // Headers
    gotoxy(0, 2); cout << "#" << endl;
    gotoxy(5, 2); cout << "Apellidos y Nombres" << endl;
    gotoxy(55, 2); cout << "Género" << endl;
    gotoxy(65, 2); cout << "Edad" << endl;
    gotoxy(75, 2); cout << "Promedio" << endl;

    // Rows
    for (int i = 0; i < studentsQuantity; i++) {
        gotoxy(0, 4 + i); cout << (i + 1) << endl;
        gotoxy(5, 4 + i); cout << students[i].lastName << " " << students[i].firstName << endl;
        gotoxy(55, 4 + i); cout << students[i].genre << endl;
        gotoxy(65, 4 + i); cout << students[i].age << endl;

        scoreAverage = (students[i].score[0] + students[i].score[1] + students[i].score[2]) / 3;

        gotoxy(75, 4 + i); cout << scoreAverage << endl;
    }
}

void showProblem() {
    cout << "Leer las edades de un conjunto de estudiantes y:" << endl;
    cout << "\t-> Calcular el promedio de edades." << endl;
    cout << "\t-> Calcular la edad del mayor." << endl;
    cout << "\t-> Calcucar la edad del menor." << endl;
    cout << "\t-> Mostrar cuantos son menores y mayores de edad." << endl;

    Sleep(3000);
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;

    Sleep(3000);
}




struct category {
    string name;
};

struct product {
    string code;
    string name;
    string description;
    float price;
    category category;
};