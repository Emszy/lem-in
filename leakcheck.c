#include "lem-in.h"

int main(void)
{
	char *newstr;
	char *newerstr;
	newstr = ft_strnew(5);
	newstr = ft_strcpy(newstr, "HELLO000");
	newerstr = ft_strdup(newstr);
	free(newstr);
	free(newerstr);
	return 0;
}