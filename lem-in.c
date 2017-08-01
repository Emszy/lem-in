#include "lem-in.h"

typedef struct	s_rooms
{
	int start;
	int end;
	char *name;
	int x;
	int y;
	int links;
	int index;
	char **connections;
}				t_rooms;

typedef struct	s_search
{
	int found_end;
	int links;
	char *end_name;
	char *the_list;
}				t_search;

typedef struct 	s_path
{
	char 	*name;
	int 	ants;
	int		is_start;
	int 	is_end;
	int		end_ants;
}				t_path;

typedef struct s_2d_ptr
{
	char	**data;
	int		length;
}				t_2d_ptr;

int error_master5000(char *message)
{
	ft_putstr(message);
	exit(-1);
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

void print_room(t_rooms *room, int room_count)
{
	int x;
	int n;

	n = 0;
	x = 0;
	while (x < room_count)
	{

		ft_printf("start: %d \n", room[x].start);
		ft_printf("end: %d \n", room[x].end);
		ft_printf("name: %s \n", room[x].name);
		ft_printf("X: %d \n", room[x].x);
		ft_printf("Y: %d \n", room[x].y);
		ft_printf("ROOMLINKS: %d\n", room[x].links);
		ft_printf("ROOMINDEX: %d\n", room[x].index);
		ft_printf("connections: ");
		n = 0;
			while (n < room[x].links)
			{
				ft_printf("%s\n", room[x].connections[n]);
				n++;
			}
		ft_printf("\n");
		ft_printf("\n");
		x++;
	}
}

int get_ant_count(t_2d_ptr file)
{
	int ants;
	int x;

	x = 0;
	ants = 0;
	while(file.data[x][0] == '#')
		x++;
	check_for_letters(file.data[x]);
	ants = ft_atoi(file.data[x]);
	if (ants <= 0)
		error_master5000("no ants");
	return (ants);
}

int get_room_count(t_2d_ptr file)
{
	int room_count;
	int x;

	x = 0;
	room_count = 0;
	while (x < file.length)
	{
		if (ft_strcmp(file.data[x], "##start") == 0 || ft_strcmp(file.data[x], "##end") == 0)
		{
			x++;
			if (!ft_strchr(file.data[x], ' '))
				error_master5000("NO START");
		}
		while (file.data[x][0] == '#')
			x++;
		if (ft_strchr(file.data[x], ' '))
			room_count++;
		x++;
	}
	return (room_count);
}

t_rooms *save_rooms(t_2d_ptr file, t_rooms *room)
{

	int x;
	int y;
	int has_start;
	int has_finish;
	char **split;

	has_finish = 0;
	has_start = 0;
	x = 0;
	y = 0;
	while (y < file.length)
	{
			if (ft_strcmp(file.data[y], "##start") == 0)
			{
				has_start = 1;
				y++;
				room[x].start = 1;
			}
			if (ft_strcmp(file.data[y], "##end") == 0)
			{
				has_finish = 1;
				y++;
				room[x].end = 1;
			}
			while (file.data[y][0] == '#')
				y++;	
		if (ft_strchr(file.data[y], ' '))
		{
			split = ft_strsplit(file.data[y], ' ');
			check_for_letters(split[1]);
			check_for_letters(split[2]);
			room[x].name = ft_strmake(split[0]);
			room[x].x = ft_atoi(split[1]);
			room[x].y = ft_atoi(split[2]);
			x++;
		}
		y++;
	}
	if (has_finish == 0 || has_start == 0)
		error_master5000("NO START  || FINISH ERROR");
	return (room);
}

t_rooms *get_link_count(t_2d_ptr file, t_rooms *room, int room_count)
{

	char *line;
	char **split;
	int x;
	int y = 1;

	while (y < file.length)
	{
		x = 0;
		if (ft_strchr(line, '-'))
		{
			split = ft_strsplit(line, '-');
			while (x < room_count)
			{
				if (!split[0] || !split[1] || split[2])
					error_master5000("NO DASH ERROR");
				if (ft_strcmp(split[0], room[x].name) == 0)
					room[x].links++;
				if (ft_strcmp(split[1], room[x].name) == 0)
					room[x].links++;
				x++;
			}
		}
		y++;
	}
	return (room);
}

t_rooms *get_link_names(char *av, t_rooms *room, int room_count)
{

	char *line;
	int fd;
	char **split;
	int x;

	fd = open(av, O_RDONLY);
	get_next_line(fd, &line);
	while (get_next_line(fd, &line))
	{
		x = 0;
		if (ft_strchr(line, '-'))
		{
			split = ft_strsplit(line, '-');
			while (x < room_count)
			{
				if (ft_strcmp(split[0], room[x].name) == 0)
				{
					room[x].connections[room[x].index] = (char*)malloc(sizeof(char) * ft_strlen(split[1]));
					ft_strcpy(room[x].connections[room[x].index], split[1]);
					room[x].index++;
				}
				if (ft_strcmp(split[1], room[x].name) == 0)
				{
					room[x].connections[room[x].index] = (char*)malloc(sizeof(char) * ft_strlen(split[0]));
					ft_strcpy(room[x].connections[room[x].index], split[0]);
					room[x].index++;
				}
				x++;
			}
		}
	}
	close (fd);
	return (room);
}

t_rooms *alloc_rooms(t_rooms *room, int room_count)
{
	int x;

	x = 0;
	while (x < room_count)
	{
		room[x].connections =  (char**)malloc(sizeof(char*) * room[x].links);
		x++;
	}
	return (room);

}

int not_on_the_list(char *the_list, char *name)
{
	char **split;
	int x;

	x = 0;
	split = ft_strsplit(the_list, ' ');

	while (split[x])
	{
		if (ft_strcmp(split[x], name) == 0)
		{
			return (0);
		}
		x++;
	}
	return (1);
}

int del_list(char *the_list, char *name)
{
	char **split;
	int x;

	x = 0;
	split = ft_strsplit(the_list, ' ');

	while (split[x])
	{
		if (ft_strcmp(split[x], name) == 0)
		{
			return (0);
		}
		x++;
	}
	return (1);
}

t_search check_end(t_rooms *room, t_rooms start_room, t_search search, int room_count)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < start_room.links)
	{
		y = 0;
		while (y < room_count)
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
			y++;
		}
		x++;
	}
	return (search);
}



t_search search_path(t_rooms *room, t_rooms start_room, t_search search, int room_count)
{
	int x;
	int y;

	y = 0;
	x = 0;

	search = check_end(room, start_room, search, room_count);
	
		while (x < start_room.links)
		{
			y = 0;
			while(y < room_count)
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
				y++;
			}
			x++;
		}
	return (search);
}

t_search find_path(t_rooms *room, int room_count)
{
	t_rooms start_room;
	t_search search;
	int x;
	int links;

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

int path_length(t_search search)
{
	char **split;
	int x;

	x = 0;
	split = ft_strsplit(search.the_list, ' ');

	while (split[x])
	{
		x++;
	}
	return (x);
}

t_path *make_path(t_search search)
{
	t_path *path;

	path = malloc(sizeof(t_path) * path_length(search));

	char **split;
	int x;

	x = 0;
	split = ft_strsplit(search.the_list, ' ');
	while (split[x])
	{
		path[x].name = malloc(sizeof(char *) * ft_strlen(split[x]));
		ft_strcpy(path[x].name, split[x]);
		if (x == 0)
		{
			path[x].is_start = 1;
		}
		else
		{
			path[x].is_start = 0;
			path[x].ants  = 0;
			path[x].is_end = 0;
		}
		printf("%s -", path[x].name);
		x++;
	}
	x--;
	path[x].is_end = 1;
	printf("\n");
	return (path);
}

void send_ants(t_search search, int ants)
{
	int x;
	int y;
	int length;
	int start_ant;
	int ant_count;
	t_path *path;
	length = path_length(search);
	y = 0;
	x = 0;
	start_ant = 0;
	ant_count = ants;
	path = make_path(search);

	while (path[length - 1].ants < ants)
	{
		start_ant++;
		
		if (ant_count <= 0)
		{
			start_ant = 0;
		}

		while (path[x].is_end != 1)
			x++;
		while(path[x].is_start == 0)
		{
			if (path[x - 1].ants != 0)
			{
				path[x].ants = path[x - 1].ants;
				path[x - 1].ants = 0;
			}
			x--;
		}
		y = 1;
		while(y < length)
		{
			if (path[y].ants)
				printf("L%d-%s ", path[y].ants, path[y].name);
			y++;
		}
		printf("\n");
		ant_count--;
		path[x].ants = start_ant;

	}
}

t_2d_ptr save_input()
{
	char *line;
	t_2d_ptr file;
	int x;
	int y;

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
	return (file);;
}

t_2d_ptr save_file(char *filename)
{
	char *line;
	t_2d_ptr file;
	int fd;
	int x;
	int y;

	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		file.data = ft_addstr(file.data, line, x);
		x++;
	}
	file.length = x;
	return (file);
}

int main(int ac, char **av)
{
	int ants;
	int room_count;
	t_rooms *room;
	t_search search;
	char *filename;
	t_2d_ptr file;

	room = NULL;
	room_count = 0;
	if (ac > 0)
	{
		if (av[1])
		{
			file = save_file(av[1]);
		}
		else
			file = save_input();
			ants = get_ant_count(file);
			filename = ft_strmake(av[1]);


			room_count = get_room_count(file);
			if (room_count <= 1)
				error_master5000("ERROR");
			printf("rooms:%d\n", room_count);
			room = (t_rooms *)malloc(sizeof(t_rooms) * room_count);
			if (!room)
				error_master5000("NO SPACE");
			ft_putstr("initializing rooms\n");
			room = init_rooms(room, room_count);
			ft_putstr("saving rooms\n");
			room = save_rooms(file, room);
			int x = -1;
			while (++x < room_count)
			{
				printf("%s\n", room[x].name);
				printf("START:%d\n", room[x].start);
				printf("END: %d\n", room[x].end);
			}

			ft_putstr("getting links\n");
			room = get_link_count(file, room, room_count);
			ft_putstr("allocating rooms\n");
			room = alloc_rooms(room, room_count);
			ft_putstr("getting links names\n");
			room = get_link_names(filename, room, room_count);
			ft_putstr("finding path\n");
			search = find_path(room, room_count);	
			send_ants(search, ants);
		}
	return 0;
}
