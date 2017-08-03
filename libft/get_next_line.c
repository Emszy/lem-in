/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucheit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:26:45 by ebucheit          #+#    #+#             */
/*   Updated: 2016/12/06 13:36:40 by ebucheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		validate_buffer(char **buff, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*buff, '\n');
	if (tmp)
	{
		*line = ft_strsub(*buff, 0, tmp - *buff);
		ft_memmove(*buff, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		read_line(int fd, char **buff, char **line)
{
	char			bfr[BUFF_SIZE + 1];
	int				bytes_read;
	char			*tmp;

	if (read(fd, bfr, 0) < 0)
		return (-1);
	while ((bytes_read = read(fd, bfr, BUFF_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		bfr[bytes_read] = '\0';
		tmp = NULL;
		if (*buff)
		{
			tmp = ft_strdup(*buff);
			ft_memdel((void **)buff);
			*buff = ft_strjoin(tmp, bfr);
			ft_memdel((void **)&tmp);
		}
		else
			*buff = ft_strdup(bfr);
		if (validate_buffer(buff, line))
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buff[4096];
	int				res;

	if (!line || fd < 0 || fd > 4096  )
		return (-1);
	if (buff[fd] && validate_buffer(&buff[fd], line))
		return (1);
	res = read_line(fd, &buff[fd], line);
	if (res != 0)
		return (res);
	if (buff[fd] == NULL || buff[fd][0] == '\0')
		return (0);
	*line = buff[fd];
	buff[fd] = NULL;
	return (1);
}