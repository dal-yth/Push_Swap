/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:02 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:36:03 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Depending on position of smallest
** value in stack a, rotates it so
** that the smallest value is at the
** top.
*/

static void	do_last_rot(t_stacks *stack, t_ops **op, int pos)
{
	if (pos <= (ACOUNT / 2))
	{
		while (pos)
		{
			ra(stack, op, 1);
			pos = pos - 1;
		}
	}
	else
	{
		while (ACOUNT - pos)
		{
			rra(stack, op, 1);
			pos = pos + 1;
		}
	}
}

/*
** Finds the position of smallest value in
** stack a and calls do_last_rot to rotate
** stack a to correct position.
*/

void		rot_in_order(t_stacks *stack, t_ops **op)
{
	int small;
	int pos;
	int i;

	i = 0;
	pos = 0;
	small = A[0];
	while (i < ACOUNT)
	{
		if (A[i] < small)
		{
			pos = i;
			small = A[i];
		}
		i = i + 1;
	}
	do_last_rot(stack, op, pos);
}

/*
** While rotation is needed, compares the
** rotation values and does rotation operations
** acoordingly.
*/

void		do_rotate(t_stacks *stack, t_ops **op, t_insert *is)
{
	while (is->best_ra || is->best_rb)
	{
		if (is->best_ra && is->best_rb)
		{
			rr(stack, op, 1);
			is->best_ra = is->best_ra - 1;
			is->best_rb = is->best_rb - 1;
		}
		else if (is->best_ra)
		{
			ra(stack, op, 1);
			is->best_ra = is->best_ra - 1;
		}
		else if (is->best_rb)
		{
			rb(stack, op, 1);
			is->best_rb = is->best_rb - 1;
		}
	}
}

/*
** While reverse rotation is needed, compares the
** reverse rotation values and does reverse rotation
** operations acoordingly.
*/

void		do_rev_rotate(t_stacks *stack, t_ops **op, t_insert *is)
{
	while (is->best_rra || is->best_rrb)
	{
		if (is->best_rra && is->best_rrb)
		{
			rrr(stack, op, 1);
			is->best_rra = is->best_rra - 1;
			is->best_rrb = is->best_rrb - 1;
		}
		else if (is->best_rra)
		{
			rra(stack, op, 1);
			is->best_rra = is->best_rra - 1;
		}
		else if (is->best_rrb)
		{
			rrb(stack, op, 1);
			is->best_rrb = is->best_rrb - 1;
		}
	}
}
