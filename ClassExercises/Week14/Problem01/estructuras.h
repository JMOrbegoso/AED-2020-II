#include <iostream>
#include <windows.h>

using namespace std;

struct estudiante {
    string codigo;
    string nombre;
    int edad;
    float notas[5];
    float promedio;
    string carreraProfesional;
};

struct nodoEstudiante {
    estudiante estudiante;
    nodoEstudiante* siguiente;
};


struct listaEstudiantes {
    nodoEstudiante* primerElemento; // cabecera
    int cantidad;
};





struct curso {
    string nombre;
};

struct nodoCurso {
    curso curso;
    nodoCurso* siguiente;
};

struct listaCursos {
    nodoCurso* primerElemento; // cabecera
    int cantidad;
};