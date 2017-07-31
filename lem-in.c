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

int get_ant_count(char *av)
{
	int fd;
	int ants;
	char *line;

	ants = 0;
	fd = open(av, O_RDONLY);
	get_next_line(fd, &line);
	ants = ft_atoi(line);
	close(fd);
	return (ants);
}

int get_room_count(char *av)
{
	char *line;
	int room_count;
	int fd;

	fd = open(av, O_RDONLY);
	room_count = 0;
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	while (get_next_line(fd, &line))
	{
		if (line[0] == '#')
			get_next_line(fd, &line);
		if (ft_strchr(line, ' '))
			room_count++;
	}
	close (fd);
	return (room_count);
}

t_rooms *save_rooms(char *av, t_rooms *room, int room_count)
{
	char *line;
	char **split;
	int fd;
	int x;

	x = 0;
	fd = open(av, O_RDONLY);
	get_next_line(fd, &line);
	while (get_next_line(fd, &line))
	{
		if (x < room_count)
		{
			if (line[0] == '#')
			{
				if (ft_strcmp(line, "##start") == 0)
					room[x].start = 1;
				if (ft_strcmp(line, "##end") == 0)
					room[x].end = 1;
				get_next_line(fd, &line);
			}
			if (ft_strchr(line, ' '))
			{
				split = ft_strsplit(line, ' ');
				room[x].name = malloc(sizeof(char*) * ft_strlen(split[0]) + 1);
				ft_strcpy(room[x].name, split[0]);
				room[x].name[ft_strlen(room[x].name)] = '\0';
				room[x].x = ft_atoi(split[1]);
				room[x].y = ft_atoi(split[2]);
				x++;
			}
			
		}
	}
	close (fd);
	return (room);
}

t_rooms *get_link_count(char *av, t_rooms *room, int room_count)
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
					room[x].links++;
				if (ft_strcmp(split[1], room[x].name) == 0)
					room[x].links++;
				x++;
			}
			
		}
	}
	close (fd);
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


int main(int ac, char **av)
{
	int ants;
	int room_count;
	int x;
	t_rooms *room;
	t_search search;


	room = NULL;
	room_count = 0;
	x = 0;

	if (ac > 1)
	{
		if (av[1])
		{
			ants = get_ant_count(av[1]);
			room_count = get_room_count(av[1]);
			room = (t_rooms *)malloc(sizeof(t_rooms) * room_count);
			room = init_rooms(room, room_count);
			room = save_rooms(av[1], room, room_count);
			room = get_link_count(av[1], room, room_count);
			room = alloc_rooms(room, room_count);
			room = get_link_names(av[1], room, room_count);
			search = find_path(room, room_count);	
			send_ants(search, ants);

			//ft_printf("%s\n", search.the_list);
			

			//print_room(room, room_count);
				
		}
	}
	


	return 0;
}
