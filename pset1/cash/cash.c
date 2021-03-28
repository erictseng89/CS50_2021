// This program wil calculate the minimum number of coins to give as change for any particular sum of change.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
	// Prompt for non-negative float. Reprompt if number is negative.
	float change;
	do {
		change = get_float("Change owed: ");
		/* printf("Change owed: ");
		scanf("%f", &change); */
	}
	while(change < 0.0);

	// Convert float into int to prevent float imprecision.
	int changeInt = (int)(round(change * 100));

	// Declare coins
	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;

	// Start counting
	int num = 0;

	num += changeInt / quarter;
	changeInt %= quarter;
	num += changeInt / dime;
	changeInt %= dime;
	num += changeInt / nickel;
	changeInt %= nickel;
	num += changeInt / penny;

	// Print number of coins;
	printf("%d\n", num);
}