// Leer las edades de un conjunto de estudiantes y:
// -> Calcular el promedio de edades
// -> Calcular la edad del mayor
// -> Calcucar la edad del menor
// -> Mostrar cuantos son menores y mayores de edad

#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void requestStudentAge(int* studentsAges, int& studentsQuantity);
void showResults(int* studentsAges, int studentsQuantity);
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    int studentsAges[20];
    int studentsQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                requestStudentAge(studentsAges, studentsQuantity);
                break;

            case 2:
                showResults(studentsAges, studentsQuantity);
                break;

            case 3:
                showProblem();
                break;

            case 4:
                showCredits();
                break;

            default:
                break;
            }

            Sleep(1000);
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 02" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Ingresar edad de estudiante" << endl;
    cout << "[2] Ver resultados" << endl;
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

void requestStudentAge(int* studentsAges, int& studentsQuantity) {
    int studentAge;

    cout << "Introduzca la edad del estudiante [de 5 años a 100 años]:" << endl;
    cin >> studentAge;

    while (!(studentAge > 4)) {
        cout << "Por favor introduzca una edad mayor que 3:";
        cin >> studentAge;
    }

    while (!(studentAge < 101)) {
        cout << "Por favor introduzca una edad menor que 100:";
        cin >> studentAge;
    }

    studentsAges[studentsQuantity] = studentAge;

    studentsQuantity++;
}

void showResults(int* studentsAges, int studentsQuantity) {
    int agesSum = 0;
    int maxAge = 0;
    int minAge = 100;
    int adultsQuantity = 0;
    int youngsQuantity = 0;
    float averageAge;

    for (int i = 0; i < studentsQuantity; i++) {
        agesSum += studentsAges[i];

        if (studentsAges[i] > maxAge) {
            maxAge = studentsAges[i];
        }

        if (studentsAges[i] < minAge) {
            minAge = studentsAges[i];
        }

        if (18 <= studentsAges[i]) {
            adultsQuantity++;
        }
        else {
            youngsQuantity++;
        }
    }

    averageAge = (float)agesSum / (float)studentsQuantity;

    cout << "Tiene " << studentsQuantity << " estudiantes." << endl;
    cout << "El promedio de edades es de: " << averageAge << endl;
    cout << "La edad del mayor es " << maxAge << endl;
    cout << "La edad del menor es " << minAge << endl;
    cout << "Hay " << adultsQuantity << " mayores de edad" << endl;
    cout << "Hay " << youngsQuantity << " menores de edad" << endl;

    system("pause");
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