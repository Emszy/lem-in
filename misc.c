/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:35:57 by ebucheit          #+#    #+#             */
/*   Updated: 2017/08/17 18:35:57 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_rooms		*alloc_rooms(t_rooms *room, int room_count)
{
	int		x;

	x = -1;
	while (++x < room_count)
		room[x].connections =  (char**)malloc(sizeof(char*) * room[x].links);
	return (room);
}

int check_for_letters(char *string)
{
	int x;

	x = 0;
	while (string[x])
	{
		if (!ft_isdigit(string[x]))
			error_master5000("letter in the num");
		x++;
	}
	return (1);
}

t_rooms *init_rooms(t_rooms *room, int room_count)
{
	int x;

	x = 0;
	while (x < room_count)
	{
		room[x].start = 0;
		room[x].end = 0;
		room[x].name = NULL;
		room[x].x = 0;
		room[x].y = 0;
		room[x].links = 0;
		room[x].index = 0;
		room[x].connections = NULL;
		x++;
	}
	return (room);
}
