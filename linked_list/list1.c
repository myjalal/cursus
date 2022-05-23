#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int age;
}
node;

node *initPerson (const int age)
{
	node *newPerson = NULL;
	newPerson = malloc(sizeof(node));
	newPerson -> age = age;
	printf ("created new person at %p\n", newPerson);
	return (newPerson);
}

void printPerson (const node *person, const char *comment)
{
	if (person == NULL)
		printf("%s is NULL\n", comment);
	else
		printf ("%s person's age is: %d stored at %p\n ", comment, person->age, person);
}


int main(void)
{
	node *first = NULL;
	node *second = NULL;

	printPerson (first, "first");
	printPerson (second, "second");

	first = initPerson(75);
	second = initPerson(80);

	printPerson (first, "first");
	printPerson (second, "second");

	free (first);
	free (second);

	first = NULL;
	second = NULL;

}