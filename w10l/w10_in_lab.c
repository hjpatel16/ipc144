#include <stdio.h>
#include <string.h>
//TODO: include the string library

//TODO: define constants for array sizes
#define size 101

int main(void)
{
	/*TODO: declare an input string that can hold up to 100 characters plus one terminating null character. Initialize to empty string*/
	char strn[size];
	/*TODO: declare a name string that can hold up to 8 characters plus one terminating null character. Initalize it to "default"*/
	char name[9] = "default";
	char cmp[9] = "default";

	printf("default name is: %s\n", name);
	printf("Enter a name 100 characters or less: ");
	/*TODO: read up to 100 characters or until the newline is encountered*/
	scanf("%[^\n]", strn);
	/*TODO: change the condition to ensure that there is enough room in the name buffer to copy the input.*/
	if (strlen(strn) < 9)
		//TODO: copy the input string to the name string
			strcpy(name, strn);
	/*TODO: in the condition compare the name string with the literal string "default" to detemrine if it was successfully changed */
	if (strcmp(name, cmp) != 0)
			printf("name was successfully changed!\n");
	else
			printf("could not copy name, was too long!!\n");
	/*TODO: display the input string */
	printf("input is: %s\n", strn);
	/*TODO: display the name string */
	printf("name is: %s\n", name);
	return 0;
}