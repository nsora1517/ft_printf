/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 05:42:08 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 01:32:15 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static void ft_putnbr(unsigned int n)
{
	char ans;
	if(n >= 10)
	ft_putnbr(n / 10);
	ans = n % 10 + '0';
	write(1, &ans , 1);
}

int ft_putunsigned_p(unsigned int n)
{
	unsigned int nbr;
	unsigned int count;
	nbr = n;
	count = 0;
	if(n == 0)
	{
		write(1, "0" , 1);
		return(1);
	}
	while(nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	ft_putnbr(n);
	return(count);
}
