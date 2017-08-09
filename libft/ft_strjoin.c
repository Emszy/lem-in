/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 21:39:53 by ebucheit          #+#    #+#             */
/*   Updated: 2016/09/30 21:39:54 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char *new;

	new = (char*)malloc(sizeof(new) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	new[ft_strlen(new)] = '\0';
	return (new);
}
