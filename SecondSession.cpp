#include "iostream"

using namespace std;

void EditAssignment(float marksAwarded[100], float marksAvailable[100], int position);

void AddAssignment(float marksAwarded[], float marksAvailable[], int *max);

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

int CheckCase(char a, char b) {

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

void DisplayAllRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments) {

    for (int i = 0; i < maxAssignments; ++i) {
        printf("%d. %.1f/%.1f -> %c\n", i, marksAwarded[i], marksAvailable[i],
               GradeFromRawMarks(marksAwarded[i], marksAvailable[i]));
    }

    printf("=====================\n");

    printf("Final Grade : %c\n", GradeFromTotalRawMarks(marksAwarded, marksAvailable, maxAssignments));

    //    Expected output
    //
    //    1: 10.0/10.0 -> A
    //    2: 7.0/11.0 -> C
    //    3: 5.0/11.0 -> D
    //    4: 3.0/11.0 -> F
    //    5: 0.0/100.0 -> F
    //    =====================
    //    Final Grade : F
}

void EditAssignment(float marksAwarded[], float marksAvailable[], int position) {
    float newAwardedMarks;
    float newAvailableMarks;

    printf("Enter new marks awarded: ");
    scanf("%f", &newAwardedMarks);

    printf("\n");

    printf("Enter new marks available: ");
    scanf("%f", &newAvailableMarks);

    marksAwarded[position] = newAwardedMarks;
    marksAvailable[position] = newAvailableMarks;
}

void AddAssignment(float marksAwarded[], float marksAvailable[], int &max) {
    EditAssignment(marksAwarded, marksAvailable, max);

    // Increase size because we added a new item
    max++;
}

void removeAssignmentsWithSentinelValue(float marksAwarded[], float marksAvailable[], int &max) {
    float a[100];
    float b[100];

    int index = 0;
    // Transfer only the valid assignments to new lists;
    for (int i = 0; i < max; i++) {
        if (marksAwarded[i] >= 0 && marksAvailable[i] >= 0) {
            a[index] = marksAwarded[i];
            b[index] = marksAvailable[i];

            index++;
        }
    }

    // Reduce array sizes by 1
    max--;

    // Transfer the right values to the right arrays
    for (int i = 0; i < max; i++) {
        marksAwarded[i] = a[i];
        marksAvailable[i] = b[i];
    }
}

void DeleteAssignment(float marksAwarded[], float marksAvailable[], int position, int &max) {

    // Set sentinel value so that these items at THAT position can be easily deleted afterwards
    marksAwarded[position] = -1;
    marksAvailable[position] = -1;

    // Remove deleted assignments from the lists
    removeAssignmentsWithSentinelValue(marksAwarded, marksAvailable, max);
}

int main() {
    char userInput = '?'; // some place to store input from the user
    int max = 0; // the maximum assignment count (i.e. how many assignements we have
    float marksAwarded[100]; // place to store the marks
    float marksAvailable[100]; // place to store the available marks


    // Since we've not got any code to add new assignments yet,
    // here's some test assignments manually assigned.
    /* Testing code: default assignment scores */
    {
        marksAwarded[0] = 10;
        marksAvailable[0] = 10;
        marksAwarded[1] = 7;
        marksAvailable[1] = 11;
        marksAwarded[2] = 5;
        marksAvailable[2] = 11;
        marksAwarded[3] = 3;
        marksAvailable[3] = 11;
        marksAwarded[4] = 0;
        marksAvailable[4] = 100;
        max = 5; // update how many items we have
    }
    /* End of testing code */


    int position;

    while (true) // forever
    {
        // Print the main menu
        printf("\nA) Display Marks\nB) Edit Assignment\nC) Add Assignment\nD) Delete Assignment\n\nQ) Quit\n\n>");

        // Grab the option from the user
        scanf(" %c", &userInput);
        if (CheckCase(userInput, 'A')) {
            // Display all the marks we have
            DisplayAllRawMarks(marksAwarded, marksAvailable, max);
        }

        if (CheckCase(userInput, 'B')) {
            // Edit the chosen assignment
            scanf("%i", &position);
            EditAssignment(marksAwarded, marksAvailable, position);
        }

        if (CheckCase(userInput, 'C')) {
            // Adding a new assignment
            AddAssignment(marksAwarded, marksAvailable, max);
        }

        if (CheckCase(userInput, 'D')) {
            // Deleting an Assignment
            scanf("%i", &position);
            DeleteAssignment(marksAwarded, marksAvailable, position, max);

            DisplayAllRawMarks(marksAwarded, marksAvailable, max);

            cout << max;
        }


        if (CheckCase(userInput, 'Q')) {
            // If 'Q' or 'q' entered, break out of the while loop
            break;
        }
        // Keep going around the while loop if the user didn't quit
    }


    return 0;
}