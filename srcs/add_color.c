/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:32:45 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:32:46 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Appends colorcode for bold green and
** reset to the correct string.
*/

static void	append_color(t_visu *v, int choice)
{
	char *temp1;
	char *temp2;

	if (choice)
		temp1 = ft_strjoin("\33[1;32m", v->print_a);
	else
		temp1 = ft_strjoin("\33[1;32m", v->print_b);
	temp2 = ft_strjoin(temp1, "\033[0m");
	free(temp1);
	if (choice)
		ft_strdel(&v->print_a);
	else
		ft_strdel(&v->print_b);
	if (choice)
		v->print_a = temp2;
	else
		v->print_b = temp2;
}

/*
** Compares operation data and position
** in stack to determine if color should
** be added. Basically color can only be
** first, second or last number.
*/

void		add_color(t_stacks *stack, t_ops *op, t_visu *v, t_check *check)
{
	if (((ft_strcmp(op->data, "sa") == 0) ||
		(ft_strcmp(op->data, "ss") == 0)) && I == 1)
		append_color(v, 1);
	if (((ft_strcmp(op->data, "sb") == 0) ||
		(ft_strcmp(op->data, "ss") == 0)) && I == 1)
		append_color(v, 0);
	if (((ft_strcmp(op->data, "ra") == 0) ||
		(ft_strcmp(op->data, "rr") == 0)) && I == ACOUNT - 1)
		append_color(v, 1);
	if (((ft_strcmp(op->data, "rb") == 0) ||
		(ft_strcmp(op->data, "rr") == 0)) && I == BCOUNT - 1)
		append_color(v, 0);
	if (((ft_strcmp(op->data, "rra") == 0) ||
		(ft_strcmp(op->data, "rrr") == 0) ||
		(ft_strcmp(op->data, "pa") == 0)) && I == 0)
		append_color(v, 1);
	if (((ft_strcmp(op->data, "rrb") == 0) ||
		(ft_strcmp(op->data, "rrr") == 0) ||
		(ft_strcmp(op->data, "pb") == 0)) && I == 0)
		append_color(v, 0);
}
