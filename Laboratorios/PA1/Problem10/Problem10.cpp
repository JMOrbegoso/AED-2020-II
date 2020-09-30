#include <iostream>

using namespace std;

int main()
{
	//Declaracion de variables
	unsigned short edad;
	float promedio;

	//Entrada de datos
	cout << "ingrese la edad del alumno: ";
	cin >> edad;

	cout << "ingrese promedio del alumno: ";
	cin >> promedio;

	//Proceso

	system("cls"); // Limpia la pantalla de la consola

	if (0 < edad && edad < 2) {
		if (10.5 <= promedio && promedio < 13) {
			cout << "la seccion que le corresponde es la  F " << endl;
		}
		else if (13 <= promedio && promedio < 15) {
			cout << "la seccion que le corresponde es la  E " << endl;
		}
		else if (15 <= promedio && promedio <= 20) {
			cout << "la seccion que le corresponde es la  C " << endl;
		}
		else {
			cout << "El estudiante no tiene un promedio válido para la institución." << endl;
		}
	}
	else if (2 <= edad && edad < 4) {
		if (10.5 <= promedio && promedio < 13) {
			cout << "la seccion que le corresponde es la  C " << endl;
		}
		else if (13 <= promedio && promedio < 15) {
			cout << "la seccion que le corresponde es la  B " << endl;
		}
		else if (15 <= promedio && promedio <= 20) {
			cout << "la seccion que le corresponde es la  A " << endl;
		}
		else {
			cout << "El estudiante no tiene un promedio válido para la institución." << endl;
		}
	}
	else {
		cout << "El estudiante no tiene una edad válida para la institución." << endl;
	}

	system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

	return 0;
}