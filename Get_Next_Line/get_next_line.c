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

char	*get_next_line(int fd)
{
	static t_buf	buf;
	char			line[5000];
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf.buf_pos >= buf.buf_read)
		{
			buf.buf_read = read(fd, buf.buffer, BUFFER_SIZE);
			buf.buf_pos = 0;
			if (buf.buf_read <= 0)
				break ;
		}
		line[i++] = buf.buffer[buf.buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
