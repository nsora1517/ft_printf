/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 01:28:24 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 00:13:01 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void ft_putnbr_16(unsigned long n, int uppercase)
{
	char ans;
	char *base;
	base = "0123456789abcdef";
	if(uppercase == 1)
	base = "0123456789ABCDEF";
	if(n >= 16)
	ft_putnbr_16(n / 16 , uppercase);
	ans = base[n % 16];
	write(1, &ans, 1);
}

static int count_len(unsigned long n)
{
	int count;
	count = 0;
	if(n == 0)
	return(1);
	while(n > 0)
	{
		n = n / 16;
		count++;
	}
	return(count);
}

int ft_puthex_p(unsigned long n, int uppercase)
{
	int len;
	ft_putnbr_16(n,uppercase);
	len = count_len(n);
	return(len);
}

// int main(){
// 	ft_puthex_p(1000,0);
// }
