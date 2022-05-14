/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llord <llord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:53:36 by llord             #+#    #+#             */
/*   Updated: 2022/04/28 12:50:14 by llord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		printnbr(int n);
int		printbase(unsigned int n, unsigned long long base, char *baselist);
int		printchr(int c);
int		printstr(char *str);
int		printptr(unsigned long long ptr);
int		allowsprint(char c);
size_t	strlenght(const char *s);

#endif