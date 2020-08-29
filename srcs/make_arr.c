/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:35:40 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:42:00 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Cycles through the correct char strings.
** Starting after possible options, get_count
** finds out how many positions for whitespaces
** there are between numbers and compares that
** to possible empty strings, because this
** push_swap allowes n amount of whitespaces
** between correct numbers.
*/

static void				get_count(t_check *check, char **arr)
{
	int i;
	int j;

	i = 0;
	j = POS;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if (ft_isdigit(arr[i][j]) || arr[i][j] == '-' || arr[i][j] == '+')
			{
				while (ft_isdigit(arr[i][j]) ||
				arr[i][j] == '-' || arr[i][j] == '+')
					j = j + 1;
				COUNT = COUNT + 1;
			}
			while (arr[i][j] == ' ')
				j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
}

/*
** Gets the number from the position opinted by *arr.
** Basically itoa, but with long long int so we don't
** need to deal with intmin intmax values also keeps
** count of the J position in original strings.
*/

static long long int	get_num(t_check *check, char *arr)
{
	long long int	i;
	int				j;
	int				k;
	int				neg;

	neg = 1;
	i = 0;
	j = 0;
	k = 0;
	if (arr[j] == '-' || arr[j] == '+')
	{
		if (arr[j] == '-')
			neg = -1;
		j = j + 1;
		J = J + 1;
	}
	while (ft_isdigit(arr[j]))
	{
		i = i * 10 + (arr[j++] - 48);
		k = k + 1;
		J = J + 1;
	}
	i = i * neg;
	(i > 2147483647 || i < -2147483648) ? put_error() : 0;
	return (i);
}

/*
** Assigns integer values from char array to int array stack.
** At this point the array is verified to be ok for assigning,
** so if we find -, + or digit, we call get_num itoa and loop
** until there is no more values to be found.
*/

static void				assign_values(t_stacks *stack, t_check *check)
{
	J = POS;
	I = 0;
	while (ARG[START])
	{
		while (ARG[START][J])
		{
			if (ft_isdigit(ARG[START][J]) ||
			ARG[START][J] == '-' || ARG[START][J] == '+')
			{
				A[I] = get_num(check, ARG[START] + J);
				J = J - 1;
				I = I + 1;
			}
			J = J + 1;
		}
		J = 0;
		START = START + 1;
	}
}

/*
** Check_dups string compares all arguments strings with each other.
** If two strings are identical, we put_error.
*/

static void				check_dups(t_stacks *stack)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (i < LEN)
	{
		while (j < LEN)
		{
			if (A[i] == A[j])
				put_error();
			j = j + 1;
		}
		i = i + 1;
		j = i + 1;
	}
}

/*
** Calls other functions to make stacks.
** Get count finds correct amount of numbers
** for allocating the stacks.
*/

void					make_arr(t_stacks *stack, t_check *check)
{
	COUNT = 0;
	get_count(check, ARG + START);
	LEN = COUNT;
	if (LEN == 0)
		exit(0);
	if (!(A = (long long int*)malloc(sizeof(long long int) * (COUNT))))
		malloc_error();
	if (!(B = (long long int*)malloc(sizeof(long long int) * (COUNT))))
		malloc_error();
	assign_values(stack, check);
	check_dups(stack);
}
