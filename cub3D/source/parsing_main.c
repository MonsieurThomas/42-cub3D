/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:42:21 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 20:41:27 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_openning_texture(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image \
	(data->mlx, data->NO, &data->imgsiz, &data->imgsiz);
	data->texture[1].img = mlx_xpm_file_to_image \
	(data->mlx, data->SO, &data->imgsiz, &data->imgsiz);
	data->texture[2].img = mlx_xpm_file_to_image \
	(data->mlx, data->WE, &data->imgsiz, &data->imgsiz);
	data->texture[3].img = mlx_xpm_file_to_image \
	(data->mlx, data->EA, &data->imgsiz, &data->imgsiz);
	if (data->texture[0].img == NULL || data->texture[1].img == NULL \
	|| data->texture[2].img == NULL || data->texture[3].img == NULL)
		return (ft_print_error("Error\nProbleme de textures", NULL));
	return (0);
}

int	parsing_main(t_data *data)
{ // Je suis peu clair concernant les messages d'erreurs, c'est fait expres, si en eval il y a un probleme que je 
	data->i = 0; // n'ai pas anticipé, on a moins de risque de me faire suprendre
	while (data->map[data->i]) // il y a probablement encore des defauts, je t'invite a faire des tests aussi
	{ // je sais que ca segfault quand on ferme la fenetre avec la croix rouge, je vais regler ce probleme
		if (!ft_strncmp(data->map[data->i], "NO ", 3) || \
		!ft_strncmp(data->map[data->i], "SO ", 3) || \
		!ft_strncmp(data->map[data->i], "WE ", 3) || \
		!ft_strncmp(data->map[data->i], "EA ", 3))
		{
			data->error += put_wall_in_struct(data, data->i);
			data->wall++; // je compte les murs pour etre sur qu'il y en a 4, et quelqu'un met 2 fois le meme, ca plantera plus loin
		}
		else if (!ft_strncmp(data->map[data->i], "F ", 2) || \
		!ft_strncmp(data->map[data->i], "C ", 2))
		{
			data->error += get_color(data, data->i);
		}
		else if (data->wall == 4 && data->colorC && data->colorF) // attend 4 murs et 2 couleurs pour commencer à chercher la carte
		{
			if (is_beginning_of_map(data, data->i))
			{
				if (create_new_map(data, data->i))
					return (1);
				break ;
			}
		}
		if (data->error)
			return (1);
		(data->i)++;
	}
	if (data->wall != 4)
		return (ft_print_error("Error\nProbleme de textures", NULL));
	if (!data->colorC || !data->colorF)
		return (ft_print_error("Error\nProbleme de couleurs", NULL));
	if (check_openning_texture(data))
		return (1);
	return (0);
}
