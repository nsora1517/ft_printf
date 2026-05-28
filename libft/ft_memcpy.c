/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:15:08 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/12 17:17:35 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ud;
	unsigned char	*us;

	if (!dest && !src)
		return (NULL);
	ud = (unsigned char *)dest;
	us = (unsigned char *)src;
	while (n--)
		*ud++ = *us++;
	return (dest);
}
