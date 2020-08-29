/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <jmakela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:35:46 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/17 16:07:42 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** If there were more than one option of any type we put error.
*/

static void		options_error(t_check *check, int choice)
{
	if (choice == 0)
	{
		(F > 1) ? put_error() : 0;
		(V > 0) ? put_error() : 0;
		(C > 0) ? put_error() : 0;
		(D > 0) ? put_error() : 0;
		(O > 0) ? put_error() : 0;
		(BASIC > 0) ? put_error() : 0;
	}
	else
	{
		(F > 1) ? put_error() : 0;
		(V > 1) ? put_error() : 0;
		(C > 1) ? put_error() : 0;
		(D > 1) ? put_error() : 0;
		(O > 1) ? put_error() : 0;
		(BASIC > 1) ? put_error() : 0;
	}
}

/*
** Checks for options.
** Checker supports -fvbcds for various options
** -f reading from a file, -v visualize stacks,
** -b for basic, -c color for latest operation,
** -s for speed (use more s for more speed: ssss)
*/

static void		options(t_check *check)
{
	if (ARG[I][J] == '-' && ARG[I][J + 1] &&
		!ft_isdigit(ARG[I][J + 1]) && ARG[I][J + 1] != ' ')
	{
		J = J + 1;
		while (ARG[I][J] && ARG[I][J] != ' ')
		{
			if (ARG[I][J] == 'f')
				F = F + 1;
			else if (ARG[I][J] == 'v')
				V = V + 1;
			else if (ARG[I][J] == 'c')
				C = C + 1;
			else if (ARG[I][J] == 'd')
				D = D + 1;
			else if (ARG[I][J] == 'o')
				O = O + 1;
			else if (ARG[I][J] == 'b')
				BASIC = BASIC + 1;
			else
				put_error();
			J = J + 1;
		}
		(ARG[I][J] != ' ' && ARG[I][J] != '\0') ? put_error() : 0;
	}
}

/*
** Checks for a file if -f option is found as the first argument.
** Opens argv[2](argv[1] was the -f option) and reads with gnl.
** Strjoins into a temporary string, deletes the last string of
** ARG and assigns the joined string read from the file to be
** the last argument.
*/

void			check_file(t_check *check, char **argv)
{
	int		fd;
	char	*buf;

	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		put_error();
	get_next_line(fd, &buf);
	if (buf)
	{
		ARG[2] = ft_strdup(buf);
		free(buf);
	}
	else
		put_error();
	close(fd);
	I = 2;
	J = 0;
}

/*
** If there is not a single digit in any of the strings,
** we consider strings empty and exit out. Otherwise we
** keep track of amount of empty strings and use them
** later when we allocate correct amount of space for
** stacks.
*/

static void		check_empty(t_check *check)
{
	int i;
	int j;
	int diff;

	EMPTY = 0;
	diff = I;
	i = I;
	j = 0;
	while (ARG[i])
	{
		while (ARG[i][j] == ' ')
			j = j + 1;
		if (ARG[i][j] == '\0')
			EMPTY = EMPTY + 1;
		j = 0;
		i = i + 1;
	}
	(EMPTY == (i - diff)) ? exit(0) : 0;
}

/*
** Evaluates the input
** Initializes the values of check struct and checks for options.
** Then loops through ARG string(s) and keeps checking that
** everything is in place and there are no weird characters or
** wrong inputs.
*/

void			eval_input(t_check *check, char **argv, int choice)
{
	while (ARG[I][J] == ' ')
		J = J + 1;
	options(check);
	options_error(check, choice);
	(F == 1) ? check_file(check, argv) : 0;
	check_empty(check);
	START = I;
	POS = J;
	while (ARG[I])
	{
		while (ARG[I][J])
		{
			if ((!ft_isdigit(ARG[I][J])) &&
			ARG[I][J] != ' ' && ARG[I][J] != '-' && ARG[I][J] != '+')
				put_error();
			if (ARG[I][J] == '-' || ARG[I][J] == '+')
			{
				(!ft_isdigit(ARG[I][J + 1])) ? put_error() : 0;
				(J != 0 && ARG[I][J - 1] != ' ') ? put_error() : 0;
			}
			J = J + 1;
		}
		J = 0;
		I = I + 1;
	}
}
