#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

struct AcessRecord {
    int customerID;
    char domain[255];
    char timestamp[20];

};

void PrintRecord(struct AcessRecord R) {
    printf("%s: User %i visited %s\n",
           R.timestamp, R.customerID, R.domain);
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

AcessRecord CreateRecord() {
    AcessRecord record;

    printf("Enter a timestamp: \n");
    cin.getline(record.timestamp, 20);

    printf("Enter a customer ID: \n");
    scanf("%i", &record.customerID);

    printf("Enter a domain Name: \n");
    scanf("%255s", &record.domain);

    return record;
}

void AddRecord(AcessRecord record[], int &max) {
    AcessRecord newRecord = CreateRecord();
    record[max++] = newRecord;

    PrintRecord(newRecord);
}

void LoadRecordsFromFile(AcessRecord records[], int &max) {

    // Path should be the exact path to the file location. It cannot be the relative to the folder.
    FILE *reader = fopen("C:\\Andrian\\Uchilishte\\Deyan\\Week_10\\example_data.ipb", "r");

    // Declaring the values here so that there will be no variable hides in the while loop
    int id;
    char domain[255];
    char timestamp[20];

    AcessRecord record{};
    while (!feof(reader)) {

        // "%d|%[^|]|%[^\n]" -> parses every line of the file
        fscanf(reader, "%d|%[^|]|%[^\n]", &id, domain, timestamp);

        record.customerID = id;

        // copies from the second string to the first
        strcpy(record.domain, domain);
        strcpy(record.timestamp, timestamp);

        // Assigns the record to the array of records
        records[max++] = record;

        // Flushes the record so that we can save new record in it
        record = {};
    }

    printf("Records loaded! \n");

    // Close the stream. I guess :?
    fclose(reader);
}

void DisplayAllRecords(AcessRecord records[], int max) {
    for (int i = 0; i < max; ++i) {
        PrintRecord(records[i]);
    }

    printf("\n");
}

string AccessRecordToString(AcessRecord record) {
    // Parse all values to string value
    string id = to_string(record.customerID);
    string domain = string(record.domain);
    string timestamp = string(record.timestamp);

    // Concat all values in the right format
    return id + "|" + domain + "|" + timestamp + "\n";
}

void SaveRecordsToAFile(AcessRecord records[], int &max) {

    // Appending records in a new file so that we wont delete the example_data file
    FILE *writer = fopen("C:\\Andrian\\Uchilishte\\Deyan\\Week_10\\data.ipb", "a");

    string result;
    for (int i = 0; i < max; ++i) {
        result = AccessRecordToString(records[i]);

        // result.c_str() -> convert string to char array
        // Writes the char array to the file
        fputs(result.c_str(), writer);
    }

    fclose(writer);
}

int main() {
    AcessRecord records[102];

    int max = 0;
    char userInput;
    while (true) // forever
    {
        // Print the main menu
        printf("\nA) Display Records\nB) Load Records\nC) Add New Record\nD) Save To File\n\nQ) Quit\n\n>");

        // Grab the option from the user
        scanf(" %c", &userInput);
        if (CheckCase(userInput, 'A')) {
            // Display all the marks we have
            DisplayAllRecords(records, max);
        }

        if (CheckCase(userInput, 'B')) {
            // Edit the chosen assignment
            LoadRecordsFromFile(records, max);
        }

        if (CheckCase(userInput, 'C')) {
            // Adding a new assignment

            printf("\n");

            AddRecord(records, max);
        }

        if (CheckCase(userInput, 'D')) {
            SaveRecordsToAFile(records, max);
        }


        if (CheckCase(userInput, 'Q')) {
            // If 'Q' or 'q' entered, break out of the while loop
            break;
        }
        // Keep going around the while loop if the user didn't quit
    }

    return 0;
}