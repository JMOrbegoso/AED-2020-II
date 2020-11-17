#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
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
        fflush(stdin);
        cin >> genre;
    }

    return genre;
}

int requestAge(int minAge, int maxAge) {
    int age;

    cout << "�Qu� edad tiene (M�nimo " << minAge << " a�os y m�ximo " << maxAge << ")?" << endl;
    cin >> age;

    while (!(minAge <= age && age <= maxAge)) {
        cout << "Por favor, ingrese una edad m�nima de " << minAge << " a�os y m�xima de " << maxAge << "." << endl;
        fflush(stdin);
        cin >> age;
    }

    return age;
}

float requestScore(string message, int minScore, int maxScore) {
    float score;

    cout << message << " (M�nimo " << minScore << " y m�ximo " << maxScore << ")." << endl;
    cin >> score;

    while (!(minScore <= score && score <= maxScore)) {
        cout << "Por favor, ingrese un n�mero m�nimo de " << minScore << " y m�ximo de " << maxScore << "." << endl;
        fflush(stdin);
        cin >> score;
    }

    return score;
}

void swapValue(string* array, int i, int j) {

    string text = array[j];

    array[j] = array[i];
    array[i] = text;
}

void swapValue(char* array, int i, int j) {

    char character = array[j];

    array[j] = array[i];
    array[i] = character;
}

void swapValue(int* array, int i, int j) {

    int number = array[j];

    array[j] = array[i];
    array[i] = number;
}