/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 06:28:36 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 00:13:11 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_putptr_p(void *ptr)
{
	int ans;
	if(ptr == NULL)
	{
		write(1,"(nil)",5);
		return(5);
	}
	write(1,"0x",2);
	ans = ft_puthex_p((unsigned long)ptr,0);
	return(ans + 2);
}
