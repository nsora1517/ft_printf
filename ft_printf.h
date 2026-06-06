/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:33:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/06 21:30:33 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_p(char c);
int	ft_putstr_p(char *s);
int	ft_putptr_p(void *ptr);
int	ft_putnbr_p(int n);
int	ft_putunsigned_p(unsigned int n);
int	ft_puthex_p(unsigned long n, int uppercase);
// int live_a(void);

#endif
