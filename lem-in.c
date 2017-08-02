#include "lem-in.h"

t_rooms		*get_link_count(t_2d_ptr file, t_rooms *room, int room_count)
{
	char	**split;
	int		x;
	int		y;
	
	y = -1;
	x = -1;
	while (++y < file.length)
	{
		if (ft_strchr(file.data[y], '-'))
		{
			x = -1;
			split = ft_strsplit(file.data[y], '-');
			while (++x < room_count)
			{
				if (ft_strcmp(split[0], room[x].name) == 0)
					room[x].links++;
				if (ft_strcmp(split[1], room[x].name) == 0)
					room[x].links++;
			}
		}
	}
	return (room);
}

t_rooms		check_link(t_rooms *room, char** split, int x)
{
	if (ft_strcmp(split[0], room[x].name) == 0)
	{
		room[x].connections[room[x].index] = ft_strmake(split[1]);
		room[x].index++;
	}
	if (ft_strcmp(split[1], room[x].name) == 0)
	{
		room[x].connections[room[x].index] = ft_strmake(split[0]);
		room[x].index++;
	}
	return (room[x]);
}


t_rooms		*get_link_names(t_2d_ptr file, t_rooms *room, int room_count)
{
	char	**split;
	int		x;
	int		y;

	y = -1;
	while (++y < file.length)
	{
		x = -1;
		if (ft_strchr(file.data[y], '-'))
		{
			split = ft_strsplit(file.data[y], '-');
			while (++x < room_count)
				room[x] = check_link(room, split, x);
		}
	}
	return (room);
}

t_rooms		*alloc_rooms(t_rooms *room, int room_count)
{
	int		x;

	x = -1;
	while (++x < room_count)
		room[x].connections =  (char**)malloc(sizeof(char*) * room[x].links);
	return (room);

}

int			not_on_the_list(char *the_list, char *name)
{
	char	**split;
	int		x;

	x = -1;
	split = ft_strsplit(the_list, ' ');

	while (split[++x])
	{
		if (ft_strcmp(split[x], name) == 0)
			return (0);
	}
	return (1);
}

int			del_list(char *the_list, char *name)
{
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(the_list, ' ');

	while (split[x])
	{
		if (ft_strcmp(split[x], name) == 0)
			return (0);
		x++;
	}
	return (1);
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
					search.the_list = ft_strjoin(search.the_list, room[y].name);
					return (search);
				}
			}
		}
	}
	return (search);
}



t_search	search_path(t_rooms *room, t_rooms start_room, t_search search, int room_count)
{
	int		x;
	int		y;

	x = -1;
	search = check_end(room, start_room, search, room_count);
		while (++x < start_room.links)
		{
			y = -1;
			while(++y < room_count)
			{
				if (search.found_end == 1)
					return (search);
				if(ft_strcmp(start_room.connections[x], room[y].name) == 0 && not_on_the_list(search.the_list, room[y].name) == 1)
				{
					if (search.found_end == 0)
					{
						search.the_list = ft_strjoin(search.the_list, room[y].name);
						search.the_list = ft_strjoin(search.the_list, " ");
						search = search_path(room, room[y], search, room_count);
					}
				}
			}
		}
	return (search);
}

t_search	find_path(t_rooms *room, int room_count)
{
	t_rooms		start_room;
	t_search	search;
	int			x;
	int			links;

	search.links = 0;
	search.found_end = 0;
	links = 0;
	x = 0;
	while (x < room_count)
	{
		if (room[x].start == 1)
			start_room = room[x];
		x++;
	}
	search.the_list = malloc(sizeof(char*) * ft_strlen(start_room.name) + 1);
	ft_strcpy(search.the_list, start_room.name);
	search.the_list = ft_strjoin(search.the_list, " ");
	search = search_path(room, start_room, search, room_count);
	if (search.found_end == 0)
			error_master5000("FOUND NO END");
	return (search);

}

int 		path_length(t_search search)
{
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(search.the_list, ' ');
	while (split[x])
		x++;
	return (x);
}

t_path 		*make_path(t_search search)
{
	t_path	*path;
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(search.the_list, ' ');
	path = malloc(sizeof(t_path) * path_length(search));
	while (split[x])
	{
		path[x].name = malloc(sizeof(char *) * ft_strlen(split[x]));
		ft_strcpy(path[x].name, split[x]);
		if (x == 0)
			path[x].is_start = 1;
		else
		{
			path[x].is_start = 0;
			path[x].ants  = 0;
			path[x].is_end = 0;
		}
		x++;
	}
	x--;
	path[x].is_end = 1;
	return (path);
}

t_path 		*move_ant(t_path *path, int x)
{
	if (path[x - 1].ants != 0)
	{
		path[x].ants = path[x - 1].ants;
		path[x - 1].ants = 0;
	}
	return (path);
}

void 		show_ant_path(t_path *path, int length)
{
	int		y;

	y = 0;
	while(++y < length)
		if (path[y].ants)
			printf("L%d-%s ", path[y].ants, path[y].name);
		printf("\n");
}

void		send_ants(t_search search, int ants)
{
	int		x;
	int		length;
	int		start_ant;
	int		ant_count;

	t_path *path;
	length = path_length(search);
	x = 0;
	start_ant = 0;
	ant_count = ants;
	path = make_path(search);
	while (path[length - 1].ants < ants)
	{
		start_ant++;
		if (ant_count <= 0)
			start_ant = 0;
		while (path[x].is_end != 1)
			x++;
		while(path[x].is_start == 0)
			path = move_ant(path, x--);
		show_ant_path(path, length);
		ant_count--;
		path[x].ants = start_ant;
	}
}

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
		x++;
	}
	file.length = x;
	return (file);
}

t_2d_ptr	save_file(char *filename)
{
	char		*line;
	t_2d_ptr	file;
	int			fd;
	int			x;
	int			y;

	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error_master5000("NO GOOD");å
	while (get_next_line(fd, &line))
	{
		file.data = ft_addstr(file.data, line, x);
		x++;
	}
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
				error_master5000("NO SPACE");
			room = prep_rooms(room, file, room_count);
			search = find_path(room, room_count);	
			send_ants(search, ants);
		}
	return (0);
}
