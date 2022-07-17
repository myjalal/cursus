/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:07:19 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/23 18:07:32 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
# This programme is to learn how to use liked list (23 mai 2022)
# creat a node with name, age and next node address, add person and assigne address.
# Print and clear a node or all the linked list.  
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node
{
	char name[30];
	int age;
	struct t_node *next;
} t_node;

// initiate node to creat a new person with name and age
t_node *new_person(char *name, const int age)
{
	t_node *person;
	person = malloc(sizeof(t_node));
	if (!person)
		return (0);
	strcpy(person->name, name);
	person->age = age;
	person->next = NULL;
	printf("\n%s aged %d has been created\n\n", person->name, person->age);
	return (person);
}

// creat a node temp, go throught the list and free each node
void clean_up(t_node *list)
{
	t_node *next;
	if (list == NULL)
		printf("list is empty\n");
	while (list)
	{
		next = list->next;
		printf("\ncleaning %s from the list\n", list->name);
		free(list);
		list = next;
	}
}

// print node -> name and node -> age
void print_person(const t_node *person)
{
	if (person == NULL)
		printf("this person doesn't exist\n");
	else
	{
		printf("%s is %d years old and is stored at %p\n", person->name, person->age, person);
	}
}

// creat node temp, go throught the list and call function print_person
void print_list(t_node *list)
{
	const t_node *temp;
	if (list == NULL)
		printf("\nThe list is empty!!\n\n");
	else
	{
		printf("\n\nPrinting the list...\n\n");
		temp = list;
		while (temp)
		{
			print_person(temp);
			temp = temp->next;
		}
		printf("\n");
	}
}

/*
Creat list head named first, and node added to add new nodes to the list.
FYI: Can use fgets to ask for commande to quit or print.
Used strcmp to compare name to quit (to quit) or print to call function print_list.
Used scanf to collect name and age of person, called new_person function to creat a new node
and added it to list and looped eveything.
Cleared the list at the end of programme to avoid leaks.
*/
int main(void)
{
	t_node *first;
	t_node *added;
	int age;
	char name[30] = {'\0'};

	first = NULL;
	added = NULL;
	age = 0;
	
	while (0 != strcmp (name, "quit"))
	{
		printf("(enter quit to quit or print to print list)\nEnter person's name: ");
		scanf("%s", name);
		if (0 == strcmp (name, "quit"))
		{
			printf("Quitting...\n");
			clean_up(first);
			first = NULL;
			added = NULL;
			return(0);
		}
		else if (0 == strcmp (name, "print"))
		{
			print_list(first);
			continue;
		}
		printf("enter %s's age: ", name);
		scanf("%d", &age);
		printf("adding %s to the list ...\n", name);

		if (first == NULL)
		{
			first = new_person(name, age);
			if (first != NULL)
				added = first;
		}
		else
		{
			added->next = new_person(name, age);
			if (added->next != NULL)
				added = added->next;
		}
	}
	print_list(first);
	clean_up(first);
	first = NULL;
	added = NULL;
}