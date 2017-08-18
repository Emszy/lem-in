/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:35:57 by ebucheit          #+#    #+#             */
/*   Updated: 2017/08/17 18:35:57 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

t_2d_ptr	save_input()
{
	char		*line;
	t_2d_ptr	file;
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "") == 0)
			break;
		file.data = ft_addstr(file.data, line, x);
		free(line);
		x++;
	}
	if (x <= 1)
		error_master5000("ERROR");
	file.length = x;
	return (file);
}

int check_line(char *line, int found_ant)
{
	int space;
	int dash;
	int hash;
	int comment;
	int x = 0;
	char **split;

	comment = 0;
	space = 0;
	dash = 0;
	hash = 0;

	if (line[0] == 'L')
		error_master5000("Error");
	if (ft_strchr(line, ' '))
	{	
		split = ft_strsplit(line, ' ');
		while (split[x])
			x++;
		free_2d_char(split, x);
		if (x != 3)
			error_master5000("ERROR SPLIT");
		space = 1;
	}
	if (ft_strchr(line, '-'))
	{
		split = ft_strsplit(line, '-');
		while (split[x])
			x++;
		free_2d_char(split, x);
		if (x != 2)
			error_master5000("ERROR DASH");
		dash = 1;
	}
	if (line[0] == '#')
		comment = 1;
	if (line[0] == '#' && line[1] == '#')
		hash = 1;
	if (space && dash)
		error_master5000("ERROR");
	if (space == 0 && dash == 0 && hash == 0 && comment == 0 && check_for_letters(line) && found_ant == 0)
		return(1);
	return (found_ant);
}

t_2d_ptr	save_file(char *filename)
{
	char		*line;
	t_2d_ptr	file;
	int			fd;
	int			x;
	int			y;
	int			found_ant;

	found_ant = 0;
	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error_master5000("ERROR");
	while (get_next_line(fd, &line))
	{
		found_ant = check_line(line, found_ant);
		file.data = ft_addstr(file.data, line, x);
		free(line);
		x++;
	}
	if (x <= 1)
		error_master5000("ERROR");
	file.length = x;
	return (file);
}

t_rooms		*prep_rooms(t_rooms *room, t_2d_ptr file, int room_count)
{
	room = init_rooms(room, room_count);
	room = save_rooms(file, room);
	room = get_link_count(file, room, room_count);
	room = alloc_rooms(room, room_count);
	room = get_link_names(file, room, room_count);
	return (room);
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

int			main(int ac, char **av)
{
	int			ants;
	int			room_count;
	t_rooms		*room;
	t_search	search;
	t_2d_ptr	file;

	room = NULL;
	room_count = 0;
	if (ac > 0)
	{
		if (av[1] && ac == 2)
			file = save_file(av[1]);
		else
			file = save_input();
			ants = get_ant_count(file);
			room_count = get_room_count(file);
			room = (t_rooms *)malloc(sizeof(t_rooms) * room_count);
			if (!room)
				error_master5000("ERROR");
			room = prep_rooms(room, file, room_count);
			search = find_path(room, room_count);
			send_ants(search, ants);
			free_lemons(room, search, file, room_count);
	}
	return (0);
}
