#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    unsigned short opcionDimensiones, opcionFigura;
    float area = 0, volumen = 0;
    float radio, lado1, lado2;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #09" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl << endl;

    cout << "¿Desea trabajar con una figura 2D o 3D? [2: 2D, 3:3D]:";
    cin >> opcionDimensiones;

    // Proceso
    if (opcionDimensiones == 2) {
        cout << "¿Con que figura desea trabajar? [1: Prisma, 2: Esfera, 3: Cubo, 4: Rombo]:" << endl;
        cin >> opcionFigura;

        switch (opcionFigura)
        {
        case 1:
            cout << "¿Cúal es el lado del cuadrado del prisma (m)?" << endl;
            cin >> lado1;

            cout << "¿Cúal es la altura #2 del prisma (m)?" << endl;
            cin >> lado2;

            area = lado1 * lado2; // Formula del Area de un lado del Prisma Cuadrangular
            volumen = 2 * lado1 * (lado1 + 2 * lado2); // Formula del Volumen de un Prisma Cuadrangular
            break;

        case 2:
            cout << "¿Cúal es el radio de la esfera? (m)" << endl;
            cin >> radio;

            area = 4 * 3.14 * pow(radio, 2); // Formula del Area de una Esfera
            volumen = 4 * 3.14 * pow(radio, 3) / 3; // Formula del Volumen de una Esfera
            break;

        case 3:
            cout << "¿Cúal es el lado del cubo (m)?" << endl;
            cin >> lado1;

            area = pow(lado1, 2); // Formula del Area de un Cubo
            volumen = pow(lado1, 3); // Formula del Area de un Cubo
            break;

        case 4:
            cout << "¿Cúal es el lado #1 del rombo (m)?" << endl;
            cin >> lado1;

            cout << "¿Cúal es el lado #2 del rombo (m)?" << endl;
            cin >> lado2;

            area = lado1 * lado2 / 2; // Formula del Area de un Rombo
            break;

        default:
            cout << "Introdujo un valor inválido para la figura, por favor intente nuevamente." << endl;
            return 0; // Termina la aplicación
            break;
        }
    }
    else if (opcionDimensiones == 3) {
        cout << "¿Con que figura desea trabajar? [1: Paralelogramo, 2: Cono Circular Recto, 3: Cilindro]:" << endl;
        cin >> opcionFigura;

        switch (opcionFigura)
        {
        case 1:
            cout << "¿Cúal es la medida de la base del Paralelogramo (m)?" << endl;
            cin >> lado1;

            cout << "¿Cúal es la medida de la altura del Paralelogramo (m)?" << endl;
            cin >> lado2;

            area = lado1 * lado2; // Formula del Area de un Paralelogramo
            break;

        case 2:
            cout << "¿Cúal es el radio del Cono circular recto? (m)" << endl;
            cin >> radio;

            cout << "¿Cúal es el la altura del Cono Circular Recto (m)?" << endl;
            cin >> lado1;

            area = 3.14 * pow(lado1, 2); // Formula del Area de la base de un Cono Circular Recto
            volumen = 3.14 * pow(radio, 2) * lado1 / 3; // Formula del Volumen de un Cono Circular Recto
            break;

        case 3:
            cout << "¿Cúal es el radio del Cilindro? (m)" << endl;
            cin >> radio;

            cout << "¿Cúal es el la altura del Cilindro (m)?" << endl;
            cin >> lado1;

            area = 3.14 * pow(lado1, 2); // Formula del Area de la base de un Cilindro
            volumen = 3.14 * pow(radio, 2) * lado1; // Formula del Volumen de un Cilindro
            break;

        default:
            cout << "Introdujo un valor inválido para la figura, por favor intente nuevamente." << endl;
            return 0; // Termina la aplicación
            break;
        }
    }
    else {
        cout << "Introdujo un valor inválido, por favor intente nuevamente." << endl;
        return 0; // Termina la aplicación
    }

    system("cls"); // Limpia la pantalla de la consola

    // Datos de Salida
    cout << "El area de la figura es de " << area << " m2." << endl;
    if (volumen != 0) {
        cout << "El Volumen de la figura es de " << volumen << " m3." << endl;
    }

    system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

    return 0;
}