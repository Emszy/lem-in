/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:35:57 by ebucheit          #+#    #+#             */
/*   Updated: 2017/08/17 18:35:57 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int			get_ant_count(t_2d_ptr file)
{
	int		ants;
	int		x;

	x = 0;
	ants = 0;
	while(file.data[x][0] == '#')
		x++;
	check_for_letters(file.data[x]);
	ants = ft_atoi(file.data[x]);
	if (ants <= 0)
		error_master5000("ERROR");
	return (ants);
}

int			get_room_count(t_2d_ptr file)
{
	int		room_count;
	int		x;

	x = 1;
	room_count = 0;
	while (x < file.length)
	{
		if (ft_strcmp(file.data[x], "##start") == 0)
		{
			if (ft_strchr(file.data[x + 1], '-'))
				error_master5000("ERROR");
			x++;
		}
		if (ft_strchr(file.data[x], ' ') && ft_strchr(file.data[x], '#') == NULL)
			room_count++;
		x++;
	}
	if (room_count <= 1)
		error_master5000("ERROR");
	return (room_count);
}

t_rooms		*check_for_hash(t_2d_ptr *file, t_rooms *room)
{
	int		x;
	int		y;

	file->has_finish = 0;
	file->has_start = 0;
	x = 0;
	y = -1;
	while (++y < file->length)
	{
		if (ft_strcmp(file->data[y], "##start") == 0)
		{
			file->has_start += 1;
			y++;
			room[x].start = 1;
		}
		if (ft_strcmp(file->data[y], "##end") == 0)
		{
			file->has_finish += 1;
			y++;
			room[x].end = 1;
		}
		if (ft_strchr(file->data[y], ' ') && ft_strchr(file->data[y], '#') == NULL)
			x++;
	}
	return(room);
}

t_rooms		room_info(char** split, t_rooms room)
{
	int		n;

	n = 0;
	while (split[n])
		n++;
	if (n > 3)
		error_master5000("ERROR");
	check_for_letters(split[1]);
	check_for_letters(split[2]);
	room.name = ft_strmake(split[0]);
	room.x = ft_atoi(split[1]);
	room.y = ft_atoi(split[2]);
	free_2d_char(split, n);
	return (room);
}

t_rooms		*save_rooms(t_2d_ptr file, t_rooms *room)
{
	int		x;
	int		y;
	char	**split;

	x = 0;
	y = -1;
	room = check_for_hash(&file, room);
	while (++y < file.length)
	{	
		if (ft_strchr(file.data[y], ' ') && ft_strchr(file.data[y], '#') == NULL)
		{
			split = ft_strsplit(file.data[y], ' ');
			room[x] = room_info(split, room[x]);
			x++;
		}
	}
	if (file.has_finish != 1 || file.has_start != 1)
		error_master5000("ERROR");
	return (room);
}
