/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:34:48 by vfurmane          #+#    #+#             */
/*   Updated: 2021/08/04 16:49:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_get_fd_in_list(t_list *lst, int fd)
{
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		else
			lst = lst->next;
	}
	return (NULL);
}

char	*ft_strdupcat(char *dest, char *src)
{
	char			*res;
	unsigned long	i;
	unsigned long	dest_start;
	unsigned long	src_size;

	i = 0;
	dest_start = 0;
	while (dest[i++])
		dest_start++;
	i = 0;
	src_size = 0;
	while (src[i++])
		src_size++;
	i = -1;
	res = malloc(sizeof(*res) * (dest_start + src_size + 1));
	if (res == NULL)
		return (NULL);
	while (dest[++i])
		res[i] = dest[i];
	i = -1;
	while (src[++i])
		res[dest_start + i] = src[i];
	res[dest_start + i] = '\0';
	free(dest);
	return (res);
}

int	ft_read(int fd, t_list *elm)
{
	int		ret;
	int		result;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (buffer == NULL)
		return (-1);
	result = 1;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret != 0)
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		elm->content = ft_strdupcat(elm->content, buffer);
	}
	else
		result = 0;
	free(buffer);
	return (result);
}

int	ft_read_until_newline(int fd, char **line, t_list *elm)
{
	int	result;

	while (ft_strchr(elm->content, '\n') == NULL)
	{
		result = ft_read(fd, elm);
		if (result == 0)
			break ;
		else if (result == -1)
			return (-1);
	}
	*line = ft_splitc(&elm->content);
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*line_list;
	int				result;
	t_list			*elm;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	elm = ft_get_fd_in_list(line_list, fd);
	if (elm == NULL)
	{
		elm = ft_lstadd_front(&line_list, fd);
		if (elm == NULL)
			return (-1);
	}
	result = ft_read_until_newline(fd, line, elm);
	if (result == -1 || *line == NULL)
		return (-1);
	if (result == 0)
		return (ft_free_elm(&line_list, elm));
	result = result != 0;
	return (result);
}
