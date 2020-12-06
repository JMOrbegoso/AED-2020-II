#include <iostream>
#include "Estructuras.h"

/*Escriba un programa que guarde los datos en vectores de un grupo de amigos (as) suyos (as) y los muestre
en pantalla, La estructura contendrá (Nombre, Apellido, Edad, Sexo, Dirección, y Teléfono) y permitirá
ubicar por diferentes criterios a una persona.:
i. Buscar por teléfono
ii. Buscar por apellido.
iii. Buscar por dirección
iv. Ordenar por edad
*/

using namespace std;

void ingresarDatos(datos per[max], int& ce);
void mostrarDatos(datos per[max], int ce);
void busTelefono(datos per[max], int ce);
void ordenarDatos(datos per[max], int ce);
void busApellido(datos per[max], int ce);
void busDireccion(datos per[max], int ce);

int main() {

	datos per[max];
	int ce = 0;
	int op;

	do {
		op = menu();
		switch (op) {
		case 1:ingresarDatos(per, ce);
			break;
		case 2: mostrarDatos(per, ce);
			break;
		case 3: busTelefono(per, ce);
			system("pause");
			break;
		case 4: busApellido(per, ce);
			system("pause");
			break;
		case 5: busDireccion(per, ce);
			system("pause");
			break;
		case 6: ordenarDatos(per, ce);
			break;
		}
	} while (!(op == 7));
	return 0;
}

void ingresarDatos(datos per[max], int& ce) {
	system("cls");
	if (ce < max) {
		gotoxy(35, 5); per[ce].nombre = leerTexto("¿cual es su nombre? ");
		gotoxy(35, 6); per[ce].apellido = leerTexto("¿cual es su apellido? ");
		gotoxy(35, 7); per[ce].edad = leerTexto("¿Cuantos años tiene? ");
		gotoxy(35, 8); per[ce].sexo = leerTexto("¿(F) femenina o (M) masculino? ");
		gotoxy(35, 9); per[ce].direccion = leerTexto("ingrese su direccion ");
		gotoxy(35, 10); per[ce].telefono = leerTexto("Ingrese su numero de telefono ");
		ce++;
	}
	else {
		gotoxy(35, 11); cout << "No hay espaco en el vector";
		system("pause");
	}
}

void mostrarDatos(datos per[max], int ce) {
	system("cls");
	gotoxy(5, 12); cout << "NOMBRE ";
	gotoxy(15, 12); cout << "APELLIDO ";
	gotoxy(28, 12); cout << "EDAD ";
	gotoxy(35, 12); cout << "SEXO ";
	gotoxy(45, 12); cout << "DIRECCION ";
	gotoxy(60, 12); cout << "TELEFONO ";
	for (int x = 0; x < ce; x++) {
		gotoxy(5, 13 + x); cout << per[x].nombre << endl;
		gotoxy(15, 13 + x); cout << per[x].apellido << endl;
		gotoxy(28, 13 + x); cout << per[x].edad << endl;
		gotoxy(35, 13 + x); cout << per[x].sexo << endl;
		gotoxy(45, 13 + x); cout << per[x].direccion << endl;
		gotoxy(60, 13 + x); cout << per[x].telefono << endl;
	}
	cout << endl << endl;
	system("pause");
}

string leerTexto(string mensaje, int largoMinimo) {
	string texto;

	cout << mensaje << " (Mínimo) " << mensaje << " caracteres)" << endl;

	do {
		fflush(stdin);
		getline(cin, texto);
	} while (!(largoMinimo <= texto.length()));

	return texto;
}

bool encontroTexto(string base, string terminoDeBusqueda) {
	if (base.find(terminoDeBusqueda, 0) != string::npos) {
		return true;
	}
	return false;
}

void busTelefono(datos per[max], int ce) {
	system("cls");
	string terminoDeBusqueda;
	terminoDeBusqueda = leerTexto("Ingrese el telefono de la persona a buscar");
	for (int x = 0; x < ce; x++) {
		if (encontroTexto(per[x].telefono, terminoDeBusqueda)) {
			cout << "Telefono :" << per[x].telefono << endl;
			cout << "Nombre :" << per[x].nombre << endl;
			cout << "Apellido :" << per[x].apellido << endl;
			cout << "Edad :" << per[x].edad << endl;
			cout << "Sexo :" << per[x].sexo << endl;
			cout << "Direccion :" << per[x].direccion << endl;
		}
		else {
			gotoxy(25, 5); cout << "datos no registrados";
			system("pause");
		}
	}
}

void busApellido(datos per[max], int ce) {
	system("cls");
	string terminoDeBusqueda;
	terminoDeBusqueda = leerTexto("Ingrese el apellido de la persona a buscar");
	for (int x = 0; x < ce; x++) {
		if (encontroTexto(per[x].apellido, terminoDeBusqueda)) {
			cout << "Apellido :" << per[x].apellido << endl;
			cout << "Nombre :" << per[x].nombre << endl;
			cout << "Edad :" << per[x].edad << endl;
			cout << "Telefono :" << per[x].telefono << endl;
			cout << "Sexo :" << per[x].sexo << endl;
			cout << "Direccion :" << per[x].direccion << endl;
		}
		else {
			gotoxy(25, 5); cout << "datos no registrados";
			system("pause");

		}
	}
}

void busDireccion(datos per[max], int ce) {
	system("cls");
	string terminoDeBusqueda;
	terminoDeBusqueda = leerTexto("Ingrese la direccion de la persona a buscar");
	for (int x = 0; x < ce; x++) {
		if (encontroTexto(per[x].direccion, terminoDeBusqueda)) {
			cout << "Direccion :" << per[x].direccion << endl;
			cout << "Apellido :" << per[x].apellido << endl;
			cout << "Nombre :" << per[x].nombre << endl;
			cout << "Edad :" << per[x].edad << endl;
			cout << "Telefono :" << per[x].telefono << endl;
			cout << "Sexo :" << per[x].sexo << endl;
		}
		else {
			gotoxy(25, 5); cout << "datos no registrados";
			system("pause");
		}
	}
}

void ordenarDatos(datos per[max], int ce) {
	string data;
	for (int x = 0; x < ce - 1; x++) {
		for (int y = x + 1; y < ce; y++) {
			if (per[x].edad > per[y].edad) {
				data = per[x].edad;
				per[x].edad = per[y].edad;
				per[y].edad = data;
			}
		}
	}
}