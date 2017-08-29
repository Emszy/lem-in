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
		error_master5000("NOT ENOUGH DATA");
	file.length = x;
	return (file);
}

t_2d_ptr	save_file(char *filename)
{
	char		*line;
	t_2d_ptr	file;
	int			fd;
	int			x;
	int			found_ant;

	found_ant = 0;
	x = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error_master5000("ERROR FILE");
	while (get_next_line(fd, &line))
	{
		found_ant = check_line(line, found_ant);
		file.data = ft_addstr(file.data, line, x);
		free(line);
		x++;
	}
	if (x <= 1)
		error_master5000("ERROR NOT ENOUGH LINES");
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

void run_lemon(t_rooms *room, t_2d_ptr file)
{
	int			ants;
	int			room_count;
	t_search	search;

	room_count = 0;
	ants = get_ant_count(file);
	room_count = get_room_count(file);
	room = (t_rooms *)malloc(sizeof(t_rooms) * room_count);
	if (!room)
		error_master5000("ERROR");
	room = prep_rooms(room, file, room_count);
	check_dup(room, room_count);
	search = find_path(room, room_count);
	send_ants(search, ants);
	free_lemons(room, search, file, room_count);
}
int			main(int ac, char **av)
{
	t_rooms		*room;
	t_2d_ptr	file;

	room = NULL;
	if (ac > 0 && av != NULL)
	{
		usage(ac);
		if (av[1] && ac == 2)
			file = save_file(av[1]);
		else
			file = save_input();
			run_lemon(room, file);
	}
	return (0);
}
