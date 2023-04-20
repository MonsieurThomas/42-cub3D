/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:00:56 by romainthoma       #+#    #+#             */
/*   Updated: 2023/04/20 15:52:55 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	put_texture_in_struc(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx, \
	data->no, &data->imgsiz, &data->imgsiz);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx, \
	data->so, &data->imgsiz, &data->imgsiz);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx, \
	data->we, &data->imgsiz, &data->imgsiz);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx, \
	data->ea, &data->imgsiz, &data->imgsiz);
	if (data->texture[0].img == NULL || \
	data->texture[1].img == NULL || data->texture[2].img == NULL
		|| data->texture[3].img == NULL)
		return (ft_print_error("Error\nProbleme de textures", NULL));
	if (get_textu_addr(data))
		return (1);
	return (0);
}

void	innit_values_reste(t_data *data)
{
	data->jmax = 0;
	data->wall = 0;
	data->error = 0;
	data->mlx = mlx_init();
	data->color_c = 0;
	data->color_f = 0;
	data->is_map = 0;
	data->parsing_main_loop = 0;
	data->map_nb_lines = 0;
	data->is_changed = 0;
	data->rotspeed = 0.1;
}

void	innit_values(t_data *data)
{
	data->img_width = 600;
	data->img_height = 600;
	data->player_x = 2.0;
	data->player_y = 2.0;
	data->main_dir_x = -1.0;
	data->main_dir_y = 0.0;
	data->fov_x = 0;
	data->fov_y = 0.66;
	data->ratio = 1 / 1.33;
	data->move_speed = 0.08;
	data->time = 0;
	data->old_time = 0;
	data->w = 600;
	data->kill_win = 0;
	data->forward = 0;
	data->backward = 0;
	data->rightward = 0;
	data->leftward = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->imgsiz = 64;
	data->deb_x = 450;
	data->deb_y = 450;
	innit_values_reste(data);
}
