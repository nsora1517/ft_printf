/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:33:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/23 13:56:10 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar_p(char c);
int	ft_putstr_p(char *s);
int	ft_putptr(void *ptr);
int	ft_putnbr_p(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_puthex(unsigned long n, int uppercase);

#endif
