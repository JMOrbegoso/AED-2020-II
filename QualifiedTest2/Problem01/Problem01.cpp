// En una competencia de 100 metros participan 11 corredores.
// De ellos se debe registrar el tiempo en segundos que utiliza en recorrer la distancia.
// Se pide realizar un programa que haga uso de bucles y que calcule :
// -El tiempo menor
// -El tiempo mayor
// -El tiempo promedio
// -Cuantos superaron los 10 segundos

#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void introduceRunnerData(float* runnerTimes, int& runnersQuantity);
void showResults(float* runnerTimes, int runnersQuantity);
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;
    float runnerTimes[12]; // En segundos, se usa float debido a que en las carreras importan tambien los decimales (milisegundos)
    int runnersQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                introduceRunnerData(runnerTimes, runnersQuantity);
                break;

            case 2:
                showResults(runnerTimes, runnersQuantity);
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

    cout << "\tBienvenido al Problema 01 de la Práctica Calificada" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Ingresar datos de los corredores" << endl;
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

void introduceRunnerData(float* runnerTimes, int& runnersQuantity) {
    float runnerTime;

    if (runnersQuantity >= 11) {
        cout << "Ya introdujo los datos de los 11 corredores, no puede seguir agregando más." << endl;
        return;
    }

    do {
        cout << "Introduzca el tiempo que tardó el corredor #" << (runnersQuantity + 1) << " en atravesar los 100m (en segundos):" << endl;
        cin >> runnerTime;
    } while (!(runnerTime > 0));

    runnerTimes[runnersQuantity] = runnerTime;

    runnersQuantity++;
}

void showResults(float* runnerTimes, int runnersQuantity) {
    float timesSum = 0;
    float maxTime = 0;
    float minTime = 1000000;
    float averageTime;
    int tookMoreThan10SecsQuantity = 0;

    cout << "------------------RESULTADOS ACTUALES DE LA CARRERA------------------" << endl;
    cout << "Participaron " << runnersQuantity << " corredores en la carrera de 100m." << endl;

    for (int i = 0; i < runnersQuantity; i++) {
        timesSum += runnerTimes[i];

        if (runnerTimes[i] > maxTime) {
            maxTime = runnerTimes[i];
        }

        if (runnerTimes[i] < minTime) {
            minTime = runnerTimes[i];
        }

        if (10 <= runnerTimes[i]) {
            tookMoreThan10SecsQuantity++;
        }

        cout << "El corredor #" << (i + 1) << " demoró " << runnerTimes[i] << " segundos en atravesar los 100m." << endl;
    }

    if (runnersQuantity == 0) {
        averageTime = 0;
        minTime = 0;
    }
    else {
        averageTime = (float)timesSum / (float)runnersQuantity;
    }

    cout << endl << "-------------------------------------------------------------------" << endl << endl;
    cout << "El más rápido demoró " << minTime << " segundos en atravesar los 100m." << endl;
    cout << "El más lento demoró " << maxTime << " segundos en atravesar los 100m." << endl;
    cout << "El promedio de los tiempos de llegada es de: " << averageTime << " segundos." << endl;
    cout << "Hay " << tookMoreThan10SecsQuantity << " corredores que tardaron más de 10 segundos en atravesar los 100m." << endl;

    system("pause");
}

void showProblem() {
    cout << "En una competencia de 100 metros participan 11 corredores." << endl;
    cout << "De ellos se debe registrar el tiempo en segundos que utiliza en recorrer la distancia." << endl;
    cout << "Se pide realizar un programa que haga uso de bucles y que calcule:" << endl;
    cout << "\t-> El tiempo menor" << endl;
    cout << "\t-> El tiempo mayor" << endl;
    cout << "\t-> El tiempo promedio" << endl;
    cout << "\t-> Cuantos superaron los 10 segundos" << endl;

    Sleep(3000);
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;

    Sleep(3000);
}