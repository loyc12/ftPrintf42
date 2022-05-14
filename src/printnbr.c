/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:05:48 by llord             #+#    #+#             */
/*   Updated: 2022/05/03 13:46:19 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//prints a signed decimal number onto the terminal. much spageth

static	char	digitfinder(int number, int position)
{
	int		digit;

	while (position > 1)
	{
		number = number / 10;
		--position;
	}
	digit = number % 10;
	return ('0' + digit);
}

static	int	lenghtfinder(int number)
{
	int	lenght;

	lenght = 0;
	while (number > 0)
	{
		number = number / 10;
		++lenght;
	}
	return (lenght);
}

static int	sortnumber(int *n, int len)
{
	if (*n == 0)
		write (1, "0", 1);
	else if (*n < 0 && *n != -2147483648)
	{
		*n = 0 - *n;
		write (1, "-", 1);
	}
	else if (*n == -2147483648)
	{
		*n += 2000000000;
		*n = 0 - *n;
		write (1, "-2", 2);
		len++;
	}
	else
		len--;
	return (len);
}

int	printnbr(int n)
{
	int		lenght;
	int		len;
	char	digit;

	len = 1;
	len = sortnumber(&n, len);
	lenght = lenghtfinder(n);
	len += lenght;
	while (lenght > 0)
	{
		digit = digitfinder(n, lenght);
		--lenght;
		write(1, &digit, 1);
	}
	return (len);
}
