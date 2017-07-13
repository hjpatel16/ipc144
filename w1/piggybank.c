// piggybank program workshop 2 IPC144
// name: Harsh Patel
// student number: 131964157
// Section: S

#include<stdio.h>
int main(void)
{
	int Toonies, Loonies, Quarters, Dimes, Nickels,Pennies;
	float total;

	printf("Please enter the number of coins in your piggy bank:\n");
	printf("Toonies: ");
	scanf("%d", &Toonies);
	printf("Loonies: ");
	scanf("%d", &Loonies);
	printf("Quarters: ");
	scanf("%d", &Quarters);
	printf("Dimes: ");
	scanf("%d", &Dimes);
	printf("Nickels: ");
	scanf("%d", &Nickels);
	printf("Pennies: ");
	scanf("%d", &Pennies);

	total = Toonies * 2 + Loonies + Quarters * 0.25 + Dimes * 0.10 + Nickels * 0.05 + Pennies * 0.01;

	printf("You have $%.2f in your piggy bank!\n",total);
	return 0;
}
