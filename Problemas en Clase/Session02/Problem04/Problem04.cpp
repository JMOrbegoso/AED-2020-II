#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    unsigned short scorePC1;
    unsigned short scorePC2;
    unsigned short scorePC3;
    unsigned short scorePC4;
    unsigned short scoreAV;
    unsigned short scoreIO;
    unsigned short scoreTR;
    unsigned short scoreEXP;
    unsigned short scoreINF;
    float averageScore1;
    float averageScore2;
    float finalAverageScore;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #04" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl;

    cout << "\tPor favor ingrese la nota PC1 (max 20):";
    cin >> scorePC1;

    cout << "\tPor favor ingrese la nota PC2 (max 20):";
    cin >> scorePC2;

    cout << "\tPor favor ingrese la nota PC3 (max 20):";
    cin >> scorePC3;

    cout << "\tPor favor ingrese la nota PC4 (max 20):";
    cin >> scorePC4;

    cout << "\tPor favor ingrese la nota AV (max 20):";
    cin >> scoreAV;

    cout << "\tPor favor ingrese la nota IO (max 20):";
    cin >> scoreIO;

    cout << "\tPor favor ingrese la nota TR (max 20):";
    cin >> scoreTR;

    cout << "\tPor favor ingrese la nota EXP (max 20):";
    cin >> scoreEXP;

    cout << "\tPor favor ingrese la nota INF (max 20):";
    cin >> scoreINF;

    // Proceso
    averageScore1 = (scorePC1 * 3 + scorePC2 * 3 + scoreAV * 2 + scoreIO * 2 + scoreTR) / 11;
    averageScore2 = (scorePC3 * 3 + scorePC4 * 2 + scoreEXP * 3 + scoreINF * 2) / 10;
    finalAverageScore = (averageScore1 + averageScore2) / 2;

    // Salida de datos
    cout << "El alumno tiene un promedio final de " << finalAverageScore << ", obteniendo un promedio de " << averageScore1 << " en la primera unidad, y un promedio de " << averageScore2 << " en la segunda unidad.";

    return 0;
}