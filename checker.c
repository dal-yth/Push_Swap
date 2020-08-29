/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:01:06 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:57:41 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
** Checker main.
** Calls error checking first, to check for various errors.
** Then calls make_arr to create stack a.
** Get_ops reads operations printed by push_swap and saves them
** to a linked list. Get_info finds out some necessary data to
** execute operations. Do_ops goes through the linked list
** and executes each operation to the stacks. Ok_ko function
** checks if the integers are in correct order in the stack a.
*/

int		main(int argc, char **argv)
{
	t_ops		*op;
	t_stacks	*stack;
	t_visu		*v;
	t_check		*check;

	if (!(v = (t_visu*)malloc(sizeof(t_visu))))
		malloc_error();
	if (!(stack = (t_stacks*)malloc(sizeof(t_stacks))))
		malloc_error();
	if (!(check = (t_check*)malloc(sizeof(t_check))))
		malloc_error();
	op = NULL;
	CHOICE = 0;
	(argc < 2) ? exit(0) : 0;
	init_check(check, argv);
	eval_input(check, argv, 1);
	make_arr(stack, check);
	get_info(stack);
	get_ops(&op);
	do_ops(stack, op, v, check);
	ok_ko(stack);
	free_stuff(stack, &op, check, 0);
	return (0);
}
