/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_comms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 22:30:04 by thiew             #+#    #+#             */
/*   Updated: 2024/05/07 12:48:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_node(t_stack **tail_a, t_stack **tail_b, t_stack **head_b,
		char *specify)
{
	t_stack	*curr;

	if (strcmp(specify, "pa ") == 0)
	{
		curr = *tail_b;
		ft_lstadd_front(curr->content, tail_a);
		(*tail_a)->di = curr->di;
		*tail_b = curr->next;
		(*tail_b)->previous = NULL;
		free(curr);
	}
	else if (strcmp(specify, "pb ") == 0)
	{
		curr = *tail_a;
		if (*tail_b == NULL)
			init(curr->content, tail_b, head_b);
		else
			ft_lstadd_front(curr->content, tail_b);
		(*tail_b)->di = curr->di;
		*tail_a = curr->next;
		(*tail_a)->previous = NULL;
		free(curr);
	}
	return (specify);
}

char	*swap_nodes(t_stack **tail, t_stack **head, char *specify)
{
	t_stack	*curr;
	t_stack	*next;

	if ((*tail)->next == NULL)
		return (" ");
	curr = *tail;
	next = (*tail)->next;
	curr->previous = next;
	if (next->next != NULL)
	{
		curr->next = next->next;
		next->next->previous = curr;
	}
	else if (next->next == NULL)
	{
		curr->next = NULL;
		*head = curr;
	}
	next->next = curr;
	next->previous = NULL;
	*tail = next;
	return (specify);
}

char	*rotate_r(t_stack **tail, t_stack **head, char *specify)
{
	t_stack	*top;
	t_stack	*bottom;

	if (*tail == NULL || (*tail)->next == NULL)
		return (" ");
	top = *tail;
	bottom = *head;
	*head = bottom->previous;
	top->previous = bottom;
	*tail = bottom;
	bottom->previous = NULL;
	bottom->next = top;
	(*head)->next = NULL;
	return (specify);
}

char	*rotate(t_stack **tail, t_stack **head, char *specify)
{
	t_stack	*top;
	t_stack	*bottom;

	if ((*tail)->next == NULL)
		return (" ");
	top = *tail;
	bottom = *head;
	*tail = top->next;
	(*tail)->previous = NULL;
	bottom->next = top;
	top->next = NULL;
	top->previous = bottom;
	*head = top;
	return (specify);
}

int	splitter(char *tmp, int argc, char ***argv, t_swap *swp)
{
	long	i;

	if (argc == 2)
	{
		swp->argx = ft_split(tmp, ' ');
		if (!swp->argx)
			return (-2);
		i = word_counter2(tmp, ' ');
		check_split(swp->argx, &i);
		return (i + 1);
	}
	i = 0;
	if (argc > 2)
	{
		swp->argx = malloc(sizeof(char *) * argc);
		while ((*argv)[i + 1] != 0)
		{
			swp->argx[i] = strdup((*argv)[i + 1]);
			if (!swp->argx[i++])
				return (-1);
		}
		swp->argx[i] = NULL;
		return (0);
	}
	return (-1);
}
