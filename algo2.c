/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:17:04 by tjuvan            #+#    #+#             */
/*   Updated: 2024/02/05 20:56:28 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*top_sort(t_stack **t_a, t_stack **h_a, t_stack **t_b, t_stack **h_b)
{
	int		low_l;
	int		high_l;
	int		b_top;
	int		i;
	char	*moves;

	i = -1;
	moves = malloc(1);
	moves[0] = 0;
	b_top = (*t_b)->di;
	low_l = (*t_a)->di;
	high_l = (*h_a)->di;
	while ((*t_b)->next != NULL)
	{
		while (i++ < CHUNK && (*t_b)->di == b_top && counter(*t_b) > CHUNK)
			moves = ft_strjoin(moves, rotate_r(t_b, h_b, "rrb "), 0);
		while ((*h_a)->di > (*t_b)->di && (*h_a)->di < high_l)
			moves = ft_strjoin(moves, rotate_r(t_a, h_a, "rra "), 0);
		while ((*t_a)->di < (*t_b)->di && (*t_a)->di != low_l)
			moves = ft_strjoin(moves, rotate(t_a, h_a, "ra "), 0);
		moves = ft_strjoin(moves, push_node(t_a, t_b, NULL, "pa "), 0);
		i = 0;
	}
	moves = ft_strjoin(moves, last_spin(t_a, h_a, t_b, high_l), 1);
	return (moves);
}

char	*bottom_sort(t_stack **tail_a, t_stack **tail_b, t_stack **head_a)
{
	int		low_l;
	int		high_l;
	char	*moves;

	moves = malloc(1);
	moves[0] = 0;
	low_l = (*tail_a)->di;
	high_l = (*head_a)->di;
	while ((*tail_b)->di > high_l)
	{
		while ((*head_a)->di > (*tail_b)->di && (*head_a)->di != high_l)
			moves = ft_strjoin(moves, rotate_r(tail_a, head_a, "rra "), 0);
		while ((*tail_a)->di < (*tail_b)->di && (*tail_a)->di != low_l)
			moves = ft_strjoin(moves, rotate(tail_a, head_a, "ra "), 0);
		moves = ft_strjoin(moves, push_node(tail_a, tail_b, NULL, "pa "), 0);
	}
	while ((*tail_a)->di != low_l)
		moves = ft_strjoin(moves, rotate(tail_a, head_a, "ra "), 0);
	return (moves);
}

char	*last_spin(t_stack **tail_a, t_stack **head_a, t_stack **tail_b,
		int high_l)
{
	char	*moves;

	moves = malloc(1);
	moves[0] = 0;
	if (di_finder2(*tail_a, *head_a, *tail_b) == 0)
	{
		while ((*tail_a)->di - 1 != (*tail_b)->di)
			moves = ft_strjoin(moves, rotate_r(tail_a, head_a, "rra "), 0);
		moves = ft_strjoin(moves, final_push(tail_a, tail_b, "pa "), 0);
	}
	else if (di_finder2(*tail_a, *head_a, *tail_b) == 1)
	{
		while ((*tail_a)->di - 1 != (*tail_b)->di)
			moves = ft_strjoin(moves, rotate(tail_a, head_a, "ra "), 0);
		moves = ft_strjoin(moves, final_push(tail_a, tail_b, "pa "), 0);
	}
	while ((*head_a)->di != high_l)
		moves = ft_strjoin(moves, rotate_r(tail_a, head_a, "rra "), 0);
	return (moves);
}

char	*final_push(t_stack **tail_a, t_stack **tail_b, char *specify)
{
	t_stack	*curr;

	curr = *tail_b;
	ft_lstadd_front(curr->content, tail_a);
	(*tail_a)->di = curr->di;
	free(curr);
	*tail_b = NULL;
	return (specify);
}
