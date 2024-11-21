/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_landing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:34 by thiew             #+#    #+#             */
/*   Updated: 2024/05/07 13:58:41 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*soft_landing(t_stack **tail_b, t_stack **head_b, int full_count,
		t_stack **tail_a)
{
	int		i;
	char	*moves;

	moves = malloc(2);
	moves[0] = '\0';
	i = 0;
	if ((*tail_a)->di >= full_count / 2 || (*tail_b) == NULL)
	{
		while (*tail_b != NULL && (*tail_b)->next != NULL && i < CHUNK
			&& (*tail_b)->di < (*tail_a)->di && (*tail_b)->di > full_count / 2)
		{
			moves = ft_strjoin(moves, rotate(tail_b, head_b, "rb "), 0);
			i++;
		}
		moves = ft_strjoin(moves, push_node(tail_a, tail_b, head_b, "pb "), 0);
		while (i > 0)
		{
			moves = ft_strjoin(moves, rotate_r(tail_b, head_b, "rrb "), 0);
			i--;
		}
	}
	else if ((*tail_a)->di < full_count / 2)
		moves = ft_strjoin(moves, bottom_landing(tail_b, head_b, full_count,
					tail_a), 1);
	return (moves);
}

char	*bottom_landing(t_stack **tail_b, t_stack **head_b, int full_count,
		t_stack **tail_a)
{
	int		i;
	char	*moves;
	int		di_stop;

	moves = malloc(2);
	moves[0] = '\0';
	i = 0;
	di_stop = (*head_b)->di;
	while ((*tail_b) != NULL && (*tail_b)->next != NULL && i < CHUNK
		&& (*head_b)->di > (*tail_a)->di && (*head_b)->di < full_count / 2)
	{
		moves = ft_strjoin(moves, rotate_r(tail_b, head_b, "rrb "), 0);
		i++;
		if (di_stop == (*head_b)->di || (*head_b)->di > full_count / 2)
			break ;
	}
	moves = ft_strjoin(moves, push_node(tail_a, tail_b, head_b, "pb "), 0);
	while (i > 0)
	{
		moves = ft_strjoin(moves, rotate(tail_b, head_b, "rb "), 0);
		i--;
	}
	moves = ft_strjoin(moves, rotate(tail_b, head_b, "rb "), 0);
	return (moves);
}

void	check_split(char **argx, long *i)
{
	if (argx[0] == NULL)
	{
		free(argx);
		*i = -4;
	}
}
