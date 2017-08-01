#include "lem-in.h"

char	*ft_strmake(char *string)
{
	char *new;

	new = (char*)malloc(sizeof(char*) * ft_strlen(string) + 1);
	new = ft_strcpy(new, string);
	new[ft_strlen(string)] = '\0';
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
	{
		return(malloc_list(string));
	}
	new = (char**)malloc(sizeof(char*) * (size + 1));

	y = 0;
	while (y < size)
	{
		new[y] = ft_strmake(list[y]);
		y++;
	}
	new[y] = ft_strmake(string);

	return (new);
}



int main(void)
{

	int x = 0;
	char **list = NULL;
	char *one = ft_strmake("ONE ONE ONE ONE 1111 11 1 1 1 11 one ONEONEONE ONE ONE ONE 1111 11 1 1 1 11 one ONEONE");
	char *two = ft_strmake("TWWO TWWO TWWO TWWO  TWWO TWWOTWWO");
	char *three = ft_strmake("THREE THREE THREE THREE  THREE THREETHREE");
	char *four = ft_strmake("FOUR FOUR FOUR FOUR  FOUR FOURFOUR");
	char *five = ft_strmake("FIVE FIVE FIVE FIVE FIVE ");
	char *six = ft_strmake("SIIX SIX SIX SIX SIX SIX ");
	char *seven = ft_strmake("SEVEN SEVEN SEVEN SEVEN");
	char *eight = ft_strmake("EIGHT EIIGHT EIGHT");
	list = ft_addstr(list, one, 0);
	list = ft_addstr(list, two, 1);
	list = ft_addstr(list, three, 2);
	list = ft_addstr(list, four, 3);
	list = ft_addstr(list, five, 4);
	list = ft_addstr(list, six, 5);
	list = ft_addstr(list, seven, 6);
	list = ft_addstr(list, eight, 7);
	list = ft_addstr(list, one, 8);
	list = ft_addstr(list, two, 9);
	list = ft_addstr(list, three, 10);
	list = ft_addstr(list, four, 11);
	list = ft_addstr(list, five, 12);
	list = ft_addstr(list, six, 13);
	list = ft_addstr(list, seven, 14);
	list = ft_addstr(list, eight, 15);

	while (x <= 15)
	{
		ft_printf("%s\n", list[x]);
		x++;
	}

	return 0;
}