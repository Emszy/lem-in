/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:06:36 by ebucheit          #+#    #+#             */
/*   Updated: 2017/06/28 17:06:36 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMON_H
# define LEMON_H

# include "libft/libft.h"

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

typedef struct s_2d_ptr
{
	char	**data;
	int		length;
	int		has_start;
	int		has_finish;
}				t_2d_ptr;

char		*ft_strmake(char *string);
char		**malloc_list(char *string);
char		**ft_addstr(char **list, char *string, int size);
int			error_master5000(char *message);
int			check_for_letters(char *string);
t_rooms		*init_rooms(t_rooms *room, int room_count);
void		print_room(t_rooms *room, int room_count);
int			get_ant_count(t_2d_ptr file);
int			get_room_count(t_2d_ptr file);
t_rooms		*check_for_hash(t_2d_ptr *file, t_rooms *room);
t_rooms		*room_info(char** split, t_rooms *room, int x);
t_rooms		*save_rooms(t_2d_ptr file, t_rooms *room);




#endif
