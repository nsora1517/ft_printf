/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:28:24 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/11 19:24:59 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_16(unsigned long n, int uppercase)
{
	char	ans;
	char	*base;
	int		check;

	base = "0123456789abcdef";
	if (uppercase == 1)
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		check = ft_putnbr_16(n / 16, uppercase);
		if (check == -1)
			return (-1);
	}
	ans = base[n % 16];
	check = write(1, &ans, 1);
	if (check == -1)
		return (-1);
	return (1);
}

static int	count_len(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_puthex_p(unsigned long n, int uppercase)
{
	int	len;
	int	check;

	check = ft_putnbr_16(n, uppercase);
	if (check == -1)
		return (-1);
	len = count_len(n);
	return (len);
}
