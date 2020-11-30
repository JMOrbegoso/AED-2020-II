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
	string lastName;
	string firstName;
	string address;
	char genre;
	string telephone;
	string dni;
};

struct product {
	int id;
	string name;
	string description;
	float price;
	int presentationTypeId;
	float discount;
	string brand;
	int stock;
	int productStatusId;
};

struct purchase {
	int id;
	int clientId;
};

struct purchasedProduct {
	int id;
	int purchaseId;

	int productId;
	int productquantity;
};