/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 05:52:42 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 00:43:49 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
static int count_len(int n)
{
	int count;
	count = 0;
	if(n == 0)
	{
		write(1, "0", 1);
		return(1);
	}
	if(n < 0)
	{
		n = n * -1;
		count++;
	}
	while(n > 0)
	{
		n = n / 10;
		count++;
	}
	return(count);

}

int ft_putnbr_p(int n)
{
	int count;
	char ans;
	if(n == -2147483648)
	{
		write(1,"-2147483648",11);
		return(11);
	}
	count = count_len(n);
	if(n == 0)
	return(count);
	if(n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if(n >= 10)
	ft_putnbr_p(n / 10);
	ans = n % 10 + '0';
	write(1,&ans,1);
	return(count);
}
