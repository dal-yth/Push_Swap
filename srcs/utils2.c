/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:39 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 20:52:41 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Puts the required error message to standard error,
** followed by new line and exits program.
*/

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

/*
** In case of malloc error, reports it and exits.
*/

void	malloc_error(void)
{
	write(2, "Malloc error.\n", 14);
	exit(0);
}

/*
** Initializes check structure values.
** I = 1 is to avoid program name in argv.
*/

void	init_check(t_check *check, char **argv)
{
	F = 0;
	V = 0;
	C = 0;
	D = 0;
	O = 0;
	J = 0;
	I = 1;
	BASIC = 0;
	ARG = argv;
}

/*
** Allocates and creates new node with data.
*/

t_ops	*newnode(char *data)
{
	t_ops *new;

	if (!(new = (t_ops*)malloc(sizeof(t_ops))))
		malloc_error();
	if (!(new->data = (char*)malloc(sizeof(char) * (ft_strlen(data) + 1))))
		malloc_error();
	new->data = ft_strcpy(new->data, data);
	new->next = NULL;
	return (new);
}

/*
** During rotation, pushes the values that are
** smaller than median.
*/

void	push_rot(t_stacks *stack, t_ops **op)
{
	if (A[0] < MEDIAN)
	{
		pb(stack, op, 1);
		SIZE = SIZE - 1;
		PART[P_POS] = PART[P_POS] + 1;
	}
}
