/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinaz <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:38:00 by kinaz             #+#    #+#             */
/*   Updated: 2022/07/01 15:28:02 by kinaz            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *str)
{
	int	count;

	count = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

int	ft_putnbr(long double number, int base, int is_upper)
{
	int	count;

	count = 1;
	if (number < 0)
	{
		count++;
		number = -number;
		write(1, "-", 1);
	}
	if (number >= base)
		count += ft_putnbr(number / base, base, is_upper);
	if (is_upper)
		write(1, &"0123456789ABCDEF"[(unsigned long)number % base], 1);
	else
		write(1, &"0123456789abcdef"[(unsigned long)number % base], 1);
	return (count);
}

int	ft_pointer(long double number, int base, int is_upper)
{
	int	count;

	count = 0;
	count += ft_str("0x");
	count += ft_putnbr(number, base, is_upper);
	return (count);
}
