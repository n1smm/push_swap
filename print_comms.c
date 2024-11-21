/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:47:37 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/09 17:39:11 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(char *moves)
{
	char	**moves_x;
	int		i;
	int		count;

	i = 0;
	count = word_counter2(moves, ' ');
	moves_x = ft_split(moves, ' ');
	comm_checker(&moves_x);
	while (i != count)
	{
		if (moves_x[i][0] != 'x')
			puts(moves_x[i]);
		i++;
	}
	while (i > -1)
		free(moves_x[i--]);
	free(moves_x);
}

void	comm_checker(char ***moves_x)
{
	char		*tmp;
	static int	i;
	static int	n;

	while ((*moves_x)[i + 1] != 0)
	{
		tmp = comm_holder((*moves_x)[i]);
		n = i + 1;
		while ((*moves_x)[n] != 0 && (*moves_x)[i][0] == 'r')
		{
			if ((*moves_x)[n][0] == 's' || (*moves_x)[n][0] == 'p')
				break ;
			if (strcmp(tmp, (*moves_x)[n]) == 0)
			{
				comm_replacer(moves_x, i, n);
				break ;
			}
			n++;
		}
		i++;
		free(tmp);
	}
}

char	*comm_holder(char *str)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strdup(str);
	if (str[0] != 'r')
		return (tmp);
	while (tmp[j] != 0)
	{
		if (tmp[j] == 'a')
			tmp[j] = 'b';
		else if (tmp[j] == 'b')
			tmp[j] = 'a';
		j++;
	}
	return (tmp);
}

void	comm_replacer(char ***moves_x, int i, int n)
{
	int	j;

	j = 0;
	while ((*moves_x)[i][j] != 0)
		j++;
	if (j == 2)
	{
		(*moves_x)[i][1] = 'r';
		(*moves_x)[n][0] = 'x';
	}
	else if (j == 3)
	{
		(*moves_x)[i][2] = 'r';
		(*moves_x)[n][0] = 'x';
	}
}

int	tester(t_stack *tail)
{
	int	i;
	int	wrong;

	i = tail->di;
	wrong = 0;
	while (tail != NULL)
	{
		if (tail->di != i)
		{
			wrong = 1;
			break ;
		}
		i++;
		tail = tail->next;
	}
	if (wrong == 1)
	{
		return (1);
	}
	else
		return (0);
}
