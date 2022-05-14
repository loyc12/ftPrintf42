/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:53:48 by llord             #+#    #+#             */
/*   Updated: 2022/04/28 12:51:20 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//small fonctions for ft_printf

int	printchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	allowsprint(char c)
{
	if (c == 'c' || c == 's' || c == 'p' \
		|| c == 'd' || c == 'i' || c == 'u' \
		|| c == 'o' || c == 'x' || c == 'X' \
		|| c == '%')
		return (1);
	return (0);
}

size_t	strlenght(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
