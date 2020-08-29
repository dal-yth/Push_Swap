/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:37:52 by jmakela           #+#    #+#             */
/*   Updated: 2020/02/13 20:37:53 by jmakela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Joins printed strings and assigns them into final string.
*/

void	strjoiner(t_visu *v)
{
	char *temp1;
	char *temp2;

	temp1 = ft_strjoin(v->print_a, v->print_b);
	temp2 = ft_strjoin(v->final, temp1);
	free(v->print_a);
	free(v->print_b);
	ft_strdel(&temp1);
	ft_strdel(&v->final);
	v->final = temp2;
}

/*
** Initializes visu values.
*/

void	init_visu(t_stacks *stack, t_visu *v, t_check *check)
{
	I = 0;
	v->final = ft_strnew(1);
	v->a = ACOUNT;
	v->b = BCOUNT;
	if (LEN == 1)
	{
		V = 0;
		BASIC = 1;
	}
}

/*
** Makes a string of len count out of character c.
*/

char	*visu_str_maker(char c, int count)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (count > 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
			malloc_error();
		while (i < count)
		{
			str[i] = c;
			i = i + 1;
		}
		str[i] = '\0';
	}
	return (str);
}
