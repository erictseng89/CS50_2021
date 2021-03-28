#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

	int populationStart;
	do {
		printf("Start size: ");
		scanf("%d", &populationStart);
	}
	while (populationStart < 9);

    // TODO: Prompt for end size
	int populationEnd;
	do {
		printf("End size: ");
		scanf("%d", &populationEnd);
	}
	while (populationEnd < populationStart);

	// TODO: Calculate number of years until we reach threshold
	float deathRate = 0.25;
	float birthRate = (1.0 / 3);

	int populationCurrent = populationStart;
	int years = 0;
	while(populationCurrent < populationEnd)
	{
		int births = populationCurrent * birthRate;
		int deaths = populationCurrent * deathRate;
		populationCurrent += births - deaths;
		years++;
	}

    // TODO: Print number of years
	printf("Years: %d\n", years);
}