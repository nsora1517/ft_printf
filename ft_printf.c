/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:35:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/06 21:15:01 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_str(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_putchar_p(va_arg(*args, int)));
	else if (spec == 's')
		return (ft_putstr_p(va_arg(*args, char *)));
	else if (spec == 'p')
		return (ft_putptr_p(va_arg(*args, void *)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	handle_num(char spec, va_list *args)
{
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_p(va_arg(*args, int)));
	else if (spec == 'u')
		return (ft_putunsigned_p(va_arg(*args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_puthex_p(va_arg(*args, unsigned long), spec == 'X'));
	return (0);
}

static int	handle_format(char spec, va_list *args)
{
	int	count;
	int	check;

	count = 0;
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == '%')
	{
		check = handle_str(spec, args);
		if (check == -1)
			return (-1);
		count = count + check;
	}
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X')
	{
		check = handle_num(spec, args);
		if (check == -1)
			return (-1);
		count = count + check;
	}
	// else if(spec == 'a')
	// count = count + live_a();
	return (count);
}

static int	process_char(const char *format, int *i, va_list *args)
{
	if (format[*i] == '%')
	{
		(*i)++;
		return (handle_format(format[*i], args));
	}
	return (write(1, &format[*i], 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		check;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		check = process_char(format, &i, &args);
		if (check == -1)
			return (-1);
		count = count + check;
		i++;
	}
	va_end(args);
	return (count);
}
