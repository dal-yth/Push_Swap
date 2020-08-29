/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:02:54 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/14 21:23:11 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

/*
** All the defines. All of them.
** To make the code more readable, most
** struct values have been given a definition.
*/

# define ACOUNT stack->a_count
# define BCOUNT stack->b_count
# define PART stack->part
# define P_POS stack->part_position
# define MEDIAN stack->median
# define LEN stack->len
# define A stack->a
# define B stack->b
# define M stack->m
# define ROT stack->rot
# define SIZE stack->size
# define CHOICE stack->choice
# define CHECK stack->check
# define PC stack->push_count
# define ARG check->argv
# define I check->i
# define J check->j
# define V check->v
# define BASIC check->b
# define C check->c
# define D check->d
# define O check->o
# define F check->f
# define START check->start
# define EMPTY check->empty
# define COUNT check->count
# define POS check->pos

/*
** Struct for insert sort.
*/

typedef struct		s_insert
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				best_ra;
	int				best_rra;
	int				best_rb;
	int				best_rrb;
	int				best_total;
}					t_insert;

/*
** Struct for error checking and storing options.
*/

typedef struct		s_check
{
	char			**argv;
	int				i;
	int				f;
	int				j;
	int				v;
	int				b;
	int				c;
	int				d;
	int				o;
	int				start;
	int				pos;
	int				empty;
	int				count;
}					t_check;

/*
** Struct for storing values for visualizer.
*/

typedef struct		s_visu
{
	int				min;
	int				max;
	int				total;
	int				r;
	int				a;
	int				b;
	char			*print_a;
	char			*print_b;
	char			*final;
}					t_visu;

/*
** Basic linked list struct for saving operation data.
*/

typedef struct		s_ops
{
	struct s_ops	*next;
	char			*data;
}					t_ops;

/*
** Struct that holds both stacks, partition count stack,
** temporary median calculation stack and several counts
** used to keep track of amount of numbers in stacks,
** amount needed to rotate stack to original position,
** median value, stack max size etc.
*/

typedef struct		s_stacks
{
	long long int	*a;
	long long int	*b;
	long long int	*m;
	int				*part;

	int				push_count;
	int				choice;
	int				size;
	int				rot;
	int				part_position;
	long long int	median;
	int				len;
	int				check;
	int				a_count;
	int				b_count;
}					t_stacks;

/*
** Error checking and evaluating input
*/

void				put_error();
void				malloc_error();
void				eval_input(t_check *check, char **argv, int choice);

/*
** Generating stacks, getting info from the stacks and
** linked list operations.
*/

void				get_info(t_stacks *stack);
void				make_arr(t_stacks *stack, t_check *check);
void				get_ops(t_ops **op);
int					append(t_ops **head, char *data);
t_ops				*newnode(char *data);

/*
** Writing, reading, executing and evaluating operations
*/

void				write_ops(t_ops *op);
void				do_ops(t_stacks *stack,
					t_ops *op, t_visu *v, t_check *check);
void				ok_ko(t_stacks *stack);

/*
** Solving functions, medians and sorted condition for quicksort
*/

void				get_push_count(t_stacks *stack, int a);
int					is_sorted(t_stacks *stack);
void				quicksort(t_stacks *stack, t_ops **op);
int					solve_3(t_stacks *stack, t_ops **op);
void				get_median(t_stacks *stack);
void				part_median(t_stacks *stack);
void				rot_median(t_stacks *stack);
void				push_rot(t_stacks *stack, t_ops **op);
int					eval_pushed(t_stacks *stack, t_ops **op);

/*
** Solving functions for insertsort.
*/

void				insertsort(t_stacks *stack, t_ops **op);
void				compare(t_insert *is);
void				do_rotate(t_stacks *stack, t_ops **op, t_insert *is);
void				do_rev_rotate(t_stacks *stack, t_ops **op, t_insert *is);
void				rot_in_order(t_stacks *stack, t_ops **op);
void				get_ra_rra(t_stacks *stack, t_insert *is, int j);
void				get_rb_rrb(t_stacks *stack, t_insert *is, int i);

/*
** Output optimization
*/

void				optimize_output(t_stacks *stack, t_ops *op);

/*
** All 11 allowed operations: swapping, rotating, pushing
*/

void				sa(t_stacks *stack, t_ops **op, int apnd);
void				sb(t_stacks *stack, t_ops **op, int apnd);
void				ss(t_stacks *stack, t_ops **op, int apnd);
void				pb(t_stacks *stack, t_ops **op, int apnd);
void				pa(t_stacks *stack, t_ops **op, int apnd);
void				ra(t_stacks *stack, t_ops **op, int apnd);
void				rb(t_stacks *stack, t_ops **op, int apnd);
void				rr(t_stacks *stack, t_ops **op, int apnd);
void				rra(t_stacks *stack, t_ops **op, int apnd);
void				rrb(t_stacks *stack, t_ops **op, int apnd);
void				rrr(t_stacks *stack, t_ops **op, int apnd);

/*
** Visualizer and helper functions that deal with relative
** lengths and create appropriate stack strings
*/

void				visu(t_stacks *stack, t_ops *op, t_visu *v, t_check *check);
void				init_visu(t_stacks *stack, t_visu *v, t_check *check);
void				get_minmax(t_stacks *stack, t_visu *v);
char				*visu_str_maker(char c, int count);
void				add_color(t_stacks *stack,
					t_ops *op, t_visu *v, t_check *check);
void				strjoiner(t_visu *v);

/*
** Utilities
*/

void				init_check(t_check *check, char **argv);
int					get_smallest(t_stacks *stack);
int					get_biggest(t_stacks *stack);
void				init_best(t_insert *is, t_stacks *stack);
void				init_is(t_insert *is);

/*
** Frees the stuff, all the stuff, not much more to it.
** Go my little memory blocks go, you are free!
*/

void				free_stuff(t_stacks *stack,
					t_ops **head, t_check *check, int pw);
void				printer(t_stacks *stack);

#endif
