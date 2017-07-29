/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:53:15 by ebucheit          #+#    #+#             */
/*   Updated: 2017/05/30 18:53:15 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*cp_pointer(long n, int len)
{
	char	*new;

	new = ft_strnew(len);
	new[len] = '\0';
	while (--len >= 0)
	{
		if (n != 0)
		{
			if ((n % 16) > 9)
				new[len] = (n % 16) - 10 + 'a';
			else
				new[len] = (n % 16) + '0';
		}
		else
			new[len] = '0';
		n /= 16;
	}
	new[1] = 'x';
	new[0] = '0';
	return (new);
}

void		p_to_s(void *pointer, t_flags flags)
{
	long	n;
	int		len;
	char	*new;

	n = (long)pointer;
	if (n == 0 && flags.precision)
	{
		print_num("0x", flags);
		return ;
	}
	len = get_size(n, 16) + 2;
	if (flags.precision > len - 2)
		len = flags.precision + 2;
	new = cp_pointer(n, len);
	print_num(new, flags);
}
