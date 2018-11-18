#include "iostream"
using namespace std;

char GradeFromPercentage(float percentage) {
    if (percentage >= 90)
        return 'A';

    if (percentage >= 70)
        return 'B';

    if (percentage >= 50)
        return 'C';

    if (percentage >= 30)
        return 'D';

    return 'F';
}

char GradeFromRawMarks(float marksAwarded, float marksAvailable) {
    float percentage = (marksAwarded / marksAvailable) * 100;

    return GradeFromPercentage(percentage);
}



int main() {
    // Expected Result: C
    cout << GradeFromPercentage(68) << endl;

    // Expected Result: F
    cout << GradeFromPercentage(0) << endl;

    // Expected Result: D
    cout << GradeFromPercentage(30) << endl;

    // Expected Result: A
    cout << GradeFromPercentage(100) << endl;

    // ------------------------------------------------ Part B ----------------------------------------------

    // Expected Result: C
    // Grade as percentage: 50
    cout << GradeFromRawMarks(10, 20) << endl;

    // Expected Result: F
    // Grade as percentage: 90
    cout << GradeFromRawMarks(2, 20) << endl;

    // Expected Result: D
    // Grade as percentage: 30
    cout << GradeFromRawMarks(6, 20) << endl;

    // Expected Result: A
    // Grade as percentage: 90
    cout << GradeFromRawMarks(18, 20) << endl;
    return 0;
}
