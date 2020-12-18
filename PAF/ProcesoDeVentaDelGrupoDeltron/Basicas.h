#include <string>
#include <windows.h>
#include <string> 

using namespace std;

#pragma region Funciones básicas

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
    SetConsoleTextAttribute(hConsole, 2);

    cout << mensaje;

    for (int i = 0; i < 6; i++)
    {
        if (esperaLarga) {
            Sleep(450);
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

void mostrarPieDePresupuesto(float precioParcial, int y) {
    gotoxy(0, y + 0); cout << "SubTotal . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ";
    gotoxy(0, y + 1); cout << "IGV . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .";
    gotoxy(0, y + 2); cout << "Total . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .";

    gotoxy(80, y + 0); cout << precioParcial;
    gotoxy(80, y + 1); cout << (precioParcial * (float)18 / (float)100);
    gotoxy(80, y + 2); cout << (precioParcial * (float)118 / (float)100);
}

void mostrarTituloDeOpcion(string titulo) {
    mostrarLineaSeparadora();
    cout << "\t\t" << titulo << endl;
    mostrarLineaSeparadora();
}

#pragma endregion

#pragma region Funciones básicas de entrada de datos

string pedirTexto(string mensaje, int minimoDeCaracteres) {
    string texto;

    cout << mensaje << " (Mínimo " << minimoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length()));

    return texto;
}

string pedirTexto(string mensaje, int minimoDeCaracteres, int maximoDeCaracteres) {
    string texto;

    cout << mensaje << " (Mínimo " << minimoDeCaracteres << " y máximo " << maximoDeCaracteres << " caracteres)" << endl;

    do {
        fflush(stdin);
        getline(cin, texto);
    } while (!(minimoDeCaracteres <= texto.length() && texto.length() <= maximoDeCaracteres));

    return texto;
}

char pedirGenero() {
    char genero;

    cout << "¿Es de genero masculino (m) o femenino (f)?" << endl;
    cin >> genero;

    while (!(genero == 'm' || genero == 'f')) {
        cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
        fflush(stdin);
        cin >> genero;
    }

    return genero;
}

int pedirEntero(string mensaje, int min) {
    int entero;

    cout << mensaje << " (Mínimo " << min << ")" << endl;
    cin >> entero;

    while (!(min <= entero)) {
        cout << "Por favor, introduzca un valor mínimo de " << min << "." << endl;
        fflush(stdin);
        cin >> entero;
    }

    return entero;
}

int pedirEntero(string mensaje, int min, int max) {
    int entero;

    cout << mensaje << "(Mínimo " << min << " y máximo " << max << ")" << endl;
    cin >> entero;

    while (!(min <= entero && entero <= max)) {
        cout << "Por favor, introduzca un valor mínimo de " << min << " o máximo de " << max << "." << endl;
        fflush(stdin);
        cin >> entero;
    }

    return entero;
}

int pedirEdad(int edadMinima) {
    return pedirEntero("¿Cúal es su edad?", 18);
}

string pedirDNI() {
    string dni;

    dni = pedirTexto("¿Cúal es su DNI?", 8, 8);

    return dni;
}

string pedirRUC() {
    string dni;

    dni = pedirTexto("¿Cúal es el RUC?", 11, 11);

    return dni;
}

string pedirClave() {
    string clave;

    clave = pedirTexto("¿Cúal es su clave?", 6);

    return clave;
}

float pedirDinero(string mensaje, int montoMinimo) {
    float monto;

    cout << mensaje << "(Mínimo S/" << montoMinimo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << montoMinimo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

float pedirDinero(string mensaje, int montoMinimo, int montoMaximo) {
    float monto;

    cout << mensaje << "(Mínimo S/" << montoMinimo << " y máximo S/" << montoMaximo << ")" << endl;
    cin >> monto;

    while (!(montoMinimo <= monto && monto <= montoMaximo)) {
        cout << "Por favor, ingrese una cantidad mínima de S/" << montoMinimo << " y máxima de S/" << montoMaximo << "." << endl;
        fflush(stdin);
        cin >> monto;
    }

    return monto;
}

string pedirTerminoDeBusqueda() {
    return pedirTexto("Ingrese el termino de busqueda", 2);
}

string toString(int numero) {
    return std::to_string(numero);
}

string pedirFecha() {
    string fecha;

    // Pide año
    int year = pedirEntero("¿Cúal es el año actual?", 2000, 2050);

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

    cout << endl << "¿Hoy en que mes no encontramos?" << endl << endl;

    for (int i = 0; i < 12; i++)
    {
        cout << "[" << (i + 1) << "] " << meses[i] << endl;
    }

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> mesSeleccionado;
    while (!(1 <= mesSeleccionado && mesSeleccionado <= 12)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> mesSeleccionado;
    }
    mesSeleccionado--;

    int maxDias;
    if (mesSeleccionado == 0 || mesSeleccionado == 2 || mesSeleccionado == 4 || mesSeleccionado == 6 || mesSeleccionado == 7 || mesSeleccionado == 9 || mesSeleccionado == 11) {
        maxDias = 31;
    }
    else if (mesSeleccionado == 3 || mesSeleccionado == 5 || mesSeleccionado == 8 || mesSeleccionado == 10) {
        maxDias = 30;
    }
    else if (mesSeleccionado == 1 && year % 4 == 0) {
        maxDias = 29;
    }
    else {
        maxDias = 28;
    }

    // Pide dia
    int dia = pedirEntero("¿Hoy que día del mes es?", 1, maxDias);

    return toString(year) + "/" + meses[mesSeleccionado] + "/" + toString(dia);
}

#pragma endregion

#pragma region Funciones básicas del Menú

int pedirOpcionDelMenuRol() {
    int opcionSeleccionada;

    system("cls");

    mostrarAppTitulo();

    cout << endl << "¿Cúal es su rol?" << endl << endl;

    cout << "[1] Personal de ventas" << endl;
    cout << "[2] Cliente" << endl;
    cout << "[0] Cerrar sistema" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
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
    cout << "\t\t\tInicio de sesión como " << rol;
    cout << endl;
    mostrarLineaSeparadora();

    cout << endl << "¿Desea iniciar sesión o registrarse?" << endl << endl;

    cout << "[1] Iniciar sesión" << endl;
    cout << "[2] Registrarse" << endl;
    cout << "[0] Volver" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 2)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
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

    cout << endl << "¿Que desea hacer?" << endl << endl;

    cout << "[1] Mostrar todas las ordenes" << endl;
    cout << "[2] Revisar Almacenes" << endl;
    cout << "[3] Registrar nuevo producto" << endl;
    cout << "[4] Editar datos de producto existente" << endl;
    cout << "[5] Cambiar stock de producto en almacén" << endl;
    cout << "[6] Retirar producto" << endl;
    cout << "[0] Cerrar Sesión" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 6)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
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

    cout << endl << "¿Que desea hacer?" << endl << endl;

    cout << "[1] Revisar catalogo de productos" << endl;
    cout << "[2] Buscar producto por nombre" << endl;
    cout << "[3] Buscar producto por marca" << endl;
    cout << "[4] Crear orden de compra" << endl;
    cout << "[5] Ver historial de ordenes realizadas" << endl;
    cout << "[0] Cerrar Sesión" << endl;

    cout << endl << "Introduzca la opción deseada:" << endl;
    cin >> opcionSeleccionada;
    while (!(0 <= opcionSeleccionada && opcionSeleccionada <= 5)) {
        cout << "Introdujo una opción inválida, por favor seleccione una opción válida:" << endl;
        cin >> opcionSeleccionada;
    }

    return opcionSeleccionada;
}

#pragma endregion
