/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unumbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		u_to_s(uintmax_t num, t_flags flags)
{
	int		size;
	char	*n;

	size = get_size(num, 10);
	if (flags.precision > size)
		size = flags.precision;
	n = ft_strnew(size);
	n[size] = '\0';
	while (--size >= 0)
	{
		if (num != 0)
			n[size] = num % 10 + '0';
		else
			n[size] = '0';
		num /= 10;
	}
	print_num(n, flags);
}

uintmax_t	promoting_u(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	if (*fmt == 'u' && flags.hh)
		res = (unsigned char)va_arg(ap, int);
	else if (*fmt == 'u' && flags.h)
		res = (unsigned short)va_arg(ap, int);
	else if ((*fmt == 'u' && flags.l) || *fmt == 'U')
		res = va_arg(ap, unsigned long);
	else if (*fmt == 'u' && flags.ll)
		res = va_arg(ap, unsigned long long);
	else if (*fmt == 'u' && flags.j)
		res = va_arg(ap, uintmax_t);
	else if (*fmt == 'u' && flags.z)
		res = va_arg(ap, ssize_t);
	else
		res = va_arg(ap, unsigned int);
	return (res);
}

void		unum_parse(va_list ap, t_flags flags, char *fmt)
{
	uintmax_t	res;

	res = promoting_u(ap, flags, fmt);
	if (flags.hash && res == 0)
	{
		prepend_width(flags, flags.width);
		ft_putchar('0');
		return ;
	}
	if (flags.precision && res == 0)
	{
		prepend_width(flags, flags.width);
		ft_putchar(' ');
		return ;
	}
	if (!flags.width && flags.precision && res == 0)
		return ;
	u_to_s(res, flags);
}
