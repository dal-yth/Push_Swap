/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:47 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 22:15:52 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Finds highest and lowest value in the stack A.
** Values are later used to find relative values
** among all values of the stack.
*/

void		get_minmax(t_stacks *stack, t_visu *v)
{
	int	i;
	int	temp;

	v->total = 0;
	i = 0;
	temp = LEN;
	v->max = A[0];
	v->min = A[0];
	while (temp > 0)
	{
		if (v->max < A[i])
			v->max = A[i];
		if (v->min > A[i])
			v->min = A[i];
		i = i + 1;
		temp = temp - 1;
	}
}

/*
** Gets the relative value.
** Based on the min, max and current number, gets the
** relative value of the current number by doing a
** division of current value - minimum value divided
** by max value - minimum value times line length.
** We add + 1, because otherwise minimum value wouldn't
** have line length at all.
*/

static int	r_val(int value, int min, int max)
{
	value = ((double)value - (double)min) /
	((double)max - (double)min) * (double)49;
	return (value + 1);
}

/*
** Uses ft_sprintf to save values into print strings.
** Allocates based on options and stack situation,
** if -v option is is chosen, saves relative stack string
** to better visualize the stack situation.
*/

static void	a_print(t_stacks *stack, t_visu *v, t_check *check)
{
	int i;

	if (V)
		v->print_a = (char*)malloc(sizeof(char) * 62);
	else
		v->print_a = (char*)malloc(sizeof(char) * 12);
	if (v->a)
	{
		i = ft_sprintf(v->print_a, "%11d", A[I]);
		if (V)
			ft_sprintf(v->print_a + i, "%-50s",
			visu_str_maker('-', r_val(A[I], v->min, v->max)));
		v->a = v->a - 1;
	}
	else
	{
		if (V)
			ft_sprintf(v->print_a, "%s", visu_str_maker(' ', 61));
		else
			ft_sprintf(v->print_a, "%s", visu_str_maker(' ', 11));
	}
	if (V)
		v->print_a[61] = '\0';
	else
		v->print_a[11] = '\0';
}

/*
** Uses ft_sprintf to save values into print strings.
** Allocates based on options and stack situation,
** if -v option is is chosen, saves relative stack string
** to better visualize the stack situation.
*/

static void	b_print(t_stacks *stack, t_visu *v, t_check *check)
{
	int i;

	if (V && BCOUNT)
		v->print_b = (char*)malloc(sizeof(char) * 63);
	else if (BCOUNT)
		v->print_b = (char*)malloc(sizeof(char) * 13);
	else
		v->print_b = (char*)malloc(sizeof(char) * 2);
	if (v->b)
	{
		i = ft_sprintf(v->print_b, "%11d", B[I]);
		(V) ? ft_sprintf(v->print_b + i, "%-50s\n",
		visu_str_maker('-', r_val(B[I], v->min, v->max))) :
		ft_sprintf(v->print_b + i, "\n");
		v->b = v->b - 1;
	}
	else
		ft_sprintf(v->print_b, "\n");
	if (V && BCOUNT)
		v->print_b[62] = '\0';
	else if (BCOUNT)
		v->print_b[12] = '\0';
	else
		v->print_b[1] = '\0';
}

/*
** Basic visualizer!
** Based on the amount of numbers in stacks a and b,
** prints out the values and strings with relative
** length of the current value.
*/

void		visu(t_stacks *stack, t_ops *op, t_visu *v, t_check *check)
{
	int temp;

	if (op && op->next != NULL)
		usleep(120000);
	(!D) ? system("clear") : 0;
	init_visu(stack, v, check);
	temp = LEN;
	(v->total) ? ft_printf("Operation: %s\n", op->data) : ft_printf("\n");
	ft_printf("Number of operations: %d\n\n", v->total);
	(V) ? ft_printf("%11s%61s\n", "Stack A:", "Stack B:") :
	ft_printf("%11s%11s\n", "Stack A:", "Stack B:");
	while (temp > 0)
	{
		a_print(stack, v, check);
		b_print(stack, v, check);
		(C && v->total) ? add_color(stack, op, v, check) : 0;
		strjoiner(v);
		temp = temp - 1;
		I = I + 1;
	}
	ft_printf("%s", v->final);
	free(v->final);
}
