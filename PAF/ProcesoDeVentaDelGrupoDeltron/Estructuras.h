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

struct producto {
	int id;
	string marca;
	string nombre;
	float precio;
	int clasificacionId;
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

struct deltronXpand {
	almacen almacenes[5];
	int almacenesCantidad = 0;

	tipoDeUso tiposDeUso[5];
	int tiposDeUsoCantidad = 0;

	clasificacion clasificaciones[5];
	int clasificacionesCantidad = 0;

	producto productos[100];
	int productosCantidad = 0;

	productoEnAlmacen productosEnAlmacen[100];
	int productosEnAlmacenCantidad = 0;

	ordenDeCompra ordenesDeCompra[100];
	int ordenesDeCompraCantidad = 0;

	empleadoDeVentas empleadosDeVentas[100];
	int empleadosDeVentasCantidad = 0;

	cliente clientes[100];
	int clientesCantidad = 0;

	productoComprado productosComprados[100];
	int productosCompradosCantidad = 0;
};