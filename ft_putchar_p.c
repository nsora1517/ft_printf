/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 05:49:19 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 21:36:51 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int ft_putchar_p(char c)
{
	int check;
	check = write(1,&c,1);
	if(check == -1)
	return(-1);
	return(1);
}
