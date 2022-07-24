/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:28 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/24 18:59:16 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*list_init(t_var *list, char **argv) //needed
{
	list = (t_var *)malloc(sizeof(t_var));
	if (!list)
		exit(1);
	list->argv = argv;
	list->len = 0;
	list->a = NULL;
	list->b = NULL;
	list->sorted = NULL;
	return (list);
}

void	add_node(t_node **top, t_node *node) //needed
{
	t_node	*temp;

	if (*top == NULL)
		*top = node;
	else
	{
		temp = *top;
		while (temp->next)
			temp = temp -> next;
		temp->next = node;
		node->previous = temp;
	}
	printf("new is: %p and a is: %p\n", node, &temp);
}

void	list_filler(t_var *list, t_node *new, int num) //needed
{
	if (!(new = malloc(sizeof(t_node))))
		error_exit(list);
	new->next = NULL;
	new->previous = NULL;
	new->num = num;
	add_node(&list->a, new);
	printf("new holds: %d\n", new->num);
	//printf("new is: %p and a is: %p\n", new, &list->a);
	//new = NULL;
}

void	indx_a(t_var *list) //needed
{
	int		i;
	t_node	*temp;
	t_node	*temp_1;

	sort_list(list);
	list->len = list_len(list->a);
	i = 0;
	temp = list->sorted;
	temp_1 = list->a;
	while (temp)
	{
		if (temp->num == temp_1->num)
		{
			temp_1->indx = i++;
			temp = temp->next;
			temp_1 = list->a;
		}
		else
			temp_1 = temp_1->next;
	}
	pivote(list);
}

void	pivote(t_var *list) //needed
{
	t_node	*temp;
	int		i;

	temp = list->a;
	if (list->len <= 10)
		i = list->len / 2;
	else if (list->len > 10 && list->len < 200)
		i = list->len / 4;
	else if (list->len >= 200)
		i = list->len / 8;
	while (temp)
	{
		if (temp->indx == i)
			list->ref = temp->num;
		temp = temp->next;
	}
}
