#include "push_swap.h"

static void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

/*
** Stores the stack in an array, sorts the array, and finds the median
*/

static void	find_median(t_frame *frame, t_stack *stack, char stack_name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	frame->stack_len = find_stack_len(frame, stack_name);
	quarter_len = frame->stack_len / 4;
	if (!(array = (long*)malloc(sizeof(long) * (frame->stack_len + 1))))
		push_swap_error(frame);
	while (i < frame->stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	sort_array(array, frame->stack_len);
	QUARTER = array[quarter_len];
	MEDIAN = array[quarter_len * 2];
	THREE_Q = array[quarter_len * 3];
	free(array);
}

void		median(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	find_median(frame, stack, stack_name);
}

/*----------------------------*/
void	find_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	SMALLEST = BIGGEST;
	while (1)
	{
		if (tmp->num <= SMALLEST)
			SMALLEST = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest(t_frame *frame, char stack_name)
{
	t_stack		*stack;
	t_stack		*tmp;
	t_stack		*end;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	tmp = stack;
	BIGGEST = tmp->num;
	end = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
	while (1)
	{
		if (tmp->num > BIGGEST)
			BIGGEST = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	find_biggest_smallest(t_frame *frame, char stack_name)
{
	t_stack		*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	find_biggest(frame, stack_name);
	find_smallest(frame, stack_name);
}

/*---------------------------------------*/

void		moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a : frame->b;
		element = (flag == 1) ? SMALLEST : BIGGEST;
		while (tmp->num != element)
		{
			flag == 1 ? SMALL_ROTATE++ : BIG_ROTATE++;
			tmp = tmp->next;
		}
	}
}

/*
** Calculates moves to bottom of stack
*/

void		moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_stack	*stack;
	t_stack	*tmp;
	int		element;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	if (stack)
	{
		tmp = (stack_name == 'a') ? frame->a->prev : frame->b->prev;
		element = (flag == 1) ? SMALLEST : BIGGEST;
		while (tmp->num != element)
		{
			flag == 1 ? SMALL_RROTATE++ : BIG_RROTATE++;
			tmp = tmp->prev;
		}
		flag == 1 ? SMALL_RROTATE++ : BIG_RROTATE++;
	}
}

static void	moves_smallest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 1;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (SMALL_ROTATE <= SMALL_RROTATE)
			SMALL_RROTATE = -1;
		else
			SMALL_ROTATE = -1;
	}
}

static void	moves_biggest(t_frame *frame, char stack_name)
{
	t_stack	*stack;
	int		flag;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	flag = 2;
	if (stack)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
		if (BIG_ROTATE <= BIG_RROTATE)
			BIG_RROTATE = -1;
		else
			BIG_ROTATE = -1;
	}
}

/*
** Calculates which has fewest moves to push to stack a:
** the biggest or smallest integer in stack b,
** either by rotating to the top or reverse rotating to the end.
*/

void		find_moves(t_frame *frame, char stack_name)
{
	t_stack	*stack;

	stack = (stack_name == 'a') ? frame->a : frame->b;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (BIG_ROTATE != -1 && (BIG_ROTATE >= SMALL_ROTATE &&
		BIG_ROTATE >= SMALL_RROTATE))
		BIG_ROTATE = -1;
	else if (BIG_RROTATE != -1 && (BIG_RROTATE >= SMALL_ROTATE &&
		BIG_RROTATE >= SMALL_RROTATE))
		BIG_RROTATE = -1;
	else if (SMALL_ROTATE != -1 && (SMALL_ROTATE >= BIG_ROTATE &&
		SMALL_ROTATE >= BIG_RROTATE))
		SMALL_ROTATE = -1;
	else if (SMALL_RROTATE != -1 && (SMALL_RROTATE >= BIG_ROTATE &&
		SMALL_RROTATE >= BIG_RROTATE))
		SMALL_RROTATE = -1;
	if (SMALL_ROTATE != -1 || SMALL_RROTATE != -1)
		SMALL_FLAG = 1;
	else if (BIG_ROTATE != -1 || BIG_RROTATE != -1)
		BIG_FLAG = 1;
}