/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:00:32 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:56:49 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*
** Operation to choose which sort to use.
** For small amount of values, we use quicksort
** or simply solve_3, with fairly big numbers
** up to 350, we use insertsort and with larger
** values, we use quicksort again.
*/

static void	choose_sort(t_stacks *stack, t_ops **op)
{
	CHOICE = 0;
	SIZE = LEN;
	ROT = 0;
	P_POS = -1;
	PC = 0;
	if (!is_sorted(stack))
	{
		if (LEN < 4)
			solve_3(stack, op);
		else if (LEN < 10)
			quicksort(stack, op);
		else if (LEN < 350)
			insertsort(stack, op);
		else
			quicksort(stack, op);
	}
}

/*
** Push_swap main.
** Calls error checking first, to check for various errors.
** Then calls make_arr to create stack a. Get_info finds out
** some necessary data to execute operations. Then some initial
** data is assigned to stack. If there are more than 3 values in
** stack a, solve function is called to sort stack a, otherwise
** solve_3 takes care of other inputs. Optimize output checks
** for pointless operations, write ops prints out all the operations
** done and free stuff, well, frees the stuff.
*/

int			main(int argc, char **argv)
{
	t_ops		*op;
	t_stacks	*stack;
	t_check		*check;

	if (!(stack = (t_stacks*)malloc(sizeof(t_stacks))))
		malloc_error();
	if (!(check = (t_check*)malloc(sizeof(t_check))))
		malloc_error();
	op = NULL;
	(argc < 2) ? exit(0) : 0;
	init_check(check, argv);
	eval_input(check, argv, 0);
	make_arr(stack, check);
	CHOICE = 1;
	get_info(stack);
	choose_sort(stack, &op);
	if (LEN > 3)
		optimize_output(stack, op);
	write_ops(op);
	free_stuff(stack, &op, check, 1);
	return (0);
}
