/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:38:11 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/12 17:16:30 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	total;
	char	*range;

	s1_len = ft_strlen(s1);
	total = s1_len + ft_strlen(s2);
	range = malloc(sizeof(char) * (total + 1));
	if (!range)
		return (NULL);
	ft_strlcpy(range, s1, s1_len + 1);
	ft_strlcat(range, s2, total + 1);
	return (range);
}
