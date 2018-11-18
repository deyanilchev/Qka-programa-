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

char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments) {
    float totalMarksAwarded = 0;
    float totalMarksAvailable = 0;

    // The cycle sums the total amount of marks awarded and marks available so that they can be used in GradeFromRawMarks() function
    for (int i = 0; i < maxAssignments; i++) {
        totalMarksAwarded += marksAwarded[i];
        totalMarksAvailable += marksAvailable[i];
    }

    return GradeFromRawMarks(totalMarksAwarded, totalMarksAvailable);
}

int CaseCheck(char a, char b) {

    // In the ASCII Table the capital letters are from 65 to 90
    // I remove 32 so that all characters can be lower case
    if (a >= 65 && a <= 90) {
        a += 32;
    }

    if (b >= 65 && b <= 90) {
        b += 32;
    }

    if ((b >= 97 && b <= 121) && (a >= 97 && a <= 121) && a == b) {
        return 1;
    }

    return 0;
}

int main() {
    // Both arrays are with size of 100 elements so that they can have a maximum of 100 elements inside them.
    float marksAwarded[100];
    float marksAvailable[100];

    // The number of assignments starts of 0
    int numberOfAssignments = 0;

    char finished = 'n';

    // In this cycle the awarded grades and the available grades are assigned to the corresponding arrays.
    // Each time a pair of grades is assigned a check is being done if the user wants to continue adding pair
    // On each adding of pair the number of assignments is incremented by 1
    while (!CaseCheck(finished, 'y') && numberOfAssignments != 100) {
        cin >> marksAwarded[numberOfAssignments];
        cin >> marksAvailable[numberOfAssignments];

        cin >> finished;
        numberOfAssignments++;
    }

    cout << GradeFromTotalRawMarks(marksAwarded, marksAvailable, numberOfAssignments);

//    cout << CaseCheck('y', 'A');
    return 0;
}
