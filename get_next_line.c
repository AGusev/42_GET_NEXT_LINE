/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:29:49 by agusev            #+#    #+#             */
/*   Updated: 2019/03/05 21:29:01 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		**checkforanewline(char **line, int fd, int len, char **str)
{
	char	*tmp;

	*line = ft_strsub(str[fd], 0, len);
	tmp = ft_strdup(str[fd] + len + 1);
	free(str[fd]);
	str[fd] = tmp;
	return (str);
}

int			newline(char **str, char **line, int fd, int n)
{
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
		checkforanewline(line, fd, len, str);
	else if (str[fd][len] == '\0')
	{
		if (n == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				n;

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > MAX_FD)
		return (EOF);
	while ((n = read(fd, buffer, BUFF_SIZE)) >= 0)
	{
		buffer[n] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		tmp = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (n < 0)
		return (EOF);
	else if (n == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (newline(s, line, fd, n));
}
