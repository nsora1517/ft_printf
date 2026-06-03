/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 06:10:11 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/04 00:37:28 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
int ft_putstr_p(char *s)
{
	int len;
	int check;
	len = 0;
	if(!s)
	{
		check = write(1, "(null)", 6);
		if(check == -1)
		return(-1);
		return(6);
	}
	while(s[len])
	{
		check = write(1, &s[len], 1);
		if(check == -1)
		return(-1);
		len++;
	}
	return(len);
}
