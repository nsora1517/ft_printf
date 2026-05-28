/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:52:09 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/12 17:15:42 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*range;

	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
	{
		range = malloc(1);
		if (!range)
			return (NULL);
		range[0] = '\0';
		return (range);
	}
	if (len > s_len - (size_t)start)
		len = s_len - (size_t)start;
	range = malloc(sizeof(char) * (len + 1));
	if (!range)
		return (NULL);
	ft_strlcpy(range, s + start, len + 1);
	return (range);
}
