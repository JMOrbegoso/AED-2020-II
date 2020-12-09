/*

                        Listas enlazadas

Deseamos guardar los datos de un conjunto de productos de una tienda
Estudiante:
    -Codigo
    -Nombre
    -Edad
    -5 notas
    -Promedio
    -Carrera profesional

Crear una lista enlazada simple.

*/

#include "basicas.h"
#include <iostream>

void inicializarEstudiantes(listaEstudiantes& listaEstudiantes);
void inicializarCursos(listaCursos& listaCursos);
void registrarEstudiante(listaEstudiantes& listaEstudiantes);
void registrarCurso(listaCursos& listaCursos);
void AgregarEstudiante(listaEstudiantes& listaEstudiantes, estudiante estudiantePorAgregar);
void AgregarCurso(listaCursos& listaCursos, curso cursoPorAgregar);
void verEstudiantes(listaEstudiantes listaEstudiantes);
void verCursos(listaCursos listaCursos);
void buscarEstudiantes(listaCursos listaCursos);
void buscarCursos(listaCursos listaCursos);

using namespace std;

int main()
{
    int seletectMenuOption;

    listaCursos listaCursos;
    listaEstudiantes listaEstudiantes;

    inicializarCursos(listaCursos);
    inicializarEstudiantes(listaEstudiantes);

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registrarEstudiante(listaEstudiantes);
                Sleep(750);
                break;

            case 2:
                registrarCurso(listaCursos);
                Sleep(750);
                break;

            case 3:
                verEstudiantes(listaEstudiantes);
                system("pause");
                break;

            case 4:
                verCursos(listaCursos);
                system("pause");
                break;

            case 5:
                buscarCursos(listaCursos);
                system("pause");
                break;

            case 6:
                buscarEstudiantes(listaEstudiantes);
                system("pause");
                break;

            case 7:
                showCredits();
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

void inicializarCursos(listaCursos& listaCursos) {
    listaCursos.primerElemento = NULL;
    listaCursos.cantidad = 0;
}

void inicializarEstudiantes(listaEstudiantes& listaEstudiantes) {
    listaEstudiantes.primerElemento = NULL;
    listaEstudiantes.cantidad = 0;
}

void registrarEstudiante(listaEstudiantes& listaEstudiantes) {

    estudiante estudiante;

    // Inicio de pedir propiedades



    // Fin de pedir propiedades

    AgregarEstudiante(listaEstudiantes, estudiante);
}

void registrarCurso(listaCursos& listaCursos) {
    curso curso;

    // Inicio de pedir propiedades
    curso.nombre = "Hola";


    // Fin de pedir propiedades

    AgregarCurso(listaCursos, curso);
}

void AgregarEstudiante(listaEstudiantes& listaEstudiantes, estudiante estudiantePorAgregar) {
    nodoEstudiante* aux = new struct nodoEstudiante;
    nodoEstudiante* temp = new struct nodoEstudiante;

    temp->estudiante = estudiantePorAgregar;

    temp->siguiente = NULL;

    if (listaEstudiantes.primerElemento == NULL) {
        listaEstudiantes.primerElemento = temp;
    }
    else {
        aux = listaEstudiantes.primerElemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = temp;
    }
    listaEstudiantes.cantidad++;
}

void AgregarCurso(listaCursos& listaCursos, curso cursoPorAgregar) {
    nodoCurso* aux = new struct nodoCurso;
    nodoCurso* temp = new struct nodoCurso;

    temp->curso = cursoPorAgregar;

    temp->siguiente = NULL;

    if (listaCursos.primerElemento == NULL) {
        listaCursos.primerElemento = temp;
    }
    else {
        aux = listaCursos.primerElemento;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = temp;
    }
    listaCursos.cantidad++;
}

void verEstudiantes(listaEstudiantes listaEstudiantes) {

}

void verCursos(listaCursos listaCursos)
{
    nodoCurso* aux = listaCursos.primerElemento;

    while (aux != NULL) {

        cout << " Curso:" << aux->curso.nombre << endl;

        aux = aux->siguiente;
    }
}

void buscarCursos(listaCursos listaCursos)
{
    string terminoBusqueda = requestText("Introduzca el nombre del curso a buscar", 2);

    nodoCurso* aux = listaCursos.primerElemento;

    while (aux != NULL) {

        if (containsString(aux->curso.nombre, terminoBusqueda)) {
            cout << " Curso:" << aux->curso.nombre << endl;
        }

        aux = aux->siguiente;
    }
}

void buscarEstudiantes(listaEstudiantes listaEstudiantes) {

}