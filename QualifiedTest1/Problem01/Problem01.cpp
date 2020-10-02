//Una empresa de venta de artefactos desea llevar el control de las ventas realizadas en la sucursal de
//Chiclayo.Se sabe qué a todas a las ventas, por aniversario de la tienda, se le descuenta del monto total el
//10 % .A partir de ello :
//-Si es lunes o martes, los productos son refrigeradoras y el monto es superior a los S / . 3000 se le hace
//descuento adicional del 5 % .
//- Si es miércoles o jueves, son televisores y el monto es superior a los S / . 3500 se le hace descuento
//adicional del 8 % .
//- Si es viernes, son cocinas o lavadoras y el monto es superior a los S / . 4000 se le hace descuento
//adicional del 6 % .
//- Los fines de semana(sábado y domingo) sea cualquiera de los artefactos, se hace un descuento del 2 %
//si el monto es superior a las S / . 5000.
//El dueño también debe validar si el cliente es mayor de edad.De no ser así no se le puede vender.
//Se debe calcular además el IGV(18 %) de la venta y mostrarlo junto a los datos del cliente y el ruc.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    unsigned short weekDay; // 0: Lunes, 1: Martes, 2:Miercoles, 3: Jueves, 4: Viernes, 5: Sabado, 6: Domingo
    unsigned short productType; // 0: Refrigerador, 1: Televisor, 2:Cocina, 3: Lavadora
    char clientFullName[100];
    char clientRuc[10];
    unsigned short clientAge;
    float grossAmount, discountedAmount, igvAmount, netAmount;
    const float anniversaryDiscount = 10 / 100;
    char productName[20];
    char weekDayName[20];

    // Entrada de datos

    cout << "BIENVENIDO AL SISTEMA DE VENTA DE LA TIENDA DE ARTEFACTOS" << endl;

    cout << "\tPor favor ingrese el día de hoy [0: Lunes, 1: Martes, 2:Miercoles, 3: Jueves, 4: Viernes, 5: Sabado, 6: Domingo]:";
    cin >> weekDay;

    cout << "\tPor favor ingrese los nombres y apellidos completos del cliente (max. 100 letras):";
    fflush(stdin);
    cin.getline(clientFullName, 100);

    cout << "\tPor favor ingrese la edad del cliente (años):";
    cin >> clientAge;

    cout << "\tPor favor ingrese el RUC de cliente (max. 10 numeros):";
    fflush(stdin);
    cin.getline(clientRuc, 10);

    cout << "\tPor favor ingrese el monto bruto de la compra (S/):";
    cin >> grossAmount;

    cout << "\tPor favor ingrese el tipo de artefacto comprado [0: Refrigerador, 1: Televisor, 2:Cocina, 3: Lavadora]:";
    cin >> productType;

    // Proceso
    system("cls"); // Limpia la pantalla de la consola

    if (clientAge < 18) {
        cout << "\tNo se puede realizar la compra, el cliente es menor de edad." << endl;
        return 0;
    }

    // Se calcula el descuento por aniversario
    discountedAmount = anniversaryDiscount * grossAmount;

    switch (weekDay) {
    case 0:
    case 1:
        if (productType == 0 && grossAmount > 3000) {
            // Se calcula el descuento adicional
            discountedAmount = discountedAmount + 5 * (grossAmount - discountedAmount) / 100;
        }
        break;
    case 2:
    case 3:
        if (productType == 1 && grossAmount > 3500) {
            // Se calcula el descuento adicional
            discountedAmount = discountedAmount + 8 * (grossAmount - discountedAmount) / 100;
        }
        break;
    case 4:
        if ((productType == 2 || productType == 3) && grossAmount > 4000) {
            // Se calcula el descuento adicional
            discountedAmount = discountedAmount + 6 * (grossAmount - discountedAmount) / 100;
        }
        break;
    case 5:
    case 6:
        if (grossAmount > 5000) {
            // Se calcula el descuento adicional
            discountedAmount = discountedAmount + 2 * (grossAmount - discountedAmount) / 100;
        }
        break;

    default:
        cout << "\tIngresó un día de la semana no válido, intente nuevamente.";
        return 0;
        break;
    }

    // Se calcula el nombre del producto
    switch (productType)
    {
    case 0:
        strcpy_s(productName, "un refrigerador");
        break;
    case 1:
        strcpy_s(productName, "un televisor");
        break;
    case 2:
        strcpy_s(productName, "una cocina");
        break;
    case 3:
        strcpy_s(productName, "una lavadora");
        break;

    default:
        break;
    }

    // Se calcula el nombre del dia de la semana
    switch (weekDay)
    {
    case 0:
        strcpy_s(weekDayName, "Lunes");
        break;
    case 1:
        strcpy_s(weekDayName, "Martes");
        break;
    case 2:
        strcpy_s(weekDayName, "Miercoles");
        break;
    case 3:
        strcpy_s(weekDayName, "Jueves");
        break;
    case 4:
        strcpy_s(weekDayName, "Viernes");
        break;
    case 5:
        strcpy_s(weekDayName, "Sabado");
        break;
    case 6:
        strcpy_s(weekDayName, "Domingo");
        break;

    default:
        break;
    }

    igvAmount = (grossAmount - discountedAmount) * 18 / 100;

    netAmount = grossAmount + igvAmount - discountedAmount;

    // Salida de datos
    cout << "El cliente " << clientFullName << "." << endl;
    Sleep(500);
    cout << "De " << clientAge << " años" << "." << endl;
    Sleep(500);
    cout << "Con RUC número: " << clientRuc << "." << endl;
    Sleep(500);
    cout << "Compró " << productName << " con un precio total de S/" << grossAmount << "." << endl;
    Sleep(500);
    cout << "Tuvo un descuento de S/ " << discountedAmount << "." << endl;
    Sleep(500);
    cout << "Su IGV fue de S/ " << igvAmount << "." << endl;
    Sleep(500);
    cout << "Por lo que debe de pagar S/" << netAmount << "." << endl;
    Sleep(500);
    cout << "Dele las gracias y deseele feliz " << weekDayName << "." << endl;

    system("pause");

    return 0;
}