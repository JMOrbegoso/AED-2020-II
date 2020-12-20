#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    // Declaración de estructuras de datos
    deltronXpand deltronXpand;

    // Inicializacion
    inicializacion(deltronXpand);
	
    // Muestra el titulo de la app
    mostrarAppTitulo();
    mostrarTituloDeOpcion("Por favor introduzca la fecha:");

	// Inicializa la fecha
	deltronXpand.fecha = pedirFecha();
	
    // Menú
    menuPrincipal(deltronXpand);

    return 0;
}
