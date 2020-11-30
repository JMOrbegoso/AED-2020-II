#include <iostream>
#include <windows.h>
#include "Functions.h"

int main()
{
    int seletectMenuOption;

    supermarket supermarket;    

    client clients[100];
    int clientsQuantity = 0;

    presentationType presentationTypes[100];
    int presentationTypesQuantity = 0;

    productStatus productStatuses[100];
    int productStatusesQuantity = 0;

    product products[100];
    int productsQuantity = 0;

    purchase purchases[100];
    int purchasesQuantity = 0;

    purchasedProduct purchasedProducts[100];
    int purchasedProductsQuantity = 0;

    initializeSupermarket(supermarket);
    initializeClients(clients, clientsQuantity);
    initializePresentationTypes(presentationTypes, presentationTypesQuantity);
    initializeProductStatuses(productStatuses, productStatusesQuantity);
    initializeProducts(products, productsQuantity);
    initializePurchases(purchases, purchasesQuantity);
    initializePurchasedProducts(purchasedProducts, purchasedProductsQuantity);

    do {
        seletectMenuOption = getSeletectOption(supermarket);

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                updateSupermarketProperties(supermarket);
                system("pause");
                break;

            case 2:
                cout << "[2] Registrar nuevo producto" << endl;
                
                system("pause");
                break;

            case 3:
                cout << "[3] Editar un producto" << endl;
                
                system("pause");
                break;

            case 4:
                cout << "[4] Buscar producto por nombre" << endl;
                
                system("pause");
                break;

            case 5:
                cout << "[5] Buscar producto por marca" << endl;
                
                system("pause");
                break;

            case 6:
                cout << "[6] Ver productos ordenados por precio de forma ascendente" << endl;
                
                system("pause");
                break;

            case 7:
                cout << "[7] Aplicar descuento del 7% a un producto" << endl;

                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}