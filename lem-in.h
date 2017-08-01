/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:06:36 by ebucheit          #+#    #+#             */
/*   Updated: 2017/06/28 17:06:36 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

char	*ft_strmake(char *string);
char	**malloc_list(char *string);
char	**ft_addstr(char **list, char *string, int size);


#endif
