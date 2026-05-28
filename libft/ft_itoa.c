/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:05:28 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/15 00:40:47 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	long	ln;

	ln = n;
	len = nbr_len(ln);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	if (ln < 0)
	{
		nbr[0] = '-';
		ln = ln * -1;
	}
	nbr[len] = '\0';
	len--;
	if (ln == 0)
		nbr[0] = '0';
	while (ln > 0)
	{
		nbr[len] = (ln % 10) + '0';
		ln = ln / 10;
		len--;
	}
	return (nbr);
}
