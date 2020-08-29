/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_counts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:35:54 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:57:14 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Checks whether we have even or odd amount of numbers
** in stack a, based on that, we assigns correct value
** to rotate counters.
*/

void	get_ra_rra(t_stacks *stack, t_insert *is, int j)
{
	int middle;

	(ACOUNT % 2) ? (middle = 1) :
	(middle = 0);
	if (middle)
	{
		if (j <= (ACOUNT / 2))
			is->ra = j;
		else
			is->rra = (ACOUNT - j);
	}
	else
	{
		if (j < (ACOUNT / 2))
			is->ra = j;
		else
			is->rra = (ACOUNT - j);
	}
}

/*
** Checks whether we have even or odd amount of numbers
** in stack a, based on that, we assigns correct value
** to rotate counters.
*/

void	get_rb_rrb(t_stacks *stack, t_insert *is, int i)
{
	int middle;

	(BCOUNT % 2) ? (middle = 1) :
	(middle = 0);
	if (middle)
	{
		if (i <= (BCOUNT / 2))
			is->rb = i;
		else
			is->rrb = (BCOUNT - i);
	}
	else
	{
		if (i < (BCOUNT / 2))
			is->rb = i;
		else
			is->rrb = (BCOUNT - i);
	}
}

/*
** Gets the total count of rotates,
** taking into account that both rotates
** having value equal to single double
** rotate. Compares rotate values to
** current best total value, if it is
** smaller, current values become best
** values.
*/

void	compare(t_insert *is)
{
	int new_total;
	int rr;
	int rrr;

	if (is->ra >= is->rb)
		rr = is->ra;
	else
		rr = is->rb;
	if (is->rra >= is->rrb)
		rrr = is->rra;
	else
		rrr = is->rrb;
	new_total = rr + rrr;
	if (new_total < is->best_total)
	{
		is->best_ra = is->ra;
		is->best_rra = is->rra;
		is->best_rb = is->rb;
		is->best_rrb = is->rrb;
		is->best_total = new_total;
	}
	init_is(is);
}
