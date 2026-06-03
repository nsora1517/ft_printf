/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 06:28:36 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/04 01:01:48 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_putptr_p(void *ptr)
{
	int ans;
	int check;
	if(ptr == NULL)
	{
		check = write(1,"(nil)",5);
		if(check == -1)
		return(-1);
		return(5);
	}
	check = write(1,"0x",2);
	if(check == -1)
	return(-1);
	ans = ft_puthex_p((unsigned long)ptr,0);
	if(ans == -1)
	return(-1);
	return(ans + 2);
}
