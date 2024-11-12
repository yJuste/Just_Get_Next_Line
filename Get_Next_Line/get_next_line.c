/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2024/11/10 15:16:43 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// 26 lignes !
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_read;
	static int	buf_pos;
	char		line[70000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_read <= 0)
				break ;
		}
		line[i++] = buffer[buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
