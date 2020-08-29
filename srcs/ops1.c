/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:49 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/17 15:50:13 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Swaps the first 2 elements of stack a.
*/

void	sa(t_stacks *stack, t_ops **op, int apnd)
{
	long long int temp;

	if (ACOUNT > 1)
	{
		temp = A[1];
		A[1] = A[0];
		A[0] = temp;
	}
	if (apnd)
		append(op, "sa\n");
}

/*
** Swaps the first 2 elements of stack b.
*/

void	sb(t_stacks *stack, t_ops **op, int apnd)
{
	long long int temp;

	if (BCOUNT > 1)
	{
		temp = B[1];
		B[1] = B[0];
		B[0] = temp;
	}
	if (apnd)
		append(op, "sb\n");
}

/*
** Makes both sa and sb operations.
*/

void	ss(t_stacks *stack, t_ops **op, int apnd)
{
	if (ACOUNT > 1 && BCOUNT > 1)
	{
		sa(stack, op, 0);
		sb(stack, op, 0);
		if (apnd)
			append(op, "ss\n");
	}
	else if (ACOUNT > 1)
		sa(stack, op, apnd);
	else if (BCOUNT > 1)
		sb(stack, op, apnd);
}

/*
** Moves the value on top of a, to the top of b.
** Stack b is rotated one position backwards and
** stack a is rotated one position forwards.
** Change counts accordingly.
*/

void	pb(t_stacks *stack, t_ops **op, int apnd)
{
	int i;

	i = BCOUNT - 1;
	if (ACOUNT > 0)
	{
		if (BCOUNT > 0)
		{
			while (i >= 0)
			{
				B[i + 1] = B[i];
				i = i - 1;
			}
		}
		B[0] = A[0];
		i = 1;
		while (i < ACOUNT)
		{
			A[i - 1] = A[i];
			i = i + 1;
		}
		BCOUNT = BCOUNT + 1;
		ACOUNT = ACOUNT - 1;
	}
	if (apnd)
		append(op, "pb\n");
}

/*
** Moves the value on top of b, to the top of a.
** Stack a is rotated one position backwards and
** stack b is rotated one position forwards.
** Change counts accordingly.
*/

void	pa(t_stacks *stack, t_ops **op, int apnd)
{
	int	i;

	i = ACOUNT - 1;
	if (BCOUNT > 0)
	{
		if (ACOUNT > 0)
		{
			while (i >= 0)
			{
				A[i + 1] = A[i];
				i = i - 1;
			}
		}
		A[0] = B[0];
		i = 1;
		while (i < BCOUNT)
		{
			B[i - 1] = B[i];
			i = i + 1;
		}
		BCOUNT = BCOUNT - 1;
		ACOUNT = ACOUNT + 1;
	}
	if (apnd)
		append(op, "pa\n");
}
