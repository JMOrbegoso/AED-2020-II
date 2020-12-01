#include <iostream>
#include <windows.h>

using namespace std;

struct subjet {
    string code;
    string name;
    unsigned short credit;
    float finalScore;
};

struct subjetNode {
    subjet subjet;
    subjetNode* subjet;
};

struct subjetsList {
    subjetNode* first;
    int size;
};




















struct estudiante {
    string code;
    string name;
    int age;
    float scores[5];
    float averageScore;
    string professionalCareer;
};

struct nodoEstudiante {
    estudiante estudiante;
    nodoEstudiante* siguiente;
};

struct listaEstudiantes {
    nodoEstudiante* cabecera;
    int largo;
};