/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:09:19 by tjuvan            #+#    #+#             */
/*   Updated: 2024/02/05 15:33:29 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_counter2(char const *word, char c)
{
	int	count;
	int	word_count;

	count = 0;
	word_count = 0;
	while (word[count] != '\0')
	{
		if (word[count] == c)
			count++;
		else
		{
			word_count++;
			while (word[count] && word[count] != c)
				count++;
		}
	}
	return (word_count);
}

char	*word_placer2(char *word, char const *s, int i, int word_len)
{
	int	count;

	count = 0;
	while (word_len > 0)
	{
		word[count] = s[i - word_len];
		count++;
		word_len--;
	}
	word[count] = '\0';
	return (word);
}

char	**free_arr2(char **big, int count)
{
	while (count > 0)
	{
		count--;
		free(big[count]);
	}
	free(big);
	return (0);
}

char	**word_splitter2(char const *s, char c, char **s2, int num_words)
{
	int	count;
	int	nbr_word;
	int	word_len;

	count = 0;
	nbr_word = 1;
	word_len = 0;
	while (nbr_word < num_words + 1)
	{
		while (s[count] && s[count] == c)
			count++;
		while (s[count] && s[count] != c)
		{
			count++;
			word_len++;
		}
		s2[nbr_word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!s2[nbr_word])
			return (free_arr2(s2, nbr_word));
		word_placer2(s2[nbr_word], s, count, word_len);
		word_len = 0;
		nbr_word++;
	}
	s2[nbr_word] = 0;
	return (s2);
}

char	**ft_split2(char const *s, char c)
{
	char			**s2;
	unsigned int	num_of_words;

	if (!s)
		return (0);
	num_of_words = word_counter2(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_of_words + 2));
	if (!s2)
		return (0);
	s2[0] = strdup(" ");
	s2 = word_splitter2(s, c, s2, num_of_words);
	return (s2);
}
