// piggybank program workshop 2 IPC144
// name: Harsh Patel
// student number: 131964157
// Section: S

#include<stdio.h>
int main(void)
{
	int Toonies, Loonies, Quarters, Dimes, Nickels,Pennies,a,b,c,d;
	float total,t2,t3;

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
	a = total / 50;
	b = (total - a*50) / 20;
	c = (total - a*50 - b*20) / 10;
	d = (total - a*50 - b*20 - c*10) / 5;
	t2 = a * 50 + b * 20 + c * 10 + d * 5;
	t3 = total - t2;
	printf("$50 bill: %d\n", a);
	printf("$20 bill: %d\n", b);
	printf("$10 bill: %d\n", c);
	printf("$5 bill: %d\n", d);

	printf("Change: $%.2f\n",t3);
	return 0;
}
