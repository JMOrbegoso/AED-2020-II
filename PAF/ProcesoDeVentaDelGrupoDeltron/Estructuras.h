#include <string>

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
	int almacenId;
	string departamento;
	string direccion;
};

struct tipoDeUso {
	int tipoDeUsoId;
	string tipo;
};

struct clasificacion {
	int clasificacionId;
	string nombre;
};

struct producto {
	int productoId;
	string marca;
	string nombre;
	float precio;
	int clasificacionId;
	int tipoDeUsoId;
	bool activo;
};

struct productoEnAlmacen {
	int productoEnAlmacenId;
	int almacenId;
	int productoId;
	int stock;
};

struct ordenDeCompra {
	int ordenDeCompraId;
	string clienteRUC;
	string fecha;
};

struct productoComprado {
	int productoCompradoId;
	int productoEnAlmacenId;
	int ordenDeCompraId;
	int cantidad;

	// Propiedades originales del producto comprado
	string marca;
	string nombre;
	float precio;
};

struct productoDisponible {
	int productoEnAlmacenId;
	int almacenId;
	int productoId;
	int stock;
	string marca;
	string nombre;
	float precio;
	int clasificacionId;
	int tipoDeUsoId;
};

struct deltronXpand {
	string fecha;

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
