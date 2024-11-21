/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:33:26 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/10 10:41:34 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(t_stack *tail)
{
	t_stack	*curr;
	int		di;

	curr = tail;
	di = 0;
	while (curr)
	{
		if (curr->di > di)
			di = curr->di;
		curr = curr->next;
	}
	return (di);
}

char	*medium_high(t_stack **t_a, t_stack **h_a, t_stack **t_b, t_stack **h_b)
{
	static int			full_count;
	static int			i;
	char				*moves;
	t_stack				*curr;

	curr = *t_a;
	moves = ft_calloc(2, 1);
	full_count = counter(*t_a);
	while (curr->di != find_highest(*t_a))
	{
		curr = curr->next;
		i++;
	}
	if (i < full_count / 2)
	{
		while ((*t_a)->di != find_highest(*t_a))
			moves = ft_strjoin(moves, rotate(t_a, h_a, "ra "), 0);
	}
	else
	{
		while ((*t_a)->di != find_highest(*t_a))
			moves = ft_strjoin(moves, rotate_r(t_a, h_a, "rra "), 0);
	}
	moves = ft_strjoin(moves, push_node(t_a, t_b, h_b, "pb "), 0);
	return (moves);
}

char	*medium_rot(t_stack **t_a, t_stack **h_a, int full_count, int i)
{
	char		*moves;

	moves = ft_calloc(2, 1);
	if (i <= full_count / 2 && full_count > 3)
	{
		while ((*t_a)->di != 0)
			moves = ft_strjoin(moves, rotate(t_a, h_a, "ra "), 0);
	}
	else if (i > full_count / 2 && full_count > 3)
	{
		while ((*t_a)->di != 0)
			moves = ft_strjoin(moves, rotate_r(t_a, h_a, "rra "), 0);
	}
	return (moves);
}

char	*medium_sort(t_stack **t_a, t_stack **h_a, t_stack **t_b, t_stack **h_b)
{
	static int	full_count;
	int			i;
	char		*moves;
	t_stack		*curr;

	curr = *t_a;
	moves = ft_calloc(2, 1);
	full_count = counter(*t_a);
	i = 0;
	while (curr->di != 0)
	{
		curr = curr->next;
		i++;
	}
	moves = ft_strjoin(moves, medium_rot(t_a, h_a, full_count, i), 1);
	if (full_count > 3)
		moves = ft_strjoin(moves, push_node(t_a, t_b, h_b, "pb "), 0);
	if (full_count > 4)
		moves = ft_strjoin(moves, medium_high(t_a, h_a, t_b, h_b), 1);
	return (moves);
}
