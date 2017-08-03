#include "lem-in.h"

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
	ft_strdel(&search.end_name);
	ft_strdel(&search.the_list);
}
