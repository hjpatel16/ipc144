
#include <stdio.h>
#define MAX 100

struct studentMarks {
	int   id;
	float marks;
};

void welcome(void);
int get_data(struct studentMarks * ptr);
void show(struct studentMarks list[], int num);

int main(void){

	// declarations of a constant, an array and variables
	struct studentMarks student[MAX];

	// call a function to display a welcome message
	welcome();

	// 1. use a do-while loop to get student ids and student marks

	int no_st = get_data(student);

	// 2. print out all the student marks

	show(student, no_st);


	return 0;
}

void welcome(void)
{
	printf("####### Marks Analyzer V3.0 #######\n");
}

int get_data(struct studentMarks *ptr)
{
	int no = 0;
	do
	{
		printf("Enter student id and marks (e.g. 12345 89.5): ");
		scanf("%d %f", &ptr[no].id, &ptr[no].marks);
		no++;
	} while (ptr[no - 1].id != -1 && ptr[no - 1].marks != -1);

	return no - 1;
}

void show(struct studentMarks list[], int num)
{
	int nof;

	for (nof = 0; nof < num; nof++)
	{
		printf("%d. %d, %2.2f\n", nof + 1, list[nof].id, list[nof].marks);
	}
}
