#include <stdio.h>



struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


/********************************************************************
Milestones 1 to 4  prototypes, definitions and etc...*/
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
const double TAX = 0.13;

/* ms1 prototypes*/
void welcome(void);
void prnTitle(void);
void prnFooter(double gTotal);
void pause(void);
void clrKyb(void);
int getInt(void);
double getDbl(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDblLimited(double lowerLimit, double upperLimit);
/* ipc_ms2 prototype*/
int yes(void);
void GrocInvSys(void);
int menu(void);

/*ipc_ms3 prototype*/
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

/*ipc_ms4 prototype*/
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);


/*End of milestone 1 to 4 stuff
*********************************************************************/



/********************************************************************
Milestone 5 prototypes*/


#define MAX_ITEM_NO 500   
#define DATAFILE "ipc_ms5_short.txt" 

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

/*End of milestone 5 prototypes
*********************************************************************/




/**************************************************************************
TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR
TT       EE         SS             TT       EE          RR     RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
TT       EE               SS       TT       EE          RR  RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
***************************************************************************
Tester for saveItem, loadItem, saveItems and loadItems:
uncomment this to test your functions prior to putting all the code together by adding a * and / here:



void prnFile() {
FILE* tp = fopen("test.txt", "r");
char ch;
if (tp) {
for (; fscanf(tp, "%c", &ch) == 1; putch(ch));
fclose(tp);
}
else {
printf("text.txt not found\n");
}
}


int main(void) {
int i, n;
struct Item GI[3] = {
{ 4.4, 275, 0, 10, 2, "Royal Gala Apples" },
{ 5.99, 386, 0, 20, 4, "Honeydew Melon" },
{ 3.99, 240, 0, 30, 5, "Blueberries" },
};
struct Item I;
struct Item IN[3];
printf("***********Testing saveItem:\n");
printf("Your saveItem saved the following in test.txt: \n");
FILE* tp = fopen("test.txt", "w");
if (tp) {
for (i = 0; i < 3; i++) saveItem(GI[i], tp);
fclose(tp);
prnFile();
}
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItem!\n\n\n");
pause();
printf("***********Testing loadItem:\n");
printf("Your loadItem loaded the following from test.txt: \n");
tp = fopen("test.txt", "r");
if (tp) {
for (i = 0; i < 3; i++) {
loadItem(&I, tp);
dspItem(I, LINEAR);
}
fclose(tp);
tp = fopen("test.txt", "w");
fclose(tp);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItem!\n\n\n");
pause();
printf("***********Testing saveItems:\n");
printf("Your saveItems saved the following in test.txt: \n");
saveItems(GI, "test.txt", 3);
prnFile();
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItems!\n\n\n");
pause();
printf("***********Testing loadItems:\n");
printf("Your loadItems loaded the following from test.txt: \n");
loadItems(IN, "test.txt", &n);
for (i = 0; i < n; i++) {
dspItem(IN[i], LINEAR);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItems!\n\n\n");
pause();
printf("Done!\n");
return 0;
}


/* End MS5 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************/


/********************************************************************
Main function to run the application
uncomment this to test your functions after putting all the code together by adding a * and / here: */

int main(void) {
	GrocInvSys();
	return 0;
}

/* End Main function
********************************************************************/





/********************************************************************
Milestone 5 functions*/
/*This function saves the item in the text file which is passed as an argument and will store in that file*/
void saveItem(struct Item item, FILE* dataFile)
{
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}
/*This function takes an item pointer and datafile as an argument and reads the item and updates that struct pointer*/
int loadItem(struct Item* item, FILE* dataFile)
{
	struct Item it;
	if (fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]", &it.sku, &it.quantity, &it.minQuantity, &it.price, &it.isTaxed, it.name) == 6)
	{
		return 0;
	}
	else
	{
		*item = it;
	}
	return 1;
}
/*SaveItems function saves the item gained through the pointer passed and updates the file fp*/
int saveItems(struct Item* item, char fileName[], int NoOfRecs)
{
	FILE *fp = NULL;
	struct Item it;
	int i = 0;
	fp = fopen(fileName, "w+");
	if (fp != NULL)
	{
		for (i = 0; i < NoOfRecs; i++)
		{
			it = item[i];
			saveItem(it, fp);
		}
		fclose(fp);
	}
	else
	{
		return -1;
	}

	return 1;
}
/*This functions first calculates what are the no of recs and then loads the item into the array*/
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr)
{
	FILE *fp = NULL;
	int i = 0;
	int k = 0;
	fp = fopen(fileName, "r");
	if (fp != NULL)
	{
		rewind(fp);
		while (loadItem(item, fp))
		{
			k++;
		}
		*NoOfRecsPtr = k;
		rewind(fp);
		for (i = 0; i < *NoOfRecsPtr; i++)
		{
			loadItem(&item[i], fp);
		}
		fclose(fp);
	}
	else
	{
		printf("File Opening Error\n");
		return 0;
	}
	return 1;
}
/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/

void search(const struct Item item[], int NoOfRecs)
{
	int sku, i, searchIndex;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	i = locateItem(item, NoOfRecs, sku, &searchIndex);
	if (i == 0)
	{
		printf("Item not found!\n");
	}
	else
	{
		dspItem(item[searchIndex], 0);
	}
}
/*This function searches the item with the help of sku and if found asks the user
whether to update the item or not*/
void updateItem(struct Item* itemptr)
{
	int j;
	struct Item itemp;
	printf("Enter new data:\n");
	itemp = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	j = yes();
	if (j == 1)
	{
		*itemptr = itemp;
		printf("--== Updated! ==--\n");
	}
	else
	{
		printf("--== Aborted! ==--\n");
	}
}
/*This function adds an item to the item array */
void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	int j;
	struct Item its;
	if (*NoOfRecs == MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		its = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		j = yes();
		if (j == 1)
		{

			item[*NoOfRecs] = its;
			*NoOfRecs += 1;
			printf("--== Added! ==--\n");
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
}
/*This function asks the user to enter sku finds in the item array and if found updates the item
if the item with the sku is not found ask user whether he wants to add the item*/
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	struct Item it;
	int l = *NoOfRecs;
	int sku, i, searchIndex, j;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	i = locateItem(item, l, sku, &searchIndex);
	if (i == 0)
	{
		addItem(item, NoOfRecs, sku);
	}
	else
	{
		dspItem(item[searchIndex], 0);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		j = yes();
		if (j == 1)
		{
			it = item[searchIndex];
			updateItem(&it);
			item[searchIndex] = it;
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}
	}
}
/*This function takes the sku and uses it to change the quantity as per the user if he wants to add
to the stock or checkout */
void adjustQty(struct Item item[], int NoOfRecs, int stock)
{
	int sku, i, searchIndex, j, d;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	i = locateItem(item, NoOfRecs, sku, &searchIndex);
	if (i == 0)
	{
		printf("SKU not found in storage!\n");
	}
	else
	{
		dspItem(item[searchIndex], 0);
		if (stock == STOCK)
		{
			printf("Please enter the quantity to stock; Maximum of %d or 0 to abort: ", MAX_QTY - item[searchIndex].quantity);
			j = getIntLimited(0, 100);
		}
		if (stock == CHECKOUT)
		{
			printf("Please enter the quantity to checkout; Maximum of %d or 0 to abort: ", item[searchIndex].quantity);
			j = getIntLimited(0, 100);
		}
		if (j != 0)
		{
			if (stock == STOCK)
			{
				item[searchIndex].quantity += j;
				printf("--== Stocked! ==--\n");
			}
			else if (stock == CHECKOUT)
			{
				item[searchIndex].quantity -= j;
				printf("--== Checked out! ==--\n");
				d = isLowQty(item[searchIndex]);
				if (d == 1)
				{
					printf("Quantity is low, please reorder ASAP!!!\n");
				}
			}
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}

	}
}
double totalAfterTax(struct Item item)
{
	double total;

	if (item.isTaxed == 1)
	{
		total = item.price * item.quantity * TAX + item.price*item.quantity;
	}
	else
	{
		total = item.price * item.quantity;
	}
	return total;
}
// isLowQty function is used to know whether the item quantity is less than its minimum quantity
int isLowQty(struct Item item)
{
	int dec;

	if (item.quantity <= item.minQuantity)
		dec = 1;
	else
		dec = 0;
	return dec;
}
// This function takes the sku number as an argument and returns struct after the user enters the rest of the data
struct Item itemEntry(int sku)
{
	struct Item it;
	it.sku = sku;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf("%20[^\n]", it.name);
	clrKyb();
	printf("      Price: ");
	it.price = getDblLimited(0.01, 1000);
	printf("   Quantity: ");
	it.quantity = getIntLimited(1, MAX_QTY);
	printf("Minimum Qty: ");
	it.minQuantity = getIntLimited(0, 100);
	printf("   Is Taxed: ");
	it.isTaxed = yes();

	return it;
}
// This function displays the item information according to linear variable which is sent as an argument by the main function
void dspItem(struct Item item, int linear)
{

	char rply[] = "Yes";
	char rp[] = "No";
	if (linear == 1)
	{
		if (item.minQuantity < item.quantity)
		{
			printf("|%3d", item.sku);
			printf("|%-20s", item.name);
			printf("|%8.2lf", item.price);
			if (item.isTaxed == 1)
				printf("|  %3s", rply);
			else
				printf("|  %3s", rp);
			printf("| %3d", item.quantity);
			printf(" | %3d", item.minQuantity);
			if (item.isTaxed == 1)
				printf(" |%12.2lf|", item.quantity * item.price*TAX + item.quantity*item.price);
			else
				printf(" |%12.2lf|", item.quantity * item.price);
			printf("\n");
		}

		else
		{
			printf("|%3d", item.sku);
			printf("|%-20s", item.name);
			printf("|%8.2lf", item.price);
			if (item.isTaxed == 1)
				printf("|  %3s", rply);
			else
				printf("|  %3s", rp);
			printf("| %3d", item.quantity);
			printf(" | %3d", item.minQuantity);
			if (item.isTaxed == 1)
				printf(" |%12.2lf|", item.quantity * item.price*TAX + item.quantity*item.price);
			else
				printf(" |%12.2lf|", item.quantity * item.price);
			printf("***");
		}
	}
	else if (linear == 0 || FORM == 1)
	{
		if (item.minQuantity < item.quantity)
		{
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			if (item.isTaxed == 1)
				printf("   Is Taxed: %s\n", rply);
			else
				printf("   Is Taxed: %s\n", rp);

		}
		else
		{
			printf("        SKU: %d\n", item.sku);
			printf("       Name: %s\n", item.name);
			printf("      Price: %.2lf\n", item.price);
			printf("   Quantity: %d\n", item.quantity);
			printf("Minimum Qty: %d\n", item.minQuantity);
			if (item.isTaxed == 1)
				printf("   Is Taxed: %s\n", rply);
			else
				printf("   Is Taxed: %s\n", rp);
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}
// This function list the item information in the Linear form and at last prints the grand Total value
void listItems(const struct Item item[], int NoOfItems)
{

	char rply[] = "Yes";
	char rp[] = "No";
	double grandTotal = 0;
	int i;
	prnTitle();
	for (i = 0; i < NoOfItems; i++)
	{

		if (item[i].minQuantity < item[i].quantity)
		{
			printf("%-4d", i + 1);
			printf("|%3d", item[i].sku);
			printf("|%-20s", item[i].name);
			printf("|%8.2lf", item[i].price);
			if (item[i].isTaxed == 1)
				printf("|  %3s", rply);
			else
				printf("|  %3s", rp);
			printf("| %3d", item[i].quantity);
			printf(" | %3d", item[i].minQuantity);
			if (item[i].isTaxed == 1)
				printf(" |%12.2lf|", item[i].quantity * item[i].price*TAX + item[i].quantity*item[i].price);
			else
				printf(" |%12.2lf|", item[i].quantity * item[i].price);
		}
		else
		{
			printf("%-4d", i + 1);
			printf("|%3d", item[i].sku);
			printf("|%-20s", item[i].name);
			printf("|%8.2lf", item[i].price);
			if (item[i].isTaxed == 1)
				printf("|  %3s", rply);
			else
				printf("|  %3s", rp);
			printf("| %3d", item[i].quantity);
			printf(" | %3d", item[i].minQuantity);
			if (item[i].isTaxed == 1)
				printf(" |%12.2lf|", item[i].quantity * item[i].price*TAX + item[i].quantity*item[i].price);
			else
				printf(" |%12.2lf|", item[i].quantity * item[i].price);
			printf("***");
		}
		printf("\n");
		if (item[i].isTaxed == 1)
			grandTotal += item[i].quantity * item[i].price*TAX + item[i].quantity*item[i].price;
		else
			grandTotal += item[i].quantity * item[i].price;
	}
	prnFooter(grandTotal);
}
// This function searches the whole array and try to match the sku number which is passed by another function
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i = 0, j = 0;
	for (i = 0; i < 21; i++)
	{
		if (item[i].sku == sku)
		{
			*index = i;
			j = 1;
			break;
		}
	}

	return j;
}
/*ms1 and 2 functions: */

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
		printf("Invalid value, %d <= value <= %d: ", lowerLimit, upperLimit);
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
		printf("Invalid value, %.6lf <= value <= %.6lf: ", lowerLimit, upperLimit);
		Value = getDbl();
	}
	return Value;

}
int yes(void)								//Function to validate user to enter Y,y or N,n
{
	int RET;
	char ch;

	scanf("%c", &ch);

	clrKyb();

	while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N')
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf("%c", &ch);
	}

	if (ch == 'Y' || ch == 'y')
	{
		return RET = 1;
	}
	else
	{
		return RET = 0;
	}

}
int menu(void)			//Function to print the menu and getting valid int
{
	int v;

	printf("1- List all items\n");

	printf("2- Search by SKU\n");

	printf("3- Checkout an item\n");

	printf("4- Stock an item\n");

	printf("5- Add new item or update item\n");

	//printf("6- delete item\n");

	//printf("7- Search by name\n");

	printf("0- Exit program\n");

	printf("> ");

	v = getIntLimited(0, 7);				//Function Call to get Valid int

	return v;

}

void GrocInvSys(void)
{
	int done = 0, SEL;
	struct Item it[MAX_ITEM_NO];
	int NoR, i;
	welcome();
	i = loadItems(it, DATAFILE, &NoR);
	if (i != 0)
	{
		while (done != 1)
		{
			SEL = menu();

			switch (SEL)
			{

			case 1: listItems(it, NoR);
				pause();
				break;

			case 2: search(it, NoR);
				pause();
				break;

			case 3: adjustQty(it, NoR, CHECKOUT);
				i = saveItems(it, DATAFILE, NoR);
				if (i == -1)
				{
					printf("could not update data file DATAFILE\n");
				}
				pause();
				break;

			case 4: adjustQty(it, NoR, STOCK);
				i = saveItems(it, DATAFILE, NoR);
				if (i == -1)
				{
					printf("could not update data file DATAFILE\n");
				}
				pause();
				break;

			case 5: addOrUpdateItem(it, &NoR);
				i = saveItems(it, DATAFILE, NoR);
				if (i == -1)
				{
					printf("could not update data file DATAFILE\n");
				}
				pause();
				break;

				/*case 6: printf("Delete Item!\n");
				printf("NOT IMPLEMENTED\n");
				pause();
				break;

				case 7: printf("Search by name!\n");
				printf("NOT IMPLEMENTED\n");
				pause();
				break;*/

			case 0: printf("Exit the program? (Y)es/(N)o): ");
				done = yes();
				break;

			}

		}
	}
	else
	{
		printf("Could not read from DATAFILE.\n");
	}
}

/*End of milestone 1 to 4 functions
*********************************************************************/








/* ms5 Tester output

***********Testing saveItem:
Your saveItem saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItem!


Press <ENTER> to continue...
***********Testing loadItem:
Your loadItem loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItem!


Press <ENTER> to continue...
***********Testing saveItems:
Your saveItems saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItems!


Press <ENTER> to continue...
***********Testing loadItems:
Your loadItems loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItems!


Press <ENTER> to continue...
Done!


*/
