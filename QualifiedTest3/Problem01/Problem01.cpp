#include <iostream>
#include <windows.h>
#include "Functions.h"

int main()
{
    int seletectMenuOption;

    supermarket supermarket;

    client clients[100];
    int clientsQuantity = 0;

    product products[100];
    int productsQuantity = 0;

    purchase purchases[100];
    int purchasesQuantity = 0;

    purchasedProduct purchasedProducts[100];
    int purchasedProductsQuantity = 0;

    initializeSupermarket(supermarket);
    initializeClients(clients, clientsQuantity);
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
                registerNewProduct(products, productsQuantity);
                system("pause");
                break;

            case 3:
                editProduct(products, productsQuantity);
                system("pause");
                break;

            case 4:
                searchProductByName(products, productsQuantity);
                system("pause");
                break;

            case 5:
                searchProductByBrand(products, productsQuantity);
                system("pause");
                break;

            case 6:
                orderAndShowProducts(products, productsQuantity);
                system("pause");
                break;

            case 7:
                applyDiscountToProduct(products, productsQuantity);
                system("pause");
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}