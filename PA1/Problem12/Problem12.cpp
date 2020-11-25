#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char firstName[100];
    char lastName[100];
    char career[100];
    unsigned short minimumPassScore, score;
    const unsigned short baseCost = 300;
    unsigned short accumulatedScore = 0;
    unsigned short failsQuantity = 0;
    float netAmount, averageScore;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #12" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl << endl;

    cout << "Por favor ingrese el nombre del alumno (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(firstName, 100);

    cout << "Por favor ingrese el apellido del alumno (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(lastName, 100);

    cout << "Por favor ingrese la carrera profesional del alumno (max. 100 caracteres): ";
    fflush(stdin);
    cin.getline(career, 100);

    cout << "Por favor ingrese la nota mínima aprobatoria:";
    cin >> minimumPassScore;

    cout << "Por favor ingrese la nota de su primer examen:";
    cin >> score;
    accumulatedScore += score;
    if (score < minimumPassScore) {
        failsQuantity++;
    }

    cout << "Por favor ingrese la nota de su segundo examen:";
    cin >> score;
    accumulatedScore += score;
    if (score < minimumPassScore) {
        failsQuantity++;
    }

    cout << "Por favor ingrese la nota de su tercer examen:";
    cin >> score;
    accumulatedScore += score;
    if (score < minimumPassScore) {
        failsQuantity++;
    }

    cout << "Por favor ingrese la nota de su cuarto examen:";
    cin >> score;
    accumulatedScore += score;
    if (score < minimumPassScore) {
        failsQuantity++;
    }

    cout << "Por favor ingrese la nota de su quinto examen:";
    cin >> score;
    accumulatedScore += score;
    if (score < minimumPassScore) {
        failsQuantity++;
    }

    // Se limpia la pantalla
    system("cls");
    averageScore = accumulatedScore / 5;

    switch (failsQuantity)
    {
    case 0:
        netAmount = baseCost - baseCost * 10 / 100;
        break;

    case 1:
        netAmount = baseCost + 50;
        break;

    case 2:
        netAmount = baseCost + 80;
        break;

    case 3:
        netAmount = baseCost + 120;
        break;

    case 4:
        netAmount = baseCost + 180;
        break;

    case 5:
        netAmount = baseCost + 250;
        break;

    default:
        break;
    }

    // Datos de salida

    cout << "Al estudiante " << lastName << " " << firstName << " de la carrera de " << career << " le corresponde un costo de matricula de S/" << netAmount << "." << endl;
    cout << "Obtuvo una nota promedio de " << averageScore << "." << endl;

    Sleep(1000);

    if (failsQuantity == 0) {
        cout << "Habiendo aprobado todos sus curso.";
    }
    else if (failsQuantity == 1) {
        cout << "Habiendo desaprobado " << failsQuantity << " curso.";
    }
    else if (failsQuantity == 5) {
        cout << "Habiendo desaprobado todos sus cursos.";
    }
    else {
        cout << "Habiendo desaprobado " << failsQuantity << " cursos.";
    }

    cout << endl;

    system("pause");

    return 0;
}