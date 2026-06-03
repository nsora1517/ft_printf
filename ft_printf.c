/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:35:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/06/04 02:05:11 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int handle_str(char spec, va_list *args)
{
	int count;
	int check;

	count = 0;
	if(spec == 'c')
	{
		check = ft_putchar_p(va_arg(*args,int));
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	else if(spec == 's')
	{
		check = ft_putstr_p(va_arg(*args,char *));
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	else if(spec == 'p')
	{
		check = ft_putptr_p(va_arg(*args,void *));
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	else if(spec == '%')
	{
		check = write(1, "%" ,1);
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	return(count);
}

static int handle_num(char spec, va_list *args)
{
	int count;
	int check;

	count = 0;
	if(spec == 'd' || spec == 'i')
	{
		check = ft_putnbr_p(va_arg(*args, int));
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	else if(spec == 'u')
	{
		check = ft_putunsigned_p(va_arg(*args,unsigned int));
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	else if(spec == 'x' || spec == 'X')
	{
		check = ft_puthex_p(va_arg(*args,unsigned long),spec == 'X');
		if(check == -1)
    	return(-1);
		count = count + check;
	}
	return(count);
}

static int handle_format(char spec, va_list *args)
{
	int count;
	int check;

	count = 0;
	if(spec == 'c'||spec == 's'||spec == 'p'||spec == '%')
	{
		check = handle_str(spec,args);
		if(check == -1)
		return(-1);
		count = count + check;
	}
	if(spec == 'd'||spec == 'i'||spec == 'u'||spec == 'x' || spec == 'X')
	{
		check = handle_num(spec,args);
		if(check == -1)
		return(-1);
		count = count + check;
	}
	// else if(spec == 'a')
	// count = count + live_a();

	return(count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	int check;

	i = 0;
	count = 0;
	check = 0;
	va_start(args,format);
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			check = handle_format(format[i + 1],&args);
			if(check == -1)
			return(-1);
			count = count + check;
			i++;
		}
		else
		{
			check = write(1, &format[i] , 1);
			if(check == -1)
			return(-1);
			count = count + 1;
		}
		i++;
	}
	if (check == -1)
		return (-1);
	va_end(args);
	return(count);
}
