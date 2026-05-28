/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 23:31:04 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/15 00:41:41 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_box(char **box, size_t size)
{
	while (size--)
		free(box[size]);
	free(box);
}

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
			i++;
		if (i > 0 && str[i - 1] != c)
			count++;
	}
	return (count);
}

static size_t	end_word(const char *s, char c, size_t i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	fill_box(const char *s, char c, char **box)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			j = end_word(s, c, i);
			box[size] = ft_substr(s, i, j - i);
			if (!box[size])
			{
				free_box(box, size);
				return (0);
			}
			size++;
			i = j;
		}
		else
			i++;
	}
	box[size] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**box;

	count = count_words(s, c);
	box = malloc(sizeof(char *) * (count + 1));
	if (!box)
		return (NULL);
	if (!fill_box(s, c, box))
		return (NULL);
	return (box);
}
