/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:18 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:37:35 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Checks if value in b, fits at the slot between
** first and last value of a or into a slot between
** two regular values.
*/

static void	b_conditions(t_stacks *stack, t_insert *is, int j, int i)
{
	if (A[0] > B[i] && A[ACOUNT - 1] < B[i])
	{
		get_ra_rra(stack, is, 0);
		get_rb_rrb(stack, is, i);
		compare(is);
	}
	else if (((j + 1) < ACOUNT) && (A[j] < B[i] && A[j + 1] > B[i]))
	{
		get_ra_rra(stack, is, j + 1);
		get_rb_rrb(stack, is, i);
		compare(is);
	}
}

/*
** Evaluates which value in stack b, takes the
** least amount of moves to get to correct
** position in stack a.
** There are three different kind of slots, where
** a value can be inserted, above smallest in a,
** between 2 values in a and between first and
** last value in a.
*/

static void	evaluate_b(t_stacks *stack, t_insert *is)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < BCOUNT)
	{
		while (j < ACOUNT)
		{
			b_conditions(stack, is, j, i);
			j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
}

/*
** Helper loop for insertsort.
** Evaluates best value, rotates, pushes and inits.
*/

static void	insert_loop(t_stacks *stack, t_ops **op, t_insert *is)
{
	evaluate_b(stack, is);
	do_rotate(stack, op, is);
	do_rev_rotate(stack, op, is);
	pa(stack, op, 1);
	init_best(is, stack);
}

/*
** Second sorting function, the insert sort.
** Insert sort pushes all but the biggest value
** to stack b, then it starts calculating which
** value in stack b takes the least amount of
** moves to get to the correct position in
** stack a, after the value is found, it is
** rotated and pushed to a.
*/

void		insertsort(t_stacks *stack, t_ops **op)
{
	t_insert	*is;
	int			big;
	int			small;

	big = get_biggest(stack);
	small = get_smallest(stack);
	(!(is = (t_insert*)malloc(sizeof(t_insert)))) ? malloc_error() : 0;
	init_is(is);
	init_best(is, stack);
	while (SIZE > 2)
	{
		if (A[0] == big || A[0] == small)
			ra(stack, op, 1);
		else
		{
			pb(stack, op, 1);
			SIZE = SIZE - 1;
		}
	}
	while (BCOUNT)
		insert_loop(stack, op, is);
	rot_in_order(stack, op);
	free(is);
}
