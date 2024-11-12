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

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		total_size;
	void		*ptr;

	i = 0;
	if (count == 0 || size == 0)
		total_size = 0;
	else
		total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while (i < total_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char		*dest;
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	dest = ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[60];
	static int	buf_read;
	static int	buf_pos;
	char		line[50000];
	int			i;

	i = 0;
	buf_read = 0;
	buf_pos = 0;
	if (fd < 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_read = read(fd, buffer, 60);
			buf_pos = 0;
			if (buf_read <= 0)
				break ;
		}
		if (line[i] == '\n')
			break ;
		line[i++] = buffer[buf_pos++];
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

