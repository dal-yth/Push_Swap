/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:26 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:13:06 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_ops	*remove_helper(t_ops *temp1, int total)
{
	t_ops *temp2;

	while (total > 0)
	{
		temp2 = temp1->next;
		free(temp1->data);
		free(temp1);
		temp1 = NULL;
		temp1 = temp2;
		total = total - 1;
	}
	return (temp1);
}

/*
** Calculates the total amount of nodes to be
** removed, frees them and sets the cur->next
** node to be the next node after removed nodes.
*/

static void		remove_elems(t_stacks *stack, t_ops *cur, int i, int j)
{
	t_ops	*temp1;
	t_ops	*prev;
	int		total;

	temp1 = cur->next;
	prev = cur;
	(i < j) ? (total = i * 2) : 0;
	(i == j) ? (total = i + j) : 0;
	if (i > j)
	{
		CHOICE = 1;
		total = j * 2;
		while (i - j++)
		{
			temp1 = temp1->next;
			prev = prev->next;
		}
	}
	temp1 = remove_helper(temp1, total);
	(CHOICE == 1) ? (prev->next = temp1) :
	(cur->next = temp1);
}

/*
** If rm_op gets matching pair of inputs, it attemps to
** find as many matching pairs as possible from the
** starting position, then it calls remove elems to
** free and re-link the list.
*/

static void		rm_op(t_stacks *stack, t_ops *cur, char *op1, char *op2)
{
	t_ops	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = cur->next;
	while (temp && (ft_strcmp(temp->data, op1) == 0))
	{
		temp = temp->next;
		i = i + 1;
	}
	while (temp && (ft_strcmp(temp->data, op2) == 0))
	{
		temp = temp->next;
		j = j + 1;
	}
	CHOICE = 0;
	if ((i >= 1) && (j >= 1))
		remove_elems(stack, cur, i, j);
}

/*
** If operations sa and ss are found in consecutive nodes,
** removes them and replaces with ss.
*/

static void		replace_op(t_ops *cur, char *str)
{
	t_ops *prev;
	t_ops *temp;

	prev = cur;
	prev->data = ft_strcpy(prev->data, str);
	temp = cur->next;
	prev->next = temp->next;
	free(temp->data);
	free(temp);
	temp = NULL;
}

/*
** Goes through the linked list and removes pointless operations.
** Basically my algorithm does two operations in a row that cancel
** each other, for example rotates a while trying to find values
** smaller than median, then reverse rotates a to return to the
** correct position. Removing these useless actions is one of
** the biggest optimizations and can cut several hundred operations
** when dealing with lot of numbers.
*/

void			optimize_output(t_stacks *stack, t_ops *op)
{
	t_ops *cur;

	cur = op;
	while (cur && cur->next)
	{
		if ((ft_strcmp(cur->data, "sa\n") == 0) &&
			(ft_strcmp(cur->next->data, "sb\n") == 0))
			replace_op(cur, "ss\n");
		else if (ft_strcmp(cur->next->data, "ra\n") == 0)
			rm_op(stack, cur, "ra\n", "rra\n");
		else if (ft_strcmp(cur->next->data, "rra\n") == 0)
			rm_op(stack, cur, "rra\n", "ra\n");
		else if (ft_strcmp(cur->next->data, "pa\n") == 0)
			rm_op(stack, cur, "pa\n", "pb\n");
		else if (ft_strcmp(cur->next->data, "pb\n") == 0)
			rm_op(stack, cur, "pb\n", "pa\n");
		else if (ft_strcmp(cur->next->data, "rrb\n") == 0)
			rm_op(stack, cur, "rrb\n", "rb\n");
		else if (ft_strcmp(cur->next->data, "rb\n") == 0)
			rm_op(stack, cur, "rb\n", "rrb\n");
		cur = cur->next;
	}
}
