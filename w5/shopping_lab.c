/*
Name :- Harsh Patel
I.D :- 131964157
*/

#include<stdio.h>
struct Item {

	int sku_;
	float price_;
	int quantity_;

};

int main(void)
{
	int no,i=0,j=0;
	struct Item prodc[30];

	printf("Welcome to the Shop\n");
	printf("===================\n");
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to shop.\n");
	printf("0) Exit.\n");
	printf("Select:");
	scanf("%d", &no);

	while (no < 0 || no > 2)
	{
		printf("Invalid input, try again: Please select from the following options:\n");
		printf("1) Display the inventory.\n");
		printf("2) Add to shop.\n");
		printf("0) Exit.\n");
		printf("Select:");
		scanf("%d", &no);
		
	} 
	while (no != 0)
	{
		

		switch (no){

		case 0: printf("Good bye!\n");
			break;

		case 2:

			printf("Please input a SKU number:");
			scanf("%d", &prodc[i].sku_);
			for (j = 0; j <= i; j++)
			{
				if (prodc[i].sku_ == prodc[j].sku_ && i > 0)
				{
					printf("Quantity:");
					scanf("%d", &prodc[i].quantity_);
					printf("The item exists in the repository, quanity is updated.\n");
					prodc[j].quantity_+=prodc[i].quantity_ ;
					break;

				}
				
				else
				{

					printf("Quantity:");
					scanf("%d", &prodc[i].quantity_);
					printf("Price:");
					scanf("%f", &prodc[i].price_);
					printf("The item is successfully added to the inventory.\n");
					i++;
					break;
				}
			}
			break;
		case 1:
			printf("\n\nInventory\n=========================================\n");
			printf("Sku         Price       Quanity\n");
			for (i = 0; i < 2; i++)
			{
				printf("%-10.0d  %-10.2f  %-10d\n", prodc[i].sku_, prodc[i].price_, prodc[i].quantity_);
			}
			printf("=========================================\n");
			break;

		}
		printf("Please select from the following options:\n");
		printf("1) Display the inventory.\n");
		printf("2) Add to shop.\n");
		printf("0) Exit.\n");
		printf("Select:");
		scanf("%d", &no);
	}
	printf("Good bye!\n");

	return 0;




}

