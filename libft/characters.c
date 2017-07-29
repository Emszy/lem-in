/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	prepend_width(t_flags flags, int width)
{
	int		x;
	char	spaces;

	x = -1;
	if (flags.zero_spacer == 1)
		spaces = '0';
	else
		spaces = ' ';
	while (++x < width)
		ft_putchar(spaces);
}

void	chars(va_list ap, t_flags flags, char specifier)
{
	char *ws;
	char c;

	if (specifier == 'c' && flags.l == 0)
	{
		c = va_arg(ap, int);
		prepend_width(flags, flags.width);
		ft_putchar(c);
	}
	else
	{
		prepend_width(flags, flags.width);
		ws = wide_to_s(va_arg(ap, wint_t));
		ft_putstr(ws);
	}
}
