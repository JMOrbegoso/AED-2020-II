#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    // Declaración de estructuras de datos
    deltronXpand deltronXpand;

    // Inicializacion
    inicializacion(deltronXpand);
	
	// Inicializa la fecha
	deltronXpand.fecha = pedirFecha();
	
    // Menú
    menuPrincipal(deltronXpand);

    return 0;
}
