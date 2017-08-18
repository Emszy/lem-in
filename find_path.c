#include "lem-in.h"

int			on_list(t_search search, char *name)
{
	int		x;

	x = -1;
	while (++x < search.list_len)
	{
		if (ft_strcmp(search.the_list[x], name) == 0)
			return (1);
	}
	return (0);
}

t_search	check_end(t_rooms *room, t_rooms start_room, t_search search, int room_count)
{
	int		x;
	int		y;

	x = -1;
	while (++x < start_room.links)
	{
		y = -1;
		while (++y < room_count)
		{
			if (ft_strcmp(start_room.connections[x], room[y].name) == 0)
			{
				if (room[y].end == 1 || start_room.end == 1)
				{
					search.found_end = 1;
					search.the_list = ft_paragraph(search.the_list, room[y].name, search.list_len);
					search.list_len++;
					return (search);
				}
			}
		}
	}
	return (search);
}

t_search	search_path(t_rooms *room, t_rooms start_room, t_search s, int room_count)
{
	int		x;
	int		y;

	x = -1;
	s = check_end(room, start_room, s, room_count);
	while (++x < start_room.links)
	{
		y = -1;
		while(++y < room_count)
		{
			if (s.found_end == 1)
				return (s);
			if (ft_strcmp(start_room.connections[x], room[y].name) == 0
				&& on_list(s, room[y].name) == 0)
			{
				if (s.found_end == 0)
				{
					s.the_list = ft_paragraph(s.the_list, room[y].name, s.list_len);
					s.list_len++;
					s = search_path(room, room[y], s, room_count);
				}
			}
		}
	}
	return (s);
}

t_search	find_path(t_rooms *room, int room_count)
{
	t_rooms		start;
	t_search	search;
	int			x;
	int			links;

	search.list_len = 0;
	search.links = 0;
	search.found_end = 0;
	links = 0;
	x = 0;
	while (x < room_count)
	{
		if (room[x].start == 1)
			start = room[x];
		x++;
	}
	search.the_list = ft_addstr(search.the_list, start.name, search.list_len);
	search.list_len++;
	search = search_path(room, start, search, room_count);
	if (search.found_end == 0)
			error_master5000("FOUND NO END");
	return (search);
}
