/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:59 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/17 15:46:39 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Shifts down all elements of stack a by 1.
** Last element becomes the first one.
*/

void	rra(t_stacks *stack, t_ops **op, int apnd)
{
	long long int	j;
	int				i;

	i = ACOUNT - 1;
	if (ACOUNT > 1)
	{
		j = A[ACOUNT - 1];
		while (i >= 1)
		{
			A[i] = A[i - 1];
			i = i - 1;
		}
		A[0] = j;
	}
	if (apnd)
		append(op, "rra\n");
}

/*
** Shifts down all elements of stack b by 1.
** Last element becomes the first one.
*/

void	rrb(t_stacks *stack, t_ops **op, int apnd)
{
	long long int	j;
	int				i;

	i = BCOUNT - 1;
	if (BCOUNT > 1)
	{
		j = B[BCOUNT - 1];
		while (i >= 1)
		{
			B[i] = B[i - 1];
			i = i - 1;
		}
		B[0] = j;
	}
	if (apnd)
		append(op, "rrb\n");
}

/*
** Both rra and rrb.
*/

void	rrr(t_stacks *stack, t_ops **op, int apnd)
{
	if (ACOUNT > 1 && BCOUNT > 1)
	{
		rra(stack, op, 0);
		rrb(stack, op, 0);
		if (apnd)
			append(op, "rrr\n");
	}
	else if (ACOUNT > 1)
		rra(stack, op, apnd);
	else if (BCOUNT > 1)
		rrb(stack, op, apnd);
}
