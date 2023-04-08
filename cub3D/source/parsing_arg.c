/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:29:33 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 19:20:47 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

int	error_map_cub(char *av)
{
	char	*ext;

	ext = ft_substr(av, (ft_strlen(av) - 4), 4); // creer une nouvelle string avec les 4 derniers char de av1
	if (ft_strncmp(ext, ".cub", 4))
	{
		free (ext);
		return (ft_print_error("Error\nProbleme d'argument", NULL));
	}
	free (ext);
	return (0);
}

int	is_av1_legit(char *av)
{
	int	fd;

	if (error_map_cub(av))
		return (1);
	fd = open(av, O_DIRECTORY); // essaye d'ouvrir dossier
	if (fd > 0)
		return (ft_print_error("Error\nProbleme d'argument", NULL));
	close (fd);
	fd = open(av, O_RDONLY);
	if (fd < 1)
		return (ft_print_error("Error\nProbleme d'argument", NULL));
	close (fd);
	return (0);
}
