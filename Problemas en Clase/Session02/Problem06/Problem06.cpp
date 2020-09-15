#include <iostream>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    char postulantFirstName[100];
    char postulantLastName[100];

    unsigned short correctAnswersQuantity;
    unsigned short incorrectAnswersQuantity;
    unsigned short noAnswersQuantity;
    float finalScore; // Puntaje final

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #06" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl;

    cout << "\tPor favor ingrese el nombre del postulante (max. 100 caracteres):";
    cin.getline(postulantFirstName, 100);

    cout << "\tPor favor ingrese el apellido del postulante (max. 100 caracteres):";
    cin.getline(postulantLastName, 100);

    cout << "\tPor favor ingrese la cantidad de respuestas correctas del postulante " << postulantFirstName << " " << postulantLastName << ":";
    cin >> correctAnswersQuantity;

    cout << "\tPor favor ingrese la cantidad de respuestas incorrectas del postulante " << postulantFirstName << " " << postulantLastName << ":";
    cin >> incorrectAnswersQuantity;

    cout << "\tPor favor ingrese la cantidad de respuestas en blanco del postulante " << postulantFirstName << " " << postulantLastName << ":";
    cin >> noAnswersQuantity;

    // Proceso
    finalScore = correctAnswersQuantity * 4 + incorrectAnswersQuantity * -1;

    // Salida de datos
    cout << "El postulante " << postulantFirstName << " " << postulantLastName << " obtuvo un puntaje final de " << finalScore << " por haber respondido " << correctAnswersQuantity <<
        " preguntas correctamente, " << incorrectAnswersQuantity << " preguntas incorrectas, y por haber dejado " << noAnswersQuantity << " preguntas en blanco.";

    return 0;
}