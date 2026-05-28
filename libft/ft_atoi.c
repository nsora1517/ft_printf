/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 01:51:15 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/15 00:29:32 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		m;
	long	ans;

	i = 0;
	m = 1;
	ans = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			m = -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		ans = (ans * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)(ans * m));
}
