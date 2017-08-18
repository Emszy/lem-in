#include "libft.h"

void free_2d_char(char **data, int length)
{
	int x;

	x = -1;
	while (++x < length)
		free(data[x]);
	free(data);
}