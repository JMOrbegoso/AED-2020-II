#include <iostream>
#include "Basicas.h"

using namespace std;

struct estudiantes {
    string codigo;
    string nombres;
    string apellidos;
    float promFinal;
    float notaspracticas[maxPracticas];
    float notasexamenes[maxExamenes];
};