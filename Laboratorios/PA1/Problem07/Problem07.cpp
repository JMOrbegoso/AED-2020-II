#include <iostream>

using namespace std;

int main()
{
    float monto, interes, kilometraje, montocancelar, montonuevo;
    const float garantia = 500;
    char nombre[50];
    char direccion[50];

    cout << "Bienvenido al taxis Servicio Marx" << endl;

    cout << "Ingresar el nombre:";
    fflush(stdin);
    cin.getline(nombre, 50);

    cout << "Ingresar la dirección:";
    fflush(stdin);
    cin.getline(direccion, 50);

    cout << "Ingresar el Kilometraje:";
    cin >> kilometraje;

    if (kilometraje < 100) {
        interes = 0;
    }
    else if (kilometraje > 100 & kilometraje <= 200) {
        interes = 0.05;
    }
    else if (kilometraje > 200 & kilometraje <= 300) {
        interes = 0.15;
    }
    else {
        interes = 0.25;
    }

    monto = kilometraje * 2;
    montonuevo = (monto * interes) + monto;
    montocancelar = montonuevo - garantia;

    cout << "El cliente es:" << nombre << endl;
    cout << "El monto a cancelar es:" << montocancelar << endl;
    cout << "La dirección es:" << direccion << endl;
    cout << "La distancia recorrida es:" << kilometraje << endl;

    return 0;
}