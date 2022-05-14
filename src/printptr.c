/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:05:48 by llord             #+#    #+#             */
/*   Updated: 2022/05/03 13:09:49 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//a mod of printbase aimed at printing a given pointer. much spageth

static void	printbase_s(unsigned long long n, \
	unsigned long long base, charj, int *len)
{
	char	digit;

	if (n >= base)
		printbase_s((n / base), base, baselist, len);
	digit = baselist[(n % base)];
	write(1, &digit, 1);
	++(*len);
}

int	printptr(unsigned long long ptr)
{
	unsigned long long		base;
	char					*baselist;
	char					digit;
	int						len;

	len = 2;
	base = 16;
	baselist = "0123456789abcdef";
	write(1, "0x", 2);
	if (ptr >= base)
		printbase_s((ptr / base), base, baselist, &len);
	digit = baselist[(ptr % base)];
	write(1, &digit, 1);
	return (++len);
}
