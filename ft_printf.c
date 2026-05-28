/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagasak <snagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:35:49 by snagasak          #+#    #+#             */
/*   Updated: 2026/05/18 23:51:30 by snagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
// // int ft_printf(const char *format, ...)
// // {

// // }

# include <stdio.h>

void foo(char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	while (fmt != NULL)
	{
		printf("%s\n", fmt);
		fmt = va_arg(ap, char*);
	}
	va_end(ap);
}

void	sum_product(double *sum, double *product, int n, ...)
{
	va_list	ap;
	va_list	dest;
	int		i;

	/* nからスタートさせているのがポイントです */
	va_start(ap, n);
	va_copy(dest,ap);

	*sum = 0.0;
	*product = 0.0;

	/* 総和 */
	for ( i = 0; i < n; i++ )
		*sum += va_arg(ap, double);

	/* 総乗 */
	*product = va_arg(dest, double);

	for ( i = 1; i < n; i++ )
		*product *= va_arg(dest, double);

	va_end(ap);
	va_end(dest);
}

int main(void) {
	double sum, product;

	sum_product(&sum, &product, 4, 1.0, 2.0, 3.0, 4.0);

	printf("総和: %.1f\n", sum);
	printf("総乗: %.1f\n", product);
	foo("aiueo", "test", "aaaaaa", NULL);
	return 0;

	return EXIT_SUCCESS;
}
