#include "push_swap.h"

/*
** Pushes biggest or smallest from stack B to stack A, in sorted order
*/
void		push_quarters(t_frame *frame, t_stack *stack_a, int split) //split = 1
{
	t_stack	*stack_a_end;
	int		flag;

	stack_a_end = frame->a->prev;
	flag = 0;
	find_biggest_smallest(frame, 'a');
	while (flag != 1)
	{
		stack_a == stack_a_end ? flag = 1 : 0;
		if (split == 1 && stack_a->num <= QUARTER)
			push_first_quarter(frame);
		else if (split == 2 && stack_a->num > QUARTER && stack_a->num <= MEDIAN)
			push_second_quarter(frame);
		else if (split == 3 && stack_a->num > MEDIAN && stack_a->num <= THREE_Q)
			push_third_quarter(frame);
		else if (split == 4 && stack_a->num > THREE_Q)
			push_fourth_quarter(frame);
		else if (split == 4 && stack_a->num == SMALLEST)
			break ;
		else
			do_ra(frame);
		stack_a = frame->a;
	}
	reset_moves(frame);
}
static void	rotate_and_push_to_a(t_frame *frame)
{
	if (SMALL_ROTATE >= 0)
		while (SMALL_ROTATE--)
			do_rb(frame);
	else if (SMALL_RROTATE >= 0)
		while (SMALL_RROTATE--)
			do_rrb(frame);
	else if (BIG_ROTATE >= 0)
		while (BIG_ROTATE--)
			do_rb(frame);
	else if (BIG_RROTATE >= 0)
		while (BIG_RROTATE--)
			do_rrb(frame);
	do_pa(frame);
	SMALL_FLAG ? do_ra(frame) : 0;
	(BIG_FLAG || !frame->b) ? frame->after_rotate++ : 0;
	reset_moves(frame);
}

static void	push_big_small(t_frame *frame, t_stack *stack, t_stack *stack_end)
{
	while (1)
	{
		while (stack->num != SMALLEST && stack->num != BIGGEST)
			stack = stack->next;
		if (stack->num == SMALLEST || stack->num == BIGGEST)
		{
			rotate_and_push_to_a(frame);
			break ;
		}
		else
			stack = stack->next;
		if (stack == stack_end)
			break ;
		stack = frame->b;
	}
}

/*
** Divides stack A into quarters
** Pushes everything above/below quarters into stack B
** Identifies biggest + smallest
** Whichever one is fewer moves gets pushed to stack A
** Pushes smallest to the end of A
** Pushes biggest to the top of A
*/

void		insertion_solve_quarters(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a'); // find 1/4, 2/4, 3/4 
	while (frame->a)
	{
		push_quarters(frame, frame->a, split); //push quarter from a to b
		while (frame->b)
		{
			find_biggest_smallest(frame, 'b'); // find biggerst and smallest of b
			find_moves(frame, 'b');
			if (frame->b && (SMALL_ROTATE >= 0 || SMALL_RROTATE >= 0
				|| BIG_ROTATE >= 0 || BIG_RROTATE >= 0))
				push_big_small(frame, frame->b, frame->b->prev);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 5)
			break ;
	}
}