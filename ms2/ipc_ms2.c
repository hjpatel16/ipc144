#include <stdio.h>
void clrKyb(void);
void pause(void);
int getInt(void);
int yes(void);  // ms2
int getIntLimited(int lowerLimit, int upperLimit);
void welcome(void);
void GrocInvSys(void);  // ms2
int menu(void);  // ms2

/*int main(void) {
	GrocInvSys();
	return 0;
}*/

// implmement MS2 fucntions here
int yes(void)								//Function to validate user to enter Y,y or N,n
{
	int RET = 0;
	char ch;

	scanf("%c", &ch);

	clrKyb();

	while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N')
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c", &ch);
	}

	if (ch == 'Y' || ch == 'y')
		RET = 1;
	else
		RET = 0;

	return RET;
}

int menu(void)			//Function to print the menu and getting valid int
{
	int v;
	
	printf("1- List all items\n");
	
	printf("2- Search by SKU\n");
	
	printf("3- Checkout an item\n");
	
	printf("4- Stock an item\n");
	
	printf("5- Add new item or update item\n");
	
	printf("6- delete item\n");
	
	printf("7- Search by name\n");
	
	printf("0- Exit program\n");
	
	printf("> ");
	
	v = getIntLimited(0, 7);				//Function Call to get Valid int

	return v;

}

void GrocInvSys(void)
{
	int done = 0, SEL;

	welcome();

	while (done != 1)
	{
		SEL = menu();

		switch (SEL)
		{

		case 1: printf("List Items!\n");
				pause();
			break;

		case 2: printf("Search Items!\n");
				pause();
			break;

		case 3: printf("Checkout Item!\n");
				pause();
			break;

		case 4: printf("Stock Item!\n");
				pause();
			break;

		case 5: printf("Add/Update Item!\n");
				pause();
			break;

		case 6: printf("Delete Item!\n");
				pause();
			break;

		case 7: printf("Search by name!\n");
				pause();
			break;

		case 0: printf("Exit the program? (Y)es/(N)o : ");
				done = yes();
			break;

		}

	}
}

// copy MS1 functions here
void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");      //prints the Title
}
void prnTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}
void prnFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0)
	{
		printf("                                           Grand Total: |%12.2lf\n", gTotal);	//Prints the total if its >0
	}
}
void clrKyb(void)
{
	char c;

	scanf("%c", &c);

	while (c != '\n')						//EXITS ONLY WHEN USER HITS ENTER
	{
		scanf("%c", &c);
	}

}
void pause(void)
{
	printf("Press <ENTER> to continue...");

	clrKyb();								// Calls the clrKyb() function
}
int getInt(void)
{
	char NL = 'x';
	int Value;

	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);

		if (NL != '\n')
		{
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	}
	return Value;

}
int getIntLimited(int lowerLimit, int upperLimit)
{
	int Value;

	Value = getInt();							// Calls getInt() and takes the Value
	while (Value < lowerLimit || Value > upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		Value = getInt();
	}
	return Value;
}
double getDbl(void)
{
	char NL = 'x';
	double Value;

	while (NL != '\n')
	{
		scanf("%lf%c", &Value, &NL);
		if (NL != '\n')
		{
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	}
	return Value;

}
double getDblLimited(double lowerLimit, double upperLimit)
{
	double Value;

	Value = getDbl();
	while (Value < lowerLimit || Value > upperLimit)
	{
		printf("Invalid value, %.6lf < value < %.6lf: ", lowerLimit, upperLimit);
		Value = getDbl();
	}
	return Value;

}


/*
---=== Grocery Inventory System ===---

1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 8
Invalid value, 0 < value < 7: 1
List Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 2
Search Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 3
Checkout Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 4
Stock Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 5
Add/Update Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 6
Delete Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 7
Search by name!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : x
Only (Y)es or (N)o are acceptable: n
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : y
*/
