#include <stdio.h>

/***************************************************************
Tester Function prototypes and information, DO NOT MODIFY */

void searchTest();
void updateTest();
void addTest();
void addOrUpdateTest();
void adjustQtyTest();

struct Item {
   double price;
   int sku;
   int isTaxed;
   int quantity;
   int minQuantity;
   char name[21];
};

struct Item GI[21] = {
   { 4.4,275,0,10,2,"Royal Gala Apples" },
   { 5.99,386,0,20,4,"Honeydew Melon" },
   { 3.99,240,0,30,5,"Blueberries" },
   { 10.56,916,0,20,3,"Seedless Grapes" },
   { 2.5,385,0,5,2,"Pomegranate" },
   { 0.44,495,0,100,30,"Banana" },
   { 0.5,316,0,123,10,"Kiwifruit" },
   { 4.49,355,1,20,5,"Chicken Alfredo" },
   { 5.49,846,1,3,5,"Veal Parmigiana" },
   { 5.29,359,1,40,5,"Beffsteak Pie" },
   { 4.79,127,1,30,3,"Curry Checken" },
   { 16.99,238,1,10,2,"Tide Detergent" },
   { 10.49,324,1,40,5,"Tide Liq. Pods" },
   { 10.99,491,1,50,5,"Tide Powder Det." },
   { 3.69,538,1,1,5,"Lays Chips S&V" },
   { 3.29,649,1,15,5,"Joe Org Chips" },
   { 1.79,731,1,100,10,"Allen's Apple Juice" },
   { 6.69,984,1,30,3,"Coke 12 Pack" },
   { 7.29,350,1,50,5,"Nestea 12 Pack" },
   { 6.49,835,1,20,2,"7up 12 pack" }
};
int GNoOfRecs = 20;

/**************************************************************/

/*************************************************************
Student Milestone 3 definitions and prototypes go here:
(Do not copy struct Item since it is already implimented above*/
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
int yes(void);  // ms2

/*ipc_ms3 prototype*/
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

/*End of Student Milestone 3 definitions and prototypes
*************************************************************/

/*************************************************************
Milestone 4 defintions and prototypes:*/
// write the define statements here:
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

// function prototypes in order of implementation:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);


/*End of Milestone 4 defintions and prototypes:
***************************************************************/

/*************************************************************
Main tester 
int main() {
   searchTest();
   updateTest();
   addTest();
  addOrUpdateTest();
   adjustQtyTest();
   return 0;
}

/*End of main tester
******************************************************************/


/***************************************************************
Milestone 4 functions to be implemented */
/*This function searches the item with particular sku and finds whether the item
is there in the item list and displays message according to that*/
void search(const struct Item item[], int NoOfRecs) 
{
	int sku,i,searchIndex;
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
	int sku, i, searchIndex,j;
	int k = *NoOfRecs;
	printf("Please enter the SKU: ");
	sku = getIntLimited(SKU_MIN, SKU_MAX);
	i = locateItem(item,k, sku, &searchIndex);
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
	int sku, i, searchIndex, j,d;
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

/*End of Milestone 4 functions
******************************************************************/

/*****************************************************************
Milestone 3 function implementations:
Please copy your milestone 3 functions here: */
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
	it.price = getDbl();
	printf("   Quantity: ");
	it.quantity = getInt();
	printf("Minimum Qty: ");
	it.minQuantity = getInt();
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
	int i=0,j=0;
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





/*End of Milestone 3 functions.
*******************************************************************/

/***************************************************************
Tester Functions DO NOT MODIFY */

void searchTest() {
   printf("================Search Test:\n");
   printf("Enter 731: \n");
   search(GI, GNoOfRecs);
   printf("Enter 222: \n");
   search(GI, GNoOfRecs);
}
void updateTest() {
   struct Item I = { 11.11,111,1,11,1,"Ones!" };
   printf("================Update Test:\n");
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: n\n");
   updateItem(&I);
   printf("Unchanged Item Data:\n");
   dspItem(I, FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 111\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   updateItem(&I);
   printf("Updated Item: \n");
   dspItem(I, FORM);
}
void addTest() {
   printf("================Add Test:\n");
   printf("Total items in Storage: %d, Max no: %d\n", GNoOfRecs, MAX_ITEM_NO);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: n\n");
   addItem(GI, &GNoOfRecs, 222); //n
   printf("Garbage here! Nothing is added, No of items in storage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs], FORM);
   printf("Enter the follwoing: \n");
   printf(
      "         SKU: 222\n"
      "        Name: Grape\n"
      "      Price : 22.22\n"
      "   Quantity : 22\n"
      "Minimum Qty : 2\n"
      "   Is Taxed : y\n"
      "Add Item? (Y)es/(N)o: y\n");
   addItem(GI, &GNoOfRecs, 222); //y
   printf("New item is added, No of itemsinstorage: %d\n", GNoOfRecs);
   dspItem(GI[GNoOfRecs - 1], FORM);
   printf("Adding 333: \n");
   addItem(GI, &GNoOfRecs, 333);
}
void addOrUpdateTest() {
   GNoOfRecs = MAX_ITEM_NO;
   printf("================AddOrUpdate Test:\n");
   printf("Enter 731 and then \'n\':\n");
   addOrUpdateItem(GI, &GNoOfRecs); // n
   printf("Enter 731, \'y\' and then:\n"
      "       Name: Apple\n"
      "      Price: 1.80\n"
      "   Quantity: 101\n"
      "Minimum Qty: 11\n"
      "   Is Taxed: n\n"
      "Overwrite old data? (Y)es/(N)o: y\n");
   addOrUpdateItem(GI, &GNoOfRecs); // yes new data Yes
   printf("Updated Item: \n");
   dspItem(GI[16], FORM);
   printf("Enter 444: \n");
   addOrUpdateItem(GI, &GNoOfRecs); //n
}

void adjustQtyTest() {
   printf("================AdjustQty Test:\n");
   printf("Invalid SKU Test; Enter 444:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   printf("Aborting Entry test; Enter 731 and then 0:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Checking out with low quantity warning; Enter 731 and then 90:\n");
   adjustQty(GI, GNoOfRecs, CHECKOUT);
   printf("Stocking; Enter 731 and then 50:\n");
   adjustQty(GI, GNoOfRecs, STOCK);
   dspItem(GI[16], FORM);
}

/* End test functions
*********************************************************************/
