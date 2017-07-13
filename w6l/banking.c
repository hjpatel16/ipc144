/*
== Banking - Savings Account ==

Author	: Harsh Patel
I.D     : 131964157
Date	:
Revision:
Workshop: #6 in-Lab

*/

#include <stdio.h>


struct account
{
	int accNumber;
	double balance;				
};



double balanceUp(double balance, double amount)
{
	if (amount > 0)
	{
		balance += amount;
	}
	

	return balance;
}

double interestCalc(double balance, double rat)
{

	balance = balance * (rat / 100);

	return balance;
}


int main(void)
{
	
	int option, i, acnum, j;
	double amt;
	double rate;
	double inter[5], flag = -1;
	struct account acct[] = { { 11111111, 123.45 }, { 22222222, 12365.50 }, { 33333333, 0 }, { 44444444, 1475 }, { 55555555, 25000.65 } };

	printf("***** Welcome to Savings Account Banking *****\n\n");

	do
	{
		
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Apply service charges to all accounts\n");
		printf("5.) Account Summary\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		scanf("%d", &option);

		switch (option)
		{
		case 0: 
			break;

		case 1:	
			printf("\n-- Make a deposit --\n");
			printf("\nEnter account number: ");
			scanf("%d", &acnum);
			flag = -1;
			for (i = 0; i < 5 && flag == -1; i++)
			{
				if (acct[i].accNumber == acnum)
				{
					printf("Enter amount to deposit (CAD): ");
					scanf("%lf", &amt);
					acct[i].balance = balanceUp(acct[i].balance, amt);
					printf("Current balance is : %.2lf\n", acct[i].balance);
					flag = 1;
				}
			}
			if (acct[i].accNumber != acnum && flag == -1)
			{
				printf("ERROR: Account number does not exist.\n");
			}

			printf("\n");
			break;

			/*case 2: // Withdraw funds
			//@HOME


			break;*/

		case 3: 
			i = 0;
			for (i = 0; i < 5; i++)
			{
				if (acct[i].balance <= 500)
				{
					rate = 0.99;
					inter[i] = interestCalc(acct[i].balance, rate);
					acct[i].balance += inter[i];

				}
				else if (acct[i].balance >500 && acct[i].balance <= 1500)
				{
					rate = 1.66;
					inter[i] = interestCalc(acct[i].balance, rate);
					acct[i].balance += inter[i];
				}
				else
				{
					rate = 2.49;
					inter[i] = interestCalc(acct[i].balance, rate);
					acct[i].balance += inter[i];
				}
			}

			printf("\n-- Add monthly interest earnings to all accounts --\n");
			printf("\nAccount# New Balance Interest Earnings (M)\n");
			printf("-------- ----------- ---------------------\n");
			for (j = 0; j < 5; j++)
			{

				printf("%8d %11.2lf %21.2lf\n", acct[j].accNumber, acct[j].balance, inter[j]);
			}
			printf("\n");
			break;

			/*	case 4: // Apply Service Charges
			//@HOME


			break;
			*/
		case 5: 
			printf("\n-- Account information --\n");
			printf("\nAccount# Balance   \n");
			printf("-------- ----------\n");
			for (i = 0; i < 5; i++)
			{
				printf("%8d %10.2lf\n", acct[i].accNumber, acct[i].balance);

			}
			printf("\n");
			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}


