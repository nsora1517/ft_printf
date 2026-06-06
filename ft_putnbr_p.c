/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 05:52:42 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/06 21:27:28 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_len(int n)
{
	int	count;
	int	check;

	count = 0;
	if (n == 0)
	{
		check = write(1, "0", 1);
		if (check == -1)
			return (-1);
		return (1);
	}
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	putintmin(void)
{
	int	check;

	check = write(1, "-2147483648", 11);
	if (check == -1)
		return (-1);
	return (11);
}

static int	minus(void)
{
	int	check;

	check = write(1, "-", 1);
	if (check == -1)
		return (-1);
	return (1);
}

static int	writenbr(int n)
{
	int		check;
	char	ans;

	ans = n % 10 + '0';
	check = write(1, &ans, 1);
	if (check == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_p(int n)
{
	int	count;
	int	check;

	if (n == -2147483648)
		return (putintmin());
	count = count_len(n);
	if (n == 0)
		return (count);
	if (n < 0)
	{
		check = minus();
		if (check == -1)
			return (-1);
		n *= -1;
	}
	if (n >= 10)
	{
		check = ft_putnbr_p(n / 10);
		if (check == -1)
			return (-1);
	}
	check = writenbr(n);
	if (check == -1)
		return (-1);
	return (count);
}
