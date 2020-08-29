/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:19 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:37:26 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Solves the special case of exactly 3 numbers in stack.
** Depending on the position of the numbers, rotates and
** swaps them accordingly to always manage 3 numbers with
** maximum of 2 actions.
*/

static void	exact_3(t_stacks *stack, t_ops **op)
{
	if ((A[0] > A[1]) && (A[0] > A[2]) && (A[2] > A[1]))
		ra(stack, op, 1);
	else if ((A[1] > A[0]) && (A[1] > A[2]) && (A[0] > A[2]))
		rra(stack, op, 1);
	else
	{
		sa(stack, op, 1);
		if ((A[0] > A[1]) && (A[0] > A[2]))
			ra(stack, op, 1);
		else if ((A[1] > A[0]) && (A[1] > A[2]))
			rra(stack, op, 1);
	}
}

/*
** Sorts 3 numbers at the top of stack a in ascending order,
** when there is more than 3 numbers in stack a.
*/

static void	do_swaps(t_stacks *stack, t_ops **op)
{
	int check;

	check = 0;
	if (B[0] > B[1])
	{
		rr(stack, op, 1);
		check = 1;
	}
	else
		ra(stack, op, 1);
	if (B[0] < B[1])
		ss(stack, op, 1);
	else
		sa(stack, op, 1);
	if (check == 1)
		rrr(stack, op, 1);
	else
		rra(stack, op, 1);
	if (A[0] > A[1] && B[0] < B[1])
		ss(stack, op, 1);
	else if (A[0] > A[1])
		sa(stack, op, 1);
}

/*
** Solves 2-3 numbers in stacks a and b.
** First checks if there are only 2 numbers and sorts
** them if necessary. Then checks if 3 number case
** is already sorted. After that depending if 3 numbers
** are at top of other numbers or if there are exactly
** 3 numbers, chooses the appropriate sort.
*/

int			solve_3(t_stacks *stack, t_ops **op)
{
	if ((SIZE == 2) && (A[0] > A[1]))
	{
		sa(stack, op, 1);
		SIZE = 0;
		return (1);
	}
	SIZE = 0;
	if ((A[0] < A[1]) && (A[0] < A[2]) && (A[1] < A[2]))
		return (1);
	if (ACOUNT > 3)
	{
		if (A[0] > A[1])
		{
			(A[0] > A[1] && B[0] < B[1]) ?
			ss(stack, op, 1) : sa(stack, op, 1);
			if (A[1] > A[2])
				do_swaps(stack, op);
		}
		else
			do_swaps(stack, op);
	}
	else if (ACOUNT == 3)
		exact_3(stack, op);
	return (1);
}

/*
** Takes care of cases where current partition is 3
** members and the third member is larger than others.
*/

static void	special_case(t_stacks *stack, t_ops **op)
{
	if (B[0] < B[1])
		sb(stack, op, 1);
	pa(stack, op, 1);
	sb(stack, op, 1);
	pa(stack, op, 1);
	sa(stack, op, 1);
	pa(stack, op, 1);
	PART[P_POS] = PART[P_POS] - 3;
	SIZE = SIZE + 3;
}

/*
** Evaluates if values should be swapped around before
** pushing them to stack a. Small optimization over
** using just solve_3 function. Can save 1-2 moves per
** three sorted numbers in some cases.
*/

int			eval_pushed(t_stacks *stack, t_ops **op)
{
	if ((B[0] > B[1]) && (B[0] > B[2]) && (B[1] > B[2]))
		return (1);
	else if ((B[0] < B[1] && (B[0] < B[2]) && (B[1] > B[2])))
		sb(stack, op, 1);
	else if ((B[1] > B[0]) && (B[1] > B[2]) && (B[0] > B[2]))
		sb(stack, op, 1);
	else if ((B[2] > B[1]) && (B[2] > B[0]))
		special_case(stack, op);
	return (1);
}
