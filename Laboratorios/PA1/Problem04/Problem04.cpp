#include <iostream>
#include <windows.h>

using namespace std;

// Forward declaration: Informa al compilador que la función existe
void printTeamResults(unsigned short teamNumber, unsigned short wonMatches, unsigned short lostMatches, unsigned short tiedMatches, unsigned short scoredGoals, unsigned short receivedGoals, unsigned short scoreTeam);

int main()
{
    // Declaración de variables y constantes
    unsigned short wonMatches1, wonMatches2, wonMatches3, wonMatches4;
    unsigned short lostMatches1, lostMatches2, lostMatches3, lostMatches4;
    unsigned short tiedMatches1, tiedMatches2, tiedMatches3, tiedMatches4;
    unsigned short scoredGoals1, scoredGoals2, scoredGoals3, scoredGoals4;
    unsigned short receivedGoals1, receivedGoals2, receivedGoals3, receivedGoals4;
    unsigned short scoreTeam1, scoreTeam2, scoreTeam3, scoreTeam4;
    unsigned short highestScoredGoal;
    unsigned short highestScoredGoalsTeam;

    // Entrada de datos

    cout << "BIENVENIDO AL PROBLEMA #04" << endl;
    cout << "Resuelto por el grupo #03" << endl << endl << endl;

    cout << "Por favor ingrese el total de partidos ganados por el equipo 1:";
    cin >> wonMatches1;
    cout << "Por favor ingrese el total de partidos perdidos por el equipo 1:";
    cin >> lostMatches1;
    cout << "Por favor ingrese el total de partidos empatados por el equipo 1:";
    cin >> tiedMatches1;
    cout << "Por favor ingrese la cantidad de goles marcados por el equipo 1:";
    cin >> scoredGoals1;
    cout << "Por favor ingrese la cantidad de goles recibidos por el equipo 1:";
    cin >> receivedGoals1;

    cout << "Por favor ingrese el total de partidos ganados por el equipo 2:";
    cin >> wonMatches2;
    cout << "Por favor ingrese el total de partidos perdidos por el equipo 2:";
    cin >> lostMatches2;
    cout << "Por favor ingrese el total de partidos empatados por el equipo 2:";
    cin >> tiedMatches2;
    cout << "Por favor ingrese la cantidad de goles marcados por el equipo 2:";
    cin >> scoredGoals2;
    cout << "Por favor ingrese la cantidad de goles recibidos por el equipo 2:";
    cin >> receivedGoals2;

    cout << "Por favor ingrese el total de partidos ganados por el equipo 3:";
    cin >> wonMatches3;
    cout << "Por favor ingrese el total de partidos perdidos por el equipo 3:";
    cin >> lostMatches3;
    cout << "Por favor ingrese el total de partidos empatados por el equipo 3:";
    cin >> tiedMatches3;
    cout << "Por favor ingrese la cantidad de goles marcados por el equipo 3:";
    cin >> scoredGoals3;
    cout << "Por favor ingrese la cantidad de goles recibidos por el equipo 3:";
    cin >> receivedGoals3;

    cout << "Por favor ingrese el total de partidos ganados por el equipo 4:";
    cin >> wonMatches4;
    cout << "Por favor ingrese el total de partidos perdidos por el equipo 4:";
    cin >> lostMatches4;
    cout << "Por favor ingrese el total de partidos empatados por el equipo 4:";
    cin >> tiedMatches4;
    cout << "Por favor ingrese la cantidad de goles marcados por el equipo 4:";
    cin >> scoredGoals4;
    cout << "Por favor ingrese la cantidad de goles recibidos por el equipo 4:";
    cin >> receivedGoals4;

    // Proceso

    // Se limpia la pantalla
    system("cls");

    scoreTeam1 = 3 * wonMatches1 + 2 * tiedMatches1 + 1 * lostMatches1;
    scoreTeam2 = 3 * wonMatches2 + 2 * tiedMatches2 + 1 * lostMatches2;
    scoreTeam3 = 3 * wonMatches3 + 2 * tiedMatches3 + 1 * lostMatches3;
    scoreTeam4 = 3 * wonMatches4 + 2 * tiedMatches4 + 1 * lostMatches4;

    // Se calcula el equipo que tiene la mayor cantidad de goles marcados
    if (scoredGoals1 > scoredGoals2 && scoredGoals1 > scoredGoals3 && scoredGoals1 > scoredGoals4) {
        scoreTeam1++;
        highestScoredGoalsTeam = 1;
    }
    else if (scoredGoals2 > scoredGoals1 && scoredGoals2 > scoredGoals3 && scoredGoals2 > scoredGoals4) {
        scoreTeam2++;
        highestScoredGoalsTeam = 2;
    }
    else if (scoredGoals3 > scoredGoals1 && scoredGoals3 > scoredGoals2 && scoredGoals3 > scoredGoals4) {
        scoreTeam3++;
        highestScoredGoalsTeam = 3;
    }
    else if (scoredGoals4 > scoredGoals1 && scoredGoals4 > scoredGoals2 && scoredGoals4 > scoredGoals3) {
        scoreTeam4++;
        highestScoredGoalsTeam = 4;
    }
    else {
        highestScoredGoalsTeam = 0;
    }

    // Datos de salida

    printTeamResults(1, wonMatches1, lostMatches1, tiedMatches1, scoredGoals1, receivedGoals1, scoreTeam1);
    printTeamResults(2, wonMatches2, lostMatches2, tiedMatches2, scoredGoals2, receivedGoals2, scoreTeam2);
    printTeamResults(3, wonMatches3, lostMatches3, tiedMatches3, scoredGoals3, receivedGoals3, scoreTeam3);
    printTeamResults(4, wonMatches4, lostMatches4, tiedMatches4, scoredGoals4, receivedGoals4, scoreTeam4);

    if (highestScoredGoalsTeam != 0) {
        cout << "Habiendo sido el equipo " << highestScoredGoalsTeam << " quien obtubo la mayor cantidad de goles marcados, por los que ganó 1 punto extra." << endl;
    }

    system("pause");

    return 0;
}

/// <summary>
/// Recibe los datos del equipo como parametro los imprime en pantalla
/// </summary>
void printTeamResults(unsigned short teamNumber, unsigned short wonMatches, unsigned short lostMatches, unsigned short tiedMatches, unsigned short scoredGoals, unsigned short receivedGoals, unsigned short scoreTeam) {
    Sleep(1000);
    cout << "El equipo " << teamNumber << " ganó " << wonMatches << " partidos, perdio " << lostMatches << " y empató " << tiedMatches << "." << endl;
    cout << "Obtuvo " << scoredGoals << " goles marcados y " << receivedGoals << " goles recibidos." << endl;
    cout << "Obteniendo un puntaje total de " << scoreTeam << "." << endl << endl;
}