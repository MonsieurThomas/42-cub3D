/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:12:32 by cleblais          #+#    #+#             */
/*   Updated: 2023/04/21 16:39:21 by cleblais         ###   ########.fr       */
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
		return (ft_print_error("Error\nArgument problem3", NULL));//*3
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
		return (ft_print_error("Error\nArgument problem4", NULL));//*4
	close (fd);
	fd = open(av, O_RDONLY);
	if (fd < 1)
		return (ft_print_error("Error\nArgument problem5", NULL));//5
	close (fd);
	return (0);
}
