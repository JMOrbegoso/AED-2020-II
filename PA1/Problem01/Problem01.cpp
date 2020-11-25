#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// DECLARACION DE VARIABLES 

	float parteEntera1, parteEntera2, parteEntera3;
	float parteDecimal1, parteDecimal2, parteDecimal3;
	float num1, num2, num3;

	// ENTRADA DE DATOS 

	cout << "\tBienvenidos al problema 1:" << endl;
	cout << "\t=========================:" << endl;

	cout << "Por favor ingrese el valor del numero 1:";
	cin >> num1;

	cout << "Por favor ingrese el valor del numero 2:";
	cin >> num2;

	cout << "Por favor ingrese el valor del numero 3:";
	cin >> num3;

	// PROCESO 

	// Obtener la parte decimal del numero 

	parteEntera1 = floor(num1);
	parteDecimal1 = num1 - parteEntera1;

	parteEntera2 = floor(num2);
	parteDecimal2 = num2 - parteEntera2;

	parteEntera3 = floor(num3);
	parteDecimal3 = num3 - parteEntera3;

	// DATOS DE SALIDA

	system("cls"); // Limpia la pantalla

	// Imprime en pantalla los valores en forma ascendente 

	if (parteDecimal1 < parteDecimal2 && parteDecimal1 < parteDecimal3) {
		cout << "El menor numero es:" << parteDecimal1 << endl;

		if (parteDecimal2 < parteDecimal3) {
			cout << "El segundo menor numero es:" << parteDecimal2 << endl;
			cout << "El mayor numero es:" << parteDecimal3 << endl;
		}
		else {
			cout << "El segundo menor numero es:" << parteDecimal3 << endl;
			cout << "El mayor numero es:" << parteDecimal2 << endl;
		}
	}
	if (parteDecimal2 < parteDecimal1 && parteDecimal2 < parteDecimal3) {
		cout << "El menor numero es:" << parteDecimal2 << endl;
		if (parteDecimal1 < parteDecimal3) {
			cout << "El segundo menor numero es:" << parteDecimal1 << endl;
			cout << "El mayor numero es:" << parteDecimal3 << endl;
		}
		else {
			cout << "El segundo menor numero es:" << parteDecimal3 << endl;
			cout << "El mayor numero es:" << parteDecimal1 << endl;
		}
	}
	if (parteDecimal3 < parteDecimal1 && parteDecimal3 < parteDecimal2) {
		cout << "el menor numero es:" << parteDecimal3 << endl;
		if (parteDecimal1 < parteDecimal2) {
			cout << "El segundo menor numero es:" << parteDecimal1 << endl;
			cout << "El mayor menor es:" << parteDecimal2 << endl;
		}
		else {
			cout << "El segundo menor numero:" << parteDecimal2 << endl;
			cout << "El menor numero es:" << parteDecimal1 << endl;
		}
	}

	system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

	return 0;
}