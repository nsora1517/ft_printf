/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:46:47 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/15 00:41:50 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	or_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*range;
	int		i;
	int		len;

	i = 0;
	len = or_strlen(s);
	range = malloc(sizeof(char) * (len + 1));
	if (!range)
		return (NULL);
	while (s[i] != '\0')
	{
		range[i] = s[i];
		i++;
	}
	range[i] = '\0';
	return (range);
}
