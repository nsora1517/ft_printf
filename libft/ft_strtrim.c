/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 21:50:44 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/15 00:42:23 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkfront(const char *s1, const char *set)
{
	int	front;
	int	i;

	i = 0;
	front = 0;
	while (set[i])
	{
		if (s1[front] == set[i])
		{
			front++;
			i = 0;
		}
		else
			i++;
	}
	return (front);
}

static int	checkback(const char *s1, const char *set)
{
	int	back;
	int	i;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (-1);
	back = (int)ft_strlen(s1) - 1;
	while (set[i])
	{
		if (s1[back] == set[i])
		{
			back--;
			i = 0;
		}
		else
			i++;
	}
	return (back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aftrim;
	int		front;
	int		back;
	int		i;

	i = 0;
	front = checkfront(s1, set);
	back = checkback(s1, set);
	if (back < front)
		return (ft_strdup(""));
	aftrim = malloc(sizeof(char) * ((back - front + 1) + 1));
	if (!aftrim)
		return (NULL);
	while (front <= back)
	{
		aftrim[i] = s1[front];
		i++;
		front++;
	}
	aftrim[i] = '\0';
	return (aftrim);
}
