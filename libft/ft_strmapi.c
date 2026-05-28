/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:04:29 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/12 17:16:13 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*range;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = (unsigned int)ft_strlen(s);
	range = malloc(sizeof(char) * (len + 1));
	if (!range)
		return (NULL);
	while (i < len)
	{
		range[i] = f(i, s[i]);
		i++;
	}
	range[i] = '\0';
	return (range);
}
