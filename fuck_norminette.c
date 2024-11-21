/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_norminette.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:28:04 by tjuvan            #+#    #+#             */
/*   Updated: 2024/05/07 14:15:53 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_left(int arr[], int temp_left[], int left, int low)
{
	int	i;

	i = 0;
	while (i < left)
	{
		temp_left[i] = arr[low + i];
		i++;
	}
}

void	fill_right(int arr[], int temp_right[], int right, int middle)
{
	int	i;

	i = 0;
	while (i < (right))
	{
		temp_right[i] = arr[middle + 1 + i];
		i++;
	}
}

int	create_arrays(int left, int right, int **temp_left, int **temp_right)
{
	*temp_left = malloc(sizeof(int) * left);
	if (!temp_left)
	{
		printf("Error: failed alloc of temp_left");
		return (-1);
	}
	*temp_right = malloc(sizeof(int) * right);
	if (!temp_right)
	{
		free(temp_left);
		printf("Error: failed alloc of temp_right");
		return (-1);
	}
	return (0);
}

int	create_one(int **arr, int argc)
{
	*arr = malloc(sizeof(int) * argc);
	if (!arr)
	{
		printf("Error: allocation of 1st array");
		return (-1);
	}
	return (0);
}

int	arg_check(t_swap *swp, char ***argv, t_stack **tail, t_stack **head)
{
	char	*tmp;
	long	i;

	tmp = NULL;
	i = 0;
	if (swp->argcx > 1)
		tmp = strdup((*argv)[1]);
	if (swp->argcx > 1)
		i = splitter(tmp, swp->argcx, argv, swp);
	if (swp->argcx == 1 || i == -3)
	{
		free(tail);
		free(head);
		if (swp->argcx > 1)
			free(tmp);
		free(swp);
		exit(EXIT_SUCCESS);
	}
	free(tmp);
	return (i);
}
