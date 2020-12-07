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

#include "estructuras.h"

#include <iostream>

int main()
{
    listaCursos listaCursos;
    listaEstudiantes listaEstudiantes;

    inicializarCursos(listaCursos);
    inicializarEstudiantes(listaEstudiantes);



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

void registrarCurso(listaCursos & listaCursos) {
    curso curso;

    // Inicio de pedir propiedades



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

void AgregarCurso(listaCursos & listaCursos, curso cursoPorAgregar) {
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