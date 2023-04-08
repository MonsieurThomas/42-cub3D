/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainthomas <romainthomas@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:00:56 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/08 20:32:27 by romainthoma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/struc.h"

int	put_texture_in_struc(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx, \
	data->NO, &data->imgsiz, &data->imgsiz);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx, \
	data->SO, &data->imgsiz, &data->imgsiz);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx, \
	data->WE, &data->imgsiz, &data->imgsiz);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx, \
	data->EA, &data->imgsiz, &data->imgsiz);
	if (data->texture[0].img == NULL || data->texture[1].img == NULL || data->texture[2].img == NULL
		|| data->texture[3].img == NULL)
		return (ft_print_error("Error\nProbleme de textures", NULL));
	get_textu_addr(data);
	return (0);
}

void	innit_values_reste(t_data *data)
{
	data->jmax = 0;
	data->wall = 0;
    data->error = 0;
	data->mlx = mlx_init();
	data->colorC = 0;
	data->colorF = 0;
}

void	innit_values(t_data *data)
{
	data->img_width = 600;
	data->img_height = 600;
	data->posX = 2.0;
	data->posY = 2.0;
	data->dirX = -1.0;
	data->dirY = 0.0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->ratio = ((double)data->img_width / \
	(double)data->img_height) / (4.0 / 3.0);
	data->moveSpeed = 0.08;
	data->time = 0;
	data->oldTime = 0;
	data->w = 600;
	data->kill_win = 0;
	data->forward = 0;
	data->backward = 0;
	data->rightward = 0;
	data->leftward = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->imgsiz = 64;
	data->debX = 450;
	data->debY = 450;
	innit_values_reste(data);
}
