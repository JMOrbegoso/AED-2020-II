#include <iostream>
#include <windows.h>

using namespace std;

// Forward declarations
float requestScore(int studentNumber, const char* message);
short requestShort(const char* message, bool positive);
float getAverage(int studentNumber);
void updateStudentStatus(float average, unsigned short& studentsApprovedQuantity, unsigned short& studentsDisapprovedQuantity);
void showResults(unsigned short& studentsApprovedQuantity, unsigned short& studentsDisapprovedQuantity);

int main()
{
    unsigned short studentsQuantity, studentsApprovedQuantity, studentsDisapprovedQuantity;
    unsigned short studentsApprovedQuantity = 0, studentsDisapprovedQuantity = 0;
    float average;

    studentsQuantity = requestShort("Por favor ingrese la cantidad de estudiantes:", true);

    for (int i = 0; i < studentsQuantity; i++) {
        average = getAverage(i + 1);

        updateStudentStatus(average, studentsApprovedQuantity, studentsDisapprovedQuantity);
    }

    cout << "Deeel grupo de estudiantes: " << studentsApprovedQuantity << " estudiantes aprobaron, y " << studentsDisapprovedQuantity << " desaprobaron";
    showResults(studentsApprovedQuantity, studentsDisapprovedQuantity);
    
    return 0;
}

float requestScore(int studentNumber, const char* message) {
    float requestedValue;

    cout << "\t" << message << studentNumber << ":" << endl;
    cin >> requestedValue;

    while (!(0 <= requestedValue && requestedValue <= 20)) {
        cout << "\tIntrodujo un valor incorrecto, por favor que la nota sea menor a 20 y mayor a 0:" << endl;
        cin >> requestedValue;
    }

    return requestedValue;
}

short requestShort(const char* message, bool positive) {
    short requestedValue;

    cout << "\t" << message << endl;
    cin >> requestedValue;

    while (positive && !(0 < requestedValue)) {
        cout << "\tIntrodujo un valor inválido, por favor que el valor sea mayor a 0:" << endl;
        cin >> requestedValue;
    }

    return requestedValue;
}

float getAverage(int studentNumber) {
    float accumulatedScores = 0;

    accumulatedScores += requestScore(studentNumber, "Ingrese la primera nota del estudiante #");
    accumulatedScores += requestScore(studentNumber, "Ingrese la segunda nota del estudiante #");
    accumulatedScores += requestScore(studentNumber, "Ingrese la tercera nota del estudiante #");
    accumulatedScores += requestScore(studentNumber, "Ingrese la cuarta nota del estudiante #");
    accumulatedScores += requestScore(studentNumber, "Ingrese la quinta nota del estudiante #");

    return accumulatedScores / 5;
}

void updateStudentStatus(float average, unsigned short& studentsApprovedQuantity, unsigned short& studentsDisapprovedQuantity) {
    if (11 < average) {
        cout << "El estudiante está aprobado con una nota de " << average << endl;
        studentsApprovedQuantity++;
    }
    else {
        cout << "El estudiante está desaprobado con una nota de " << average << endl;
        studentsDisapprovedQuantity++;
    }
}

void showResults(unsigned short& studentsApprovedQuantity, unsigned short& studentsDisapprovedQuantity) {
    cout << "Del grupo de estudiantes: " << studentsApprovedQuantity << " estudiantes aprobaron, y " << studentsDisapprovedQuantity << " desaprobaron";
}