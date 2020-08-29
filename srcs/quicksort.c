/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:13 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:49:11 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Checks if stack a or stack b should be rotated
** back to original position.
*/

static void	check_rot(t_stacks *stack, t_ops **op)
{
	CHECK = 0;
	if (CHOICE == 1)
	{
		if (ROT > 3)
		{
			rot_median(stack);
			P_POS = P_POS + 1;
			CHECK = 1;
		}
		while (ROT)
		{
			rra(stack, op, 1);
			(CHECK) ? push_rot(stack, op) : 0;
			ROT = ROT - 1;
		}
	}
	else if (CHOICE == 2)
	{
		while (ROT)
		{
			rrb(stack, op, 1);
			ROT = ROT - 1;
		}
	}
}

/*
** Goes through all current partition values in stack a
** and pushes those smaller than median to stack b.
*/

static void	move_smalls(t_stacks *stack, t_ops **op)
{
	int temp;

	temp = SIZE;
	while (temp)
	{
		if (A[0] < MEDIAN)
		{
			pb(stack, op, 1);
			temp = temp - 1;
			PART[P_POS] = PART[P_POS] + 1;
			SIZE = SIZE - 1;
		}
		else
		{
			ra(stack, op, 1);
			temp = temp - 1;
			ROT = ROT + 1;
		}
	}
}

/*
** Goes through all current partition values in stack b
** and pushes those larger than median back to stack a.
*/

static void	part_sort(t_stacks *stack, t_ops **op)
{
	int temp;

	temp = PART[P_POS];
	while (temp && PC)
	{
		if (B[0] > MEDIAN)
		{
			pa(stack, op, 1);
			PART[P_POS] = PART[P_POS] - 1;
			SIZE = SIZE + 1;
			temp = temp - 1;
			PC = PC - 1;
		}
		else
		{
			rb(stack, op, 1);
			temp = temp - 1;
			(P_POS != 0) ? (ROT = ROT + 1) : 0;
		}
	}
}

/*
** Pushes values of latest partition in stack b to stack a.
** If there are more than 3 values, part_sort uses median to
** only push larger values to stack a. Otherwise all values
** are pushed. Eval_pushed optimizes sorting when there are
** 3 numbers being pushed.
*/

static void	push_part(t_stacks *stack, t_ops **op)
{
	if (PART[P_POS] > 3)
		part_sort(stack, op);
	else
	{
		if (PART[P_POS] == 3)
			eval_pushed(stack, op);
		while (PART[P_POS])
		{
			pa(stack, op, 1);
			PART[P_POS] = PART[P_POS] - 1;
			SIZE = SIZE + 1;
		}
	}
}

/*
** Calls the functions that iteratively sort stack a.
** Solving function runs in a while loop with stop condition
** of being sorted.
**
** Basic idea is to split the stacks into large and small values
** using a median. Inner while loop splits stack A and pushes smaller
** values to stack B while recording the amount of pushed numbers as
** partitions.
**
** The part outside the inner loop finds a median for latest
** partition in stack B and pushes larger values into stack A.
**
** If only 3 or less numbers are pushed, solve_3 or eval_pushed
** functions sort the numbers in correct order, using swaps and
** rotations.
**
** To help with readability:
** SIZE is used to indicate amount of pushed values in stack A or
** stack B depending which operation was done last.
**
** P_POS is the current partition in PART array, which
** holds the amount of numbers in partitions.
**
** ROT is a value that keeps track of how many rotations should
** be done to return the stack to the original position before
** pushing. This is important so we don't lose track of partitions.
**
** CHOICE is simply used to indicate which stack is currently using
** check_rot.
*/

void		quicksort(t_stacks *stack, t_ops **op)
{
	while (BCOUNT || !(is_sorted(stack)))
	{
		while (SIZE > 3)
		{
			P_POS = P_POS + 1;
			get_median(stack);
			move_smalls(stack, op);
			check_rot(stack, op);
			ROT = 0;
			if (SIZE < 4)
				solve_3(stack, op);
		}
		CHOICE = 2;
		if (PART[P_POS] > 3)
			part_median(stack);
		get_push_count(stack, 0);
		push_part(stack, op);
		check_rot(stack, op);
		if (SIZE < 4)
			solve_3(stack, op);
		if (PART[P_POS] == 0 && P_POS > 0)
			P_POS = P_POS - 1;
		CHOICE = 1;
	}
}
