/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:53:06 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/22 13:27:54 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*isolate_save(char *tmp)
{
	char	*save;
	int		i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	save = ft_substr(tmp, i + 1, ft_strlen(tmp));
	free(tmp);
	return (save);
}

char	*isolate_line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!tmp[0])
		return (0);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, i);
	return (line);
}

char	*keep_line_and_save(int fd, char *save)
{
	char	*buffer;
	int		num;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	num = 1;
	while (!ft_strchr(save, '\n') && num != 0)
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[num] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*tmp;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (0);
	tmp = keep_line_and_save(fd, save);
	if (!tmp)
		return (0);
	line = isolate_line(tmp);
	save = isolate_save(tmp);
	return (line);
}
// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("./../map.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	// while (line != NULL)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	if (line != NULL)
// 	// 		printf("%s\n", line);
// 	// 	free(line);
// 	// }
// }