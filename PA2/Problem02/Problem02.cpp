#include <iostream>
#include "Estructuras.h"

/* Elabore un algoritmo que registre los datos de Libros (Titulo, codigo, año de publicación, Autor).
? Buscar un libro por título o código
? Ordenar por título en forma ascendente
? mostrar lista de libros */

using namespace std;

void mostrarLibros(datosdeunLibro libro[max], int ce);
void buscarLibros(datosdeunLibro libro[max], int ce);
void ordenarLibros(datosdeunLibro libro[max], int ce);
void registrarLibros(datosdeunLibro libro[max], int& ce);

int main()
{
	datosdeunLibro libro[max];
	int op, ce = 0;

	do {
		op = menu();
		switch (op) {
		case 1:registrarLibros(libro, ce);
			break;
		case 2: buscarLibros(libro, ce);
			break;
		case 3:ordenarLibros(libro, ce);
			break;
		case 4:mostrarLibros(libro, ce);
			break;
		}
	} while (!(op == 5));

	return 0;
}

void mostrarLibros(datosdeunLibro libro[max], int ce) {
	system("cls");
	gotoxy(25, 10); cout << "Lista de libros registrados";
	gotoxy(25, 11); cout << "======================";
	gotoxy(5, 13); cout << "Titulo ";
	gotoxy(20, 13); cout << "Codigo ";
	gotoxy(30, 13); cout << "Fecha de publicacion";
	gotoxy(60, 13); cout << "Autor ";
	for (int x = 0; x < ce; x++) {
		gotoxy(4, 14 + x); cout << libro[x].titulo << endl;
		gotoxy(22, 14 + x); cout << libro[x].codigo << endl;
		gotoxy(32, 14 + x); cout << libro[x].publicacion << endl;
		gotoxy(55, 14 + x); cout << libro[x].autor << endl;
	}
	cout << endl << endl;
	system("pause");
}

string leerTexto(string mensaje, int largoMinimo) {
	string texto;
	cout << mensaje << " (Mínimo) " << mensaje << " (caracteres)" << endl;
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

void buscarLibros(datosdeunLibro libro[max], int ce) {
	system("cls");
	string terminoDeBusqueda;
	terminoDeBusqueda = leerTexto("Ingrese el titulo del libro a buscar");
	for (int x = 0; x < ce; x++) {
		if (encontroTexto(libro[x].titulo, terminoDeBusqueda)) {
			gotoxy(20, 5); cout << "Titulo :" << libro[x].titulo << endl;
			gotoxy(20, 7); cout << "Codigo :" << libro[x].codigo << endl;
			gotoxy(20, 9); cout << "Publicacion:" << libro[x].publicacion << endl;
			gotoxy(20, 11); cout << "Autor :" << libro[x].autor << endl;
		}
	}
}

void ordenarLibros(datosdeunLibro libro[max], int ce) {
	system("cls");
	string data;
	for (int x = 0; x < ce - 1; x++) {
		for (int y = x + 1; y < ce; y++) {
			if (libro[x].titulo > libro[y].titulo) {
				data = libro[x].titulo;
				libro[x].titulo = libro[y].titulo;
				libro[y].titulo = data;
			}
			system("pause");
		}
	}
}

void registrarLibros(datosdeunLibro libro[max], int& ce) {
	system("cls");
	if (ce <= 30) {
		gotoxy(5, 5); libro[ce].titulo = leerTexto("Ingrese el Titulo del libro a registrar: ");
		gotoxy(5, 6); libro[ce].codigo = leerTexto("Ingrese el codigo del libro a registrar: ");
		gotoxy(5, 7); libro[ce].publicacion = leerTexto("Ingrese la fecha de publicacion del libro a registrar: ");
		gotoxy(5, 8); libro[ce].autor = leerTexto("Ingrese el autor del libro a registrar: ");
		ce++;
	}
	else {
		gotoxy(5, 9); cout << "no hay espacio en el vector";
		Sleep(1000);
	}
}

