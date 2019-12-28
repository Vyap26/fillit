/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmlkshk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:41:45 by tmlkshk           #+#    #+#             */
/*   Updated: 2019/11/09 13:39:29 by tmlkshk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_rest(char **rest, char **line)
{
	char *p_n;

	p_n = NULL;
	if (*rest)
	{
		if ((p_n = (ft_strchr(*rest, '\n'))))
		{
			*p_n = '\0';
			*line = ft_strdup(*rest);
			if (*(++p_n) != '\0')
				ft_strcpy(*rest, p_n);
			else
				ft_memdel((void **)rest);
		}
		else
		{
			*line = ft_strdup(*rest);
			ft_memdel((void **)rest);
		}
	}
	else
	{
		*line = NULL;
	}
	return (p_n);
}

int		get_line(const int fd, char **line, char **rest)
{
	char		buf[BUFF_SIZE + 1];
	int			byte_read;
	char		*p_n;
	char		*temp;

	byte_read = 0;
	p_n = check_rest(rest, line);
	while (!p_n && (byte_read = read(fd, buf, BUFF_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			if (*(++p_n) != '\0')
				*rest = ft_strdup(p_n);
			else
				ft_memdel((void **)rest);
		}
		temp = *line;
		if (!(*line = ft_join(*line, buf)) || byte_read < 0)
			return (-1);
		if (temp != NULL)
			free(temp);
	}
	return (byte_read >= 0 && *line) ? 1 : 0;
}

t_gnl	*new_linked_list(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->rest = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	char			c;

	if (fd < 0 || read(fd, &c, 0) == -1 || line == NULL)
		return (-1);
	if (head == NULL)
		head = new_linked_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->rest));
}
