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
			x = 0;
			free_2d_char(split, 2);
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
	int		n;

	n = 0;
	y = -1;
	while (++y < file.length)
	{
		x = -1;
		if (ft_strchr(file.data[y], '-'))
		{
			split = ft_strsplit(file.data[y], '-');
			while (++x < room_count)
				room[x] = check_link(room, split, x);
			n = 0;
			while(split[n])
			{
				free(split[n]);
				n++;
			}
			free(split);
		}
	}
	return (room);
}
