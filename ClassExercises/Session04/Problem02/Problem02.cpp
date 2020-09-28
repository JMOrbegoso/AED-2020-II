#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // Declaración de variables y constantes
    unsigned short breadOption; // 0: Pan Francés, 1: Panetón, 2:Marraqueta, 3: Croissant, 4: Ciabatta
    unsigned short quantity;
    char fullName[100];
    char ruc[11];
    char breadName[20];
    float breadPrice, igvAmount, discount, grossAmount, netAmount;
    const short igv = 18;
    const float frenchBreadPrice = 0.30;
    const float panettonePrice = 15.50;
    const float marraquetaPrice = 0.20;
    const float croissantPrice = 0.40;
    const float ciabattaPrice = 0.60;

    // Entrada de datos

    cout << "BIENVENIDO A LA PANADERIA" << endl;

    cout << "\tPor favor ingrese su nombre y apellidos completos (max. 100 letras):";
    fflush(stdin);
    cin.getline(fullName, 100);

    cout << "\tPor favor ingrese su RUC (max. 11 caracteres):";
    fflush(stdin);
    cin.getline(ruc, 11);

    cout << "\tPor favor ingrese el número del pan deseado [0: Pan Francés, 1: Panetón, 2: Croissant, 3: Ciabata]:";
    cin >> breadOption;

    cout << "\tPor favor ingrese la cantidad de panes deseado:";
    cin >> quantity;

    // Proceso
    system("cls");

    switch (breadOption) {
    case 0:
        breadPrice = frenchBreadPrice;
        strcpy_s(breadName, "Pan Francés");
        break;
    case 1:
        breadPrice = panettonePrice;
        strcpy_s(breadName, "Panetón");
        break;
    case 2:
        breadPrice = marraquetaPrice;
        strcpy_s(breadName, "Marraqueta");
        break;
    case 3:
        breadPrice = croissantPrice;
        strcpy_s(breadName, "Croissant");
        break;
    case 4:
        breadPrice = ciabattaPrice;
        strcpy_s(breadName, "Ciabatta");
        break;
    default:
        cout << "\tEl tipo de pan no es válido, intente otra vez.";
        return 0;
        break;
    }

    grossAmount = breadPrice * quantity;

    igvAmount = igv * grossAmount / 100;
    grossAmount = igvAmount + grossAmount;

    if (grossAmount <= 20) {
        discount = 0;
    }
    else if (20 < grossAmount && 35 <= grossAmount) {
        discount = 2 * grossAmount / 100;
    }
    else if (35 < grossAmount && 50 <= grossAmount) {
        discount = 5 * grossAmount / 100;
    }
    else {
        discount = 10 * grossAmount / 100;
    }

    netAmount = grossAmount - discount;

    // Salida de datos
    cout << "El cliente " << fullName << " con RUC " << ruc << endl;
    Sleep(500);
    cout << "Ha comprado " << quantity << " panes del tipo " << breadName << endl;
    Sleep(500);
    cout << "Por lo que debe de pagar S/" << netAmount << "." << endl;
    Sleep(500);
    cout << "Su IGV fue de S/" << igvAmount << "." << endl;
    Sleep(500);
    cout << "Su descuento fue de S/" << discount << "." << endl;

    system("pause");

    return 0;
}