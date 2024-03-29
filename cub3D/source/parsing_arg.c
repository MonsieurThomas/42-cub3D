/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:32 by cleblais          #+#    #+#             */
/*   Updated: 2023/04/21 19:09:54 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	error_map_cub(char *av)
{
	char	*ext;

	ext = ft_substr(av, (ft_strlen(av) - 4), 4);
	if (ft_strncmp(ext, ".cub", 4))
	{
		free (ext);
		return (ft_print_error("Error\nArgument problem", NULL));
	}
	free (ext);
	return (0);
}

int	is_av1_legit(char *av)
{
	int	fd;

	if (error_map_cub(av))
		return (1);
	fd = open(av, O_DIRECTORY);
	if (fd > 0)
		return (ft_print_error("Error\nArgument problem", NULL));
	close (fd);
	fd = open(av, O_RDONLY);
	if (fd < 1)
		return (ft_print_error("Error\nArgument problem", NULL));
	close (fd);
	return (0);
}
