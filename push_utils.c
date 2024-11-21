/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:16:22 by thiew             #+#    #+#             */
/*   Updated: 2024/04/10 12:40:57 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int free_all)
{
	size_t	count_later;
	size_t	count;
	char	*twin;

	count = 0;
	count_later = count;
	twin = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!twin || !s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	while (s1[count])
	{
		twin[count] = s1[count];
		count++;
	}
	while (s2[count_later])
		twin[count++] = s2[count_later++];
	twin[count] = 0;
	if (free_all == 1 && free_all != 2)
		free(s2);
	if (free_all != 2)
		free(s1);
	return (twin);
}

int	free_argv(char **argv, int i, int success, int skip)
{
	if (success == -1)
		write(1, "Error", 5);
	if (skip == 2 && success != -1)
	{
		if (ft_atoi(argv[0]) > INT_MAX || ft_atoi(argv[0]) < INT_MIN)
		{
			write(1, "Error", 5);
		}
		success = -1;
	}
	while (i != -1)
	{
		free(argv[i]);
		i--;
	}
	free(argv);
	return (success);
}

int	stack_alloc(t_stack ***tail, t_stack ***head, t_swap *swp, int argc)
{
	*tail = malloc(sizeof(t_stack *));
	if (!tail)
	{
		write(1, "Error", 5);
		free(swp);
		return (-1);
	}
	*head = malloc(sizeof(t_stack *));
	if (!head)
	{
		write(1, "Error", 5);
		free(tail);
		free(swp);
		return (-1);
	}
	**tail = NULL;
	**head = NULL;
	swp->argcx = argc;
	return (0);
}
