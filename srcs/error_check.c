/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:35:57 by ebucheit          #+#    #+#             */
/*   Updated: 2017/08/17 18:35:57 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../lem-in.h"

int split_count(char c, char *line, int count)
{
	int x;
	char **split;

	x = 0;
	if (ft_strchr(line, c))
	{	
		split = ft_strsplit(line, c);
		while (split[x])
			x++;
		free_2d_char(split, x);
		if (x != count)
			error_master5000("ERROR WRONG SPACES OR DASHES");
			return (1);
	}
	return (0);
}

void check_for_l_and_spaces(char *line)
{
	int space;
	int x;

	x = 0;
	space = 0;
	if (line[0] == 'L')
		error_master5000("ERROR L");
	if (ft_strchr(line, ' ') != NULL && ft_strchr(line, '-') != NULL)
		error_master5000("ERROR SPACE AND DASH");
	while (line[x] != '\0')
	{
		if (line[x] == ' ')
			space++;
		x++;
	}
	if (space != 2 && space != 0)
		error_master5000("ERROR WRONG SPACE");
}

int check_line(char *line, int found_ant)
{
	int space;
	int dash;
	int hash;
	int comment;

	comment = 0;
	space = 0;
	dash = 0;
	hash = 0;
	if (line[0] == '#' && line[1] != '#')
	{
		ft_printf("%s\n", line);
		comment = 1;
	}
	if (line[0] == '#' && line[1] == '#')
	{
		ft_printf("%s\n", line);
		hash = 1;
	}
	if (hash == 0 && comment == 0)
	{
		space = split_count(' ', line, 3);
		dash = split_count('-', line, 2);
		check_for_l_and_spaces(line);
	}
	if (space && dash)
		error_master5000("ERROR SPACE & DASH");
	if (space == 0 && dash == 0 && hash == 0 && comment == 0 && check_for_letters(line) && found_ant == 0)
		return(1);
	return (found_ant);
}

void check_dup(t_rooms *room, int room_count)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++x < room_count)
	{
		y = -1;
		while (++y < room_count)
		{
			if (ft_strcmp(room[x].name, room[y].name) == 0 && x != y)
				error_master5000("DUPLICATE");
		}
	}
}
