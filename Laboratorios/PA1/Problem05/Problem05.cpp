#include <iostream>

using namespace std;

int main()
{
    // Declaracion de variables y constantes 
    unsigned short tipoMonedaInicial, tipoMonedaFinal; // 1: Dolares, 2: Soles, 3: Yenes, 4: Euros, 5: Yuan
    float montoInicial, montoDolares, montoFinal;

    const float solesADolares = 0.28;
    const float yenesADolares = 0.01;
    const float eurosADolares = 1.17;
    const float yuanesADolares = 0.15;

    const float dolarASoles = 3.59;
    const float dolarAYenes = 105.52;
    const float dolarAEuros = 0.86;
    const float dolarAYuan = 6.82;

    // 	Entrada de datos 

    cout << "BIENVENID@S AL PROGRAMADOR DE CAMBIADOR DE MONEDAS:" << endl;
    cout << "==================================================:" << endl;

    cout << "¿Cúal es el tipo de moneda Inicial? [1: Dolares, 2: Soles, 3: Yenes, 4: Euros, 5: Yuan]:";
    cin >> tipoMonedaInicial;

    cout << "¿Cúal es el tipo de moneda Final? [1: Dolares, 2: Soles, 3: Yenes, 4: Euros, 5: Yuan]:";
    cin >> tipoMonedaFinal;

    cout << "¿Cúal es el monto a convertir?:";
    cin >> montoInicial;

    // Proceso

    // Primero se convierte la moneda inicial a dolares
    switch (tipoMonedaInicial)
    {
    case 1: // De Dolares a Dolares
        montoDolares = montoInicial;
        break;
    case 2:// De Soles a Dolares
        montoDolares = montoInicial * solesADolares;
        break;
    case 3:// De Yenes a Dolares
        montoDolares = montoInicial * yenesADolares;
        break;
    case 4:// De Euros a Dolares
        montoDolares = montoInicial * eurosADolares;
        break;
    case 5:// De Yuanes a Dolares
        montoDolares = montoInicial * yuanesADolares;
        break;

    default:
        cout << "La moneda inicial es inválida";
        return 0; // Se termina el programa
        break;
    }

    // Ahora se convierte de dolares a la moneda de destino
    switch (tipoMonedaFinal)
    {
    case 1: // De Dolares a Dolares
        montoFinal = montoDolares;
        break;
    case 2:// De Dolares a Soles
        montoFinal = montoDolares * dolarASoles;
        break;
    case 3:// De Dolares a Yenes
        montoFinal = montoDolares * dolarAYenes;
        break;
    case 4:// De Dolares a Euros
        montoFinal = montoDolares * dolarAEuros;
        break;
    case 5:// De Dolares a Yuanes
        montoFinal = montoDolares * dolarAYuan;
        break;

    default:
        cout << "La moneda destino es inválida";
        return 0; // Se termina el programa
        break;
    }

    // Salida de datos

    system("cls"); // Limpia la pantalla de la consola

    cout << "El monto del dinero original es de " << montoInicial << ", y el monto convertido a la moneda destino es de " << montoFinal << ".";

    system("pause"); // Pausa la ejecución para que la ventana no se cierre inmediatamente

    return 0;
}