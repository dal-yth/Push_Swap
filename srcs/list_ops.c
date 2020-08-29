/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:36:41 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 21:08:16 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Executes current operation to stacks.
** String compares operation data to instruction,
** if it matches, executes the operation.
*/

static void		execute_op(t_stacks *stack, t_ops *op)
{
	if (ft_strcmp("sa", op->data) == 0)
		sa(stack, &op, 0);
	else if (ft_strcmp("sb", op->data) == 0)
		sb(stack, &op, 0);
	else if (ft_strcmp("ss", op->data) == 0)
		ss(stack, &op, 0);
	else if (ft_strcmp("pa", op->data) == 0)
		pa(stack, &op, 0);
	else if (ft_strcmp("pb", op->data) == 0)
		pb(stack, &op, 0);
	else if (ft_strcmp("ra", op->data) == 0)
		ra(stack, &op, 0);
	else if (ft_strcmp("rb", op->data) == 0)
		rb(stack, &op, 0);
	else if (ft_strcmp("rr", op->data) == 0)
		rr(stack, &op, 0);
	else if (ft_strcmp("rra", op->data) == 0)
		rra(stack, &op, 0);
	else if (ft_strcmp("rrb", op->data) == 0)
		rrb(stack, &op, 0);
	else if (ft_strcmp("rrr", op->data) == 0)
		rrr(stack, &op, 0);
}

/*
** Gets the created stack a and list of operations to perform.
** Evaluates options and calls visualizer.
*/

void			do_ops(t_stacks *stack, t_ops *op, t_visu *v, t_check *check)
{
	if (O)
		v->total = 0;
	if (V || BASIC || D)
	{
		get_minmax(stack, v);
		visu(stack, op, v, check);
	}
	while (op != NULL)
	{
		execute_op(stack, op);
		v->total = v->total + 1;
		if (V || BASIC || D)
			visu(stack, op, v, check);
		op = op->next;
	}
	if (O)
		ft_printf("OPERATIONS: %d\n", v->total);
}

/*
** Checks if data from get_next_line indeed is correct.
** Calls put_error if operation is not valid.
*/

static int		check_op(char *buf)
{
	if (ft_strcmp("sa", buf) == 0)
		return (1);
	if (ft_strcmp("sb", buf) == 0)
		return (1);
	if (ft_strcmp("ss", buf) == 0)
		return (1);
	if (ft_strcmp("pa", buf) == 0)
		return (1);
	if (ft_strcmp("pb", buf) == 0)
		return (1);
	if (ft_strcmp("ra", buf) == 0)
		return (1);
	if (ft_strcmp("rb", buf) == 0)
		return (1);
	if (ft_strcmp("rr", buf) == 0)
		return (1);
	if (ft_strcmp("rra", buf) == 0)
		return (1);
	if (ft_strcmp("rrb", buf) == 0)
		return (1);
	if (ft_strcmp("rrr", buf) == 0)
		return (1);
	put_error();
	return (0);
}

/*
** Append creates new t_ops list member and appends it to the list.
** Takes pointer to the head of the list and data for new node.
** If there is no list head, create it, else find out the last member
** of the list and make a new node to be the last member.
*/

int				append(t_ops **head, char *data)
{
	t_ops *last;

	last = *head;
	if (*head == NULL)
	{
		*head = newnode(data);
		return (1);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newnode(data);
	return (1);
}

/*
** Get_ops uses get_next_line to read operations from standard input.
** Calls check_op verify that each line read is ok.
** Append makes linked list with read values.
*/

void			get_ops(t_ops **op)
{
	char *buf;

	while (get_next_line(0, &buf) > 0)
	{
		check_op(buf);
		append(op, buf);
		free(buf);
	}
}
