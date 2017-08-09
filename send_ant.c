#include "lem-in.h"

t_path 		*make_path(t_search search)
{
	t_path	*path;
	int		x;

	x = 0;
	path = malloc(sizeof(t_path) * search.list_len);
	while (x < search.list_len)
	{
		path[x].name = ft_strmake(search.the_list[x]);
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
	if (path[x - 1].ants > 0)
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
	t_path 	*path;
	
	length = search.list_len;
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
