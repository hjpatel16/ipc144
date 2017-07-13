/* 
Name : Harsh Patel
Student I.D : 131964157

marks.c 
*/

#include<stdio.h>

int main(void)
{
	float nom,i,marks,avg;
	float total = 0;
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
		total = total + marks;
	}

	avg = total / nom;
	printf("The average of all marks in this group is %.1f.\n", avg);
	printf("Program Ended.\n");

	return 0;
}