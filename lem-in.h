/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
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
	int alloc;
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
	int list_len;
	char **the_list;
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

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void		free_lemons(t_rooms *room, t_search search, t_2d_ptr file, int room_count);
void		usage(int ac);
int			split_count(char c, char *line, int count);
void		check_for_l_and_spaces(char *line);
int			check_line(char *line, int found_ant);
void		check_dup(t_rooms *room, int room_count);
t_rooms		*alloc_rooms(t_rooms *room, int room_count);
int			check_for_letters(char *string);
t_rooms		*init_rooms(t_rooms *room, int room_count);
void		print_room(t_rooms *room, int room_count);
int			get_ant_count(t_2d_ptr file);
int			get_room_count(t_2d_ptr file);
t_rooms		*check_for_hash(t_2d_ptr *file, t_rooms *room);
t_rooms		room_info(char** split, t_rooms room);
t_rooms		*save_rooms(t_2d_ptr file, t_rooms *room);
t_rooms		*get_link_count(t_2d_ptr file, t_rooms *room, int room_count);
t_rooms		check_link(t_rooms *room, char** split, int x);
t_rooms		*get_link_names(t_2d_ptr file, t_rooms *room, int room_count);
int			not_on_the_list(t_search search, char *name);
t_search	check_end(t_rooms *room, t_rooms start_room, t_search search, int room_count);
t_search	search_path(t_rooms *room, t_rooms start_room, t_search search, int room_count);
t_search	find_path(t_rooms *room, int room_count);
int 		path_length(t_search search);
t_path 		*make_path(t_search search);
t_path 		*move_ant(t_path *path, int x);
void 		show_ant_path(t_path *path, int length);
void		send_ants(t_search search, int ants);

#endif
