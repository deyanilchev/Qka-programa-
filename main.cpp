#include <stdio.h>
/* Insert your functions from last week here */
int main()
{
char userInput = '?'; // some place to store input from the user
int max = 0; // the maximum assignment count (i.e. how many assignements we have
float marksAwarded[100]; // place to store the marks
float marksAvailable[100]; // place to store the available marks
// Since we've not got any code to add new assignments yet,
// here's some test assignments manually assigned.
/* Testing code: default assignment scores */
{
marksAwarded[0] = 10; marksAvailable[0] = 10;
marksAwarded[1] = 7; marksAvailable[1] = 11;
marksAwarded[2] = 5; marksAvailable[2] = 11;
marksAwarded[3] = 3; marksAvailable[3] = 11;
marksAwarded[4] = 0; marksAvailable[4] = 100;
max = 5; // update how many items we have
}
/* End of testing code */
while(1) // forever
{
// Print the main menu
printf("\nA) Display Marks\nB) Edit Assignment\nC) Add Assignment\n\nQ) Quit\n\n>");
// Grab the option from the user
scanf(" %c", &userInput);
if(CheckCase(userInput, 'A'))
{
// Display all the marks we have
DisplayAllRawMarks(marksAwarded, marksAvailable, max);
}
if(CheckCase(userInput, 'Q'))
{
// If 'Q' or 'q' entered, break out of the while loop
break;
}
// Keep going around the while loop if the user didn't quit
}
return 0;
