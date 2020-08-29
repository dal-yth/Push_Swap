/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:54 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/17 15:50:02 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Shifts up all elements of stack a by 1.
** First element becomes the last one.
*/

void	ra(t_stacks *stack, t_ops **op, int apnd)
{
	long long int	j;
	int				i;

	i = 1;
	if (ACOUNT > 1)
	{
		j = A[0];
		while (i < ACOUNT)
		{
			A[i - 1] = A[i];
			i = i + 1;
		}
		A[i - 1] = j;
	}
	if (apnd)
		append(op, "ra\n");
}

/*
** Shifts up all elements of stack b by 1.
** First element becomes the last one.
*/

void	rb(t_stacks *stack, t_ops **op, int apnd)
{
	long long int	j;
	int				i;

	i = 1;
	if (BCOUNT > 1)
	{
		j = B[0];
		while (i < BCOUNT)
		{
			B[i - 1] = B[i];
			i = i + 1;
		}
		B[i - 1] = j;
	}
	if (apnd)
		append(op, "rb\n");
}

/*
** Both ra and rb.
*/

void	rr(t_stacks *stack, t_ops **op, int apnd)
{
	if (BCOUNT > 1 && ACOUNT > 1)
	{
		ra(stack, op, 0);
		rb(stack, op, 0);
		if (apnd)
			append(op, "rr\n");
	}
	else if (ACOUNT > 1)
		ra(stack, op, apnd);
	else if (BCOUNT > 1)
		rb(stack, op, 0);
}
