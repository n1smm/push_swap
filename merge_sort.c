/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:06:43 by tjuvan            #+#    #+#             */
/*   Updated: 2024/02/05 15:36:57 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cold_start(int arr[], t_stack **list_a, int length, int success)
{
	t_stack	*curr;
	int		di;

	if (success == -1)
		return (-1);
	curr = *list_a;
	merge_sort(arr, length);
	di = 0;
	while (di + 1 < length)
	{
		if ((arr)[di] == (arr)[di + 1])
			return (1);
		di++;
	}
	while (curr != NULL)
	{
		di = binary_search(arr, curr->content, 0, length);
		if (di < 0)
			return (-1);
		curr->di = di;
		curr = curr->next;
	}
	return (0);
}

void	merge_sort(int arr[], int length)
{
	merge_sort_recursion(arr, 0, length - 1);
}

void	merge_sort_recursion(int arr[], int low, int high)
{
	int	middle;

	if (low >= high)
		return ;
	middle = low + (high - low) / 2;
	merge_sort_recursion(arr, low, middle);
	merge_sort_recursion(arr, middle + 1, high);
	merge_sorted_arrays(arr, low, middle, high);
}

void	merge_sorted_arrays(int arr[], int low, int middle, int high)
{
	int	i;
	int	j;
	int	k;
	int	*temp_left;
	int	*temp_right;

	i = create_arrays(middle - low + 1, high - middle, &temp_left, &temp_right);
	if (i == -1)
		return ;
	fill_left(arr, temp_left, middle - low + 1, low);
	fill_right(arr, temp_right, high - middle, middle);
	i = low;
	j = 0;
	k = 0;
	while (i <= high)
	{
		if ((j < (middle - low + 1)) && (k >= (high - middle)
				|| temp_left[j] <= temp_right[k]))
			arr[i] = temp_left[j++];
		else
			arr[i] = temp_right[k++];
		i++;
	}
	free(temp_left);
	free(temp_right);
}

int	binary_search(int arr[], int target, int low, int high)
{
	int	i;

	i = (low + high) / 2;
	if (arr[i] == target)
		return (i);
	if (low >= high)
		return (-1);
	if (arr[i] < target)
		return (binary_search(arr, target, i + 1, high));
	if (arr[i] > target)
		return (binary_search(arr, target, low, i - 1));
	return (i);
}
