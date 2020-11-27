#include <string>

using namespace std;

struct empleadoDeVentas {
	string dni;
	string nombre;
	string apellido;
	string clave;
};

struct cliente {
	string ruc;
	string razonSocial;
	string clave;
};

struct almacen {
	int id;
	string departamento;
	string direccion;
};

struct tipoDeUso {
	int id;
	string tipo;
};

struct clasificacion {
	int id;
	string nombre;
};

struct subclasificacion {
	int id;
	int clasificacionId;
	string nombre;
};

struct producto {
	int id;
	string marca;
	string nombre;
	float precio;
	int subclasificacionId;
	int tipoDeUsoId;
};

struct productoEnAlmacen {
	int id;
	int almacenId;
	int productoId;
	int stock;
};

struct ordenDeCompra {
	int id;
	int clienteId;
};

struct productoComprado {

	int id;
	int productoEnAlmacenId;
	int ordenDeCompraId;
	int cantidad;
};