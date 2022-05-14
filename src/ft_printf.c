/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:53:48 by llord             #+#    #+#             */
/*   Updated: 2022/05/03 13:59:42 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//printf but wonkier

static int	printparam(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = printchr(va_arg(args, int));
	else if (c == '%')
		len = printchr('%');
	else if (c == 's')
		len = printstr(va_arg(args, char *));
	else if (c == 'p')
		len = printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = printnbr(va_arg(args, int));
	else if (c == 'u')
		len = printbase(va_arg(args, unsigned long long), 10, "0123456789"); // unsigned int?????
	else if (c == 'o')
		len = printbase(va_arg(args, unsigned long long), 8, "01234567");
	else if (c == 'x')
		len = printbase(va_arg(args, \
		unsigned long long), 16, "0123456789abcdef");
	else if (c == 'X')
		len = printbase(va_arg(args, \
		unsigned long long), 16, "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (allowsprint(input[i + 1]))
				len += printparam(input[i + 1], args);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
