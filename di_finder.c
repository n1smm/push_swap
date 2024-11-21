/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:41:16 by tjuvan            #+#    #+#             */
/*   Updated: 2024/02/05 15:32:51 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	di_finder(t_stack *tail, t_stack *head, int full_count, t_stack *ref_node)
{
	int	di;

	if (ref_node->di == tail->di)
		di = di_finder1(tail, head, full_count);
	else
		di = di_finder2(tail, head, ref_node);
	return (di);
}

int	di_finder2(t_stack *tail, t_stack *head, t_stack *ref_node)
{
	int		i;
	int		di;
	t_stack	*curr;

	di = 0;
	i = 0;
	curr = tail;
	while (curr != head && curr != NULL)
	{
		if (-(curr->di) + ref_node->di < -di + ref_node->di && -(curr->di)
			+ ref_node->di >= 0)
			di = curr->di;
		curr = curr->next;
	}
	if (-(curr->di) + ref_node->di < -di + ref_node->di && -(curr->di)
		+ ref_node->di >= 0)
		di = curr->di;
	curr = tail;
	while (curr != NULL && curr->di != di && ++i)
		curr = curr->next;
	if (counter(tail) / 2 < i - 1)
		return (0);
	return (1);
}

int	di_finder1(t_stack *tail, t_stack *head, int full_count)
{
	int	top;
	int	bottom;
	int	low_di;
	int	high_di;
	int	count;

	count = counter(tail);
	if (count <= 3)
		return (-1);
	count = 0;
	low_di = full_count / 2;
	high_di = full_count / 2;
	top = di_finder_top(tail, low_di, high_di, full_count);
	bottom = di_finder_bottom(head, low_di, high_di, full_count);
	high_di = full_count - top;
	low_di = full_count - bottom;
	while (count <= full_count)
	{
		if (count == top || count == high_di)
			return (top);
		else if (count == bottom || count == low_di)
			return (bottom);
		count++;
	}
	return (-1);
}

int	di_finder_top(t_stack *tail, int low_di, int high_di, int full_count)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = tail;
	while (i <= CHUNK + (counter(tail) / 50) && curr != NULL)
	{
		if (curr->di <= (full_count - 1) / 2 && curr->di <= low_di)
			low_di = curr->di;
		if (curr->di > (full_count - 1) / 2 && curr->di > high_di)
			high_di = curr->di;
		curr = curr->next;
		i++;
	}
	if (low_di <= (full_count - 1) - high_di)
		high_di = low_di;
	return (high_di);
}

int	di_finder_bottom(t_stack *head, int low_di, int high_di, int full_count)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = head;
	while (i <= CHUNK + (counter(head) / 50) && curr != NULL)
	{
		if (curr->di <= (full_count - 1) / 2 && curr->di <= low_di)
			low_di = curr->di;
		if (curr->di > (full_count - 1) / 2 && curr->di > high_di)
			high_di = curr->di;
		curr = curr->previous;
		i++;
	}
	if (low_di <= (full_count - 1) - high_di)
		high_di = low_di;
	return (high_di);
}
