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

#include "../lem-in.h"

t_rooms		*alloc_rooms(t_rooms *room, int room_count)
{
	int		x;

	x = -1;
	while (++x < room_count)
		room[x].connections =  (char**)malloc(sizeof(char*) * room[x].links);
	return (room);
}

int			check_for_letters(char *string)
{
	int x;

	x = 0;
	while (string[x])
	{
		if (!ft_isdigit(string[x]))
			error_master5000("ERROR LETTER IN NUM");
		x++;
	}
	return (1);
}

t_rooms		*init_rooms(t_rooms *room, int room_count)
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

void		usage(int ac)
{
	if (ac > 2)
	{
		ft_printf("Usage:\n");
		ft_printf("\t./lem-in\n");
		ft_printf("or\n");
		error_master5000("./lem-in map_goes_here");
	}
}

void		free_lemons(t_rooms *room, t_search search, t_2d_ptr file, int room_count)
{
	int x = -1;

	free_2d_char(search.the_list, search.list_len);
	free_2d_char(file.data, file.length);
	while (++x < room_count)
	{
		free(room[x].name);
		free_2d_char(room[x].connections, room[x].links);
	}
	free(room);
}
