/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:34 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:49:20 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Frees linked nodes, int arrays and stack.
*/

void	free_stuff(t_stacks *stack, t_ops **head, t_check *check, int pw)
{
	t_ops	*lst;
	t_ops	*nextlst;

	I = 0;
	lst = *head;
	while (lst)
	{
		nextlst = lst->next;
		free(lst->data);
		free(lst);
		lst = nextlst;
	}
	*head = NULL;
	free(A);
	free(B);
	if (pw)
		free(PART);
	free(stack);
	free(check);
}

/*
** Writes out operations for checker.
*/

void	write_ops(t_ops *op)
{
	int		i;
	char	*ops;
	char	*temp;

	ops = ft_strnew(1);
	i = 0;
	while (op != NULL)
	{
		temp = ft_strjoin(ops, op->data);
		ft_strdel(&ops);
		ops = temp;
		op = op->next;
		i = i + 1;
	}
	write(1, ops, ft_strlen(ops));
	free(ops);
}

/*
** Goes through stack a until it either finds
** that a[i] is larger than a[a + 1] or gets
** all the way through, in which case stack is
** sorted.
*/

int		is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	if (ACOUNT < LEN)
		return (0);
	while ((i + 1) < ACOUNT)
	{
		if (A[i] > A[i + 1])
			return (0);
		i = i + 1;
	}
	return (1);
}

/*
** Gets info from stack a.
** Finds out how many numbers are in stack a,
** allocates stack B and partition array.
** Amount of partitions necessary is found by
** dividing total amount of numbers by 2, since
** our algorithm keeps splitting numbers into
** two "equally large" partitions.
*/

void	get_info(t_stacks *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = LEN;
	if (CHOICE == 1)
	{
		while (temp)
		{
			temp = temp / 2;
			i = i + 1;
		}
		if (!(PART = (int*)malloc(sizeof(int) * i)))
			malloc_error();
		while (i--)
			PART[i] = 0;
	}
	ACOUNT = LEN;
	BCOUNT = 0;
}

/*
** Ok_ko checks if the solved stack a is in ascending order.
** Prints, KO if it is not and OK if it is.
*/

void	ok_ko(t_stacks *stack)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while ((i + 1) < ACOUNT)
	{
		if (A[i] > A[i + 1])
			check = 1;
		i = i + 1;
	}
	if (ACOUNT != LEN)
		check = 1;
	if (check == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
