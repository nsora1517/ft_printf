/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 05:42:08 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/06 18:50:46 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned int n)
{
	char	ans;
	int		check;

	if (n >= 10)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
	}
	ans = n % 10 + '0';
	check = write(1, &ans, 1);
	if (check == -1)
		return (-1);
	return (1);
}

int	ft_putunsigned_p(unsigned int n)
{
	unsigned int	nbr;
	unsigned int	count;
	int				check;

	nbr = n;
	count = 0;
	if (n == 0)
	{
		check = write(1, "0", 1);
		if (check == -1)
			return (-1);
		return (1);
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	check = ft_putnbr(n);
	if (check == -1)
		return (-1);
	return (count);
}
