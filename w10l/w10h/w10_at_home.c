#include<stdio.h>
#include<string.h>

int main()
{
	int i;
	char name[9], guess[9];
	printf("Password Game\n=============\nEnter your name(up to 8 characters) : ");
	scanf("%s", name);
	char pwd[9] = "SGQHKKGN";
	printf("WELCOME %s", name);
	printf("\nGuess the password (up to 8 characters) %8s:", name);
	scanf("%s", guess);
	for (i = 0; i < 7; i++)
	{
		if (strcmp(guess, pwd) != 0)
		{
			int j;
			printf("FALSE: Guess the password (up to 8 characters) ");
			for (j = 0; j < 7 - i; j++)
			{
				printf("%c", name[j]);
			}
			printf(": ");
			scanf("%s", guess);
			if (i == 7)
				printf("Thou has failed.\n");
		}
		else
		{
			printf("You got it, %s!!!\n", name);
			break;
		}
	}
	printf("Game Over!\n");
return 0;
}
