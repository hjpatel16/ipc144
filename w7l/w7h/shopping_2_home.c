
#include <stdio.h>

#define MAX_ITEMS 10
struct Item {
	int _sku;
	float _price;
	int _quantity;
};


void displayInventory(const struct Item items[], const int size);
void clear();
int validate(const int low, const int high);
int searchInventory(const struct Item items[], const int sku_item, const int size);
void addItem(struct Item items[], int *size);
void menu();
void checkPrice(const struct Item items[], const int size);



int main(){
	struct Item its[10];
	int num, size = 0;
	clear();
	printf("Welcome to the Shop\n");
	printf("===================\n");
	menu();
	num = validate(0, 4);

	while (num > 0 && num < 5)
	{
		switch (num)
		{
		case 0:	printf("Goodbye!\n");
			break;
		case 1: displayInventory(its, size);
			break;
		case 2: addItem(its, &size);
			break;
		case 3: checkPrice(its, size);
			break;
		case 4: clear();
			break;
		}
		num = validate(0, 4);
	}
	printf("Goodbye!\n");

	return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Clear Screen.\n");
	printf("0) Exit.\n");
}

int validate(const int low, const int high)
{
	int no;
	printf("Select: ");
	scanf("%d", &no);
	while (no < low || no > high)
	{
		printf("Invalid input, try again: ");
		scanf("%d", &no);
		if (no > low && no < high)
		{
			break;
		}
	}
	return no;
}

void clear()
{
	int i;
	for (i = 0; i < 20; i++)
	{
		printf("\n");
	}
}

void displayInventory(const struct Item items[], const int size)
{
	int i;
	printf("\n\nInventory\n=========================================\n");
	printf("Sku         Price       Quantity\n");
	for (i = 0; i < size; i++)
	{
		printf("%-10.0d  %-10.2f  %-10d\n", items[i]._sku, items[i]._price, items[i]._quantity);
	}
	printf("=========================================\n");
	menu();
}

int searchInventory(const struct Item items[], const int sku_item, const int size)
{
	int  j = 0;
	for (j = 0; j <= size; j++)
	{
		if (items[size]._sku == items[j]._sku)
		{
			break;
		}
		else
		{
			j = -1;
			break;
		}
	}
	return j;
}

void addItem(struct Item items[], int *size)
{
	int  i = 0;
	printf("Please input a SKU number: ");
	scanf("%d", &items[*size]._sku);
	printf("Quantity: ");
	scanf("%d", &items[*size]._quantity);
	if (*size == 0)
	{
		i = -1;
	}

	if (*size != 0)
	{
		i = searchInventory(items, items[*size]._sku, *size);
	}
	if (i != -1)
	{
		printf("The item exists in the repository, quantity is updated.\n");
		items[i]._quantity += items[*size]._quantity;

	}

	else
	{
		printf("Price: ");
		scanf("%f", &items[*size]._price);
		*size = *size + 1;
		printf("The item is successfully added to the inventory.\n");

	}
	menu();

}


void checkPrice(const struct Item items[], const int size)
{
	int n, i = 0, flag = 1;

	printf("Please input the sku number of the item: ");

	scanf("%d", &n);

	for (i = 0; i < size && flag == 1; i++)
	{
		if (items[i]._sku == n)
		{
			printf("Item %d costs $%.2f\n", items[i]._sku, items[i]._price);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		printf("Item does not exist in the shop! Please try again.\n");

	}

	menu();

}



/* output:






















Welcome to the Shop
===================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 5
Invalid input, try again: 2
Please input a SKU number: 1234
Quantity: 2
Price: 45.63
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 9010
Quantity: 5
Price: 23.50
The item is successfully added to the inventory.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 2
Please input a SKU number: 1234
Quantity: 5
The item exists in the repository, quantity is updated.
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 1


Inventory
=========================================
Sku         Price       Quantity
1234        45.63       7
9010        23.50       5
=========================================
Please select from the following options:
1) Display the inventory.
2) Add to the inventory.
3) Check price.
4) Clear Screen.
0) Exit.
Select: 0
Goodbye!
*/


