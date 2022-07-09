/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:37:28 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/09 18:47:44 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*list_init(t_var *list)
{
	list = (t_var *)malloc(sizeof(t_var));
	if (!list)
		exit(1);
	list->temp = NULL;
	list->len = 0;
	list->fd = 0;
	list->a = NULL;
	list->b = NULL;
	return (list);
}

void	add_node(t_node **top, t_node *node)
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
}

t_node	*list_filler(char **argv, t_var *list, t_node *temp)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		temp = malloc(sizeof(t_node));
		if (!list)
			return (NULL);
		temp->num = ps_atoll(argv[i]);
		temp->next = NULL;
		temp->previous = NULL;
		add_node(&list->a, temp);
		temp = NULL;
	}
	list->len = i;
	return (list->a);
}

void	top(t_node **list, t_node *node)
{
	node->previous = NULL;
	node->next = *list;
	if (*list != NULL)
		(*list)->previous = node;
	*list = node;
}

void	bottom(t_node **list, t_node *node)
{
	t_node	*temp;

	temp = *list;
	if (*list == NULL)
		*list = node;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->previous = temp;
	}
}