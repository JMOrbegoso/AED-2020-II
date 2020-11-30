#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    float monto;
    string nombre;

    int* pX;
    int* pY;
    float* pMonto;
    string* pNombre;

    // puntero pX que apunta a X
    pX = &x;

    // pY que apunta a lo que apunta pX
    pX = pY;

    // Incremente el valor de x en 10 a través del puntero
    *pX = *pX + 10;
}