/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:11 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 21:00:10 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Initializes rotation counts.
*/

void	init_is(t_insert *is)
{
	is->ra = 0;
	is->rra = 0;
	is->rb = 0;
	is->rrb = 0;
}

/*
** Initializes best rotation counts.
** Total is assigned to be LEN * 2
** because it is always much higher
** value than maximum amount of moves
** possible for any number.
*/

void	init_best(t_insert *is, t_stacks *stack)
{
	is->best_ra = 0;
	is->best_rra = 0;
	is->best_rb = 0;
	is->best_rrb = 0;
	is->best_total = LEN * 2;
}

/*
** Finds the smallest value in stack a,
** compares it against the current value
** in b and returns the position of smallest
** if current b was smaller, else returns -1.
*/

int		get_smallest(t_stacks *stack)
{
	int i;
	int small;

	i = 0;
	small = A[0];
	while (i < ACOUNT)
	{
		if (A[i] < small)
			small = A[i];
		i = i + 1;
	}
	return (small);
}

/*
** Finds the biggest value in stack a.
** Is used to leave the biggest value
** in stack a during the initial push to b.
** Makes it so that when we push back from b
** We never have to consider if the value
** could be largest in the stack.
*/

int		get_biggest(t_stacks *stack)
{
	int i;
	int big;

	i = 0;
	big = A[0];
	while (i < ACOUNT)
	{
		if (A[i] > big)
			big = A[i];
		i = i + 1;
	}
	return (big);
}
