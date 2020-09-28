#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    double elapsedTime1;
    double elapsedTime2;
    double elapsedTime3;
    double elapsedTime4;
    double elapsedTimeSum;
    double elapsedTimeAverage;
    const unsigned short distance = 100;
    float speed1;
    float speed2;
    float speed3;
    float speed4;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #08" << endl;
    cout << "Resuelto por el grupo #03" << endl;

    // Recordatorio: Una bala de 9mm tiene una velocidad promedio de 0.35 m/ms

    cout << "\tPor favor ingrese la velocidad de la bala en el primer disparo (m/ms):";
    cin >> speed1;

    cout << "\tPor favor ingrese la velocidad de la bala en el segundo disparo (m/ms):";
    cin >> speed2;

    cout << "\tPor favor ingrese la velocidad de la bala en el tercer disparo (m/ms):";
    cin >> speed3;

    cout << "\tPor favor ingrese la velocidad de la bala en el cuarto disparo (m/ms):";
    cin >> speed4;

    // Proceso
    // Al tener una distancia tan corta, se ha ignorado la aceleración (gravedad, resistencia del aire)
    // Por lo que se ha considerad usar la formula del MRU (d=v*t)

    elapsedTime1 = distance / speed1;
    elapsedTime2 = distance / speed2;
    elapsedTime3 = distance / speed3;
    elapsedTime4 = distance / speed4;

    elapsedTimeSum = elapsedTime1 + elapsedTime2 + elapsedTime3 + elapsedTime4;
    elapsedTimeAverage = elapsedTimeSum / 4;

    // Salida de datos
    cout << "El primer disparo tuvo una velocidad inicial de " << speed1 << " m/ms, y llegó al objetivo en " << elapsedTime1 << " ms." << endl;
    cout << "El segundo disparo tuvo una velocidad inicial de " << speed2 << " m/ms, y llegó al objetivo en " << elapsedTime2 << " ms." << endl;
    cout << "El tercer disparo tuvo una velocidad inicial de " << speed3 << " m/ms, y llegó al objetivo en " << elapsedTime3 << " ms." << endl;
    cout << "El cuarto disparo tuvo una velocidad inicial de " << speed4 << " m/ms, y llegó al objetivo en " << elapsedTime4 << " ms." << endl;
    cout << "Los tiempos suman en total " << elapsedTimeSum << " ms, teniendo un tiempo promedio de " << elapsedTimeAverage << " ms." << endl;

    return 0;
}