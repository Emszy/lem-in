#include "lem-in.h"

char	*ft_strmake(char *string)
{
	char *new;

	new = (char*)malloc(sizeof(char*) * ft_strlen(string));
	new = ft_strcpy(new, string);
	return(new);
}


char	**malloc_list(char *string)
{
	char **new;

	new = (char**)malloc(sizeof(char*));
	new[0] = ft_strmake(string);
	return (new);
}

char	**ft_addstr(char **list, char *string, int size)
{
	int x;
	int y;
	char **new;
	x = 0;
	y = 0;

	if (size == 0)
		return(malloc_list(string));
	new = (char**)malloc(sizeof(char*) * (size + 1));
	y = 0;
	while (y < size)
	{
		new[y] = ft_strmake(list[y]);
		y++;
	}
	new[y] = ft_strmake(string);
	y = -1;
	while (++y < size)
		ft_strdel(&list[y]);
	free(list);
	return (new);
}
