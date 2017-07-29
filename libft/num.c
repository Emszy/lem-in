/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		edge_case(t_flags flags)
{
	int x;

	x = 0;
	if (flags.precision < flags.width && flags.precision != 0)
	{
		x = 0;
		flags.width = flags.width - flags.precision;
		while (x < flags.width)
		{
			ft_putchar(' ');
			x++;
		}
	}
	return (flags);
}

int			char_len(uintmax_t number, t_flags flags, char before)
{
	int		len;

	len = get_size(number, 10);
	if (flags.precision >= len)
		len = flags.precision;
	if (before != 0 && !flags.zero_spacer)
		len++;
	else if (before == '-' && flags.zero_spacer && !flags.neg)
		len++;
	return (len);
}

void		num_to_s(uintmax_t number, t_flags flags, char before)
{
	char	*nbr;
	int		len;

	len = char_len(number, flags, before);
	nbr = ft_strnew(len);
	nbr[len] = '\0';
	while (--len >= 0)
	{
		if (number != 0)
			nbr[len] = number % 10 + '0';
		else
			nbr[len] = '0';
		number /= 10;
	}
	if (before == '+' && flags.zero_spacer)
	{
		ft_putchar(before);
		flags.width--;
	}
	else if (before != 0)
		nbr[0] = before;
	flags = edge_case(flags);
	print_num(nbr, flags);
}

intmax_t	promo_check(va_list ap, t_flags flags, char *fmt)
{
	intmax_t	res;

	if (*fmt == 'D' || flags.l)
		res = va_arg(ap, long);
	else if (flags.h)
		res = (short)va_arg(ap, int);
	else if (flags.hh)
		res = (signed char)va_arg(ap, int);
	else if (flags.ll)
		res = va_arg(ap, long long);
	else if (flags.z)
		res = va_arg(ap, ssize_t);
	else if (flags.j)
		res = va_arg(ap, intmax_t);
	else
		res = va_arg(ap, int);
	return (res);
}

void		num_parse(va_list ap, t_flags flags, char *fmt)
{
	intmax_t	number;
	char		before;

	number = promo_check(ap, flags, fmt);
	if (flags.plus_sign != 0)
		before = '+';
	else
		before = 0;
	if (flags.space && !flags.plus_sign)
		before = ' ';
	if (number < 0)
	{
		number *= -1;
		before = '-';
	}
	if (number == 0 && !flags.width && flags.precision)
		return ;
	if (number == 0 && flags.precision)
		ft_putchar(' ');
	num_to_s((uintmax_t)number, flags, before);
}
