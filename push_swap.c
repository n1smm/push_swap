/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:34 by tjuvan            #+#    #+#             */
/*   Updated: 2024/05/07 12:42:40 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 0;
	while ((nptr[count] > 8 && nptr[count] < 14) || nptr[count] == 32)
		count++;
	if (nptr[count] == '+')
		count++;
	else if (nptr[count] == '-')
	{
		sign = 1;
		count++;
	}
	while (nptr[count] > 47 && nptr[count] < 58)
	{
		result = (result * 10 + nptr[count]) - 48;
		count++;
	}
	if (sign == 1)
		result = -result;
	result = check_input(nptr, result);
	return (result);
}

long	check_input(const char *nptr, long result)
{
	int	count;

	count = 0;
	while ((nptr[count] > 8 && nptr[count] < 14) || nptr[count] == 32)
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
		count++;
	if (nptr[count] == 48 && nptr[count + 1] != 0)
		return ((long)INT_MAX + 10);
	if (nptr[count] == 0)
		return ((long)INT_MAX + 10);
	while (nptr[count] != 0)
	{
		if (nptr[count] > 47 && nptr[count] < 58)
			count++;
		else
			return ((long)INT_MAX + 10);
	}
	return (result);
}

int	create_list(int arr[], int argc, t_stack **tail, t_stack **head)
{
	int	i;
	int	success;

	i = 0;
	success = 0;
	init((arr)[i++], tail, head);
	while (i < argc - 1)
		success = ft_lstadd_back((arr)[i++], head);
	success = cold_start(arr, tail, argc - 1, success);
	if (tail == NULL || head == NULL || success == -1)
	{
		write(1, "Error", 5);
		return (-1);
	}
	if (success == 1)
	{
		write(1, "Error", 5);
		return (-1);
	}
	return (0);
}

int	fill_array(int *arr, char **argv, int skip, t_swap *swp)
{
	int	i;
	int	success;

	i = 0;
	success = 0;
	if (skip > -1)
	{
		while (argv[i])
		{
			arr[i] = ft_atoi(argv[i]);
			if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
				success = -1;
			i++;
		}
	}
	if (free_argv(swp->argx, i, success, skip) == -1)
		return (-1);
	if (skip < 0)
		success = -1;
	return (success);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_swap	*swp;
	t_stack	**tail;
	t_stack	**head;

	swp = (t_swap *)malloc(sizeof(t_swap));
	if (stack_alloc(&tail, &head, swp, argc) == -1)
		return (-1);
	swp->i = arg_check(swp, &argv, tail, head);
	if (swp->i > 0)
		argc = swp->i;
	if (swp->i > -1)
		swp->k = create_one(&arr, argc);
	if (swp->i > -1 && swp->k > -1)
		swp->i = fill_array(arr, swp->argx, swp->i, swp);
	if (swp->i > -1 && swp->k > -1)
		swp->i = create_list(arr, argc, tail, head);
	if (swp->i <= -1 || swp->k == -1)
	{
		if (swp->i == -1)
			deallocate(tail, head, &arr, swp);
		return (1);
	}
	cheat_sort(tail, head);
	deallocate(tail, head, &arr, swp);
}
