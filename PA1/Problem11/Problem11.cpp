#include <iostream>

using namespace std;

int main()
{
    // Declaración de Variables
    float num1, num2, num3, num4, limite1, limite2, promedio;

    // Datos de entrada
    cout << "Ingrese Numero 1" << endl;
    cin >> num1;

    cout << "Ingrese el primer limite" << endl;
    cin >> limite1;

    cout << "Ingrese el segundo limite" << endl;
    cin >> limite2;

    // Proceso

    if (limite1 < num1 && num1 < limite2) {
        cout << "Ingrese Numero 2" << endl;
        cin >> num2;

        cout << "Ingrese Numero 3" << endl;
        cin >> num3;

        cout << "Ingrese Numero 4" << endl;
        cin >> num4;

        promedio = (num1 + num2 + num3 + num4) / 4;

        cout << "El promedio es de " << promedio;
    }
    else {
        cout << "El numero original es  " << num1 << " y no está en los limites establecidos de " << limite1 << " y " << limite2;
    }

    system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

    return 0;
}