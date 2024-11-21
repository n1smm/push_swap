/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:22 by tjuvan            #+#    #+#             */
/*   Updated: 2024/04/10 10:43:56 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(int content, t_stack **tail, t_stack **head)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->content = content;
	*tail = new_node;
	*head = new_node;
	return (new_node);
}

void	deallocate(t_stack **tail, t_stack **head, int **arr, t_swap *swp)
{
	t_stack	*curr;
	t_stack	*next_node;

	curr = NULL;
	next_node = NULL;
	free(swp);
	if (*tail != NULL || *head != NULL)
	{
		curr = *tail;
		while (curr->next != NULL)
		{
			next_node = curr->next;
			free(curr);
			curr = next_node;
		}
		free(curr);
	}
	free(tail);
	free(head);
	if (arr == NULL)
		return ;
	free(*arr);
}

int	ft_lstadd_front(int content, t_stack **tail)
{
	t_stack	*curr;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	curr = *tail;
	if (!new)
		return (-1);
	if (*tail == NULL)
	{
		free(new);
		return (-1);
	}
	new->content = content;
	new->next = curr;
	curr->previous = new;
	*tail = new;
	return (0);
}

int	ft_lstadd_back(int content, t_stack **head)
{
	t_stack	*curr;
	t_stack	*new;

	curr = *head;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (-1);
	if (*head == NULL)
	{
		free(new);
		return (-1);
	}
	new->content = content;
	new->next = NULL;
	curr->next = new;
	new->previous = curr;
	*head = new;
	return (0);
}

void	print_list(t_stack *tail)
{
	t_stack	*curr;
	int		i;

	i = 0;
	curr = tail;
	while (curr != NULL)
	{
		printf("index: %i\t value: %d\t di: %i\n", i++, curr->content,
			curr->di);
		curr = curr->next;
	}
}
