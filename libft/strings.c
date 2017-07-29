/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*wide_to_s(wint_t w)
{
	char *ws;

	ws = ft_strnew(4);
	if (w <= 0x0ff)
		ws[0] = w;
	else if (w <= 0x07ff)
	{
		ws[0] = (w >> 6) + 0xc0;
		ws[1] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		ws[0] = (w >> 12) + 0xe0;
		ws[1] = ((w >> 6) & 0x3f) + 0x80;
		ws[2] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0x10FFFF)
	{
		ws[0] = (w >> 18) + 0xf0;
		ws[1] = (w >> 12 & 0x3f) + 0x80;
		ws[2] = (w >> 6 & 0x3f) + 0x80;
		ws[3] = (w & 0x3f) + 0xc80;
	}
	return (ws);
}

void		limit_print(char *str, int len)
{
	int x;

	x = -1;
	while (*str && ++x < len)
	{
		ft_putchar(*str);
		str++;
	}
}

void		make_string(char *s, t_flags flags)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(s);
	if (flags.precision && !(flags.precision > size))
		size = flags.precision;
	if (flags.neg)
	{
		if (flags.precision == 0)
			ft_putstr(s);
		if (flags.precision > 0)
			limit_print(s, flags.precision);
	}
	if (flags.width > size)
		prepend_width(flags, flags.width - size);
	if (flags.precision == 0 && !flags.neg)
		ft_putstr(s);
	else if (flags.precision > 0 && !flags.neg)
		limit_print(s, flags.precision);
}

void		l_str(wchar_t *ws, t_flags flags)
{
	int		total;
	int		len;
	char	*str;
	char	*new;

	new = ft_strnew(4);
	total = 0;
	if (flags.precision > 0)
		len = flags.precision;
	else
		len = MAX_INT;
	while (ws != NULL && *ws && (total <= len))
	{
		total += ft_strlen(str = wide_to_s(*ws++));
		if (total <= len)
			new = ft_strjoin(new, str);
	}
	make_string(new, flags);
	ft_strdel(&new);
}

void		str_parse(va_list ap, t_flags flags, char c)
{
	char	*str;
	wchar_t	*wide;

	str = "\0";
	if (c == 'S' || (flags.l && c == 's'))
	{
		wide = va_arg(ap, wchar_t *);
		if (wide)
			l_str(wide, flags);
		else
			make_string("(null)", flags);
	}
	else
	{
		str = va_arg(ap, char *);
		if (str)
			make_string(str, flags);
		else
			make_string("(null)", flags);
	}
}
