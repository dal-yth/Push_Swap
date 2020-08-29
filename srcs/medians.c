/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medians.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:32 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 21:06:18 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Sorts temporary array M in ascending order.
** Loops through M, and keeps swapping values
** until M is sorted.
*/

static int	sort_m(t_stacks *stack, int count)
{
	int				change;
	int				i;
	long long int	temp;

	change = 0;
	i = 0;
	while (i < (count - 1))
	{
		if (M[i] > M[i + 1])
		{
			temp = M[i];
			M[i] = M[i + 1];
			M[i + 1] = temp;
			change = 1;
		}
		i = i + 1;
	}
	return (change);
}

/*
** Gets the median of SIZE amount of numbers in stack a.
** Size amount of numbers are copied to temporary array M.
** M is sorted in sort_M in ascending order and median is
** calculated based on amount of numbers being even or odd.
** For odd values we choose middle value and for even we
** take a value between two middle values.
*/

void		get_median(t_stacks *stack)
{
	int	temp;
	int	change;

	change = 1;
	temp = SIZE;
	if (!(M = (long long int*)malloc(sizeof(long long int) * SIZE)))
		malloc_error();
	while (temp--)
		M[temp] = A[temp];
	while (change)
	{
		change = 0;
		change = sort_m(stack, SIZE);
	}
	(SIZE % 2) ? (MEDIAN = (M[SIZE / 2])) :
	(MEDIAN = ((M[SIZE / 2] + M[(SIZE / 2) - 1]) / 2));
	free(M);
}

/*
** Gets median of partition in stack b.
** Partition (PART) in position P_POS has PART[P_POS] numbers.
** This information is used to make a temporary int array M,
** where partition values are copied. sort_M function sorts M
** array in ascending order so we can find median value.
** Different median is used depending if the array has even or
** odd amount of numbers. With odd, we choose middle value, with even
** we divide the two middle values by two.
*/

void		part_median(t_stacks *stack)
{
	int	temp;
	int	change;

	change = 1;
	temp = PART[P_POS];
	if (!(M = (long long int*)malloc(sizeof(long long int) * PART[P_POS])))
		malloc_error();
	while (temp--)
		M[temp] = B[temp];
	while (change)
	{
		change = 0;
		change = sort_m(stack, PART[P_POS]);
	}
	(PART[P_POS] % 2) ? (MEDIAN = (M[PART[P_POS] / 2])) :
	(MEDIAN = ((M[PART[P_POS] / 2] + M[(PART[P_POS] / 2) - 1]) / 2));
	free(M);
}

/*
** Gets the median of SIZE amount of rot numbers in stack a.
** Size amount of numbers are copied to temporary array M.
** M is sorted in sort_M in ascending order and median is
** calculated based on amount of numbers being even or odd.
** For odd values we choose middle value and for even we
** take a value between two middle values.
*/

void		rot_median(t_stacks *stack)
{
	int	temp;
	int	change;
	int temp2;

	change = 1;
	temp = SIZE - 1;
	temp2 = ACOUNT - 1;
	if (!(M = (long long int*)malloc(sizeof(long long int) * SIZE)))
		malloc_error();
	while (temp >= 0)
	{
		M[temp] = A[temp2];
		temp = temp - 1;
		temp2 = temp2 - 1;
	}
	while (change)
	{
		change = 0;
		change = sort_m(stack, SIZE);
	}
	(SIZE % 2) ? (MEDIAN = (M[SIZE / 2])) :
	(MEDIAN = ((M[SIZE / 2] + M[(SIZE / 2) - 1]) / 2));
	free(M);
}
