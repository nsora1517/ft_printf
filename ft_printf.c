/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:35:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/03 01:00:39 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int handle_format(char spec, va_list *args)
{
	int count;
	count = 0;
	if(spec == 'c')
	count = count + ft_putchar_p(va_arg(*args,int));
	else if(spec == 's')
	count = count + ft_putstr_p(va_arg(*args,char *));
	else if(spec == 'd')
	count = count + ft_putnbr_p(va_arg(*args,int));
	else if(spec == 'p')
	count = count + ft_putptr_p(va_arg(*args,void *));
	else if(spec== 'i')
	count = count + ft_putnbr_p(va_arg(*args,int));
	else if(spec == 'u')
	count = count + ft_putunsigned_p(va_arg(*args,unsigned int));
	else if(spec == 'x')
	count = count + ft_puthex_p(va_arg(*args,unsigned long),0);
	else if(spec == 'X')
	count = count + ft_puthex_p(va_arg(*args,unsigned long),1);
	else if(spec == '%')
	{
		write(1, "%" ,1);
		count = count + 1;
	}
	return(count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	i = 0;
	count = 0;
	va_start(args,format);
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			count = count + handle_format(format[i + 1],&args);
			i++;
		}
		else
		{
			write(1, &format[i] , 1);
			count = count + 1;
		}
		i++;
	}
	va_end(args);
	return(count);
}
