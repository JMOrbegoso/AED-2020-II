#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    // Declaraci�n de estructuras de datos
    deltronXpand deltronXpand;

    // Inicializacion
    inicializacion(deltronXpand);
	
	// Inicializa la fecha
	deltronXpand.fecha = pedirFecha();
	
    // Men�
    menuPrincipal(deltronXpand);

    return 0;
}
