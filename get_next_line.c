/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrenier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:36:46 by vgrenier          #+#    #+#             */
/*   Updated: 2016/03/17 15:32:27 by vgrenier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_retour(int i, char *line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && !*line)
		return (0);
	return (1);
}

static int		ft_read(int fd, char **tmp, char **buff, char **tmpb)
{
	int	i;

	i = 1;
	while ((i > 0) && !ft_strchr(*tmp, '\n'))
	{
		free(*tmp);
		i = (!*buff) ? read(fd, *buff, BUFF_SIZE) :
			read(fd, *buff, (BUFF_SIZE - ft_strlen(*buff)));
		(*buff)[i] = '\0';
		if (i < 0)
		{
			if (**tmpb)
				free(*tmpb);
		}
		else if (i > 0)
		{
			*tmp = *tmpb;
			*tmpb = ft_strjoin(*tmpb, *buff);
			free(*tmp);
			*tmp = ft_strdup(*buff);
			ft_bzero(*buff, BUFF_SIZE);
		}
	}
	return (i);
}

static int		ft_copy_line(int fd, char **str, char *buff, char **tmpbuff)
{
	char	*tmp;
	char	*tmpb;
	int		i;

	i = 1;
	tmp = ft_strdup(buff);
	tmpb = ft_strdup(buff);
	i = ft_read(fd, &tmp, &buff, &tmpb);
	if (i > 0)
	{
		*tmpbuff = ft_strdup(ft_strchr(tmp, '\n') + 1);
		free(tmp);
	}
	else if (*tmpbuff)
		ft_bzero(*tmpbuff, ft_strlen(*tmpbuff));
	tmp = tmpb;
	if (ft_strchr(tmpb, '\n'))
		tmpb = ft_strrevchr(tmpb, '\n');
	*str = ft_strdup(tmpb);
	if (i > 0)
		free(tmpb);
	free(tmp);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	char		*str;
	char		*tmpbuff;
	static char	buff[512][BUFF_SIZE + 1];
	int			i;
	int			j;

	if (fd < 0 || fd > 511 || !line || BUFF_SIZE <= 0)
		return (-1);
	j = 0;
	str = NULL;
	tmpbuff = NULL;
	i = ft_copy_line(fd, &str, buff[fd], &tmpbuff);
	ft_bzero(buff[fd], BUFF_SIZE);
	if (i >= 0)
		while (i > 0 && tmpbuff[j])
		{
			buff[fd][j] = tmpbuff[j];
			j++;
		}
	*line = ft_strdup(str);
	free(str);
	free(tmpbuff);
	return (ft_retour(i, *line));
}
