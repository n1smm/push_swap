/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:03:28 by thiew             #+#    #+#             */
/*   Updated: 2024/04/10 10:35:12 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheat_sort(t_stack **tail_a, t_stack **head_a)
{
	t_stack	*tail_b;
	t_stack	*head_b;
	int		full_count;
	char	*moves;

	tail_b = NULL;
	head_b = NULL;
	if (tester(*tail_a) == 0)
		return ;
	full_count = counter(*tail_a);
	if (full_count <= 3)
		moves = mini_sort(tail_a, head_a);
	else
	{
		moves = divide(tail_a, head_a, &tail_b, &head_b);
		moves = ft_strjoin(moves, mini_sort(tail_a, head_a), 1);
		moves = ft_strjoin(moves, bottom_sort(tail_a, &tail_b, head_a), 1);
		moves = ft_strjoin(moves, top_sort(tail_a, head_a, &tail_b, &head_b),
				1);
		head_b = NULL;
	}
	print_commands(moves);
	free(moves);
}

char	*divide(t_stack **t_a, t_stack **h_a, t_stack **t_b, t_stack **h_b)
{
	static int	full_count;
	int			di;
	char		*moves;

	moves = malloc(2);
	moves[0] = '\0';
	full_count = counter(*t_a);
	di = 0;
	if (full_count < 6)
	{
		moves = ft_strjoin(moves, medium_sort(t_a, h_a, t_b, h_b), 1);
		return (moves);
	}
	while (di != -1)
	{
		di = di_finder(*t_a, *h_a, full_count, *t_a);
		if (di == -1)
			break ;
		moves = ft_strjoin(moves, rotate_best_memb(t_a, h_a, di, "ra "), 1);
		moves = ft_strjoin(moves, push_node(t_a, t_b, h_b, "pb "), 0);
		if ((*t_b)->next != NULL && di < (full_count / 2))
			moves = ft_strjoin(moves, rotate(t_b, h_b, "rb "), 0);
	}
	return (moves);
}

char	*rotate_best_memb(t_stack **t, t_stack **h, int di, char *mv)
{
	int		i;
	int		count;
	t_stack	*curr;
	char	*moves;

	i = 0;
	moves = malloc(2);
	moves[0] = '\0';
	count = counter(*t);
	curr = *t;
	while (curr->di != di && curr != NULL && di != -1 && ++i)
		curr = curr->next;
	i--;
	if ((i <= CHUNK + (counter(*t) / 50) || count <= CHUNK) && di != -1)
	{
		while (di != (*t)->di)
			moves = ft_strjoin(moves, rotate(t, h, mv), 0);
		return (moves);
	}
	while (di != (*h)->di && di != -1)
		moves = ft_strjoin(moves, rotate_r(t, h, ft_strjoin("r", mv, 2)), 1);
	if (di != -1)
		moves = ft_strjoin(moves, rotate_r(t, h, ft_strjoin("r", mv, 2)), 1);
	return (moves);
}

int	counter(t_stack *tail_a)
{
	t_stack	*curr;
	int		count;

	count = 0;
	curr = tail_a;
	if (curr->next == NULL)
	{
		while (curr != NULL)
		{
			curr = curr->previous;
			count++;
		}
		return (count);
	}
	while (curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	if (count <= 3)
		return (count);
	return (count);
}

char	*mini_sort(t_stack **tail, t_stack **head)
{
	int			i;
	static int	di;
	t_stack		*curr;
	char		*moves;

	curr = *tail;
	moves = malloc(1);
	moves[0] = '\0';
	i = 0;
	while (curr != NULL)
	{
		if (curr->di > di)
		{
			i++;
			di = curr->di;
		}
		curr = curr->next;
	}
	if (i == 1)
		moves = ft_strjoin(moves, rotate(tail, head, "ra "), 0);
	else if (i == 2 && (*head)->di != di)
		moves = ft_strjoin(moves, rotate_r(tail, head, "rra "), 0);
	if ((*tail)->di > (*tail)->next->di)
		moves = ft_strjoin(moves, swap_nodes(tail, head, "sa "), 0);
	return (moves);
}
