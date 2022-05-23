/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:53:25 by jechekao          #+#    #+#             */
/*   Updated: 2022/05/23 15:42:21 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int	age;
	struct t_node *next;
}t_node;

t_node	*init_person(const int age)
{
	t_node	*new_person;

	new_person = malloc(sizeof(t_node));
	new_person->age = age;
	new_person->next = NULL;
	printf("created new person at %p\n", new_person);
	return (new_person);
}

void	print_person(const t_node *person, const char *name)
{
	if (person == NULL)
		printf("%s person is NULL\n", name);
	else
	{
		printf("%s person's age is: %d, stored at %p, and the next in line address is: %p\n",
			name, person->age, person, person->next);
	}
}

void clean_up(t_node *list)
{
	t_node *next;
	while (list)
	{
		next = list->next;
		printf("cleaning %d\n", list->age);
		free(list);
		list = next;
	}
}

void print_list(const t_node *list)
{
	printf("printing list\n");
	const t_node *temp;
	temp = list;
	if (temp == NULL)
		printf("list is empty\n");
	else
	{
		while(temp)
		{
			print_person(temp, "temp");
			temp = temp->next;
		}
	}
}

int	main(void)
{
	int age;
	t_node	*first;
	t_node	*added;

	age = 0;
	first = NULL;
	added = NULL;
	while (age != 200)
	{
		printf("to close programme, enter 200\nintput a new person's age:");
		scanf("%d", &age);

		if (first == NULL)
		{
			first = init_person(age);
			if (first != NULL)
				added = first;
		}
		else
		{
			added->next = init_person(age);
			if (added->next != NULL)
				added = added->next;
		}
	}
	print_list(first);
	clean_up(first);
	first = NULL;
	added = NULL;
	
}
