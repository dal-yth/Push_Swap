/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:06 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:15:16 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Counts the numbers in current partition that are larger
** or smaller than median, depending which stack is calling.
** Keeps the count in PC (push_count) which is used to optimize pushing.
*/

void	get_push_count(t_stacks *stack, int a)
{
	int temp;
	int i;

	i = 0;
	(a) ? (temp = SIZE) :
	(temp = PART[P_POS]);
	PC = 0;
	while (temp)
	{
		if (a)
		{
			if (A[i] < MEDIAN)
				PC = PC + 1;
		}
		else if (B[i] > MEDIAN)
			PC = PC + 1;
		i = i + 1;
		temp = temp - 1;
	}
}
