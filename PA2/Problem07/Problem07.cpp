/*
Una compa��a de infanter�a tiene 100 cantidad de reclutas.
Se desea desarrollar un programa que mediante arreglos se pueda determinar:

- Cu�ntos infantes son mujeres y cuantos hombres.
- Cuantos son mayores de edad.
- Cuantos son de la ciudad de Lima.
- Mostrar la lista ordenados por nombre
*/

#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>

using namespace std;

// Forward declarations
int getSeletectOption();
void gotoxy(int x, int y);
void registerSoldier(string* firstNamesArray, string* lastNamesArray, char* genresArray, int* agesArray, string* citiesArray, int& soldiersQuantity);
string requestText(string message);
char requestGenre();
int requestAge(int minAge, int maxAge);
void showSoldiersByGenre(char* genresArray, int soldiersQuantity);
void showSoldiersByAgeStatus(int* agesArray, int soldiersQuantity);
void showSoldiersInLimaCity(string* citiesArray, int soldiersQuantity);
void showProblem();
void showCredits();

int main()
{
    unsigned short seletectMenuOption;

    string firstNamesArray[100];
    string lastNamesArray[100];
    char genresArray[100];
    int agesArray[100];
    string citiesArray[100];
    int soldiersQuantity = 0;

    do {
        seletectMenuOption = getSeletectOption();

        if (seletectMenuOption != 0) {
            switch (seletectMenuOption)
            {
            case 1:
                registerSoldier(firstNamesArray, lastNamesArray, genresArray, agesArray, citiesArray, soldiersQuantity);
                Sleep(2000);
                break;

            case 2:
                showSoldiersByGenre(genresArray, soldiersQuantity);
                Sleep(2000);
                break;

            case 3:
                showSoldiersByAgeStatus(agesArray, soldiersQuantity);
                Sleep(2000);
                break;

            case 4:
                showSoldiersInLimaCity(citiesArray, soldiersQuantity);
                Sleep(2000);
                break;

            case 5:

                Sleep(2000);
                break;

            case 6:
                showProblem();
                Sleep(3000);
                break;

            case 7:
                showCredits();
                Sleep(3000);
                break;

            default:
                break;
            }
        }

    } while (!(seletectMenuOption == 0));

    return 0;
}

int getSeletectOption() {
    int seletectOption;

    system("cls");

    cout << "\tBienvenido al Problema 07" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "[1] Registrar infante" << endl;
    cout << "[2] Calcular cu�ntos infantes son mujeres y cuantos hombres" << endl;
    cout << "[3] Calcular cu�ntos infantes son mayores de edad" << endl;
    cout << "[4] Calcular cu�ntos infantes son de la ciudad de Lima" << endl;
    cout << "[5] Mostrar lista de infantes ordenados por nombre" << endl;
    cout << "[6] Ver planteamiento del problema" << endl;
    cout << "[7] Ver Creditos" << endl;
    cout << "[0] Salir" << endl;

    cout << "Introduzca la opci�n deseada:" << endl;
    cin >> seletectOption;
    while (!(0 <= seletectOption && seletectOption <= 7)) {
        cout << "Introdujo una opci�n incorrecta, por favor seleccione una opci�n v�lida:";
        cin >> seletectOption;
    }

    return seletectOption;
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void registerSoldier(string* firstNamesArray, string* lastNamesArray, char* genresArray, int* agesArray, string* citiesArray, int& soldiersQuantity) {
    int age;

    system("cls");

    if (soldiersQuantity >= 100) {
        cout << "Ya ingres� 100 infantes, no puede seguir registrando m�s." << endl;
        Sleep(2000);
        return;
    }

    cout << "\t\tRegistrar� un nuevo infante" << endl << endl;

    firstNamesArray[soldiersQuantity] = requestText("�C�al es el nombre del infante? (M�nimo 2 letras)");

    lastNamesArray[soldiersQuantity] = requestText("�C�al es el apellido del infante? (M�nimo 2 letras)");

    citiesArray[soldiersQuantity] = requestText("�C�al es su ciudad de procedencia? (M�nimo 2 letras)");

    genresArray[soldiersQuantity] = requestGenre();

    agesArray[soldiersQuantity] = requestAge(15, 60);

    soldiersQuantity++;

    cout << endl << "El infante fue a�adido correctamente." << endl;
}

string requestText(string message) {
    string text;

    cout << message << ":" << endl;

    do {
        fflush(stdin);
        getline(cin, text);
    } while (!(2 <= text.length()));

    return text;
}

char requestGenre() {
    char genre;

    cout << "�Es de genero masculino (m) o femenino (f)?" << endl;
    cin >> genre;

    while (!(genre == 'm' || genre == 'f')) {
        cout << "Por favor, solo ingrese 'm' o 'f':" << endl;
        cin >> genre;
    }

    return genre;
}

int requestAge(int minAge, int maxAge) {
    int age;

    cout << "�Qu� edad tiene (M�nimo " << minAge << " a�os y m�ximo " << maxAge << ")?" << endl;
    cin >> age;

    while (!(15 <= age && age <= 60)) {
        cout << "Por favor, ingrese una edad m�nima de " << minAge << " a�os y m�xima de " << maxAge << "." << endl;
        cin >> age;
    }

    return age;
}

void showSoldiersByGenre(char* genresArray, int soldiersQuantity) {
    int womenQuantity = 0;
    int menQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (genresArray[i] == 'f') {
            womenQuantity++;
        }
        else {
            menQuantity++;
        }
    }

    cout << "En total de infantes est� compuesto de " << womenQuantity << " mujer/es y " << menQuantity << " hombre/s." << endl;
}

void showSoldiersByAgeStatus(int* agesArray, int soldiersQuantity) {
    int adultsQuantity = 0;
    int youngsQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (18 <= agesArray[i]) {
            adultsQuantity++;
        }
    }

    youngsQuantity = soldiersQuantity - adultsQuantity;

    cout << "En total de infantes est� compuesto de " << adultsQuantity << " mayores de edad y " << youngsQuantity << " menores de edad." << endl;
}

void showSoldiersInLimaCity(string* citiesArray, int soldiersQuantity) {
    int soldiersInLimaQuantity = 0;
    int soldiersOutLimaQuantity = 0;

    system("cls");

    for (int i = 0; i < soldiersQuantity; i++) {
        if (citiesArray[i] == "lima") {
            soldiersInLimaQuantity++;
        }
    }

    soldiersOutLimaQuantity = soldiersQuantity - soldiersInLimaQuantity;

    cout << "En total hay" << soldiersInLimaQuantity << " infantes en Lima, y " << soldiersOutLimaQuantity << " fuera de Lima." << endl;
}

void showProblem() {
    cout << "Una compa��a de infanter�a tiene 100 cantidad de reclutas." << endl;
    cout << "Se desea desarrollar un programa que mediante arreglos se pueda determinar:" << endl;
    cout << "\t-> Cu�ntos infantes son mujeres y cuantos hombres." << endl;
    cout << "\t-> Cuantos son mayores de edad." << endl;
    cout << "\t-> Cuantos son de la ciudad de Lima." << endl;
    cout << "\t-> Mostrar la lista ordenados por nombre." << endl;
}

void showCredits() {
    cout << "Desarrollado por Juan Manuel Orbegoso" << endl;
    cout << "https://www.jmorbegoso.com" << endl;
}