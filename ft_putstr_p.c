/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 06:10:11 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 00:13:17 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
int ft_putstr_p(char *s)
{
	int len;
	len = 0;
	if(!s)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while(s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return(len);
}
