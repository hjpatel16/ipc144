/*
Name : Harsh Patel
Student I.D : 131964157

marks.c
*/

#include<stdio.h>

int main(void)
{
	float nom, i, marks, avg, nop = 0, max=0, nof = 0, min=100, avg1, avg2;
	float totop = 0, totof = 0, total = 0;
	printf("       ---=== IPC mark Analyser ===---\n");

	printf("Please enter the number of marks(between 3 and 40): ");
	scanf("%f", &nom);
	while (nom < 3 || nom > 40)
	{

		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%f", &nom);
	}

	for (i = nom; i > 0; i--)
	{
		printf("%.0f> ", nom - i + 1);
		scanf("%f", &marks);
		if (marks > 0 && marks < 100)
		{
			if (marks > 50)
			{
				nop++;
				totop += marks;

				if (marks > max)
				{
					max = marks;
				}

			}
			else
			{
				nof++;
				totof += marks;

				if (marks < min)
				{
					min = marks;
				}

			}
			total = total + marks;
		}
		else
		{
			printf("Error: Enter values between 0 and 100 inclusive.\n");
			i++;
		}

	}
	avg1 = totop / nop;
	avg2 = totof / nof;
	avg = total / nom;
	printf("Total of %.0f students passed with an average of %.1f.\n", nop, avg1);
	printf("Total of %.0f students failed with an average of %.1f.\n", nof, avg2);
	printf("Highest mark in group: %.0f\n", max);
	printf("Lowest mark in group: %.0f\n", min);

	printf("The average of all marks in this group is %.1f.\n", avg);
	printf("Program Ended.\n");

	return 0;
}
