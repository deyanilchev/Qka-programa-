#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

struct AcessRecord {
	int customerID;
	char domain[255];
	char timestamp[20];

};

void PrintRecord(struct AcessRecord R)
{
	printf("%s: User %i visited %s\n",
		R.timestamp, R.customerID, R.domain);
}


int main()
{
	AcessRecord record;
	printf("Enter a timestamp: \n");
	cin.getline(record.timestamp, 20);
	// printf("Timestamp: %s \n", record.timestamp);

	printf("Enter a customer ID: \n");
	scanf("%i", &record.customerID);
	// printf("Customer ID: %i \n", record.customerID);

	printf("Enter a domain Name: \n");
	scanf("%255s", &record.domain);

	// printf("Domain name: %s \n", record.domain);
	return 0;
}
