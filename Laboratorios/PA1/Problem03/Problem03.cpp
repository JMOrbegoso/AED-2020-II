#include <iostream>

using namespace std;

int main()
{
    float montobon, montototal, sueldo;
    unsigned short year;

    cout << "Bienvenido a la Empresa S.A. SKIPTER" << endl;

    cout << "Ingrese el sueldo base S/: " << endl;
    cin >> sueldo;

    cout << "Ingrese la cantidad de años de servicio a la empresa: " << endl;
    cin >> year;

    if (year > 10) {
        montobon = 0.45 * sueldo;
    }
    else if (7 <= year && year <= 10) {
        montobon = 0.35 * sueldo;
    }
    else if (4 <= year && year <= 8) {
        montobon = 0.25 * sueldo;
    }
    else if (1 <= year && year <= 3) {
        montobon = 0.15 * sueldo;
    }
    else {
        montobon = 0;
    }

    montototal = sueldo + montobon;

    cout << "El monto de bonificación es S/" << montobon << endl;
    cout << "El monto total a pagar al empleado es S/" << montototal << endl;

    return 0;
}