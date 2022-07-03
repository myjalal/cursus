#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct node
{
	int				num;
	struct node		*next;
	struct node		*previous;
}	t_node;


void	swap(t_node **list);

void	s_swap(t_node **list_a, t_node **list_b);

void	one_top_two(t_node **l_one, t_node **l_two);

void	revers(t_node **list);

void	r_revers(t_node **list);

#endif
