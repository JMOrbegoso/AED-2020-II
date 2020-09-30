#include <iostream>

using namespace std;

int main()
{
    //Declaracion de variables
    char nombre[50];
    float nota;
    unsigned short educaciontipo;

    //Entrada de datos
    cout << "\t\t Sistema de calificacion peruano (Minedu 2020)" << endl << endl;
    cout << "ingrese su nombre completo:";
    fflush(stdin);
    cin.getline(nombre, 50);

    cout << "\t\t\t" << endl;
    cout << "Por favor introduzca el tipo de educacion al que pertenece:" << endl;
    cout << "0: Educación Básica Inicial" << endl;
    cout << "1: Educación Básica Primaría" << endl;
    cout << "2:Educación Secundaria" << endl;
    cin >> educaciontipo;

    cout << "Por favor introduzca su nota (max. 100):" << endl;
    cin >> nota;

    // Proceso

    system("cls"); // Limpia la pantalla de la consola

    if (nota < 0 || nota > 100) {
        cout << "\tTiene una nota inválida, por favor intente de nuevo." << endl;
        return 0;
    }

    switch (educaciontipo)
    {
    case 0:
        cout << "el docente: " << nombre << endl;
        cout << "pertenece a la educacion basica inicial" << endl;

        if (90 <= nota && nota <= 100) {
            cout << "\tTiene una nota de A." << endl;
        }
        else if (nota < 90 && nota >= 75) {
            cout << "\tTiene una nota de B." << endl;
        }
        else if (nota < 75 && nota >= 60) {
            cout << "\tTiene una nota de C." << endl;
        }
        else if (nota < 60 && nota >= 50) {
            cout << "\tTiene una nota de D." << endl;
        }
        else if (nota < 50) {
            cout << "\tTiene una nota de E." << endl;
        }
        else {
            cout << "\tTiene una nota inválida." << endl;
        }
        break;
    case 1:
        cout << "el docente: " << nombre << endl;
        cout << "pertenece a la educacion basica primaria" << endl;

        if (95 <= nota && nota <= 100) {
            cout << "\tTiene una nota de A." << endl;
        }
        else if (nota < 95 && nota >= 80) {
            cout << "\tTiene una nota de B." << endl;
        }
        else if (nota < 80 && nota >= 65) {
            cout << "\tTiene una nota de C." << endl;
        }
        else if (nota < 65 && nota >= 55) {
            cout << "\tTiene una nota de D." << endl;
        }
        else if (nota < 55) {
            cout << "\tTiene una nota de E." << endl;
        }
        else {
            cout << "\tTiene una nota inválida." << endl;
        }
        break;
    case 2:
        cout << "el docente: " << nombre << endl;
        cout << "pertenece a la educacion secundaria" << endl;

        if (98 <= nota && nota <= 100) {
            cout << "\tTiene una nota de A." << endl;
        }
        else if (nota < 98 && nota >= 85) {
            cout << "\tTiene una nota de B." << endl;
        }
        else if (nota < 85 && nota >= 70) {
            cout << "\tTiene una nota de C." << endl;
        }
        else if (nota < 70 && nota >= 60) {
            cout << "\tTiene una nota de D." << endl;
        }
        else if (nota < 60) {
            cout << "\tTiene una nota de E." << endl;
        }
        else {
            cout << "\tTiene una nota inválida." << endl;
        }
        break;
    default:
        cout << "El numero que acaba de ingresar no es valido, intentelo nuevamente. " << endl;
        break;
    }

    system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

    return 0;
}