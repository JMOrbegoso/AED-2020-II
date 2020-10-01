#include <iostream>

using namespace std;

int main()
{
	// Declaracion de variables y constantes 
	char nombre[50];
	unsigned short edad;
	const float sueldoBase = 4500;
	float sueldo = 4500;

	// Entrada de datos 

	cout << "\tBIENVENIDOS AL PROBLEMA #13:" << endl;
	cout << "===============================:" << endl;
	cout << "Resuelto por el grupo #3";

	cout << "Ingrese el nombre del empleado de la USS:";
	cin.getline(nombre, 50);

	cout << "Por favor Ingrese el tiempo de años en la USS:";
	cin >> edad;

	// Proceso

	if (edad > 10) {
		sueldo = sueldoBase + sueldoBase * 10 / 100;
	}
	else if (5 < edad && edad < 10) {
		sueldo = sueldoBase + sueldoBase * 7 / 100;
	}
	else if (3 < edad && edad < 5) {
		sueldo = sueldoBase + sueldoBase * 5 / 100;
	}
	else {
		sueldo = sueldoBase + sueldoBase * 3 / 100;
	}

	// Datos de salida

	cout << "El sueldo correspondiente de " << nombre << " es de S/" << sueldo << "." << endl;

	system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

	return 0;
}