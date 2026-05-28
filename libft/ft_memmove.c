/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:14:12 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/16 00:09:41 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ud;
	unsigned char	*us;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ud = (unsigned char *)dest;
	us = (unsigned char *)src;
	if (src < dest)
	{
		while (n--)
			ud[n] = us[n];
	}
	else
	{
		while (n--)
		{
			ud[i] = us[i];
			i++;
		}
	}
	return (dest);
}
