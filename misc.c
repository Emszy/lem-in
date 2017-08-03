#include "lem-in.h"

int error_master5000(char *message)
{
	ft_putstr(message);
	ft_putstr("\n");
	exit(-1);
}

t_rooms		*alloc_rooms(t_rooms *room, int room_count)
{
	int		x;

	x = -1;
	while (++x < room_count)
		room[x].connections =  (char**)malloc(sizeof(char*) * room[x].links);
	return (room);
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
	x = -1;
	while (++x < room_count)
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
	}
}