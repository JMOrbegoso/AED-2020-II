//#include <algorithm>
#include <string>
#include <windows.h>
#include <sstream> 

using namespace std;

#pragma region Funciones b�sicas

string convertirEnMinusculas(string texto) {
    /*for_each(texto.begin(), texto.end(), [](char& c) {
        c = ::tolower(c);
    });*/
    return texto;
}

bool contieneTexto(string textoBase, string textoPorBuscar) {
    if (convertirEnMinusculas(textoBase).find(convertirEnMinusculas(textoPorBuscar), 0) != string::npos) {
        return true;
    }
    return false;
}

void esperarMostrandoTexto(string mensaje, bool esperaLarga = false) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 236);

    cout << mensaje;

    for (int i = 0; i < 6; i++)
    {
        if (esperaLarga) {
            Sleep(350);
        }
        else {
            Sleep(150);
        }

        cout << ".";
    }

    SetConsoleTextAttribute(hConsole, 15);
}

void mostrarLineaSeparadora() {
    cout << "------------------------------------------------------------------------------------------------" << endl;
}

void mostrarAppTitulo() {
    cout << endl;
    mostrarLineaSeparadora();
    cout << endl << "\t\t\t\tSistema Xpand del Grupo Deltron S.A." << endl << endl;
    mostrarLineaSeparadora();
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void mostrarPieDePresupuesto(float precioParcial) {
    mostrarLineaSeparadora();
    cout << "SubTotal: " << precioParcial << endl;
    cout << "IGV: " << (precioParcial * (float)18 / (float)100) << endl;
    mostrarLineaSeparadora();
    cout << "Total: " << (precioParcial * (float)118 / (float)100) << endl;
}

void mostrarTituloDeOpcion(string titulo) {
    mostrarLineaSeparadora();
    cout << "\t\t" << titulo << endl;
    mostrarLineaSeparadora();
}

#pragma endregion

#pragma region Funciones b�sicas de entrada de datos

string pedirTexto(string mensaje, int minimoDeCaracteres) {
    string texto;

    cout << mensaje << " (M�nimo " << minimoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length()));

    return texto;
}

string pedirTexto(string mensaje, int minimoDeCaracteres, int maximoDeCaracteres) {
    string texto;

    cout << mensaje << " (M�nimo " << minimoDeCaracteres << " y m�ximo " << maximoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length() && texto.length() <= maximoDeCaracteres));

    return texto;
}

char pedirGenero() {
    char genero;

    cout << "�Es de genero masculino (m) o femenino (f)?" << endl;
    cin >> genero;

    while (!(genero == 'm' || genero == 'f')) {
        cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
        fflush(stdin);
        cin >> genero;
    }

    return genero;
}

int pedirEdad(int edadMinima) {
    int edad;

    cout << "�Qu� edad tiene (M�nimo " << edadMinima << " a�os)?" << endl;
    cin >> edad;

    while (!(edadMinima <= edad)) {
        cout << "Por favor, ingrese una edad m�nima de " << edadMinima << " a�os." << endl;
        fflush(stdin);
        cin >> edad;
    }

    return edad;
}

int pedirEdad(int edadMinima, int edadMaxima) {
    int edad;

    cout << "�Qu� edad tiene (M�nimo " << edadMinima << " a�os y m�ximo " << edadMaxima << ")?" << endl;
    cin >> edad;

    while (!(edadMinima <= edad && edad <= edadMaxima)) {
        cout << "Por favor, ingrese una edad m�nima de " << edadMinima << " a�os y m�xima de " << edadMaxima << "." << endl;
        fflush(stdin);
        cin >> edad;
    }

    return edad;
}

string pedirDNI() {
    string dni;

    dni = pedirTexto("�C�al es su DNI?", 8, 8);

    return dni;
}

string pedirRUC() {
    string dni;

    dni = pedirTexto("�C�al es el RUC?", 11, 11);

    return dni;
}

string pedirClave() {
    string clave;

    clave = pedirTexto("�C�al es su clave?", 6);

    return clave;
}

float pedirDinero(string mensaje, int montoMinimo) {
    float monto;

    cout << mensaje << "(M�nimo S/" << montoMinimo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto)) {
        cout << "Por favor, ingrese una cantidad m�nima de S/" << montoMinimo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

float pedirDinero(string mensaje, int montoMinimo, int montoMaximo) {
    float monto;

    cout << mensaje << "(M�nimo S/" << montoMinimo << " y m�ximo S/" << montoMaximo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto && monto <= montoMaximo)) {
        cout << "Por favor, ingrese una cantidad m�nima de S/" << montoMinimo << " y m�xima de S/" << montoMaximo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

string pedirTerminoDeBusqueda() {
    return pedirTexto("Ingrese el termino de busqueda", 2);
}

string toString(int& i) {
    stringstream ss;
    ss << i;

    return ss.str();
}

string pedirFecha() {
    string fecha;

    // Pide a�o
    int year;
    cout << endl << "�En que a�o nos encontramos?" << endl;
    cin >> year;
    while (!(2000 <= year && year <= (2040))) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> year;
    }

    // Pide mes
    int mesSeleccionado;
    string meses[12];
    meses[0] = "Enero";
    meses[1] = "Febrero";
    meses[2] = "Marzo";
    meses[3] = "Abril";
    meses[4] = "Mayo";
    meses[5] = "Junio";
    meses[6] = "Julio";
    meses[7] = "Agosto";
    meses[8] = "Septiembre";
    meses[9] = "Octubre";
    meses[10] = "Noviembre";
    meses[11] = "Diciembre";

    cout << endl << "�Hoy en que mes no encontramos?" << endl << endl;

    for (int i = 0; i < 12; i++)
    {
        cout << "[" << (i + 1) << "] " << meses[i] << endl;
    }

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> mesSeleccionado;
    while (!(1 <= mesSeleccionado && mesSeleccionado <= (12))) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> mesSeleccionado;
    }

    // Pide dia
    int dia;
    cout << endl << "�Que d�a del mes es hoy?" << endl;
    cin >> dia;
    while (!(1 <= dia && dia <= (31))) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> dia;
    }

    //
	fecha = toString(year) + " - " + meses[mesSeleccionado - 1] + " - " + toString(dia);

    return fecha;
}

#pragma endregion

#pragma region Funciones b�sicas del Men�

int pedirOpcionDelMenuRol() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "�C�al es su rol?" << endl << endl;

    cout << "[1] Personal de ventas" << endl;
    cout << "[2] Cliente" << endl;
    cout << "[0] Cerrar sistema" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

int pedirOpcionDelMenuLogin(string rol) {

    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl;
    mostrarLineaSeparadora();
    cout << "\t\t\tInicio de sesi�n como " << rol;
    cout << endl;
    mostrarLineaSeparadora();

    cout << endl << "�Desea iniciar sesi�n o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesi�n" << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

int pedirOpcionDelMenuEmpleadoDeVentas(string nombreEmpleadoDeVentas) {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl;
    mostrarLineaSeparadora();
    cout << "\t\t\tBienvenid@ " << nombreEmpleadoDeVentas;
    cout << endl;
    mostrarLineaSeparadora();

    cout << endl << "�Que desea hacer hoy?" << endl << endl;

    cout << "[1] Mostrar todas las ordenes" << endl;
    cout << "[2] Revisar Almacenes" << endl;
    cout << "[3] Registrar nuevo producto" << endl;
    cout << "[4] Editar datos de producto existente" << endl;
    cout << "[5] Cambiar stock de producto en almac�n" << endl;
    cout << "[0] Cerrar Sesi�n" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

int pedirOpcionDelMenuCliente(string razonSocialCliente) {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl;
    mostrarLineaSeparadora();
    cout << "\t\t\tBienvenid@ " << razonSocialCliente;
    cout << endl;
    mostrarLineaSeparadora();

    cout << endl << "�Que desea hacer hoy?" << endl << endl;

    cout << "[1] Revisar catalogo de productos" << endl;
    cout << "[2] Buscar producto por nombre" << endl;
    cout << "[3] Buscar producto por marca" << endl;
    cout << "[4] Crear orden de compra" << endl;
    cout << "[5] Ver historial de ordenes realizadas" << endl;
    cout << "[0] Cerrar Sesi�n" << endl;

    cout << endl << "Introduzca la opci�n deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opci�n inv�lida, por favor seleccione una opci�n v�lida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

#pragma endregion
