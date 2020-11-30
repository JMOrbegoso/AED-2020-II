#include <string>

using namespace std;

struct supermarket {
	string name;
	string address;
	string telephone;
	string admin;
	string ruc;
};

struct client {
	int id;
	string  lastName;
	string firstName;
	string address;
	char genre;
	string telephone;
	string dni;
	purchase purchases[100];
};

struct product {
	int id;
	string  name;
	string  description;
	float price;
	int presentationType;
	float discount;
	string brand;
	int stock;
	int status;
};

struct purchase {
	int clientId;
	purchasedProduct purchasedProduct[100];
};

struct purchasedProduct {
	int purchaseId;

	int productId;
	int productquantity;
};