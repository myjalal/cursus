/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:50:41 by jechekao          #+#    #+#             */
/*   Updated: 2022/07/17 18:56:08 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// managing errors
#include "push_swap.h"

void		free_stack(t_node *stack)
{
	t_node		*track_next;
	t_node		*delete;

	if (stack)
	{
		track_next = stack->next;
		while (track_next != stack)
		{
			delete = track_next;
			track_next = track_next->next;
			free(delete);
		}
		free(track_next);
	}
}

void		free_frame(t_var *frame)
{
	if (frame)
	{
		if (frame->a)
			free_stack(frame->a);
		if (frame->b)
			free_stack(frame->b);
		if (frame->sorted)
			free_stack(frame->sorted);
		free(frame);
	}
}

void			free_string(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str[i] == NULL)
		free(str[i]);
	str = NULL;
}

int	error_exit(char *error, int err_exit, t_var *list)
{
	if (err_exit != 0)
		ft_putstr_fd(error, 2);
	free_frame(list);
	exit(err_exit);
}
