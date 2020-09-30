#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables y constantes

    char nombre[50];
    char carrera[50];
    char colegio;
    unsigned short rpcorrectas, rpincorrectas, rpenblanco;
    float puntaje;

    // Ingreso de Datos

    cout << "Ingrese nombre completo: ";
    fflush(stdin);
    cin.getline(nombre, 50);

    cout << "Ingrese su carrera profesional: ";
    fflush(stdin);
    cin.getline(carrera, 50);

    cout << "Ingrese numero de respuestas correctas: ";
    cin >> rpcorrectas;

    cout << "Ingrese numero de respuestas incorrectas: ";
    cin >> rpincorrectas;

    cout << "Ingrese numero de respuestas en blanco: ";
    cin >> rpenblanco;

    cout << "Ingrese el tipo de su colegio de procedencia [n: Nacional, p: Privado]: ";
    fflush(stdin);
    cin >> colegio;

    // Proceso

    puntaje = rpcorrectas * 4 - rpincorrectas * 1.5 - rpenblanco;

    if (colegio == 'n') {
        puntaje = puntaje + 5;
    }

    system("cls"); // Limpia la pantalla

    cout << "el postulante: " << nombre << "de la carrera de: " << carrera << "obtuvo un puntaje total de: " << puntaje << endl;

    system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

    return 0;
}