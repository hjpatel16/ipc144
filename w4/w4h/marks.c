


/*
Name : Harsh Patel
Student I.D : 131964157
Week 4 Workshop
marks.c
*/

#include<stdio.h>

int main(void)
{
	float avg, nop = 0, max = 0, nof = 0, min = 100, avg1, avg2;
	int i, nom;
	float  totof = 0, totop = 0;
	float total = 0;
	int stnum[40], marks[40];
	printf("       ---=== IPC mark Analyser V2.0 ===---\n");

	printf("Please enter the number of students(between 3 and 40): ");
	scanf("%d", &nom);
	while (nom < 3 || nom > 40)
	{

		printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		scanf("%d", &nom);
	}
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	for (i = 0; i < nom; i++)
	{
		printf("    _________ ___\r%3d ", i + 1);
		scanf("%d %d", &stnum[i], &marks[i]);

		if (stnum[i] < 10000000 || stnum[i] > 999999999)
		{
			printf("Error: Enter student number values between 10000000 and 999999999 inclusive.\n");
			i--;
		}
		else if (marks[i] > 0 && marks[i] < 100)
		{
			total = total + marks[i];
			if (marks[i] > 50)
			{
				nop++;
				totop += marks[i];

				if (marks[i] > max)
				{
					max = marks[i];
					
				}

			}
			else
			{
				nof++;
				totof += marks[i];

				if (marks[i] < min)
				{
					min = marks[i];
					
				}


			}

		}
		else
		{
			printf("Error: Enter mark values between 0 and 100 inclusive.\n");
			i--;
		}
		
	}

	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");

	for (i = 0; i < nom; i++)
	{
		if (marks[i] == max)
		{
			printf("%03d %09d %3d ***Highest mark***", i + 1, stnum[i], marks[i]);
		}
		else if (marks[i] == min)
		{
			printf("%03d %09d %3d ***Lowest mark***", i + 1, stnum[i], marks[i]);
		}
		else
			printf("%03d %09d %3d", i + 1, stnum[i], marks[i]);
		printf("\n");
	}

	printf("=================\n");





	//printf("%.0f> ", nom - i + 1);
	//scanf("%f", &marks);




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


/* the output
---=== IPC mark Analyser V2.0 ===---
Please enter the number of students(between 3 and 40): 2
Invalid number, enter a number between 3 and 40 inclusive: 41
Invalid number, enter a number between 3 and 40 inclusive: 5
Row   Std No  Mrk
--- --------- ---
1 123456789 45_
2 456789123 90_
3 789123456 57_
4 147258369 89_
5 014725836 32_
=================
Marks Entered, printing results:
Row   Std No  Mrk
--- --------- ---
001 123456789  45
002 456789123  90
003 789123456  57
004 147258369  89
005 014725836  32
=================
The average of all marks in this group is 62.6.
Program Ended.
*/
