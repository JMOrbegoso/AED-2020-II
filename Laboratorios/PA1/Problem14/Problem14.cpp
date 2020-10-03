#include <iostream>

using namespace std;

int main()
{
	//Declaracion de variables
	float pension, promedio, descuento;

	//Entrada de datos
	cout << "Ingrese el monto de la pension a pagar (S/): ";
	cin >> pension;

	cout << "Ingresa tu promedio del ciclo anterior (de 0 a 20): ";
	cin >> promedio;

	//Proceso
	system("cls"); // Limpia la pantalla de la consola

	if (16 <= promedio && promedio <= 20) {
		descuento = pension * 0.5;
		pension = pension - descuento;
		cout << "Usted cuenta con el 50% de descuento, el monto de descuento es de S/: " << descuento << endl;
	}
	else if (13.5 <= promedio && promedio < 16) {
		descuento = pension * 0.2;
		pension = pension - descuento;
		cout << "Usted cuenta con el 20% de descuento, el monto de descuento es de S/: " << descuento << endl;
	}
	else {
		cout << "Usted no cuenta con ningun descuento " << endl;
	}

	cout << "El total a pagar es de: " << pension << endl;

	system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

	return 0;
}