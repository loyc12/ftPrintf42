/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:05:48 by llord             #+#    #+#             */
/*   Updated: 2022/04/28 13:18:30 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//prints a number in a given base

static void	printbase_s(unsigned int n, \
	unsigned long long base, char *baselist, int *len)
{
	char	digit;

	if (base > strlenght(baselist))
		write(1, "Unsuitable baselist", 19);
	else
	{
		if (n >= base)
			printbase_s((n / base), base, baselist, len);
		digit = baselist[(n % base)];
		write(1, &digit, 1);
	}
	++(*len);
}

int	printbase(unsigned int n, unsigned long long base, char *baselist)
{
	char	digit;
	int		len;

	len = 0;
	if (base > strlenght(baselist))
		write(1, "Unsuitable baselist", 19);
	else
	{
		if (n >= base)
			printbase_s((n / base), base, baselist, &len);
		digit = baselist[(n % base)];
		write(1, &digit, 1);
	}
	return (++len);
}
