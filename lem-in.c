#include "lem-in.h"

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
	if (x <= 1)
		error_master5000("NO GOOD");
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
		error_master5000("NO GOOD");
	while (get_next_line(fd, &line))
	{
		file.data = ft_addstr(file.data, line, x);
		x++;
	}
	if (x <= 1)
		error_master5000("NO GOOD");
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

void free_2d_char(char **data, int length)
{
	int x;

	x = 0;
	while (x < length)
	{
		ft_strdel(&data[x]);
		x++;
	}
	free(&data);
}

void free_room(t_rooms	*room, int room_count)
{
	int x;

	x = 0;
	while (x < room_count)
	{
		free_2d_char(room[x].connections, room[x].links);
		x++;
	}
}

int			main(int ac, char **av)
{
	int			ants;
	int			room_count;
	t_rooms		*room;
	t_search	search;
	t_2d_ptr	file;
	// t_malloc_ptrs head;

	// head = malloc(sizeof(t_malloc_ptrs));
	// head->next = NULL;

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
